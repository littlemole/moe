#include "stdafx.h"
#include "form2.h"
#include "app.h"
#include "xmlui.h"
#include "xmlid.h"

using namespace mol::win;
using namespace mol::ole;
using namespace mol;


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

MoeForm2Wnd::MoeForm2Wnd(  )
{
    eraseBackground_ = 1;
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 

	//oleObject = this;
}


MoeForm2Wnd::~MoeForm2Wnd()
{
	ODBGS("~MoeFormWnd() dropped dead");
}


MoeForm2Wnd::Instance* MoeForm2Wnd::CreateInstance( const std::wstring& loc, int left, int top, int width, int height, int style )
{
	std::wstring tmp = loc;
	size_t pos = loc.find_first_of( _T("#?"));
	if ( pos != std::string::npos )
		tmp = loc.substr(0,pos);

	std::wstring f = findFile(tmp);

	if ( !mol::Path::exists(f) )
		return 0;

	Instance* form = new Instance;
	form->view = MoeDialogView::CreateInstance(form);
	form->AddRef();

	form->location_ = f;
	form->load( bstr(f).towstring(), style, mol::Rect( left, top, width, height)  );

	return form;
}


void MoeForm2Wnd::load( const std::wstring& loc, int s, Rect& r )
{
	std::wstring l = loc;

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

	if ( style_ & MoeForm2Wnd::STANDALONE )
		create(  0, r ,  (HWND)0 );
	else
		create( 0, r ,  (HWND)(*moe()) );

	show(SW_SHOW);

	if ( pos != std::string::npos )
		l.append(loc.substr(pos));

	moe()->edge->createWebView(hWnd_, [this, l](HRESULT hr, ICoreWebView2Controller* controller)
	{
		this->onCreateWebView(l, controller);
	});
}

void MoeForm2Wnd::onCreateWebView(std::wstring target, ICoreWebView2Controller* controller)
{
	webViewController = controller;

	webViewController->get_CoreWebView2(&webview);

	mol::punk<IDispatch> disp(&external_);
	mol::variant obj(disp);
	webview->AddHostObjectToScript(L"external", &obj);

	webview->add_DocumentTitleChanged(
		make_callback<ICoreWebView2DocumentTitleChangedEventHandler>(
			[this](ICoreWebView2* sender, IUnknown*)
	{
		this->onDocumentTitleChanged();
	}),
		&documentTitleChangedToken
		);

	webview->add_NavigationStarting(
		make_callback<ICoreWebView2NavigationStartingEventHandler>(
			[this](ICoreWebView2* webView, ICoreWebView2NavigationStartingEventArgs* args)
	{
		this->onNavigationStarted(args);
	}),
		&navigationStartingToken
		);

	webview->add_PermissionRequested(
		make_callback<ICoreWebView2PermissionRequestedEventHandler>(
			[this](ICoreWebView2* webView, ICoreWebView2PermissionRequestedEventArgs* args)
	{
		this->onPermissionRequest(args);
	}),
		&permissionRequestToken
		);

	webview->Navigate(target.c_str());
}


void MoeForm2Wnd::onDocumentTitleChanged()
{
	LPWSTR title = nullptr;
	webview->get_DocumentTitle(&title);
	this->setText(title);
	::CoTaskMemFree(title);
}

void MoeForm2Wnd::onNavigationStarted(ICoreWebView2NavigationStartingEventArgs* args)
{
	LPWSTR uri = nullptr;
	args->get_Uri(&uri);
	if (mol::wcstricmp(uri, L"mol://close") == 0)
	{
		args->put_Cancel(TRUE);
		::CoTaskMemFree(uri);

		if (style_ & HIDE_ON_KILL_FOCUS)
		{
			postMessage(WM_COMMAND, IDM_HTML_FORM_HIDE, 0);
		}
		else
		{
			postMessage(WM_CLOSE, 0, 0);
		}
		return;
	}

	::CoTaskMemFree(uri);
}

void MoeForm2Wnd::onPermissionRequest(ICoreWebView2PermissionRequestedEventArgs* args)
{
	LPWSTR uri = nullptr;
	COREWEBVIEW2_PERMISSION_KIND kind = COREWEBVIEW2_PERMISSION_KIND_UNKNOWN_PERMISSION;
	BOOL userInitiated = FALSE;

	args->get_Uri(&uri);
	args->get_PermissionKind(&kind);
	args->get_IsUserInitiated(&userInitiated);

	std::wostringstream oss;
	oss << L"Do you want to grant permission for ";

	switch (kind)
	{
	case COREWEBVIEW2_PERMISSION_KIND_CAMERA:
	{
		oss << "Camera";
		break;
	}
	case COREWEBVIEW2_PERMISSION_KIND_CLIPBOARD_READ:
	{
		oss << "Clipboard Read";
		break;
	}
	case COREWEBVIEW2_PERMISSION_KIND_GEOLOCATION:
	{
		oss << "GeoLocation";
		break;
	}
	case COREWEBVIEW2_PERMISSION_KIND_MICROPHONE:
	{
		oss << "Microphone";
		break;
	}
	case COREWEBVIEW2_PERMISSION_KIND_NOTIFICATIONS:
	{
		oss << "Notifications";
		break;
	}
	case COREWEBVIEW2_PERMISSION_KIND_OTHER_SENSORS:
	{
		oss << "Other Sensors";
		break;
	}
	}

	oss << L" to the website at "
		<< uri
		<< L"?\n\n";

	if (userInitiated)
	{
		oss << L"This request came from a user gesture.";
	}
	else
	{
		oss << L"This request did not come from a user gesture.";
	}

	int response = MessageBox(nullptr, oss.str().c_str(), L"Permission Request",
		MB_YESNOCANCEL | MB_ICONWARNING);

	COREWEBVIEW2_PERMISSION_STATE state =
		response == IDYES ? COREWEBVIEW2_PERMISSION_STATE_ALLOW
		: response == IDNO ? COREWEBVIEW2_PERMISSION_STATE_DENY
		: COREWEBVIEW2_PERMISSION_STATE_DEFAULT;

	args->put_State(state);
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


void MoeForm2Wnd::OnSize(WPARAM wParam, LPARAM lParam)
{
	if (webViewController)
	{
		RECT bounds;
		GetClientRect(hWnd_, &bounds);
		webViewController->put_Bounds(bounds);
	};

}
void MoeForm2Wnd::OnClose()
{
	ODBGS("MoeFormWnd::OnClose");
}

void MoeForm2Wnd::OnNcDestroy()
{
	ODBGS("MoeFormWnd::OnNcDestroy");

	if (webview)
	{
		webview->RemoveHostObjectFromScript(L"external");
		webview->remove_DocumentTitleChanged(documentTitleChangedToken);
		webview->remove_NavigationStarting(navigationStartingToken);
		webview->remove_PermissionRequested(permissionRequestToken);

		webViewController->Close();
		webViewController.release();
		webview.release();
	}

	//oleObject.release();

	::CoDisconnectObject(((IExternalMoe*)&external_), 0);


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

void MoeForm2Wnd::OnHide()
{
	show(SW_HIDE);
}

LRESULT MoeForm2Wnd::OnActivate(WPARAM wParam, LPARAM lParam)
{
	if (style_ & HIDE_ON_KILL_FOCUS)
	{
		WORD mode = LOWORD(wParam);
		if (mode == WA_INACTIVE && (HWND)lParam != hWnd_)
		{
			// TODO: post yourself a SW_HIDE request ;-)
			// this crashes MDI managemt otherwise ??????
			//show(SW_HIDE);
			postMessage(WM_COMMAND, IDM_HTML_FORM_HIDE, 0);
			//postMessage(WM_CLOSE, 0, 0);
			//destroy();
			//::SetActiveWindow(*moe());
		}
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////


int MoeForm2Wnd::style()
{ 
	static int s = WS_CLIPSIBLINGS|WS_CLIPCHILDREN;

	if ( style_ & MoeForm2Wnd::TITLE )
		return WS_OVERLAPPEDWINDOW|WS_CLIPSIBLINGS|WS_CLIPCHILDREN; 
	else
		return WS_POPUP|WS_CLIPSIBLINGS|WS_CLIPCHILDREN; 
} 

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeForm2Wnd::get_onDocumentLoad(IDispatch** disp)
{
	return E_NOTIMPL;
}

HRESULT __stdcall MoeForm2Wnd::put_onDocumentLoad(IDispatch* disp)
{
	return E_NOTIMPL;
}

HRESULT __stdcall MoeForm2Wnd::get_onMessage(IDispatch** disp)
{
	return E_NOTIMPL;
}

HRESULT __stdcall MoeForm2Wnd::put_onMessage(IDispatch* disp)
{
	return E_NOTIMPL;
}

HRESULT __stdcall MoeForm2Wnd::PostMessage2WebView(BSTR json)
{
	return E_NOTIMPL;
}


HRESULT __stdcall  MoeForm2Wnd::get_View(IMoeDialogView** d)
{
	if (!d)
		return E_INVALIDARG;
	*d = 0;

	return view->QueryInterface(IID_IMoeDialogView, (void**)d);
}

HRESULT __stdcall  MoeForm2Wnd::get_Scripts(IDispatch** s)
{
	if (!s)
		return E_INVALIDARG;

	*s = 0;


	return E_FAIL;
}

HRESULT __stdcall  MoeForm2Wnd::Eval(BSTR src, IDispatch* future)
{
	if (!webview) return S_OK;

	return webview->ExecuteScript(mol::bstr(src).towstring().c_str(), nullptr);

}

HRESULT __stdcall  MoeForm2Wnd::OleCmd(  long cmd)
{
	switch (cmd)
	{
	case OLECMDID_CUT:
	{
		cut();
		break;
	}
	case OLECMDID_COPY:
	{
		copy();
		break;
	}
	case OLECMDID_PASTE:
	{
		paste();
		break;
	}
	}
	return S_OK;
}

void MoeForm2Wnd::cut()
{
	if (!webview) return;

	webview->ExecuteScript(L"document.execCommand('cut')", nullptr);

}
void MoeForm2Wnd::copy()
{
	if (!webview) return;

	webview->ExecuteScript(L"document.execCommand('copy')", nullptr);
}

std::wstring escape_json_str(const std::wstring& in);

void MoeForm2Wnd::paste()
{
	if (!webview) return;

	mol::win::ClipBoard clip(hWnd_);
	UINT format = clip.format(mol::win::ClipBoard::UNICODE_TEXT);
	std::wstring pasteText = escape_json_str(clip.getUnicodeText(format));

	std::wostringstream oss;
	oss << L"(function(){ let el = document.activeElement; "
		<< L"el.value = el.value.substring(0,el.selectionStart) + "
		<< L"'" << pasteText.substr(0, pasteText.size() - 1);
	oss << L"' + "
		<< L"el.value.substring(el.selectionEnd,el.value.length); }) ();";

	std::wstring ws(oss.str());
	webview->ExecuteScript(ws.c_str(), nullptr);
}


HRESULT __stdcall  MoeForm2Wnd::get_FilePath(  BSTR *filename)
{
	if (!filename)
		return E_INVALIDARG;
	*filename=0;

	*filename = ::SysAllocString( mol::towstring(location_).c_str() );
	return S_OK;
}


HRESULT __stdcall MoeForm2Wnd::addExternalObject(BSTR name, IDispatch* disp)
{
	if (!webview)
		return S_FALSE;

	mol::bstr objName(name);
	mol::variant v(disp);
	return webview->AddHostObjectToScript(objName.towstring().c_str(), &v);
}

HRESULT __stdcall MoeForm2Wnd::removeExternalObject(BSTR name)
{
	if (!webview)
		return S_FALSE;

	mol::bstr objName(name);
	return webview->RemoveHostObjectFromScript(objName.towstring().c_str());
}


HRESULT __stdcall MoeForm2Wnd::Reload()
{
	if (!webview)
		return S_FALSE;

	webview->Reload();

	return S_OK;
}

HRESULT __stdcall MoeForm2Wnd::Next()
{
	if (!webview)
		return S_FALSE;

	webview->GoForward();

	return S_OK;
}

HRESULT __stdcall MoeForm2Wnd::Back()
{
	if (!webview)
		return S_FALSE;

	webview->GoBack();
	return S_OK;
}
/////////////////////////////////////////////////////////////////////////////////////////////
// external events called from script inside MoeWnd
/////////////////////////////////////////////////////////////////////////////////////////////

MoeForm2Wnd::ExternalMoe::ExternalMoe()
{
}

MoeForm2Wnd::ExternalMoe::~ExternalMoe()
{
	ODBGS("ExternalMoe ~");
}

HRESULT __stdcall MoeForm2Wnd::ExternalMoe::get_Moe(IDispatch** disp)
{
	if ( !disp )
		return E_INVALIDARG;

	HRESULT hr = ((IMoe*)(moe()))->QueryInterface(IID_IDispatch, (void**)disp );
	if ( hr != S_OK )
		*disp = 0;

	return hr;
}



HRESULT __stdcall MoeForm2Wnd::ExternalMoe::Close()
{
	ODBGS("MoeFormWnd::ExternalMoe::Close()");
	This()->postMessage(WM_CLOSE,0,0);
	return S_OK;
}

HRESULT __stdcall MoeForm2Wnd::ExternalMoe::CreateObject( BSTR progId, IDispatch** disp)
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

HRESULT __stdcall MoeForm2Wnd::ExternalMoe:: get_Frame( IMoeHtmlFrame** f)
{
	if (!f) 
		return E_INVALIDARG;
	return ((IMoeHtmlFrame*)This())->QueryInterface( IID_IMoeHtmlFrame, (void**) f );
}


HRESULT __stdcall MoeForm2Wnd::ExternalMoe::CodeBehind( BSTR fname )
{
	return S_OK;
}

HRESULT __stdcall MoeForm2Wnd::ExternalMoe::get_Code( IDispatch** code )
{
	if ( !code )
		return E_INVALIDARG;

	*code = 0;
	return E_FAIL;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
