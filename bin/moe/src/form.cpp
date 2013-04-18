#include "stdafx.h"
#include "form.h"
#include "app.h"
#include "xmlui.h"

using namespace mol::win;
using namespace mol::ole;
using namespace mol;


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

MoeFormWnd::MoeFormWnd(  )
{
    eraseBackground_ = 1;
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 
}


MoeFormWnd::~MoeFormWnd()
{
	ODBGS("~MoeFormWnd() dropped dead");
}


MoeFormWnd::Instance* MoeFormWnd::CreateInstance( const mol::string& loc, int left, int top, int width, int height, int style )
{
	mol::string tmp = loc;
	size_t pos = loc.find_first_of( _T("#?"));
	if ( pos != std::string::npos )
		tmp = loc.substr(0,pos);

	mol::string f = findFile(tmp);

	if ( !mol::Path::exists(f) )
		return 0;

	Instance* form = new Instance;
	form->view = MoeDialogView::CreateInstance(form);
	form->AddRef();

	form->location_ = f;
	form->load( bstr(f).toString(), style, mol::Rect( left, top, width, height)  );

	return form;
}


void MoeFormWnd::load( const mol::string& loc, int s, Rect& r )
{
	mol::string l = loc;

	size_t pos = loc.find_first_of( _T("#?"));
	if ( pos != std::string::npos )
		l = loc.substr(0,pos);

	if ( !mol::Path::exists(l) )
	{
		l = mol::Path::pathname(mol::app<MoeApp>().getModulePath()) + _T("\\");
		l += loc;

		if ( !mol::Path::exists(l) )
		{
			l = mol::Path::pathname(mol::app<MoeApp>().getModulePath()) + _T("\\forms\\") + loc;
			if ( !mol::Path::exists(l) )
				return;
		}
	}

	style_	  = s;

	if ( style_ & MoeFormWnd::STANDALONE )
		create(  0, r ,  (HWND)0 );
	else
		create( 0, r ,  (HWND)(*moe()) );

	show(SW_SHOW);

	if ( pos != std::string::npos )
		l.append(loc.substr(pos));

	setLocation( l );
	advise(htmlSink_);
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



void MoeFormWnd::OnClose()
{
	ODBGS("MoeFormWnd::OnClose");
	unAdvise(htmlSink_);
}

void MoeFormWnd::OnNcDestroy()
{
	ODBGS("MoeFormWnd::OnNcDestroy");
	::CoDisconnectObject(((IExternalMoe*)&external_),0);

	// trigger the missing WM_MDIACTIVATE as we broke MDI handling
	// by showing this form. note we don't call m->activate but
	// post the message directly; this is due the MDI def impl
	// would swallow it in this case :-)
	HWND active = moe()->getActive();
	mol::MdiChild* m = mol::wndFromHWND<mol::MdiChild>(active);
	if ( m )
	{
		::PostMessage( active, WM_MDIACTIVATE, 0,(LPARAM)(HWND)(active));
	}
	
	((IMoeHtmlFrame*)this)->Release();

	ODBGS("~MoeFormWnd()OnNcDestroy --");
}

/////////////////////////////////////////////////////////////////////////////////////////////


int MoeFormWnd::style() 
{ 
	static int s = WS_CLIPSIBLINGS|WS_CLIPCHILDREN;

	if ( style_ & MoeFormWnd::TITLE )
		return WS_OVERLAPPEDWINDOW|WS_CLIPSIBLINGS|WS_CLIPCHILDREN; 
	else
		return WS_POPUP|WS_CLIPSIBLINGS|WS_CLIPCHILDREN; 
} 

/////////////////////////////////////////////////////////////////////////////////////////////

DWORD MoeFormWnd::UIflags()						
{
	DWORD d = DOCHOSTUIFLAG_NO3DBORDER;
	if ( style_ & MoeFormWnd::DIALOG )
		d = d | DOCHOSTUIFLAG_DIALOG;
	if ( style_ & MoeFormWnd::NOSCROLL )
		d = d | DOCHOSTUIFLAG_SCROLL_NO;
	
	return d;
}

HRESULT MoeFormWnd::hideContextMenu() 
{ 
	return S_FALSE; 
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  MoeFormWnd::get_Object( IDispatch **d)
{
	if (!d)
		return E_INVALIDARG;
	*d=0;

	return this->doc(d);
}

HRESULT __stdcall  MoeFormWnd::get_View(  IMoeDialogView **d)
{
	if (!d)
		return E_INVALIDARG;
	*d=0;

	return view->QueryInterface( IID_IMoeDialogView, (void**)d);
}

HRESULT __stdcall  MoeFormWnd::get_Scripts(  IDispatch **s)
{
	if (!s)
		return E_INVALIDARG;

	*s = 0;
	
	punk<IDispatch> disp;
	if ( S_OK == get_Object( &disp ) && disp )
	{
		punk<IHTMLDocument2> doc2(disp);
		if ( doc2 )
		{
			punk<IHTMLDocument> doc(doc2);
			if ( doc )
			{
				return doc->get_Script(s);
			}
		}
	}
	return E_FAIL;
}

HRESULT __stdcall  MoeFormWnd::Eval(  BSTR src, BSTR scriptLanguage)
{
	punk<IDispatch> disp;
	if ( S_OK == get_Object(&disp) && disp )
	{
		punk<IHTMLDocument2> doc(disp);

		if (doc )
		{
			punk<IHTMLWindow2> window;
			if ( S_OK == doc->get_parentWindow(&window) && window )
			{
				variant var;
				return window->execScript( src, scriptLanguage, &var );
			}
		}
	}
	return E_FAIL;
}

HRESULT __stdcall  MoeFormWnd::OleCmd(  long cmd)
{
	execWb((OLECMDID)cmd);
	return S_OK;
}

HRESULT __stdcall  MoeFormWnd::get_FilePath(  BSTR *filename)
{
	if (!filename)
		return E_INVALIDARG;
	*filename=0;

	*filename = ::SysAllocString( mol::towstring(location_).c_str() );
	return S_OK;
}



/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeFormWnd::IDocHostUIHandler_GetExternal( IDispatch **ppDispatch)
{
	ODBGS("MoeFormWnd::IDocHostUIHandler_GetExternal");
	return external_.QueryInterface(IID_IDispatch, (void**)ppDispatch);
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
// webbrowser events
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
// external events called from script inside MoeWnd
/////////////////////////////////////////////////////////////////////////////////////////////

MoeFormWnd::ExternalMoe::ExternalMoe()
{
}

MoeFormWnd::ExternalMoe::~ExternalMoe()
{
	ODBGS("ExternalMoe ~");
}

HRESULT __stdcall MoeFormWnd::ExternalMoe::get_Moe(IMoe** disp)
{
	if ( !disp )
		return E_INVALIDARG;

	HRESULT hr = ((IMoe*)(moe()))->QueryInterface(IID_IDispatch, (void**)disp );
	if ( hr != S_OK )
		*disp = 0;

	return hr;
}

HRESULT __stdcall MoeFormWnd::ExternalMoe::Close()
{
	ODBGS("MoeFormWnd::ExternalMoe::Close()");
	This()->postMessage(WM_CLOSE,0,0);
	return S_OK;
}

HRESULT __stdcall MoeFormWnd::ExternalMoe::CreateObject( BSTR progId, IDispatch** disp)
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

HRESULT __stdcall MoeFormWnd::ExternalMoe:: get_Frame( IMoeHtmlFrame** f)
{
	if (!f) 
		return E_INVALIDARG;
	return ((IMoeHtmlFrame*)This())->QueryInterface( IID_IMoeHtmlFrame, (void**) f );
}


HRESULT __stdcall MoeFormWnd::ExternalMoe::CodeBehind( BSTR fname )
{
	return S_OK;
}

HRESULT __stdcall MoeFormWnd::ExternalMoe::get_Code( IDispatch** code )
{
	if ( !code )
		return E_INVALIDARG;

	*code = 0;
	return E_FAIL;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// webbrowser events
//////////////////////////////////////////////////////////////////////////////


HRESULT __stdcall MoeFormWnd::MoeFormWnd_htmlSink::BeforeNavigate2(IDispatch* pDisp, VARIANT* URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers, VARIANT_BOOL* Cancel)
{
	static std::wstring ws(L"moe://close/");
	if ( ws == bstr(URL->bstrVal).towstring() )
	{
		This()->postMessage(WM_CLOSE,0,0);
		*Cancel = VARIANT_TRUE;
	}
	return S_OK;
}

HRESULT __stdcall MoeFormWnd::MoeFormWnd_htmlSink::WindowClosing( VARIANT_BOOL isChildWindow, VARIANT_BOOL* vbCancel )
{
ODBGS("MoeFormWnd::MoeFormWnd_htmlSink::WindowClosing");

	if ( vbCancel )
		*vbCancel = VARIANT_FALSE;

	if ( (isChildWindow == VARIANT_FALSE) )
	{
	}
	return S_OK;
}

HRESULT __stdcall MoeFormWnd::MoeFormWnd_htmlSink::DocumentComplete( IDispatch* pDisp,  VARIANT* URL)
{
	punk<IWebBrowser2> ie(pDisp);
	if (!ie )
		return S_OK;

	punk<IDispatch> docDisp;

	if ( S_OK != ie->get_Document(&docDisp) )
		return S_OK;

	if ( !docDisp )
		return S_OK;

	statusBar()->status(_T("form document complete"));

	punk<IHTMLDocument2> doc(docDisp);
	if ( doc )
	{
		bstr title;
		if ( S_OK == doc->get_title(&title) && title )
		{
			This()->setText( title.toString() );
		}
	}
	return S_OK;
}
