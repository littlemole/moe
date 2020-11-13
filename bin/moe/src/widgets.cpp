#include "stdafx.h"
#include "widgets.h"
#include "moe.h"
#include "Docs.h"
#include "mdichild.h"
#include "xmlui.h"
#include "MoeBar.h"
#include "ribbonres.h"
#include "resource.h"
#include "Shobjidl.h"
#include "win/msgloop.h"
#include <regex>

// open file dialog std filte for moe
wchar_t  InFilesFilter[]   = _T("open text files *.*\0*.*\0open UTF-8 text files *.*\0*.*\0open HTML files *.*\0*.*\0open rtf files *.*\0*.rtf\0open file in hexviewer *.*\0*.*\0tail log file *.*\0*.*\0\0");


/////////////////////////////////////////////////////////////////////////////////////////////

Encodings::Encodings()
{
	//capture supported codepages. we add three pretty well-known to the list
	codePages_.push_back( CodePage(std::make_pair(CP_ACP,L"Default CodePage")) );
	codePages_.push_back( CodePage(std::make_pair(CP_UTF8,L"UTF-8")) );
	codePages_.push_back( CodePage(std::make_pair(CP_WINUNICODE,L"Unicode (UTF-16)")) );

	const mol::CodePages::Entries& cps = mol::CodePages::codePages();
	for ( mol::CodePages::Iterator it = cps.begin(); it != cps.end(); it++)
	{
		codePages_.push_back( CodePage( std::make_pair( (*it).first, (*it).second.second)) );
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////



void MoeStatusBar::status(int i)
{
	progress()->show(SW_SHOW);
	progress()->setPos(i);
}

void MoeStatusBar::status( const std::wstring& txt )
{
	progress()->show(SW_HIDE);

	std::wostringstream oss;
	std::wostringstream oss2;

	std::wstring dirty(_T("         "));
	VARIANT_BOOL vb = VARIANT_FALSE;

	mol::punk<IMoeDocument> doc;
	docs()->get_ActiveDoc(&doc);
	if(doc)
	{
		mol::punk<IDispatch> disp;
		doc->get_Object(&disp);
		if(disp)
		{
			mol::punk<IScintillAx> sci(disp);
			if(sci)
			{
				mol::punk<IScintillAxText> txt;
				sci->get_Text(&txt);
				if(txt)
				{
					txt->get_Modified(&vb);
				}
				mol::punk<IScintillAxLine> line;
				sci->get_Line(&line);
				if(line)
				{
					long l = 0;
					line->Current(&l);
					oss << (l+1);

					long pos = 0;
					long linepos = 0;

					mol::punk<IScintillAxPosition> position;
					sci->get_Position(&position);
					if(position)
					{
						position->get_Caret(&pos);
						line->PosFromLine(l,&linepos);
					}

					long col = pos-linepos;
					oss2 << col << " "; 
				}
				if ( vb == VARIANT_TRUE )
				{
					dirty = _T("modified");
				}
				else
				{
					dirty = _T("not modified");
				}
			}
		}
	}

	setText( txt, dirty, oss.str(), oss2.str());
}

/////////////////////////////////////////////////////////////////////////////////////////////

class Timeout
{
public:

	typedef Script Host;

	Timeout(mol::variant& f, mol::variant& d, Host* script)
		:f_(f),script_(script)
	{
		timer_.set( d.lVal, std::bind( &Timeout::operator(), this ));
	}

	~Timeout()
	{
	}

	void operator()();

	void kill()
	{
		timer_.kill();
	}

private:
	mol::variant f_;
	mol::punk<Host> script_;
	mol::Timer timer_;

};


class Timeouts
{
public:
	Timeouts() : count_(0) {}

	int setTimeout( mol::variant& f, mol::variant& delay, Timeout::Host* script );
	void clear(Timeout::Host* script, int t);
	void remove(Timeout::Host* script, Timeout* t);
	size_t count(Timeout::Host* s);


private:
	int count_;
	std::map<int, Timeout*> lookup_;
	std::map<Timeout::Host*, std::list<Timeout*> > timeouts_;
};

Timeouts& timeouts();

int Timeouts::setTimeout( mol::variant& f, mol::variant& delay, Timeout::Host* script )
{
	Timeout* t = new Timeout(f,delay,script);
	timeouts_[script].push_back( t );
	int result = count_;
	count_++;
	lookup_[result] = t;

	if ( delay.vt != VT_I4) 
	{
		delay.changeType(VT_I4);
	}
	return result;
}

void Timeouts::clear(Timeout::Host* script, int i)
{
	if ( lookup_.count(i) == 0 )
		return;

	Timeout* t = lookup_[i];
	lookup_.erase(i);

	for ( std::list<Timeout*>::iterator it = timeouts_[script].begin(); it != timeouts_[script].end(); it++)
	{
		if ( *it == t )
		{
			t->kill();
			timeouts_[script].erase(it);
			delete t;
			break;
		}
	}
}

void Timeouts::remove(Timeout::Host* script,Timeout* t)
{

	if ( timeouts_.count(script) == 0 )
	{
		delete t;
		return;
	}

	for ( std::list<Timeout*>::iterator it = timeouts_[script].begin(); it != timeouts_[script].end(); it++)
	{
		if ( *it == t )
		{
			timeouts_[script].erase(it);
			if ( count(script) == 0  )
			{
				if ( script->completed.test() )
				{
					script->close();
					script->Release();
				}
				timeouts_.erase(script);
			}
			delete t;
			break;
		}
	}
}

size_t Timeouts::count(Timeout::Host* s)
{
	if ( timeouts_.count(s) == 0 )
	{
		return 0;
	}
	return timeouts_[s].size();
}


Timeouts& timeouts()
{
	return mol::singleton<Timeouts>();
}

void Timeout::operator()()
{
	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;
	DISPPARAMS p = {0,0};

	kill();
	HRESULT hr = f_.pdispVal->Invoke(0,IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD,&p,0,&ex,&e);
	timeouts().remove(script_,this);

}

Script::Script()
{
	sci_ = 0;
	ODBGS("Script start");
}

Script::~Script()
{
	removeNamedObject(L"moe");
	removeNamedObject(L"Java");
	removeNamedObject(L"NET");
	removeNamedObject(L"MoeImport");

	close();
	ODBGS("Script death");
}

HRESULT Script::init(const std::wstring& engine)
{
	if ( sci_ )
	{
		mol::punk<IScintillAxAnnotation> anno;
		sci_->get_Annotation(&anno);
		anno->ClearAll();
	}

	HRESULT hr = mol::ScriptHost::init(engine);
	if ( hr != S_OK )
	{
		ODBGS("failed to init engine");
		this->Release();
		return hr;
	}

	addNamedObject((IMoe*)(moe()),_T("moe"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE);
	 
	mol::punk<IMoeImport> import;
 	import = MoeImport::CreateInstance(this);
 	addNamedObject((IMoeImport*)(import),_T("Importer"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE);

	mol::punk<IDispatch> java;
	MoeScriptObject::CreateInstance(&java, L"JRE.Java");
 	addNamedObject(java,_T("Java"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_ISSOURCE);

	mol::punk<IDispatch> net;
	MoeScriptObject::CreateInstance(&net, L"Net.DotNet");
 	addNamedObject(net,_T("NET"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_ISSOURCE);

	return S_OK;
}


void Script::eval(  const std::wstring& engine, const std::wstring& script, IScintillAx* sci )
{
	sci_ = sci;

	ODBGS("Script::eval()\r\n");

	HRESULT hr = init(engine);
	if ( hr != S_OK )
	{
		ODBGS("failed to init engine");
		this->Release();
		return;
	}

	runScript(script);
	completed.signal();

	if ( timeouts().count( this) == 0 )
	{
		close();
		this->Release();
	}
	
}

void Script::debug(  const std::wstring& engine, const std::wstring& script, IScintillAx* sci )
{
	sci_ = sci;

	ODBGS("Script::eval()\r\n");

	HRESULT hr = init(engine);
	if ( hr != S_OK )
	{
		ODBGS("failed to init engine");
		this->Release();
		return;
	}

	debugScript(script);
	completed.signal();

	if ( timeouts().count( this) == 0 )
	{
		close();
		this->Release();
	}
}
void Script::call(  const std::wstring& engine, const std::wstring& func, const std::wstring& script )
{
	HRESULT hr = init(engine);
	if ( hr != S_OK )
	{
		ODBGS("failed to init engine");
		this->Release();
		return;
	}

	runScript(script);
	ScriptHost::call(func);
	completed.signal();

	if ( timeouts().count( this) == 0 )
	{
		close();
		this->Release();
	}
}




HRESULT  __stdcall Script::OnScriptError( IActiveScriptError *pscripterror)
{
	if ( !sci_ )
		return mol::ScriptHost::OnScriptError(pscripterror);

	EXCEPINFO ex;
	pscripterror->GetExceptionInfo(&ex);

	DWORD context;
	ULONG line;
	LONG pos;
	pscripterror->GetSourcePosition(&context,&line,&pos);

	std::wostringstream oss;
	oss << "line: " << (line+1) << std::endl << mol::bstr(ex.bstrDescription).towstring();

	mol::punk<IScintillAxAnnotation> anno;
	sci_->get_Annotation(&anno);
	anno->SetText( line, mol::bstr(oss.str()) );

	return S_OK;
}

HRESULT  __stdcall Script::GetWindow(HWND *phwnd )
{
	HWND w = *moe();
	*phwnd = w;
	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT  MoeScriptObject::CreateInstance(IDispatch** d, const std::wstring& progid)
{
	Instance* i = new Instance;
	i->progId_ = progid;
	return i->QueryInterface(IID_IDispatch, (void**)d);
}

HRESULT __stdcall MoeScriptObject::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
{ 
	rgDispId[0] = 0;
	return S_OK;
}

HRESULT  __stdcall MoeScriptObject::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
{ 
	if(!pReturn)
		return S_OK;

	pReturn->vt = VT_EMPTY;
	pReturn->pdispVal = 0;

	if(dispIdMember != 0 )
		return S_OK;

	CLSID clsid;
	HRESULT hr = ::CLSIDFromProgID(progId_.c_str(),&clsid);
	if(hr != S_OK)
		return hr;

	mol::punk<IDispatch> d;
	hr = d.createObject(clsid,CLSCTX_ALL);
	if(hr != S_OK)
		return hr;

	::CoAllowSetForegroundWindow(d,0);

	mol::variant v(d);
	return ::VariantCopy(pReturn,&v);
}

HRESULT __stdcall MoeScriptObject::GetDispID( BSTR bstrName, DWORD grfdex, DISPID *pid)
{
	return GetIDsOfNames(IID_NULL,&bstrName,1,LOCALE_SYSTEM_DEFAULT,pid);
}

HRESULT __stdcall MoeScriptObject::InvokeEx( DISPID id,LCID lcid, WORD wFlags, DISPPARAMS *pdp, VARIANT *pvarRes, EXCEPINFO *pei, IServiceProvider *pspCaller)
{
	return Invoke(id,IID_NULL,lcid,wFlags,pdp,pvarRes,pei,0);
}

HRESULT __stdcall MoeScriptObject::DeleteMemberByName( BSTR bstrName, DWORD grfdex)
{
	return  S_FALSE ;
}

HRESULT __stdcall MoeScriptObject::DeleteMemberByDispID( DISPID id)
{
	return  S_FALSE ;
}

HRESULT __stdcall MoeScriptObject::GetMemberProperties( DISPID id, DWORD grfdexFetch, DWORD *pgrfdex)
{
	return S_OK;
}

HRESULT __stdcall MoeScriptObject::GetMemberName( DISPID id, BSTR *pbstrName)
{
	return E_NOTIMPL;
}

HRESULT __stdcall MoeScriptObject::GetNextDispID( DWORD grfdex, DISPID id, DISPID *pid)
{
	return E_NOTIMPL;
}

HRESULT __stdcall MoeScriptObject::GetNameSpaceParent( IUnknown **ppunk)
{
	*ppunk = 0;
	return E_UNEXPECTED;
}


/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

UrlBox::UrlBox()
{

}

UrlBox::~UrlBox()
{

}

void UrlBox::go( const std::string location )
{
	for ( std::list<std::string>::iterator it = history_.begin(); it != history_.end(); it ++ )
	{
		if ( (*it) == location )
		{
			history_.erase(it);
			break;
		}
	}

    history_.push_front(location);
	if ( history_.size() > 32 )
		history_.pop_back();

	updateGUI();
}


void UrlBox::updateGUI()
{
    clear();
    int s = (int)history_.size();
    if ( s == 0 )
	{
		setText( _T("http://") );
        return;    
	}

	std::list<std::string>::iterator it = history_.begin();
	setText( mol::towstring((*it)) );
    editBox().setSelection( (int)(*it).size(), (int)(*it).size() );

    for ( int i = 0; i < s; i++ )
    {
		addString( mol::towstring((*it)) );
        it++;
    }
}


HRESULT __stdcall UrlBox::Load( LPSTREAM pStm)
{
	DWORD c = 0;
	ULONG len;

	history_.clear();

	HRESULT hr = pStm->Read( (void*)&c, sizeof(DWORD), &len );
	if ( hr != S_OK )
		return hr;

	for ( DWORD i = 0; i < c; i++ )
	{
		DWORD s = 0;

		HRESULT hr = pStm->Read( (void*)&s, sizeof(DWORD), &len );
		if ( hr != S_OK )
			return hr;

		mol::cbuff sz(s);

		hr = pStm->Read( (void*)sz, s, &len );
		if ( hr != S_OK )
			return hr;

		history_.push_back( sz.toString(len));
	}
	return S_OK;
}

HRESULT __stdcall UrlBox::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	DWORD c = (DWORD)history_.size();
	ULONG len;
	HRESULT hr = pStm->Write( (void*)&c, sizeof(DWORD), &len );
	if ( hr != S_OK )
		return hr;

	for ( std::list<std::string>::iterator it = history_.begin(); it != history_.end(); it++ )
	{
		DWORD s = (DWORD)(*it).size();

		HRESULT hr = pStm->Write( (void*)&s, sizeof(DWORD), &len );
		if ( hr != S_OK )
			return hr;

		hr = pStm->Write( (void*)(*it).c_str(), s, &len );
		if ( hr != S_OK )
			return hr;
	}
	return S_OK;
}

HRESULT __stdcall UrlBox::GetSizeMax( ULARGE_INTEGER *pCbSize)
{
	unsigned long long uli = (*pCbSize).QuadPart;

	unsigned long long s = sizeof(DWORD) * ( history_.size() + 1 );
	uli += s;

	for ( std::list<std::string>::iterator it = history_.begin(); it != history_.end(); it++ )
	{
		s = (unsigned long long)((*it).size());
		uli += s;
	}
	(*pCbSize).QuadPart = uli;
	return S_OK;
}


//////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////


InfoDlg::InfoDlg(  )
{
	icon_.load(IDI_MOE,64,64);
}

//////////////////////////////////////////////////////////////////////////////

LRESULT InfoDlg::wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
    {
		case WM_INITDIALOG:
		{
			setDlgButtonIcon(IDOK,icon_);
			return FALSE; // note: false! look into PSDK!
		}
        case WM_COMMAND:
		{
			if (LOWORD(wParam) == IDOK )
			{
                endDlg(LOWORD(wParam));
				return FALSE;
			}
			if (LOWORD(wParam) == IDCANCEL )
			{
                endDlg(LOWORD(wParam));
				return FALSE;
			}
		}
    }
	return mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
}

/////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////


DebugDlg::DebugDlg(  )
{}

DebugDlg::~DebugDlg(  )
{
	//exp_.release();
}

//////////////////////////////////////////////////////////////////////////////
/*
HRESULT __stdcall  DebugDlg::ExpCallback::onComplete()
{
	HRESULT phr;
	mol::bstr txt;
	HRESULT hr = This()->exp_->GetResultAsString(&phr,&txt);
	if ( hr == S_OK && txt )
	{
		This()->setDlgItemText( IDC_EDIT_DEBUG_RESULT, txt.toString() );
	}
	This()->exp_.release();
	return S_OK;
}
*/
LRESULT DebugDlg::wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
    {
		case WM_INITDIALOG:
		{
			setDlgButtonImg( IDC_BUTTON_DEBUG_GO, mol::UI().Bitmap(IDB_DEBUG_GO) );
			setDlgButtonImg( IDC_BUTTON_DEBUG_PAUSE, mol::UI().Bitmap(IDB_DEBUG_PAUSE) );
			setDlgButtonImg( IDC_BUTTON_DEBUG_QUIT, mol::UI().Bitmap(IDB_DEBUG_QUIT) );

			setDlgButtonImg( IDC_BUTTON_DEBUG_STEPIN, mol::UI().Bitmap(IDB_DEBUG_STEPIN) );
			setDlgButtonImg( IDC_BUTTON_DEBUG_STEPOVER, mol::UI().Bitmap(IDB_DEBUG_STEPOVER) );
			setDlgButtonImg( IDC_BUTTON_DEBUG_STEPOUT, mol::UI().Bitmap(IDB_DEBUG_STEPOUT) );

			return FALSE; // note: false! look into PSDK!
		}
        case WM_COMMAND:
		{
			if (LOWORD(wParam) == IDOK )
			{/*
				Mmoe()->getActive()
				std::wstring result = 
				exp_.release();

				std::wstring code;
				getDlgItemText(IDC_EDIT_DEBUG_EXP,code);

				if ( code.empty() )
					return FALSE;

				if ( !remote )
					return FALSE;

				mol::punk<IRemoteDebugApplicationThread> r(remote);
				if ( !r )
					return FALSE;

				mol::punk<IEnumDebugStackFrames> frames;
				HRESULT hr = r->EnumStackFrames(&frames);
				if ( hr != S_OK)
					return FALSE;
				if (!frames)
					return FALSE;

				ULONG fetched = 0;							
				DebugStackFrameDescriptor dsfd;
				hr = frames->Next(1,&dsfd,&fetched);
				if ( hr != S_OK)
					return FALSE;
				if (! fetched )
					return FALSE;

				if ( !dsfd.pdsf )
					return FALSE;

				mol::punk<IDebugStackFrame> frame(dsfd.pdsf);
				dsfd.pdsf->Release();

				mol::punk<IDebugExpressionContext> ctx(frame);
				if (!ctx)
					return FALSE;

				hr = ctx->ParseLanguageText( mol::towstring(code).c_str(), 10, 0, DEBUG_TEXT_ISEXPRESSION|DEBUG_TEXT_RETURNVALUE,&exp_);
				if ( hr != S_OK)
					return FALSE;
				if ( !exp_ )
					return FALSE;

				hr = exp_->Start(&expCallback);
				*/
				::PostMessage( moe()->getActive(),WM_COMMAND,IDM_EDIT_DEBUG_EVAL_EXPR,0);

				return FALSE;
			}
			if (LOWORD(wParam) == IDCANCEL )
			{
				//exp_.release();
				show(SW_HIDE);
				return FALSE;
			}
			if (LOWORD(wParam) == IDC_BUTTON_DEBUG_GO )
			{
				::PostMessage( moe()->getActive(),WM_COMMAND,IDM_EDIT_DEBUG_GO,0);
				show(SW_HIDE);
				return FALSE;
			}
			if (LOWORD(wParam) == IDC_BUTTON_DEBUG_PAUSE )
			{
				::PostMessage( moe()->getActive(),WM_COMMAND,IDM_EDIT_DEBUG_STOP,0);
				return FALSE;
			}
			if (LOWORD(wParam) == IDC_BUTTON_DEBUG_QUIT )
			{
				::PostMessage( moe()->getActive(),WM_COMMAND,IDM_EDIT_DEBUG_QUIT,0);
				show(SW_HIDE);
				return FALSE;
			}

			if (LOWORD(wParam) == IDC_BUTTON_DEBUG_STEPIN )
			{
				::PostMessage( moe()->getActive(),WM_COMMAND,IDM_EDIT_DEBUG_STEPIN,0);
				return FALSE;
			}
			if (LOWORD(wParam) == IDC_BUTTON_DEBUG_STEPOVER )
			{
				::PostMessage( moe()->getActive(),WM_COMMAND,IDM_EDIT_DEBUG_STEPOVER,0);
				return FALSE;
			}
			if (LOWORD(wParam) == IDC_BUTTON_DEBUG_STEPOUT )
			{
				::PostMessage( moe()->getActive(),WM_COMMAND,IDM_EDIT_DEBUG_STEPOUT,0);
				return FALSE;
			}
		}
    }
	return mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
}

void DebugDlg::update_variables(IEnumDebugStackFrames* frames)
{
	HWND tree = getDlgItem(IDC_DEBUG_VARIABLES);
	TreeView_DeleteAllItems(tree);

	TV_INSERTSTRUCTW			insertStruct;
	ZeroMemory(&insertStruct, sizeof(TV_INSERTSTRUCT));
	insertStruct.hInsertAfter = TVI_LAST;
	insertStruct.item.mask = TVIF_TEXT;

	ODBGS("EnumStackFrames:");
	DebugStackFrameDescriptor d;
	ULONG fetched = 0;
	HRESULT hr = frames->Reset();
	if ( hr != S_OK  )
		return;

	hr = frames->Next(1, &d, &fetched );
	if ( hr != S_OK || fetched == 0 )
		return;
		
	if ( d.punkFinal != NULL )
	{
		mol::punk<IEnumDebugStackFrames> f(d.punkFinal);
		if ( f )
		{
			update_variables(f);
		}

		mol::punk<IDebugProperty> p(d.punkFinal);
		if ( p )
		{
			addPropertyToList(tree,&insertStruct,p);
		}

		d.punkFinal->Release();
		d.pdsf->Release();
		return;
	}
		

	mol::punk<IDebugProperty> prop;
	hr = d.pdsf->GetDebugProperty(&prop);
	if ( hr == S_OK && prop )
	{
				
		addPropertyToList(tree,&insertStruct,prop);

	}

	d.pdsf->Release();
}

HRESULT DebugDlg::addPropertyToList(HWND tree, TV_INSERTSTRUCTW *insertStruct, IDebugProperty *prop, int level )
{
	if ( level > 5 )
		return S_OK;

	HRESULT		hr;

	mol::punk<IEnumDebugPropertyInfo> dpis;
	hr = prop->EnumMembers( PROP_INFO_NAME|PROP_INFO_VALUE|PROP_INFO_DEBUGPROP,10, IID_IDebugPropertyEnumType_LocalsPlusArgs, &dpis);
	if ( hr != S_OK )
		return S_OK;

	ULONG fetched = 0;
	ULONG cnt = 0;
	hr = dpis->GetCount(&cnt);
	if ( hr != S_OK || cnt == 0 )
		return S_OK;

	for ( unsigned int i = 0; i < cnt; i++ )
	{
		HTREEITEM parent = insertStruct->hParent;

		DebugPropertyInfo pi;
		::ZeroMemory(&pi,sizeof(DebugPropertyInfo));

		hr = dpis->Next( 1, &pi, &fetched );
		if ( hr != S_OK || fetched == 0 )
		{
			insertStruct->hParent = parent;
			continue;
		}

		if ( pi.m_pDebugProp == prop )
		{
			insertStruct->hParent = parent;
			continue;
		}

		std::wstringstream oss;
		if ( pi.m_bstrName )
		{
			oss << mol::bstr(pi.m_bstrName).towstring() << " - ";
			::SysFreeString(pi.m_bstrName);
		}
		if ( pi.m_bstrType )
		{
			oss << mol::bstr(pi.m_bstrType).towstring() << " : ";
			::SysFreeString(pi.m_bstrType);
		}
		if ( pi.m_bstrValue )
		{
			oss << mol::bstr(pi.m_bstrValue).towstring() << std::endl;
			::SysFreeString(pi.m_bstrValue);	
		}

		std::wstring s = oss.str();
		insertStruct->item.pszText = (LPWSTR)(s.c_str()); 

		if ( pi.m_pDebugProp)
		{
			insertStruct->hParent = (HTREEITEM)SendMessageW(tree, TVM_INSERTITEM, 0, (LPARAM)insertStruct);
			if ( insertStruct->hParent )
			{
				if( pi.m_pDebugProp != prop )
				{
					addPropertyToList( tree, insertStruct, pi.m_pDebugProp,level+1);
				}
			}
			pi.m_pDebugProp->Release();
		}

		insertStruct->hParent = parent;
		
	}

	return S_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////


UrlDlg::UrlDlg(  )
{
}

//////////////////////////////////////////////////////////////////////////////

LRESULT UrlDlg::wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static mol::Menu menu( mol::bookmarks().getMenu() ); 
	switch (message)
    {
		case WM_INITDIALOG:
		{
			setDlgButtonImg( IDC_BUTTON_BOOKMARK, mol::UI().Bitmap(IDB_MOE_FAV) );
			setDlgButtonImg( IDOK, mol::UI().Bitmap(IDB_MOE_GO) );
			urlBox_.subClass( getDlgItem(IDC_EDIT_URL) );
			urlBox_.updateGUI();
			
			return FALSE; // note: false! look into PSDK!
		}
        case WM_COMMAND:
		{
			if (LOWORD(wParam) == IDC_BUTTON_BOOKMARK )
			{				
				RECT r;
				::GetWindowRect(getDlgItem(IDC_BUTTON_BOOKMARK),&r);
				int id = menu.returnTrackPopup( getDlgItem(IDC_BUTTON_BOOKMARK),r.left+15,r.top+15);
				
				mol::Bookmark& bm = mol::bookmarks().getBookmarkFromMenuId(id);
				if ( !bm.url.empty() )
				{
					urlBox_.setText(bm.url);
				}
				return FALSE;
			}
			if (LOWORD(wParam) == IDOK )
			{
				int sel = urlBox_.getCurSel();
				// check wether user select from last-urls-list or enter a new one
				if ( sel == CB_ERR ) //no selection
				{
					// user typed new url into edit-field of combobox
					url = urlBox_.getText();
				}
				else
				{
					//user has chosen the url from the combobox-dropdownlist
					url = urlBox_.getString(sel);
				}
				if (url.size()>0)
				{
					urlBox_.go( mol::tostring(url));
				}
                endDlg(LOWORD(wParam));
				return FALSE;
			}
			if (LOWORD(wParam) == IDCANCEL )
			{
                endDlg(LOWORD(wParam));
				return FALSE;
			}
		}
    }
	return mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
}

HRESULT __stdcall UrlDlg::Load( LPSTREAM pStm)
{
	return urlBox_.Load(pStm);
}

HRESULT __stdcall UrlDlg::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	return urlBox_.Save(pStm,fClearDirty);
}

HRESULT __stdcall UrlDlg::GetSizeMax( ULARGE_INTEGER *pCbSize)
{
	return urlBox_.GetSizeMax(pCbSize);
}

//////////////////////////////////////////////////////////////////////////////

std::string resolvePath(const std::string& p)
{
	if (mol::Path::exists(mol::towstring(p)))
	{
		return p;
	}

	std::ostringstream oss;
	for ( size_t i = 0; i < p.size(); i++ ) 
	{
		if ( p[i] == '/' )
			oss << '\\';
		else
			oss << p[i];
	}

	std::vector<std::string> v = mol::split( oss.str(), "\\" );

	std::vector<std::string> v2;
	if ( !v.empty() )
		v2.push_back(v[0]);

	for ( size_t i = 1; i < v.size(); i++ )
	{
		if ( i < v.size()-1 && v[i+1] == ".." )
		{
			continue;
		}
		if ( v[i] == ".." )
		{
			continue;
		}

		if ( v[i] == "." ) 
		{
			continue;
		}
		if ( v[i] == "" ) 
		{
			continue;
		}

		v2.push_back(v[i]);
	}

	std::ostringstream oss2;
	if ( !v2.empty() )
	{
		oss2 << v2[0];
	}
	for ( size_t i = 1; i < v2.size(); i++ )
	{
		oss2 << "\\" << v2[i];
	}

	std::string s = oss2.str();

	const std::string cygdrive("\\cygdrive\\");

	size_t pos = s.find(cygdrive);
	if ( pos == 0 )
	{
		return s.substr(cygdrive.size(),1) + ":\\" + s.substr(cygdrive.size()+2);
	}

	if (mol::Path::exists(mol::towstring(s)))
	{
		return s;
	}

	char buf[MAX_PATH];
	::GetCurrentDirectoryA(MAX_PATH,buf);

	std::ostringstream oss3;
	oss3 << buf << "\\" << s;

	std::string path = oss3.str();
	if (mol::Path::exists(mol::towstring(path)))
	{
		return path;
	}
	return "";
}


std::wstring findFile(const std::wstring& f)
{
	ODBGS(f);

	if ( mol::Path::exists(f) ) 
	{
		ODBGS("FOUND");
		return f;
	}

	std::wstring modulePath = mol::Path::pathname(mol::app<mol::win::AppBase>().getModulePath());
	std::wstring configPath = mol::app<mol::win::AppBase>().CreateAppPath(_T("moe"));

	modulePath = mol::Path::addBackSlash(modulePath);
	configPath = mol::Path::addBackSlash(configPath);

	configPath.append(f);

	ODBGS(configPath);
	if ( mol::Path::exists(configPath) )
	{
		ODBGS("FOUND");
		return configPath;
	}

	modulePath.append(f);
	ODBGS(modulePath);
	if ( mol::Path::exists(modulePath) )
	{
		ODBGS("FOUND");
		return modulePath;
	}

	return mol::towstring(resolvePath(mol::tostring(f)));
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////
//
// Drag & Drop_ Support 
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeDrop::Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect)
{
	std::vector<std::wstring> v;
    v = mol::vectorFromDataObject(pDataObject);
	mol::ImageList::drop(*moe());
	for ( unsigned int i = 0; i < v.size(); i++ )
	{
		bool result = ::docs()->open(v[i],MOE_DOCTYPE_DOC,-1,false,0);
		statusBar()->status(v[i]);
		if (!result)
		{
			::MessageBox(*moe(),v[i].c_str(),_T("failed to load"),MB_ICONERROR);
			return S_FALSE;
		}
	}
	*pEffect = DROPEFFECT_NONE;
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
// Com EVENT interface sink implementations
//////////////////////////////////////////////////////////////////////////////


HRESULT  __stdcall MoeDrop::DragEnter( IDataObject* , DWORD , POINTL , DWORD* pEffect )
{
	mol::ImageList::enterDrag(*moe());
    return S_OK;
}

HRESULT __stdcall MoeDrop::DragOver( DWORD, POINTL, DWORD* pEffect )
{
	mol::ImageList::doDrag(*moe());
	*pEffect &= DROPEFFECT_COPY;
    return S_OK;
}


HRESULT  __stdcall MoeDrop::DragLeave()
{
	mol::ImageList::leaveDrag(*moe());
    return S_OK;
}




//////////////////////////////////////////////////////////////////////////////


TabPage::TabPage(  )
{}


void TabPage::init()
{
	LONG w = 4;
	moe()->moeConfig->get_TabWidth(&w);	
	setDlgItemInt(IDC_EDIT_TABWIDTH,w);

	VARIANT_BOOL vb = VARIANT_FALSE;

	moe()->moeConfig->get_TabUsage(&vb);	
	if ( vb == VARIANT_TRUE )
		setDlgItemChecked(IDC_CHECK_USETABS);

	moe()->moeConfig->get_TabIndents(&vb);	
	if ( vb == VARIANT_TRUE )
		setDlgItemChecked(IDC_CHECK_TABINDENTS);

	moe()->moeConfig->get_BackSpaceUnindents(&vb);	
	if ( vb == VARIANT_TRUE )
		setDlgItemChecked(IDC_CHECK_BACKSPACEUNINDENTS);

	moe()->moeConfig->get_ShowLineNumbers(&vb);	
	if ( vb == VARIANT_TRUE )
		setDlgItemChecked(IDC_CHECK_SHOWLINENUM);
}


int TabPage::apply()
{
	int w = 0;
	getDlgItemInt(IDC_EDIT_TABWIDTH,w);
	moe()->moeConfig->put_TabWidth(w);	

	VARIANT_BOOL vb = VARIANT_TRUE;

	vb = getDlgItemChecked(IDC_CHECK_USETABS) ? VARIANT_TRUE : FALSE;
	moe()->moeConfig->put_TabUsage(vb);		

	vb = getDlgItemChecked(IDC_CHECK_TABINDENTS) ? VARIANT_TRUE : FALSE;
	moe()->moeConfig->put_TabIndents(vb);

	vb = getDlgItemChecked(IDC_CHECK_BACKSPACEUNINDENTS) ? VARIANT_TRUE : FALSE;
	moe()->moeConfig->put_BackSpaceUnindents(vb);

	vb = getDlgItemChecked(IDC_CHECK_SHOWLINENUM) ? VARIANT_TRUE : FALSE;
	moe()->moeConfig->put_ShowLineNumbers(vb);

	return PSNRET_NOERROR;
}

//////////////////////////////////////////////////////////////////////////////

void ExportPage::command(int c)
{
	if ( c == IDC_BUTTON_EXPORT )
	{
		mol::FilenameDlg dlg( *moe() );
		if ( dlg.dlgSave() )
		{
			moe()->moeConfig->ExportSettings( mol::bstr( dlg.fileName() ) );
		}
	}

	if ( c == IDC_BUTTON_IMPORT )
	{
		mol::FilenameDlg dlg( *moe() );
		if ( dlg.dlgOpen() )
		{
			moe()->moeConfig->ImportSettings( mol::bstr( dlg.fileName() ) );
		}
	}

	if ( c == IDC_BUTTON_EXTENSIONS )
	{
		mol::v7::editFileExtensions(L"moe");
	}
}

//////////////////////////////////////////////////////////////////////////////

void PrefPage::setObjects()
{
	mol::punk<IDispatch> disp;
	moe()->moeConfig->get_Settings(&disp);
	mol::punk<IUnknown> unk(disp);
	prop_->SetObjects( 1, &(unk.interface_) );
}

//////////////////////////////////////////////////////////////////////////////
// PasteAs
//////////////////////////////////////////////////////////////////////////////

PasteAs::PasteAs()
	:clipboard_(*moe())
{
}



PasteAs::~PasteAs()
{}

std::wstring PasteAs::get()
{
	const int HTML_CTX = 999;

	std::map<UINT,mol::win::ClipBoard::Entry> formats;

	const std::vector<mol::win::ClipBoard::Entry>& v = clipboard_.formats();
	for ( unsigned int i = 0; i < v.size(); i++)
	{
		if ( v[i].format == clipboard_.format(clipboard_.CSV) )
		{
			formats.insert(std::make_pair(v[i].format,v[i]));
			continue;
		}
		if ( v[i].format == clipboard_.format(clipboard_.HTML) )
		{
			formats.insert(std::make_pair(v[i].format,v[i]));
			continue;
		}
		if ( v[i].format == clipboard_.format(clipboard_.TEXT_HTML) )
		{
			formats.insert(std::make_pair(v[i].format,v[i]));
			continue;
		}
		if ( v[i].format == clipboard_.format(clipboard_.TEXT) )
		{
			formats.insert(std::make_pair(v[i].format,v[i]));
			continue;
		}
		if ( v[i].format == clipboard_.format(clipboard_.UNICODE_TEXT) )
		{
			formats.insert(std::make_pair(v[i].format,v[i]));
			continue;
		}
		if ( v[i].format == clipboard_.format(clipboard_.RTF) )
		{
			formats.insert(std::make_pair(v[i].format,v[i]));
			continue;
		}

		std::regex rgxp("xml", std::regex_constants::ECMAScript | std::regex_constants::icase);
		std::smatch m;
		std::string s = mol::tostring(v[i].title);
		if( std::regex_search( s, m, rgxp ))
		{
			formats.insert(std::make_pair(v[i].format,v[i]));
			continue;
		}
	}

	if ( formats.empty() )
	{
		return L"";
	}

	mol::Menu menu;
	menu.createContext();

	for ( std::map<UINT,mol::win::ClipBoard::Entry>::iterator it = formats.begin();
		  it != formats.end(); it ++ )
	{
		menu.addItem( (*it).second.format, (*it).second.title );

		if ( (*it).second.format == clipboard_.format(mol::win::ClipBoard::HTML) )
		{
			menu.addItem( HTML_CTX, L"HTML with context" );
		}
	}

	POINT pt = {0,0};
	::GetCursorPos(&pt);
	UINT format = menu.returnTrackPopup( *moe(), pt.x, pt.y );

	if ( format == clipboard_.format(clipboard_.CSV) )
	{
		return mol::towstring( clipboard_.getAnsiText(format) );
	}
	if ( format ==  clipboard_.format(clipboard_.HTML) )
	{
		return mol::fromUTF8(( clipboard_.getHTMLfragment()) );
	}
	if ( format == clipboard_.format(clipboard_.TEXT_HTML) )
	{
		return clipboard_.getUnicodeText(format);
	}
	if ( format == clipboard_.format(clipboard_.TEXT) )
	{
		return mol::towstring( clipboard_.getAnsiText(format) );
	}
	if ( format == clipboard_.format(clipboard_.UNICODE_TEXT) )
	{
		return clipboard_.getUnicodeText(format);
	}
	if ( format == clipboard_.format(clipboard_.RTF) )
	{
		return mol::towstring( clipboard_.getAnsiText(format) );
	}
	if ( format == HTML_CTX )
	{
		return mol::towstring( clipboard_.getHTML() );
	}
	return mol::fromUTF8( clipboard_.getAnsiText(format) );
}


MolFileFialog::MolFileFialog( HWND parent )
	: FilenameDlg(parent), index_(-1)
{
}


void MolFileFialog::OnCustomize()
{
	this->of_.lpfnHook = &mol::FilenameDlg::hook;
	this->of_.lpTemplateName = MAKEINTRESOURCE(IDD_DIALOG_OFN);
	this->of_.hInstance = ::GetModuleHandle(0);
}

void MolFileFialog::OnInit()
{
	combo_.attach(::GetDlgItem(dlg_,IDC_COMBO_ENC));
	for ( Encodings::Iterator it = codePages()->begin(); it!= codePages()->end(); it++)
	{
		combo_.addString((*it).second);
	}

	if ( index_ != -1 )
	{
		combo_.setCurSel(index_);
	}
}
	
void MolFileFialog::OnDestroy()
{
	index_ = combo_.getCurSel();
}

int MolFileFialog::codePage()
{
	if ( index_ == -1 )
		return -1;

	return codePages()->item(index_).first;
}

void MolFileFialog::codePage(int cp)
{
	index_ = (int)codePages()->index(cp);
}



#define CONTROL_GROUP           2000
#define CONTROL_COMBOBOX        2001

#define OPENCHOICES					0
#define OPENCHOICES_OPEN			0
#define OPENCHOICES_OPEN_READONLY	1


MoeVistaFileDialog::MoeVistaFileDialog(HWND parent)
	: parent_(parent),filter_(0),nFilters_(0),readOnly_(false),encoding_(CP_ACP)
{}

void MoeVistaFileDialog::setFilter(COMDLG_FILTERSPEC* filter, int size)
{
	filter_ = filter;
	nFilters_ = size;
}



HRESULT MoeVistaFileDialog::open(int options)
{
	HRESULT hr = init(options,CLSID_FileOpenDialog);
	if (hr != S_OK)
		return hr;

	hr = fdc_->EnableOpenDropDown(OPENCHOICES);
	if (hr != S_OK)
		return hr;

	hr = fdc_->AddControlItem(OPENCHOICES, OPENCHOICES_OPEN, L"&Open");
	if (hr != S_OK)
		return hr;

	hr = fdc_->AddControlItem(OPENCHOICES, OPENCHOICES_OPEN_READONLY, L"Open &read-only");
	if (hr != S_OK)
		return hr;

	addEncodingComboBox();

	// Now show the dialog.
	hr = fd_->Show(parent_);
	if (hr != S_OK)
		return hr;

	mol::punk<IFileOpenDialog> fod(fd_);
	if (!fod)
		return hr;

	mol::punk<IShellItemArray> psiResult;
	hr = fod->GetResults(&psiResult);
	if (hr != S_OK)
		return hr;

	DWORD numItems = 0;
	psiResult->GetCount(&numItems);
	for ( DWORD i = 0; i < numItems; i++ )
	{
		mol::punk<IShellItem> shit;
		hr = psiResult->GetItemAt(i,&shit);
		if (hr != S_OK)
			return hr;

		mol::CoStrBuf pszFilePath;
		hr = shit->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
		if ( hr == S_OK )
		{
			paths_.push_back(std::wstring(pszFilePath));
		}
		else
		{
			hr = shit->GetDisplayName(SIGDN_URL, &pszFilePath);
			if ( hr == S_OK )
			{
				paths_.push_back(std::wstring(pszFilePath));
			}
		}
	}

	DWORD openChoices = 0;
	hr = fdc_->GetSelectedControlItem(OPENCHOICES,&openChoices);
	if (hr != S_OK)
		return hr;

	readOnly_ = openChoices == 0 ? false : true;

	DWORD enc = 0;
	hr = fdc_->GetSelectedControlItem(CONTROL_COMBOBOX,&enc);
	//if (hr != S_OK)
		//return hr;

	encoding_ = enc;

	hr = fd_->GetFileTypeIndex(&type_);
	//if (hr != S_OK)
		//return hr;
		
	return S_OK;
}


HRESULT MoeVistaFileDialog::save(int options)
{
	HRESULT hr = init(options,CLSID_FileSaveDialog);
	if (hr != S_OK)
		return hr;

	// Create a Visual Group.
	hr = fdc_->StartVisualGroup(CONTROL_GROUP, L"Encoding");
	if (hr != S_OK)
		return hr;

	// Add a combo box
	hr = fdc_->AddComboBox(CONTROL_COMBOBOX);
	if (hr != S_OK)
		return hr;

	// populate box
	hr = fdc_->SetControlState(CONTROL_COMBOBOX, CDCS_VISIBLE | CDCS_ENABLED);
	if (hr != S_OK)
		return hr;

	DWORD i = 0;
	for ( Encodings::Iterator it = codePages()->begin(); it!= codePages()->end(); it++)
	{
		const mol::CodePages::Entry codePage = *it;
		hr = fdc_->AddControlItem(CONTROL_COMBOBOX, i, codePage.second.c_str() );
		if (hr != S_OK)
			return hr;
		i++;
	}

	hr = fdc_->SetSelectedControlItem(CONTROL_COMBOBOX,encoding_);
	if (hr != S_OK)
		return hr;

	// End the visual group.
	hr = fdc_->EndVisualGroup();
	if (hr != S_OK)
		return hr;


	// Now show the dialog.
	hr = fd_->Show(parent_);
	if (hr != S_OK)
		return hr;

	mol::punk<IShellItem> psiResult;
	hr = fd_->GetResult(&psiResult);
	if (hr != S_OK)
		return hr;

	mol::CoStrBuf pszFilePath;
	hr = psiResult->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
	paths_.push_back(std::wstring(pszFilePath));

	DWORD enc = 0;
	hr = fdc_->GetSelectedControlItem(CONTROL_COMBOBOX,&enc);
	//if (hr != S_OK)
		//return hr;

	encoding_ = enc;
	type_ = 0;
		
	return S_OK;
}


long MoeVistaFileDialog::encoding()
{
	return codePages()->item(encoding_).first;
}

void MoeVistaFileDialog::encoding(long enc)
{
	encoding_ = (int)codePages()->index(enc);
}

long MoeVistaFileDialog::type()
{
	return type_;
}

bool MoeVistaFileDialog::readOnly()
{
	return readOnly_;
}

const std::vector<std::wstring>& MoeVistaFileDialog::paths()
{
	return paths_;
}

const std::wstring& MoeVistaFileDialog::path()
{
	return paths_[0];
}


HRESULT MoeVistaFileDialog::addEncodingComboBox()
{
	// Create a Visual Group.
	HRESULT hr = fdc_->StartVisualGroup(CONTROL_GROUP, L"Encoding");
	if (hr != S_OK)
		return hr;

	// Add a combo box
	hr = fdc_->AddComboBox(CONTROL_COMBOBOX);
	if (hr != S_OK)
		return hr;

	// populate box
	hr = fdc_->SetControlState(CONTROL_COMBOBOX, CDCS_VISIBLE | CDCS_ENABLED);
	if (hr != S_OK)
		return hr;

	DWORD i = 0;
	for ( Encodings::Iterator it = codePages()->begin(); it!= codePages()->end(); it++)
	{
		const mol::CodePages::Entry codePage =*it;
		hr = fdc_->AddControlItem(CONTROL_COMBOBOX, i, codePage.second.c_str() );
		if (hr != S_OK)
			return hr;
		i++;
	}

	// End the visual group.
	hr = fdc_->EndVisualGroup();
	if (hr != S_OK)
		return hr;

	return S_OK;
}



HRESULT MoeVistaFileDialog::init(int options, REFCLSID clsid)
{
	fd_.release();
	fdc_.release();

	HRESULT hr = fd_.createObject(clsid);
	if (hr != S_OK)
		return hr;

	hr = fd_.queryInterface(&fdc_);
	if ( hr != S_OK )
		return hr;

	DWORD dwFlags;
	hr = fd_->GetOptions(&dwFlags);
	if (hr != S_OK)
		return hr;
	
	hr = fd_->SetOptions(/*dwFlags |*/ options );
	if (hr != S_OK)
		return hr;

	hr = fd_->SetFileTypes(nFilters_, filter_);
	if (hr != S_OK)
		return hr;

	if ( !path_.empty() )
	{
		hr = fd_->SetFileName(path_.c_str());
		if (hr != S_OK)
			return hr;

		mol::punk<IShellItem> shit;
		hr = ::SHCreateItemFromParsingName( 
					mol::Path::parentDir(path_).c_str(),
					NULL,
					IID_IShellItem,
					(void**)&shit
				);

		if (hr != S_OK)
			return hr;

		hr = fd_->SetFolder(shit);			
		if (hr != S_OK)
			return hr;

	}

	return hr;
}

void MoeVistaFileDialog::path(const std::wstring& path)
{
	path_ = path;
}


MOE_DOCTYPE index2type(int index)
{
	switch(index)
	{
		case 1 :
		{
			return MOE_DOCTYPE_DOC;
		}
		case 2 :
		{
			return MOE_DOCTYPE_HTML;
		}
		case 3 :
		{
			return MOE_DOCTYPE_RTF;
		}
		case 4 :
		{
			return MOE_DOCTYPE_HEX;
		}
		case 5 :
		{
			return MOE_DOCTYPE_TAIL;
		}
	}
	return MOE_DOCTYPE_DOC;
}







void MoeImport::dispose() 
{
	if(stop_)
	{
		::CloseHandle(stop_);
		stop_ = 0;
	}
}
 
MoeImport::Instance* MoeImport::CreateInstance(Host* host)
{
 	Instance* i = new Instance();
 	i->host_ = host;
	i->stop_ = 0;
 	return i;
}
 
HRESULT __stdcall  MoeImport::Import(BSTR filename)
{
	std::wstring file = findFile(mol::towstring(filename));
 
 	mol::filestream fs;
 	fs.open(mol::tostring(file),GENERIC_READ);
 	std::string s = fs.readAll();
 	fs.close();
 
	host_->runScript(mol::towstring(s));
 	return S_OK;
}

HRESULT __stdcall  MoeImport::Sleep(long ms)
{
	::SleepEx(ms,TRUE);
	return S_OK;
}

HRESULT __stdcall  MoeImport::Wait(long ms,VARIANT_BOOL* vb)
{
	DWORD startTick = ::GetTickCount();
	DWORD nowTick = startTick;

	if(vb)
	{
		*vb = VARIANT_FALSE;
	}

	if(stop_)
	{
		::CloseHandle(stop_);
	}
	stop_ = ::CreateEvent(NULL,FALSE,FALSE,NULL);

	MSG msg;
	while( (ms == 0) || ((nowTick-startTick)<(unsigned long)ms) )
	{
		nowTick = ::GetTickCount();
  	    DWORD r = ::MsgWaitForMultipleObjectsEx(1,&stop_,100,QS_ALLINPUT,MWMO_INPUTAVAILABLE|MWMO_ALERTABLE);
		if ( r == WAIT_IO_COMPLETION || r == WAIT_TIMEOUT) 
		{
			continue;
		}
		if ( r == WAIT_OBJECT_0 )
		{
			if(vb)
			{
				*vb = VARIANT_TRUE;
			}
			break;
		}

		if (!::GetMessage(&msg,0,0,0) || msg.message == WM_QUIT)
		{
			if(vb)
			{
				*vb = VARIANT_TRUE;
			}
			break;
		}
	
		if ( mol::win::dialogs().isDialogMessage(msg) )
			continue;

		if ( mol::win::accelerators().translate(msg) )
			continue;

		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
		
	if(stop_)
	{
		::CloseHandle(stop_);
		stop_ = 0;
	}

	return S_OK;
}

HRESULT __stdcall  MoeImport::Quit()
{
	if(stop_)
	{
		::SetEvent(stop_);
	}
	return S_OK;
}

HRESULT __stdcall  MoeImport::get_Dispatch(IDispatch** disp)
{
	return host_->getScript(L"",disp);
}

HRESULT __stdcall  MoeImport::Callback(BSTR name,IDispatch** disp)
{
	mol::punk<IDispatch> d;
	HRESULT hr = host_->getScript(L"",&d);
	if ( hr == S_OK && d )
	{
		return EventWrapper::CreateInstance(d,mol::bstr(name),disp);
	}
	return S_OK;
}

HRESULT __stdcall  MoeImport::setTimeout( VARIANT f, VARIANT d, VARIANT* retval)
{
	if ( f.vt != VT_DISPATCH )
		return E_INVALIDARG;

	int i = timeouts().setTimeout( mol::variant(f), mol::variant(d), (Script*)(host_.interface_) );
	if ( retval )
	{
		retval->vt = VT_I4;
		retval->lVal = i;
	}
	return S_OK;
}

HRESULT __stdcall  MoeImport::clearTimeout( VARIANT t)
{
	mol::variant v(t);
	if ( v.vt != VT_I4 )
	{
		v.changeType(VT_I4);
	}
	timeouts().clear( (Script*)(host_.interface_), v.lVal );
	return S_OK;
}


HRESULT EventWrapper::CreateInstance(IDispatch* disp, BSTR handler, IDispatch** d)
{
	Instance* i = new Instance;
	i->handler_ = disp;
	i->callback_ = handler;
	return i->QueryInterface(IID_IDispatch,(void**)d);
}


HRESULT __stdcall EventWrapper::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId )
{
	OLECHAR* name = rgszNames[0];
	rgDispId[0] = 0;
	return S_OK;
}

HRESULT __stdcall EventWrapper::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * e)
{
	if( dispIdMember != 0 )
		return E_UNEXPECTED;

	HRESULT hr = S_OK;
	if ( handler_ && callback_.bstr_ == 0)
	{
		hr = handler_->Invoke(0,IID_NULL,LOCALE_SYSTEM_DEFAULT,w,pDisp,pReturn,ex,e);
	}
	else if ( handler_ )
	{
		DISPID id = 0;
		hr = handler_->GetIDsOfNames(IID_NULL,&callback_.bstr_,1,LOCALE_SYSTEM_DEFAULT,&id);
		if ( hr == S_OK )
		{
			hr = handler_->Invoke(id,IID_NULL,LOCALE_SYSTEM_DEFAULT,DISPATCH_METHOD,pDisp,pReturn,ex,e);
		}
	}
	return hr;
}