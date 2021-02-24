#include "stdafx.h"
#include "html2.h"
#include "app.h"
#include "MoeBar.h"
#include "Docs.h"

MoeHtml2Wnd::MoeHtml2Wnd( )
{
    eraseBackground_ = 1;
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 

	oleObject = &frame_;
}

MoeHtml2Wnd::~MoeHtml2Wnd()
{
	ODBGS("~MoeHtml2Wnd dead");
}

MoeHtml2Wnd::Instance* MoeHtml2Wnd::CreateInstance( const std::wstring& loc)
{
	statusBar()->status(20);

	Instance* form = new Instance;
	form->AddRef();

	if (!form->load(mol::bstr(loc).towstring()))
	{
		form->destroy();
		form->Release();
		return 0;
	}

	form->maximize();

	std::wstring tmp = loc;
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
	::SetFocus(*form);	
    return form;
}

handle_msg(&MoeHtml2Wnd::OnMDIActivate, WM_MDIACTIVATE)
void MoeHtml2Wnd::OnMDIActivate( HWND activated )
{
	tab()->select( *this );
	statusBar()->status( location );

	ribbon()->setAppMode("Html");
}


handle_msg(&MoeHtml2Wnd::OnSize, WM_SIZE)
void MoeHtml2Wnd::OnSize(WPARAM wParam, LPARAM lParam)
{
	if (webViewController) 
	{
		RECT bounds;
		GetClientRect(hWnd_, &bounds);
		webViewController->put_Bounds(bounds);
	};

}
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

MoeHtml2Wnd::MoeFrame::MoeFrame(  )
{
}


MoeHtml2Wnd::MoeFrame::~MoeFrame()
{

    ODBGS("~MoeHtmlWnd::MoeFrame() dropped dead");
}


/////////////////////////////////////////////////////////////////////

handle_cmd(&MoeHtml2Wnd::back, IDM_NAVIGATE_BACK)
void MoeHtml2Wnd::back()
{
	if (!webview) return;

	webview->GoBack();
}

handle_cmd(&MoeHtml2Wnd::forward, IDM_NAVIGATE_NEXT)
void MoeHtml2Wnd::forward()
{
	if (!webview) return;

	webview->GoForward();

}

handle_cmd(&MoeHtml2Wnd::reload, IDM_EDIT_UPDATE)
void MoeHtml2Wnd::reload()
{
	if (!webview) return;

	webview->Reload();

}

handle_cmd(&MoeHtml2Wnd::options, IDM_MODE_SETTINGS)
void MoeHtml2Wnd::options()
{
	if (!webview) return;

	webview->OpenDevToolsWindow();
}

handle_cmd(&MoeHtml2Wnd::print, IDM_FILE_PRINT)
void MoeHtml2Wnd::print()
{
	if (!webview) return;

	webview->ExecuteScript(L"window.print();", nullptr);
}

handle_cmd(&MoeHtml2Wnd::cut, IDM_EDIT_CUT)
void MoeHtml2Wnd::cut()
{
	if (!webview) return;

	webview->ExecuteScript(L"document.execCommand('cut')", nullptr);

}

handle_cmd(&MoeHtml2Wnd::copy, IDM_EDIT_COPY)
void MoeHtml2Wnd::copy()
{
	if (!webview) return;

	webview->ExecuteScript(L"document.execCommand('copy')", nullptr);
}

std::wstring escape_json_str(const std::wstring& in);

handle_cmd(&MoeHtml2Wnd::paste, IDM_EDIT_PASTE)
void MoeHtml2Wnd::paste()
{
	if (!webview) return;

	mol::win::ClipBoard clip(hWnd_);
	UINT format = clip.format(mol::win::ClipBoard::UNICODE_TEXT);
	std::wstring pasteText = escape_json_str( clip.getUnicodeText(format) );

	std::wostringstream oss;
	oss << L"(function(){ let el = document.activeElement; "
		<< L"el.value = el.value.substring(0,el.selectionStart) + "
		<< L"'" << pasteText.substr(0,pasteText.size()-1); 
	oss << L"' + "
		<< L"el.value.substring(el.selectionEnd,el.value.length); }) ();";

	std::wstring ws(oss.str());
	webview->ExecuteScript(ws.c_str(), nullptr);
}

handle_cmd(&MoeHtml2Wnd::stop, IDM_EDIT_STOP)
void MoeHtml2Wnd::stop()
{
	if (!webview) return;
	webview->Stop();
}


handle_cmd(&MoeHtml2Wnd::OnCloseAll, IDM_VIEW_CLOSEALL)
LRESULT MoeHtml2Wnd::OnCloseAll()
{
	return MoeChild<
		MoeHtml2Wnd,
		mol::MdiChild,
		MOE_DOCTYPE_HTML,
		IDM_MOE_HTML
	>::OnCloseAll();
}


HRESULT __stdcall MoeHtml2Wnd::get_FilePath(BSTR* fname)
{
	if (fname)
	{
		*fname = 0;
		*fname = ::SysAllocString(mol::towstring(location).c_str());
	}
	return S_OK;
}

HRESULT __stdcall MoeHtml2Wnd::get_Object(IDispatch** d)
{
	if (!d)
		return E_INVALIDARG;
	*d = 0;

	return frame_.QueryInterface(IID_IDispatch, (void**) d);
}


HRESULT __stdcall MoeHtml2Wnd::get_Model(IDispatch** d)
{
	if (!d)
		return E_INVALIDARG;
	*d = 0;

	return frame_.QueryInterface(IID_IDispatch, (void**)d);
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeHtml2Wnd::MoeFrame::Eval( BSTR src, IDispatch* future )
{
	if (!This()->oleObject) return S_OK;

	mol::punk<IDispatch> disp(future);

	auto cb = make_callback< ICoreWebView2ExecuteScriptCompletedHandler>(
		[disp](HRESULT errorCode, LPCWSTR json) mutable
	{
		if (!disp || !json)
			return;

		mol::bstr bJson(json);
		mol::variant v(bJson);

		EXCEPINFO ex;
		::ZeroMemory(&ex, sizeof(EXCEPINFO));
		UINT e = 0;
		DISPPARAMS p = { 0,0 };
		p.cArgs = 1;
		p.rgvarg = &v;

		HRESULT hr = disp->Invoke(DISPID_VALUE, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &p, NULL, &ex, &e);
	});
	return This()->webview->ExecuteScript(mol::bstr(src).towstring().c_str(), cb);

}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeHtml2Wnd::MoeFrame::get_onDocumentLoad( IDispatch** disp)
{
	if (!disp)
		return E_INVALIDARG;
	*disp = 0;
	 
	if (!This()->onDocumentLoadHandler)
		return S_OK;

	return This()->onDocumentLoadHandler.queryInterface(disp);
}

HRESULT __stdcall MoeHtml2Wnd::MoeFrame::put_onDocumentLoad(IDispatch* disp)
{
	This()->onDocumentLoadHandler = disp;
	return S_OK;
}

HRESULT __stdcall MoeHtml2Wnd::MoeFrame::get_onMessage(IDispatch** disp)
{
	if (!disp)
		return E_INVALIDARG;
	*disp = 0;

	if (!This()->onMessageHandler)
		return S_OK;

	return This()->onMessageHandler.queryInterface(disp);
}

HRESULT __stdcall MoeHtml2Wnd::MoeFrame::put_onMessage(IDispatch* disp)
{
	This()->onMessageHandler = disp;
	return S_OK;
}

HRESULT __stdcall MoeHtml2Wnd::MoeFrame::PostMessage2WebView(BSTR json)
{
	if (!This()->oleObject)
		return S_FALSE;

	mol::bstr b(json);

	return This()->webview->PostWebMessageAsJson(b.towstring().c_str());
}

HRESULT __stdcall  MoeHtml2Wnd::MoeFrame::get_View(  IMoeDialogView **d)
{
	if (!d)
		return E_INVALIDARG;
	*d=0;

	return This()->view.queryInterface(d);
}

HRESULT __stdcall  MoeHtml2Wnd::MoeFrame::get_Scripts(  IDispatch **s)
{
	return E_NOTIMPL;

}

HRESULT __stdcall  MoeHtml2Wnd::MoeFrame::OleCmd(  long cmd)
{
	switch (cmd)
	{
		case OLECMDID_CUT : 
		{
			This()->cut();
			break;
		}
		case OLECMDID_COPY:
		{
			This()->copy();
			break;
		}
		case OLECMDID_PASTE:
		{
			This()->paste();
			break;
		}
	}
	return S_OK;
}

HRESULT __stdcall  MoeHtml2Wnd::MoeFrame::get_FilePath(  BSTR *filename)
{
	if (!filename)
		return E_INVALIDARG;
	*filename=0;

	*filename = ::SysAllocString( mol::towstring(This()->location).c_str() );
	return S_OK;
}

HRESULT __stdcall MoeHtml2Wnd::MoeFrame::addExternalObject(BSTR name, IDispatch* disp)
{
	if (!This()->oleObject)
		return S_FALSE;

	removeExternalObject(name);

	mol::bstr objName(name);
	objects_.insert(objName.towstring());

	mol::variant v(disp);
	return This()->webview->AddHostObjectToScript(objName.towstring().c_str(), &v);
}

HRESULT __stdcall MoeHtml2Wnd::MoeFrame::removeExternalObject(BSTR name)
{
	if (!This()->webview)
		return S_FALSE;

	mol::bstr objName(name);
	if (objects_.count(objName.towstring()) == 0)
		return S_OK;

	return This()->webview->RemoveHostObjectFromScript(objName.towstring().c_str());
}

HRESULT __stdcall MoeHtml2Wnd::MoeFrame::Reload()
{
	if (!This()->webview)
		return S_FALSE;

	This()->webview->Reload();

	return S_OK;
}

HRESULT __stdcall MoeHtml2Wnd::MoeFrame::Next()
{
	if (!This()->webview)
		return S_FALSE;

	This()->webview->GoForward();

	return S_OK;
}

HRESULT __stdcall MoeHtml2Wnd::MoeFrame::Back()
{
	if (!This()->webview)
		return S_FALSE;

	This()->webview->GoBack();
	return S_OK;
}









/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

bool MoeHtml2Wnd::load( const std::wstring& loc )
{
	location = loc;
	std::wstring l = loc;
	std::wstring d = _T("");

	size_t pos = loc.find_first_of( _T("#?") );

	if ( pos != std::string::npos )
	{
		l = loc.substr(0,pos);
		d = loc.substr(pos);
	}

	if ( loc.substr(0,8) == _T("shell:::") )
	{
	}
	else
	{

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
				mol::bstr cfgPath;
				moe()->moeConfig->get_ConfigPath(&cfgPath);
				l = cfgPath.towstring() + _T("\\");
				l += loc;

				if ( !mol::Path::exists(l) )
				{
					l = cfgPath.towstring() + _T("\\forms\\") + loc;
					if ( !mol::Path::exists(l) )
						return false;
				}
			}
			l = _T("file:///") + l;
		}

		pos = 0;
		while ( (pos = l.find(_T("\\"),pos)) != std::string::npos ) 
		{
			l.replace(pos,1,_T("/"));
		}
	}
	statusBar()->status(30);

	initializeMoeChild(loc);

	std::wstring target = l + d;

	moe()->edge->createWebView(hWnd_, [this,target](HRESULT hr, ICoreWebView2Controller* controller)
	{
		this->onCreateWebView(target, controller);
	});

	return true;
}

void MoeHtml2Wnd::onCreateWebView(std::wstring target, ICoreWebView2Controller* controller)
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

	webview->add_NavigationCompleted(
		make_callback< ICoreWebView2NavigationCompletedEventHandler>(
			[this](ICoreWebView2* webView, ICoreWebView2NavigationCompletedEventArgs* args) 
			{
				BOOL success = FALSE;
				args->get_IsSuccess(&success);
				if(success)
					this->onDocumentLoad();
			}),
		&onDocumentLoadedToken
	);

	webview->add_WebMessageReceived(
		make_callback< ICoreWebView2WebMessageReceivedEventHandler>(
			[this](ICoreWebView2* webView, ICoreWebView2WebMessageReceivedEventArgs* args)
			{
				LPWSTR json = 0;
				args->get_WebMessageAsJson(&json);
				this->onMessage(json);
				::CoTaskMemFree(json);
			}
		), 
		&onMessageToken
	);

	webview->Navigate(target.c_str());
}

void MoeHtml2Wnd::onDocumentLoad()
{
	if (onDocumentLoadHandler)
	{
		EXCEPINFO ex;
		::ZeroMemory(&ex, sizeof(EXCEPINFO));
		UINT e = 0;
		DISPPARAMS p = { 0,0 };
	
		onDocumentLoadHandler->Invoke(DISPID_VALUE, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &p, NULL, &ex, &e);
	}
}


void MoeHtml2Wnd::onMessage(LPCWSTR json)
{
	if (onMessageHandler)
	{
		mol::variant v(json);

		EXCEPINFO ex;
		::ZeroMemory(&ex, sizeof(EXCEPINFO));
		UINT e = 0;
		DISPPARAMS p = { 0,0 };
		p.cArgs = 1;
		p.rgvarg = &v;

		onMessageHandler->Invoke(DISPID_VALUE, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &p, NULL, &ex, &e);
	}
}

handle_msg(&MoeHtml2Wnd::OnClose,WM_CLOSE)
void MoeHtml2Wnd::OnClose()
{
	ODBGS("MoeHtmlWndImpl::OnClose");
}

handle_msg(&MoeHtml2Wnd::OnDestroy, WM_DESTROY)
void MoeHtml2Wnd::OnDestroy()
{
	ODBGS("MoeHtmlWndImpl::OnDestroy");

	if (this->onCloseHandler)
	{
		EXCEPINFO ex;
		::ZeroMemory(&ex, sizeof(EXCEPINFO));
		UINT e = 0;
		DISPPARAMS p = { 0,0 };
		this->onCloseHandler->Invoke(DISPID_VALUE, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &p, NULL, &ex, &e);
	}


	if (oleObject)
	{
		for (auto& it : frame_.objects_)
		{
			webview->RemoveHostObjectFromScript(it.c_str());
		}
		webview->RemoveHostObjectFromScript(L"external");
		webview->remove_DocumentTitleChanged(documentTitleChangedToken);
		webview->remove_NavigationStarting(navigationStartingToken);
		webview->remove_PermissionRequested(permissionRequestToken);
		webview->remove_NavigationCompleted(onDocumentLoadedToken);
		webview->remove_WebMessageReceived(onMessageToken);

		oleObject.release();
	}

	docs()->remove(this);
}


handle_msg(&MoeHtml2Wnd::OnNcDestroy, WM_NCDESTROY)
LRESULT MoeHtml2Wnd::OnNcDestroy()
{
	thumb.destroy();

	if (webViewController)
	{
		webViewController->Close();
		webViewController.release();
	}

	ODBGS("MoeHtmlWndImpl::OnNcDestroy");
	((IMoeDocument*)this)->Release();

	return 0;
}

handle_cmd(&MoeHtml2Wnd::OnCloseAll, IDM_VIEW_CLOSEALL)


std::wstring escape_json_str(const std::wstring& in)
{
	std::wostringstream oss;

	for (auto it = in.begin(); it != in.end(); it++)
	{
		if ((*it) == L'\\' || (*it) == L'\'')
		{
			oss << '\\';
		}
		oss << (*it);
	}
	return oss.str();
}

handle_msg(&MoeHtml2Wnd::OnSearch, WM_SEARCH_MSG)
void MoeHtml2Wnd::OnSearch(FINDREPLACE* fi)
{
	if (!oleObject) return;

	bool down = fi->Flags & FR_DOWN;
	bool caseSensitite = fi->Flags & FR_MATCHCASE;
	bool wholeWord = fi->Flags & FR_WHOLEWORD;

	std::wostringstream oss;

	oss << L"window.find('" << escape_json_str(fi->lpstrFindWhat) << L"', "
		<< caseSensitite << L", " << !down << L", 1, " << wholeWord << ", 1, 1 );";

	webview->ExecuteScript(oss.str().c_str(), nullptr);
}


void MoeHtml2Wnd::onDocumentTitleChanged()
{
	LPWSTR title = nullptr;
	webview->get_DocumentTitle(&title);
	this->setText(title);
	::CoTaskMemFree(title);
}

void MoeHtml2Wnd::onNavigationStarted(ICoreWebView2NavigationStartingEventArgs* args)
{
	LPWSTR uri = nullptr;
	args->get_Uri(&uri);
	if (mol::wcstricmp(uri, L"mol://close") == 0)
	{
		args->put_Cancel(TRUE);
		::CoTaskMemFree(uri);
		postMessage(WM_CLOSE, 0, 0);
		return;
	}

	::CoTaskMemFree(uri);
}

void MoeHtml2Wnd::onPermissionRequest(ICoreWebView2PermissionRequestedEventArgs* args)
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
// external events called from script inside MoeWnd
/////////////////////////////////////////////////////////////////////////////////////////////

MoeHtml2Wnd::ExternalMoe::ExternalMoe()
{}

MoeHtml2Wnd::ExternalMoe::~ExternalMoe()
{
	for (std::map<DWORD, IUnknown*>::iterator it = ctrls.begin(); it != ctrls.end(); it++)
	{
		mol::punk<IConnectionPointContainer>	icPc((*it).second);
		if (icPc)
		{
			mol::punk<IConnectionPoint>			icP;

			HRESULT hr = icPc->FindConnectionPoint(iids[(*it).first], &icP);
			if (S_OK == hr)
			{
				hr = icP->Unadvise((*it).first);
			}
			if (sinks.count((*it).first) > 0)
			{
				sinks[(*it).first]->Release();
				(*it).second->Release();
			}
		}
	}
	sinks.clear();
	ctrls.clear();
	ODBGS("ExternalMoe ~");

}

HRESULT __stdcall MoeHtml2Wnd::ExternalMoe::get_Moe(IDispatch** disp)
{
	if ( !disp )
		return E_INVALIDARG;

	HRESULT hr = ((IMoe*)(moe()))->QueryInterface(IID_IDispatch, (void**)disp );
	if ( hr != S_OK )
		*disp = 0;

	return hr;
}

HRESULT __stdcall MoeHtml2Wnd::ExternalMoe::Close()
{
	This()->postMessage(WM_CLOSE,0,0);
	return S_OK;
}


HRESULT __stdcall MoeHtml2Wnd::ExternalMoe:: get_Frame( IMoeHtmlFrame** f)
{
	if (!f) 
		return E_INVALIDARG;

	return This()->frame_.QueryInterface( IID_IMoeHtmlFrame, (void**) f );
}


HRESULT __stdcall  MoeHtml2Wnd::ExternalMoe::Connect(IUnknown* obj, BSTR event, IDispatch* eventHandler)
{
	IID iid;
	if (S_OK != mol::findSourceOnCP(obj, &iid))
		return S_FALSE;

	DWORD cookie;
	mol::com_obj<ScriptEventHandler>* handler = new mol::com_obj<ScriptEventHandler>;
	handler->AddRef();

	//TODO: assure only to advis IF script handler present
	// use static factory func pattern
	handler->init(iid, mol::bstr(event).towstring(), eventHandler);

	mol::punk<IConnectionPointContainer>	icPc(obj);
	mol::punk<IConnectionPoint>			icP;
	HRESULT hr = icPc->FindConnectionPoint(iid, &icP);
	if (S_OK == hr)
	{
		hr = icP->Advise(handler, &cookie);
	}

	sinks[cookie] = handler;
	obj->AddRef();
	ctrls[cookie] = obj;
	iids[cookie] = iid;


	return S_OK;
}
