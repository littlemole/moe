#include "stdafx.h"
#include "widgets.h"
#include "app.h"
#include "xmlui.h"
#include "MoeBar.h"
#include "ole/Rib.h"
#include "ribbonres.h"
#include "Shared.h"
#include "fm20_tlh.h"
#include <Commctrl.h>
#include "util/regex.h"

// ==================== platform specific: TaskDialog  =======================

enum _MOLTASKDIALOG_COMMON_BUTTON_FLAGS
{
    TDCBF_OK_BUTTON            = 0x0001, // selected control return value IDOK
    TDCBF_YES_BUTTON           = 0x0002, // selected control return value IDYES
    TDCBF_NO_BUTTON            = 0x0004, // selected control return value IDNO
    TDCBF_CANCEL_BUTTON        = 0x0008, // selected control return value IDCANCEL
    TDCBF_RETRY_BUTTON         = 0x0010, // selected control return value IDRETRY
    TDCBF_CLOSE_BUTTON         = 0x0020  // selected control return value IDCLOSE
};
typedef int MOLTASKDIALOG_COMMON_BUTTON_FLAGS;           // Note: _TASKDIALOG_COMMON_BUTTON_FLAGS is an int


typedef 
WINCOMMCTRLAPI HRESULT WINAPI 
MOLTaskDialogPtr( 
	HWND hwndParent, 
	HINSTANCE hInstance, 
	PCWSTR pszWindowTitle, 
	PCWSTR pszMainInstruction, 
	PCWSTR pszContent, 
	MOLTASKDIALOG_COMMON_BUTTON_FLAGS dwCommonButtons, 
	PCWSTR pszIcon, 
	int *pnButton
);

// ==================== End TaskDialog =======================


MOLTaskDialogPtr* MOLTaskDialog = (MOLTaskDialogPtr*)mol::dllFunc( _T("Comctl32.dll"), _T("TaskDialog") );


/////////////////////////////////////////////////////////////////////
// msgbox trampoline - either classic or win7 style
/////////////////////////////////////////////////////////////////////

int msgbox( const mol::string& txt, const mol::string& title, const mol::string& detail )
{
	if ( MOLTaskDialog )
	{
		int result = 0;
		HRESULT hr = MOLTaskDialog( 
						*moe(), 
						mol::hinstance(), 
						title.c_str(), 
						txt.c_str(), 
						detail.c_str(), 
						TDCBF_YES_BUTTON|TDCBF_NO_BUTTON,
						MAKEINTRESOURCE(IDI_MOE),
						&result
					);
		return result;
	}
	else
	{
		return ::MessageBox( *moe(), txt.c_str(), title.c_str(), MB_YESNO|MB_ICONINFORMATION );
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////

CLIControl::CLIControl()
{}

CLIControl::~CLIControl()
{}


/////////////////////////////////////////////////////////////////////////////////////////////



void MoeStatusBar::status(int i)
{
	progress()->show(SW_SHOW);
	progress()->setPos(i);
}

void MoeStatusBar::status( const mol::string& txt )
{
	progress()->show(SW_HIDE);
	setText(txt);
}

/////////////////////////////////////////////////////////////////////////////////////////////

Script::Script()
{
	sci_ = 0;
	ODBGS("Script start");
}

Script::~Script()
{
	close();
	ODBGS("Script death");
}

void Script::eval(  const mol::string& engine, const mol::string& script, IScintillAx* sci )
{
	sci_ = sci;

	if ( sci )
	{
		mol::punk<IScintillAxAnnotation> anno;
		sci->get_Annotation(&anno);
		anno->ClearAll();
	}

	ODBGS("Script::eval()\r\n");
	this->AddRef();
	HRESULT hr = init(engine);
	if ( hr != S_OK )
	{
		ODBGS("failed to init engine");
		return;
	}
	ODBGS("engine initialized");
	addNamedObject((IMoe*)(moe()),_T("moe"));
	ODBGS("moe object added");
	runScript(script);
	//close();
	this->Release();
}

void Script::debug(  const mol::string& engine, const mol::string& script, IScintillAx* sci )
{
	sci_ = sci;
	if ( sci )
	{
		mol::punk<IScintillAxAnnotation> anno;
		sci->get_Annotation(&anno);
		anno->ClearAll();
	}

	ODBGS("Script::eval()\r\n");
	this->AddRef();
	init(engine);
	addNamedObject((IMoe*)(moe()),_T("moe"));
	debugScript(script);
	//close();
	this->Release();
}
void Script::call(  const mol::string& engine, const mol::string& func, const mol::string& script )
{
	this->AddRef();
	init(engine);
	addNamedObject((IMoe*)moe(),_T("moe"));
	runScript(script);
	ScriptHost::call(func);
	close();
	this->Release();
}


void Script::formscript( const mol::string& engine, const mol::string& s, IDispatch* form )
{
	init(engine);

	addNamedObject((IDispatch*)(moe()),_T("moe"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE);//|SCRIPTITEM_CODEONLY );
	addNamedObject(form,_T("form"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE);//|SCRIPTITEM_CODEONLY );

	runScript(s,SCRIPTTEXT_ISVISIBLE|SCRIPTTEXT_ISPERSISTENT);//|SCRIPTTEXT_DELAYEXECUTION);	
	
	this->setState(SCRIPTSTATE_STARTED);
}

void Script::formdebug( const mol::string& engine, const mol::string& s, IDispatch* form )
{
	init(engine);

	addNamedObject((IDispatch*)(moe()),_T("moe"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE);//|SCRIPTITEM_CODEONLY );
	addNamedObject(form,_T("form"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE);//|SCRIPTITEM_CODEONLY );

	debugScript(s,SCRIPTTEXT_ISVISIBLE|SCRIPTTEXT_ISPERSISTENT);//|SCRIPTTEXT_DELAYEXECUTION);	
	
	this->setState(SCRIPTSTATE_STARTED);
}

void Script::formcontrols( IUnknown* f )
{
	mol::punk<MSForms::_UserForm> form(f);
	if (!form)
		return;

	if ( !form )
		return;

//	mol::bstr title("form");
//	addNamedObject((form),title.toString(),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE );

	mol::punk<MSForms::Controls> controls;
	if ( S_OK != form->get_Controls(&controls) )
		return;

	if ( !controls )
		return;

	long n = 0;
	if ( S_OK != controls->get_Count(&n) )
		return;

	for ( long i = 0; i < n; i++ )
	{
		mol::punk<IDispatch> disp;
		if ( S_OK != controls->Item(mol::variant(i),&disp) )
			continue;

		if ( !disp )
			continue;

		mol::punk<MSForms::IControl> c(disp);
		if ( !c )
			continue;

		mol::bstr name;
		if ( S_OK != c->get_Name(&name) )
			continue;

		if ( !name )
			continue;

		addNamedObject((MSForms::IControl*)(c),name.toString(),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE );
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

	mol::ostringstream oss;
	oss << "line: " << (line+1) << std::endl << mol::bstr(ex.bstrDescription).toString();

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
/////////////////////////////////////////////////////////////////////////////////////////////

ScriptEventHandler::~ScriptEventHandler()
{
	ODBGS("ScriptEventHandler dead");
}
/////////////////////////////////////////////////////////////////////////////////////////////


void ScriptEventHandler::init(Script* s, REFIID iid, const mol::string& on)
{
	riid = iid;
	script = s;
	objname = on;
	info.release();
	if ( (S_OK == mol::typeInfoForInterface(riid,&info)) && info )
	{
		
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScriptEventHandler::QueryInterfaceImpl(REFIID iid , LPVOID* ppv)  
{                                                                       
	ODBGS("::QueryInterface ScriptEventHandler");                                        
	if (ppv==(void**)0)                                                 
		return E_INVALIDARG;                                            
                                                                        
	if(IsEqualIID(iid, IID_IUnknown))                                   
	{                                                                   
		*ppv = (IUnknown*)this;                          
		((IUnknown*)(*ppv))->AddRef();                                  
		return S_OK;                                                    
	}                                                                   
	if(IsEqualIID(iid, IID_IDispatch))                                   
	{                                                                   
		*ppv = (IDispatch*)this;                          
		((IDispatch*)(*ppv))->AddRef();                                  
		return S_OK;                                                    
	}    
	if(IsEqualIID(iid, riid))                                   
	{                                                                   
		*ppv = (IDispatch*)this;                          
		((IDispatch*)(*ppv))->AddRef();                                  
		return S_OK;                                                    
	} 
	ODBGS("ScriptEventHandler::QueryInterface E_NOINTERFACE");                          
	*ppv = (IUnknown*)(0);                                              
	return E_NOINTERFACE;                                               
}                                                                       
       
/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScriptEventHandler::GetTypeInfoCount (unsigned int FAR*  pctinfo ) 
{ 
    *pctinfo = 1;
    return S_OK; 
}

/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScriptEventHandler::GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) 
{ 
	return info->QueryInterface(IID_ITypeInfo,(void**)ppTInfo);
}

/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScriptEventHandler::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
{ 
	return info->GetIDsOfNames( rgszNames, cNames, rgDispId );
}

/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScriptEventHandler::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
{ 
	UINT nNames = 0;
	mol::bstr name;
	if ( (S_OK == info->GetNames(dispIdMember,&name,1,&nNames)) && (nNames == 1) )
	{
		std::stringstream oss;
		oss << mol::tostring(objname) << "_";
		oss << mol::tostring(name); 

		mol::punk<IDispatch> disp;
		if ( (S_OK == script->getScript(_T(""),&disp)) )
		{
			DISPID dispid;
			std::wstring ws = mol::towstring(oss.str());
			mol::bstr func(ws);
			HRESULT hr = disp->GetIDsOfNames(IID_NULL, &(func), 1, 0, &dispid);
			if ( hr == S_OK )
			{
				mol::variant varResult;
				disp->Invoke( dispid, IID_NULL, 
							  LOCALE_SYSTEM_DEFAULT, 
							  w, 
							  pDisp, 
							  &varResult, NULL, NULL 
							 );
			}				
		}
	}
    return S_OK;
}	


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
	setText( mol::toString((*it)) );
    editBox().setSelection( (int)(*it).size(), (int)(*it).size() );

    for ( int i = 0; i < s; i++ )
    {
		addString( mol::toString((*it)) );
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

		char* sz = new char[s];

		hr = pStm->Read( (void*)sz, s, &len );
		if ( hr != S_OK )
			return hr;

		history_.push_back( std::string( sz, len ) );

		delete[] sz;
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
	exp_.release();
}

//////////////////////////////////////////////////////////////////////////////

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
			{
				exp_.release();

				mol::string code;
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

				return FALSE;
			}
			if (LOWORD(wParam) == IDCANCEL )
			{
				exp_.release();
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

HRESULT DebugDlg::addPropertyToList(HWND tree, TV_INSERTSTRUCTW *insertStruct, IDebugProperty *prop)
{
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
			oss << mol::bstr(pi.m_bstrName).toString() << " - ";
			::SysFreeString(pi.m_bstrName);
		}
		if ( pi.m_bstrType )
		{
			oss << mol::bstr(pi.m_bstrType).toString() << " : ";
			::SysFreeString(pi.m_bstrType);
		}
		if ( pi.m_bstrValue )
		{
			oss << mol::bstr(pi.m_bstrValue).toString() << std::endl;
			::SysFreeString(pi.m_bstrValue);	
		}

		std::wstring s = oss.str();
		insertStruct->item.pszText = (LPWSTR)(s.c_str()); 

		insertStruct->hParent = (HTREEITEM)SendMessageW(tree, TVM_INSERTITEM, 0, (LPARAM)insertStruct);
		if ( insertStruct->hParent )
		{
			if ( pi.m_pDebugProp && pi.m_pDebugProp != prop )
			{
				addPropertyToList( tree, insertStruct, pi.m_pDebugProp);
				pi.m_pDebugProp->Release();
			}
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

mol::string findFile(const mol::string& f)
{
	ODBGS(f);

	if ( mol::Path::exists(f) ) 
	{
		ODBGS("FOUND");
		return f;
	}

	mol::string modulePath = mol::Path::pathname(binPath());
	mol::string configPath = mol::Path::pathname(prefPath());

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

	return _T("");
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
	std::vector<mol::string> v;
    v = mol::vectorFromDataObject(pDataObject);
	mol::ImageList::drop(*moe());
	for ( unsigned int i = 0; i < v.size(); i++ )
	{
		bool result = ::docs()->open(0,v[i],Docs::PREF_TXT,false,0);
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
// tree events sink
//////////////////////////////////////////////////////////////////////////////

MoeTreeWnd::~MoeTreeWnd() 
{
	ODBGS("~MoeTreeWnd");
}
/*
void MoeTreeWnd::OnCreate()
{

}
*/

void MoeTreeWnd::OnTreeOpen()
{
	mol::bstr p;
	mol::punk<IShellTree> tree(oleObject);
	tree->get_Selection(&p);
	treeWndSink()->OnTreeOpen(p);
}

void MoeTreeWnd::OnTreeUpdate()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Update();
}			

void MoeTreeWnd::OnTreeRename()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Rename();
}

void MoeTreeWnd::OnTreeDelete()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Delete();
}

void MoeTreeWnd::OnTreeExecute()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Execute();
}

void MoeTreeWnd::OnTreeProperties()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Properties();
}

void MoeTreeWnd::OnTreeNewDir()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->CreateDir();
}

void MoeTreeWnd::OnEditCut()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Cut();
}

void MoeTreeWnd::OnEditCopy()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Copy();
}

void MoeTreeWnd::OnEditPaste()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Paste();
}


HRESULT __stdcall TreeWndSink::OnTreeSelection(BSTR filename)
{
	return moe()->IOleInPlaceFrame_SetStatusText(filename);
}

HRESULT __stdcall TreeWndSink::OnTreeDblClick(BSTR filename)
{
	mol::string p(mol::toString(filename));
	if ( !mol::Path::exists(p) && !mol::Path::isUNC(p) )
	{
		if ( p.substr(0,2) != _T("::") )
			return S_OK;
	}
	mol::punk<IShellTree> tree(treeWnd()->oleObject);
	if ( tree )
	{
		bool result = ::docs()->open(0,mol::toString(filename),Docs::PREF_TXT,false,0);
		statusBar()->status(mol::toString(filename));
		if (!result)
		{
			statusBar()->status( mol::string(_T("failed to load ")) + mol::toString(filename));
			return S_FALSE;
		}
	}
	return S_OK;
}

HRESULT __stdcall TreeWndSink::OnTreeOpen(BSTR filename)
{
	mol::punk<IShellTree> tree(treeWnd()->oleObject);
	if ( tree )
	{
		mol::string fn = mol::toString((wchar_t*)filename);
		if ( mol::Path::isDir( fn) || fn.substr(0,2) == _T("::") )
		{
			statusBar()->status(fn);
			bool result = ::docs()->open(0,fn,Docs::PREF_TXT,false,0);

			if (!result)
			{
				statusBar()->status( mol::string(_T("failed to load ")) + fn);
				return S_OK;
			}
			return S_OK;
		}
		mol::FilenameDlg dlg(*moe());
		dlg.setFilter( InFilesFilter );	
		dlg.fileName(fn);
		if ( !dlg.dlgOpen(OFN_ALLOWMULTISELECT | OFN_EXPLORER) )
			return S_OK;

		int s = dlg.selections();
		int p = dlg.index();
		for ( int i = 0; i < s; i++ )
		{
			mol::string f = dlg.fileName(i);
			statusBar()->status(f);


			bool result = ::docs()->open(0,f,(Docs::InFiles)(p-1 >=0 ? p-1 :0),false,0);

			if (!result)
			{
				statusBar()->status( mol::string(_T("failed to load ")) + f);
				return S_OK;
			}
		}
	}
	return S_OK;
}

HRESULT __stdcall TreeWndSink::OnContextMenu(BSTR fname)
{
	mol::punk<IShellTree> tree(treeWnd()->oleObject);
	if ( !tree )
		return S_OK;

	POINT pt;
	::GetCursorPos(&pt);

	if ( mol::Ribbon::ribbon()->enabled() )
	{
		mol::Ribbon::ribbon()->showContextualUI( RibbonTreeViewContextMap, pt.x, pt.y);
		return 0;
	}

	mol::Menu sub = mol::UI().SubMenu(IDM_CONTEXT_TREE,IDM_TREE);

	moe()->showContext(sub);

	return 0;

	int id = sub.returnTrackPopup(*moe(),pt.x-10,pt.y-10);
	switch ( id )
	{
		case IDM_TREE_OPEN:
		{
			OnTreeOpen(fname);
			break;
		}
		case IDM_TREE_UPDATE:
		{
			tree->Update();
			break;
		}
		case IDM_TREE_RENAME:
		{
			tree->Rename();
			break;
		}
		case IDM_TREE_DELETE:
		{
			tree->Delete();
			break;
		}
		case IDM_EDIT_CUT:
		{
			tree->Cut();
			break;
		}
		case IDM_EDIT_COPY:
		{
			tree->Copy();
			break;
		}
		case IDM_EDIT_PASTE:
		{
			tree->Paste();
			break;
		}
		case IDM_TREE_PROPERTIES:
		{
			tree->Properties();
			break;
		}
		case IDM_TREE_EXECUTE:
		{
			tree->Execute();
			break;
		}
		case IDM_TREE_NEWDIR:
		{
			tree->CreateDir();
			break;
		}
	}
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
}

//////////////////////////////////////////////////////////////////////////////

void PrefPage::setObjects()
{
	IUnknown* unk(config());
	prop_->SetObjects( 1, &unk );
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

		mol::RegExp regex( PCRE_CASELESS,"xml" );
		if ( regex.imatch( mol::tostring(v[i].title) ) )
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
