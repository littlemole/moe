#include "stdafx.h"
#include "html.h"
#include "app.h"
#include "xmlui.h"
#include "ole/Rib.h"
#include "MoeBar.h"
#include "win/TaskBar.h"

MoeHtmlWnd::MoeHtmlWnd( )
{
    eraseBackground_ = 1;
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 
}

MoeHtmlWnd::~MoeHtmlWnd()
{
	ODBGS("~MoeHtmlWnd dead");
}

MoeHtmlWnd::Instance* MoeHtmlWnd::CreateInstance( const mol::string& loc)
{
	statusBar()->status(20);

	Instance* form = new Instance;
	form->AddRef();

	if (!form->load( mol::bstr(loc).toString() ))
	{
		form->destroy();
		form->Release();
		return 0;
	}

	form->maximize();

	mol::string tmp = loc;
	size_t pos = 0;
	while ( (pos = tmp.find( _T("\\"), pos)) != std::string::npos ) 
	{
		tmp.replace(pos,1,_T("/"));
	}

	if ( (tmp.substr(0,4) != _T("file")) &&
		 (tmp.substr(0,4) != _T("http"))    )
	{
		tmp = _T("file://") + tmp;
	}

	statusBar()->status(100);
	form->frame_.Release();
	::SetFocus(*form);	
    return form;
}

void MoeHtmlWnd::OnMDIActivate( HWND activated )
{
	tab()->select( location );
	statusBar()->status( location );

	mol::Ribbon::ribbon()->maximize();
	mol::Ribbon::ribbon()->mode(5);
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

MoeHtmlWnd::MoeFrame::MoeFrame(  )
{
}


MoeHtmlWnd::MoeFrame::~MoeFrame()
{

    ODBGS("~MoeHtmlWnd::MoeFrame() dropped dead");
}


/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeHtmlWnd::MoeFrame::Eval( BSTR src, BSTR scrptLanguage )
{
	mol::punk<IDispatch> disp;
	
	if ( S_OK == get_Object(&disp) && disp )
	{
		mol::punk<IHTMLDocument2> doc(disp);
		if ( doc )
		{
			mol::punk<IHTMLWindow2> window;
			if ( S_OK == doc->get_parentWindow(&window) && window )
			{
				mol::variant var;
				return window->execScript( src, scrptLanguage, &var );
			}
		}
	}
	return E_FAIL;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeHtmlWnd::MoeFrame::get_Object( IDispatch** disp)
{
	if (!disp)
		return E_INVALIDARG;

	*disp = 0;
	return This()->doc(disp);
}

HRESULT __stdcall  MoeHtmlWnd::MoeFrame::get_View(  IMoeDialogView **d)
{
	if (!d)
		return E_INVALIDARG;
	*d=0;

	return view->QueryInterface( IID_IMoeDialogView, (void**)d);
}

HRESULT __stdcall  MoeHtmlWnd::MoeFrame::get_Scripts(  IDispatch **s)
{
	if (!s)
		return E_INVALIDARG;

	*s = 0;
	
	mol::punk<IDispatch> disp;
	if ( S_OK == get_Object( &disp ) && disp )
	{
		mol::punk<IHTMLDocument2> doc2(disp);
		if ( doc2 )
		{
			mol::punk<IHTMLDocument> doc(doc2);
			if ( doc )
			{
				return doc->get_Script(s);
			}
		}
	}
	return E_FAIL;
}

HRESULT __stdcall  MoeHtmlWnd::MoeFrame::OleCmd(  long cmd)
{
	This()->execWb((OLECMDID)cmd);
	return S_OK;
}

HRESULT __stdcall  MoeHtmlWnd::MoeFrame::get_FilePath(  BSTR *filename)
{
	if (!filename)
		return E_INVALIDARG;
	*filename=0;

	*filename = ::SysAllocString( mol::towstring(This()->location).c_str() );
	return S_OK;
}








/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

bool MoeHtmlWnd::load( const mol::string& loc )
{
	location = loc;
	mol::string l = loc;
	mol::string d = _T("");

	size_t pos = loc.find_first_of( _T("#?") );

	if ( pos != std::string::npos )
	{
		l = loc.substr(0,pos);
		d = loc.substr(pos);
	}

	pos = 0;
	while ( (pos = l.find( _T("/"), pos)) != std::string::npos ) 
	{
		l.replace(pos,1, _T("\\") );
	}

	if ( (l.substr(0,4) != _T("file")) &&
		 (l.substr(0,4) != _T("http"))    )
	{
		if ( !mol::Path::exists(l) )
		{
			l = mol::Path::pathname(mol::app<MoeApp>().getModulePath()) + _T("\\");
			l += loc;

			if ( !mol::Path::exists(l) )
			{
				l = mol::Path::pathname(mol::app<MoeApp>().getModulePath()) + _T("\\forms\\") + loc;
				if ( !mol::Path::exists(l) )
					return false;
			}
		}
		l = _T("file://") + l;
	}

	pos = 0;
	while ( (pos = l.find(_T("\\"),pos)) != std::string::npos ) 
	{
		l.replace(pos,1,_T("/"));
	}

	statusBar()->status(30);

	// determine window menu

	windowMenu_ = mol::UI().SubMenu( IDM_MOE_HTML, IDM_VIEW_WINDOWS );
	create( loc.c_str(), (HMENU)mol::UI().Menu(IDM_MOE_HTML), mol::stdRect ,  *moe() );//hWnd() );
	statusBar()->status(40);

	show(SW_SHOW);
	setLocation( l + d );

	advise(htmlSink);

	statusBar()->status(50);

	thumb = mol::taskbar()->addTab( *this,loc );

	return true;
}


void MoeHtmlWnd::OnClose()
{
	ODBGS("MoeHtmlWndImpl::OnClose");
}

void MoeHtmlWnd::OnDestroy()
{
	ODBGS("MoeHtmlWndImpl::OnDestroy");


}

void MoeHtmlWnd::OnNcDestroy()
{
	ODBGS("MoeHtmlWndImpl::OnNcDestroy");

	mol::bstr filename;
	if ( S_OK == get_FilePath(&filename) )
	{
		mol::variant v(filename);
		docs()->Remove(v);
	}

	::CoDisconnectObject(((IExternalMoe*)&external_),0);

	unAdvise(htmlSink);

	((IMoeDocument*)this)->Release();
}

void MoeHtmlWnd::OnSearch(FINDREPLACE* fi)
{
	find(fi->lpstrFindWhat,fi->Flags);
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

DWORD MoeHtmlWnd::UIflags()						
{
	DWORD d = 0;
	return d;
}

HRESULT MoeHtmlWnd::hideContextMenu() 
{ 
	return S_FALSE; 
}

HRESULT __stdcall MoeHtmlWnd::IDocHostUIHandler_GetExternal( IDispatch **ppDispatch)
{
	return external_.QueryInterface(IID_IDispatch, (void**)ppDispatch);
}

/////////////////////////////////////////////////////////////////////////////////////////////
// webbrowser events
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
// external events called from script inside MoeWnd
/////////////////////////////////////////////////////////////////////////////////////////////

MoeHtmlWnd::ExternalMoe::ExternalMoe()
{}

MoeHtmlWnd::ExternalMoe::~ExternalMoe()
{
	ODBGS("ExternalMoe ~");
}

HRESULT __stdcall MoeHtmlWnd::ExternalMoe::get_Moe(IMoe** disp)
{
	if ( !disp )
		return E_INVALIDARG;

	HRESULT hr = ((IMoe*)(moe()))->QueryInterface(IID_IMoe, (void**)disp );
	if ( hr != S_OK )
		*disp = 0;

	return hr;
}

HRESULT __stdcall MoeHtmlWnd::ExternalMoe::Close()
{
	This()->postMessage(WM_CLOSE,0,0);
	return S_OK;
}

HRESULT __stdcall MoeHtmlWnd::ExternalMoe::CreateObject( BSTR progId, IDispatch** disp)
{
	if (!disp) 
		return E_INVALIDARG;

	*disp = 0;
	CLSID clsid;

	if ( S_OK == ::CLSIDFromProgID( progId, &clsid ) )
	{
		if ( S_OK == ::CoCreateInstance( clsid, NULL, CLSCTX_INPROC|CLSCTX_LOCAL_SERVER, IID_IDispatch, (void**) disp ) )
			return S_OK;
	}
	return E_FAIL;
}

HRESULT __stdcall MoeHtmlWnd::ExternalMoe:: get_Frame( IMoeHtmlFrame** f)
{
	if (!f) 
		return E_INVALIDARG;
	return ((IMoeHtmlFrame*)This())->QueryInterface( IID_IMoeHtmlFrame, (void**) f );
}


HRESULT __stdcall MoeHtmlWnd::ExternalMoe::CodeBehind( BSTR fname )
{
	return S_OK;
}

HRESULT __stdcall MoeHtmlWnd::ExternalMoe::get_Code( IDispatch** code )
{
	if ( !code )
		return E_INVALIDARG;

	*code = 0;
	return E_FAIL;
}

//////////////////////////////////////////////////////////////////////////////
// webbrowser events
//////////////////////////////////////////////////////////////////////////////


HRESULT __stdcall MoeHtmlWnd::MoeHtmlWnd_htmlSink::BeforeNavigate2(IDispatch* pDisp, VARIANT* URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers, VARIANT_BOOL* Cancel)
{
	static std::wstring ws(L"moe://close/");
	if ( ws == mol::bstr(URL->bstrVal).towstring() )
	{
		This()->postMessage(WM_CLOSE,0,0);
		*Cancel = VARIANT_TRUE;
	}

	return S_OK;
}


HRESULT __stdcall MoeHtmlWnd::MoeHtmlWnd_htmlSink::WindowClosing( VARIANT_BOOL isChildWindow, VARIANT_BOOL* vbCancel )
{
	if ( vbCancel )
		*vbCancel = VARIANT_FALSE;

	if ( isChildWindow == VARIANT_FALSE )
	{
	}
	return S_OK;
}

HRESULT __stdcall MoeHtmlWnd::MoeHtmlWnd_htmlSink::DocumentComplete( IDispatch* pDisp,  VARIANT* URL)
{
	statusBar()->status(60);

	mol::punk<IWebBrowser2> ie(pDisp);
	if (!ie )
	{
		statusBar()->status(_T(""));	
		return S_OK;
	}

	mol::punk<IDispatch> docDisp;

	if ( S_OK != ie->get_Document(&docDisp) )
	{
		statusBar()->status(_T(""));	
		return S_OK;
	}

	if ( !docDisp )
	{
		statusBar()->status(_T(""));	
		return S_OK;
	}

	mol::punk<IHTMLDocument2> doc(docDisp);
	if ( doc )
	{
		mol::bstr title;
		if ( S_OK == doc->get_title(&title) && title )
		{
			This()->setText( title.toString() );
		}

		statusBar()->status(70);
	}

	statusBar()->status(100);
	mol::punk<IOleCommandTarget> oct(This()->oleObject);
	if ( oct)
	{
		oct->Exec(0,OLECMDID_HIDETOOLBARS,1,0,0);
	}
	statusBar()->status(_T(""));	
	return S_OK;
}
