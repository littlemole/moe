#include "stdafx.h"
#include "MoeBar.h"
#include "moe.h"
#include "app.h"
#include "docs.h"
//#include "xmlui.h"
#include "resource.h"

using namespace mol::io;

using namespace mol;
using namespace mol::ole;
using namespace mol::win;
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

// simple app-internal dragDrop passing a HWND
class TxtDragDrop
{
public:

	// start drag drop
	static int doDragDrop( CLIPFORMAT format, HWND from )
	{
		punk<IDropSource> source = new mol::DropSrc();

		size_t i = moe()->index(from);

		punk<mol::DataTransferObj> ido = new mol::DataTransferObj(true);
		ido->addData(format,(void*)&i,sizeof(size_t));

		DWORD effect;
		if ( DRAGDROP_S_DROP == ::DoDragDrop( 
									ido, 
									source, 
									DROPEFFECT_COPY|DROPEFFECT_MOVE,
									&effect) 
			)
			return effect;

		return DROPEFFECT_NONE;
	}

	// determine wether custom format is avail
	static bool isTxtDragDropFormat( IDataObject* ido, CLIPFORMAT format ) 
	{
		format_etc fe( format );
		HRESULT hr = ido->QueryGetData( &fe);
		if (hr != S_OK )
		{
			return false;
		}
		return true;
	}

	// retrieve dragDrop txt value for custom format from IDataObject
	static HWND getHWND( IDataObject* ido, CLIPFORMAT format )
	{
		format_etc fe( format );

		STGMEDIUM sm;
		HRESULT hr = ido->GetData( &fe, &sm );
		if (hr != S_OK )
			return 0;

		if ( sm.tymed != TYMED_HGLOBAL || !sm.hGlobal )
			return 0;

		HWND hwnd = 0;
		size_t i = 0;
		mol::global::get(sm.hGlobal,i);
		hwnd = moe()->childAt((int)i);

		::ReleaseStgMedium(&sm);
		return hwnd;
	}
};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

MoeTabControl::MoeTabControl()
{
	dragTabFormat_      = ::RegisterClipboardFormat( _T("MoeTabDragDropCustomClipBoardFormat") );
	isMouseDown_ = false;
}


MoeTabControl::~MoeTabControl()
{
}


void MoeTabControl::OnCtrlCreated()
{
	// enable tab ctrl drag drop support
	TabCtrl_SetExtendedStyle(*this,TCS_EX_REGISTERDROP );
}

handle_notify_code(&MoeTabControl::OnSelect, TCN_SELCHANGE)
void MoeTabControl::OnSelect()
{
    int sel = (int)selection();
	mol::TabCtrl::TabCtrlItem* c = getTabCtrlItem(sel);
	HWND h = (HWND)(c->lparam);
	if ( !h ) 
		return;

	mol::MdiChild* mdi = mol::wndFromHWND<mol::MdiChild>(h);
	if (!mdi) 
		return;

	mdi->activate();
    return ;
}

std::wstring dirPathFromChildHWND(HWND hwnd)
{
	// get mdi child from HWND
	mol::MdiChild* mdi = mol::wndFromHWND<mol::MdiChild>(hwnd);
	if (!mdi) 
		return _T("");

	// cast mdi child to IMoeDocument
	IMoeDocument* doc = dynamic_cast<IMoeDocument*>(mdi);
	if (!doc)
		return _T("");

	mol::bstr path;
	if ( doc->get_FilePath(&path) != S_OK )
		return _T("");
	return mol::Path::parentDir(mol::towstring(path));
}

handle_notify_code(&MoeTabControl::OnRightClick, NM_RCLICK)
void MoeTabControl::OnRightClick()
{
	// check whether right click hit a tab
	int i = hitTest();
	if ( i == -1 )
		return ;

	// get right click tab item and retrieve HWND
	mol::TabCtrl::TabCtrlItem* c = (mol::TabCtrl::TabCtrlItem*)tab()->getTabCtrlItem(i);
	HWND h = (HWND)c->lparam;
	if ( !h ) 
		return;

	// current mouse pos
	POINT pt;
	::GetCursorPos(&pt);

	// display context menut
	//mol::Menu sub = mol::UI().SubMenu(IDM_MENU_TAB,IDM_TAB);

	mol::Menu m;
	m.load(IDM_MENU_TAB);

	mol::Menu sub(m.getSubMenu(0));

	// use moe main window as parent for ownerdrawn menus to work on XP
	LONG_PTR id = sub.returnTrackPopup(*moe(),pt.x-10,pt.y-10);
	switch ( id )
	{
		case IDM_VIEW_CLOSE:
		{
			::PostMessage( h, WM_CLOSE, 0, 0 );
			break;
		}
		case IDM_TAB_CLOSEALLBUTTHIS:
		{
			HWND m = h;
			for ( int i = 0; i < count(); i++ )
			{
				if ( moe()->childAt(i) != m )
					::PostMessage(moe()->childAt(i), WM_CLOSE, 0, 0 );
			}
			break;
		}
		case IDM_TAB_RELOADTAB:
		{
			::PostMessage( h, WM_COMMAND, IDM_EDIT_UPDATE, 0 );

			break;
		}
		case IDM_FILE_SAVE:
		{
			::PostMessage( h, WM_COMMAND, IDM_FILE_SAVE, 0 );
			break;
		}
		case IDM_TAB_DIRTAB:
		{
			docs()->OpenDir( mol::bstr(dirPathFromChildHWND(h)), 0 );
			break;
		}
	}
	return ;
}


handle_msg(&MoeTabControl::OnMouseDown, WM_LBUTTONDOWN)
void MoeTabControl::OnMouseDown()
{
	isMouseDown_ = false;

	int i = hitTest();
	if ( i!= -1 )
	{
		// wait a bit might be a drag-drop
		isMouseDown_ = true;
		SetTimer( ID_TABDRAGDROPTIMER, 500 );
	}
}

handle_msg(&MoeTabControl::OnMouseUp, WM_LBUTTONUP)
void MoeTabControl::OnMouseUp()
{
	isMouseDown_ = false;
}


handle_msg(&MoeTabControl::OnTimer, WM_TIMER)
void MoeTabControl::OnTimer(int id,int)
{
	if ( id == ID_TABDRAGDROPTIMER && isMouseDown_)
	{
		KillTimer(ID_TABDRAGDROPTIMER);
		isMouseDown_ = false;
		int i = hitTest();
		if ( i!= -1 )
		{
			// do a simple dragDrop
			mol::TabCtrl::TabCtrlItem* c = getTabCtrlItem(i);
			TxtDragDrop::doDragDrop( dragTabFormat_, (HWND)(c->lparam) );
		}
	}
}

handle_notify_code(&MoeTabControl::OnGetObject, TCN_GETOBJECT)
void MoeTabControl::OnGetObject(NMOBJECTNOTIFY* notify)
{
	// return our drop source for a drag-drop event
	notify->hResult = E_FAIL;
	IID iid = *(notify->piid);
	if ( ::IsEqualIID( IID_IDropTarget, iid) )
	{
		notify->pObject = (IUnknown*)&Drop;
		notify->hResult = S_OK;
	}
}


// helpers

int MoeTabControl::index( HWND d )
{
	for ( int i = 0; i < count(); i++ )
	{
		mol::TabCtrl::TabCtrlItem* c = getTabCtrlItem(i);
		HWND mdi = (HWND)(c->lparam);
		if ( mdi == d )
		{
			return i;
		}
	}
	return -1;
}

void MoeTabControl::select( HWND d )
{
	int i = index(d);
	if ( i == -1 )
		return;

	mol::TabCtrl::select(i);
}

void MoeTabControl::move( HWND what, HWND to )
{	
	int iwhat = index(what);
	if ( iwhat == -1 )
		return;

	int ito = index(to);
	if ( ito == -1 )
		return;

	mol::TabCtrl::TabCtrlItem* c = getTabCtrlItem(iwhat);
	mol::TabCtrl::TabCtrlItem* tiwhat = new mol::TabCtrl::TabCtrlItem(c->title,c->tooltip,c->lparam);

	removeItem(iwhat);

	ito = index(to);
	if ( ito == -1 )
		return;

	insertItem( tiwhat, ito );
}

void MoeTabControl::remove( HWND d )
{
	int i = index(d);
	if ( i == -1 )
		return;

	removeItem(i);
}

void MoeTabControl::rename( HWND d, const std::wstring& newpath, const std::wstring& name )
{
	int i = index(d);
	if ( i == -1 )
		return;

	mol::TabCtrl::TabCtrlItem* c = getTabCtrlItem(i);
	mol::TabCtrl::TabCtrlItem* nc = new mol::TabCtrl::TabCtrlItem(name,newpath,c->lparam);
	renameItem( nc, i );
}



//////////////////////////////////////////////////////////////////////////////////
// msgmap support for event handling
//////////////////////////////////////////////////////////////////////////////////


LRESULT MoeTabControl::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return mol::msgMap<MoeTabControl>().call(this,message,wParam,lParam);	
}


//////////////////////////////////////////////////////////////////////////////
//
// Drag & Drop_ Support 
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeTabControl::MoeTabControl_Drop::Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect)
{
	*pEffect = DROPEFFECT_NONE;

	ODBGS("Tab Drop");
	// get the dropped tabs path
	HWND from = TxtDragDrop::getHWND( pDataObject, tab()->dragTabFormat_ );

	if ( !from )
		return S_OK;

	if(!::IsWindow(from))
		return S_OK;

	mol::MdiChild* m = mol::wndFromHWND<mol::MdiChild>(from);
	if (!m)
		return S_OK;

	// determine drop target tab
	int index = tab()->hitTest();
	int cur = (int)tab()->selection();
	/*
	if ( index == cur )
	{
		*pEffect = DROPEFFECT_NONE;
		return S_OK;
	}
	*/
	if ( index == -1 )
		index = (int)tab()->count();
	if ( index == -1 )
		index = 0;

	if ( index == tab()->index(from) )
		return S_OK;

	docs()->move( m, index );

	// clear highlight bits from tabctrl
	for ( int i = 0; i < tab()->count(); i++ )
		tab()->postMessage(TCM_HIGHLIGHTITEM,i,false);

	*pEffect = DROPEFFECT_NONE;
	return S_OK;
}

HRESULT  __stdcall MoeTabControl::MoeTabControl_Drop::DragEnter( IDataObject* pDataObject, DWORD , POINTL , DWORD* pEffect )
{
	ODBGS("Tab Drag Enter");
	if ( !TxtDragDrop::isTxtDragDropFormat(pDataObject,tab()->dragTabFormat_) )
	{
		*pEffect = DROPEFFECT_NONE;
		 return S_OK;
	}
 
	return S_OK;
}

HRESULT __stdcall MoeTabControl::MoeTabControl_Drop::DragOver( DWORD, POINTL, DWORD* pEffect )
{
	ODBGS("Tab Drag Over");
	*pEffect &= DROPEFFECT_COPY;
    return S_OK;
}


HRESULT  __stdcall MoeTabControl::MoeTabControl_Drop::DragLeave()
{
	ODBGS("Tab Drag Leave");
    return S_OK;
}




/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/*
void MoeToolBar::OnRightClick(NMHDR* notify)
{
	if ( moe()->toolbarFrozen() )
		return ;

	switch ( notify ->idFrom )
	{
		case IDC_TOOLBARS_FILEBAR    :
		case IDC_TOOLBARS_EDITBAR    :
		case IDC_TOOLBARS_TOOLBAR    :
		case IDC_TOOLBARS_SETTINGBAR :
		case IDC_TOOLBARS_VIEWBAR    :
		case IDC_TOOLBARS_USERBAR    :
			::SendMessage( mol::UI().hWnd((unsigned int)notify->idFrom), TB_CUSTOMIZE, 0,0 );
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

MoeBar::~MoeBar()
{
	ODBGS("~MoeBar");
}

HRESULT __stdcall MoeBar::Load( LPSTREAM pStm)
{
	mol::ReBar::Load(pStm);
	int n = this->count();

	if ( n > 0 )
	for ( int i = 0; i < n-1; i++)
		postMessage(RB_MAXIMIZEBAND,i, 0 );

	//redraw();
	return S_OK;
}

HRESULT __stdcall MoeBar::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	mol::ReBar::Save(pStm, fClearDirty);
	return S_OK;
}

LRESULT MoeBar::wndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_CREATE :
		{
			RECT r;
			::GetClientRect(*this,&r);
			postMessage(WM_SIZE,0,MAKELPARAM(r.right,r.bottom));
			redraw();
			break;
		}
	}
	return mol::ReBar::wndProc(wnd,msg,wParam,lParam);
}

*/

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

MoeHtmlRibbon::MoeHtmlRibbon()
{
	eraseBackground_ = 1;
//	wndClass().setIcon(moe()->icon);
//	wndClass().hIconSm(moe()->icon);
}


MoeHtmlRibbon::~MoeHtmlRibbon()
{
	ODBGS("~MoeHtmlRibbon() dropped dead");
}

handle_msg(&MoeHtmlRibbon::OnCreate,WM_CREATE)
void MoeHtmlRibbon::OnCreate()
{
}

void MoeHtmlRibbon::postMessageAsJSON(const Json::Value& json)
{
	std::string utf8 = JSON::flatten(json);
	webView->PostWebMessageAsJson(mol::fromUTF8(utf8).c_str());
}

void MoeHtmlRibbon::load(mol::punk<ChromeEdge> edge)
{
	std::wstring l = mol::app<MoeApp>().CreateAppPath(L"moe");
	location_ = l + L"\\ui\\ribbon.html";

	edge->createWebView(hWnd_, [this](HRESULT hr, ICoreWebView2Controller* controller)
	{
		this->onCreateWebView(location_, controller);
	});
}

void MoeHtmlRibbon::setAppMode(const std::string& m)
{
	std::ostringstream oss;
	oss << "{ \"appmode\" : \"" << m << "\" }";
	webView->PostWebMessageAsJson(mol::towstring(oss.str()).c_str());
}

void getActiveDocProperties(IScintillAxProperties** ax)
{
	*ax = 0;

	mol::punk<IMoeDocument> doc;
	moe()->get_ActiveDoc(&doc);

	if (!doc) return;

	long type = 0;
	doc->get_Type(&type);

	if (type != MOE_DOCTYPE_DOC) return;

	mol::punk<IDispatch> disp;
	doc->get_Object(&disp);

	if (!disp) return;

	mol::punk<IScintillAx> sci(disp);
	if (!sci) return;

	mol::punk<IScintillAxProperties> props;
	sci->get_Properties(ax);
}

void setActiveDocLongProperty(HRESULT(__stdcall IScintillAxProperties::* mfp)(long), long value) 
{
	mol::punk<IScintillAxProperties> props;
	getActiveDocProperties(&props);
	if (!props) return;

	(props->*mfp)(value);
}

void setActiveDocBooleanProperty(HRESULT(__stdcall IScintillAxProperties::* mfp)(VARIANT_BOOL), bool value)
{
	mol::punk<IScintillAxProperties> props;
	getActiveDocProperties(&props);
	if (!props) return;

	(props->*mfp)(value ? VARIANT_TRUE : VARIANT_FALSE);
}

static std::map<std::string, std::function<void(Json::Value)>> webMsgActionHandlers =
{
	{ "recent", [](Json::Value msg) 
		{ 				
			std::string path = msg["recent"].asString();
			mol::punk<IMoeDocument> doc;
			moe()->moeDialogs->Open(mol::bstr(path), &doc);
		} 
	},
	{ "enc", [](Json::Value msg) 
		{ 
			const int enc = atoi(msg["enc"].asString().c_str());
			setActiveDocLongProperty(&IScintillAxProperties::put_Encoding, enc);		
		}
	},
	{ "syntax", [](Json::Value msg) 
		{ 
			const int syntax = atoi(msg["syntax"].asString().c_str());
			setActiveDocLongProperty(&IScintillAxProperties::put_Syntax, syntax);		
		}
	},
	{ "eol", [](Json::Value msg)
		{
			const int eol = atoi(msg["eol"].asString().c_str());
			setActiveDocLongProperty(&IScintillAxProperties::put_SysType, eol);
		}
	},
	{ "tabs", [](Json::Value msg)
		{
			const bool tabs = msg["tabs"].asBool();
			setActiveDocBooleanProperty(&IScintillAxProperties::put_TabUsage, tabs);
		}
	},
	{ "tabindents", [](Json::Value msg)
		{
			const bool tabindents = msg["tabindents"].asBool();
			setActiveDocBooleanProperty(&IScintillAxProperties::put_TabIndents, tabindents);
		}
	},
	{ "backspaceunindents", [](Json::Value msg)
		{
			const bool backspaceunindents = msg["backspaceunindents"].asBool();
			setActiveDocBooleanProperty(&IScintillAxProperties::put_BackSpaceUnindents, backspaceunindents);
		}
	},
	{ "tabwidth", [](Json::Value msg)
		{
			const long tabwidth = atoi(msg["tabwidth"].asString().c_str());
			setActiveDocLongProperty(&IScintillAxProperties::put_TabWidth, tabwidth);
		}
	},
	{ "bom", [](Json::Value msg)
		{
			const bool bom = msg["bom"].asBool();
			setActiveDocBooleanProperty(&IScintillAxProperties::put_WriteBOM, bom);
		}
	},
	{ "lines", [](Json::Value msg)
		{
			const bool lines = msg["lines"].asBool();
			setActiveDocBooleanProperty(&IScintillAxProperties::put_ShowLineNumbers, lines);
		}
	},
	{ "script", [](Json::Value msg)
		{
			const std::string script = msg["script"].asString();
			moe()->moeScript->Run(mol::bstr(script), mol::bstr("JScript"));
		}
	},
	{ "system", [](Json::Value msg)
		{
			const std::string system = msg["system"].asString();
			moe()->moeScript->System(mol::bstr(system));
		}
	},
	{ "showexplorer", [](Json::Value msg)
		{
			const std::string showexplorer = msg["showexplorer"].asString();
			VARIANT_BOOL vb = showexplorer == "true" ? VARIANT_TRUE : VARIANT_FALSE;
			moe()->moeConfig->put_ShowTreeView(vb);
		}
	}
};

void handleAction(Json::Value msg)
{
	std::string action = msg["action"].asString();
	if (!msg.isMember(action))
	{
		return;
	}
	if (webMsgActionHandlers.count(action) == 0)
	{
		return;
	}
	webMsgActionHandlers[action](msg);
}

static std::map<std::string, std::function<void(Json::Value)>> webMsgHandlers =
{
	{ "cmd",	[](Json::Value msg) { moe()->postMessage(WM_COMMAND, msg["cmd"].asInt(), 0);  } },
	{ "msg",	[](Json::Value msg) { moe()->postMessage(msg["msg"].asInt(), 0, 0);  } },
	{ "action",	[](Json::Value msg) { handleAction(msg); } }
};

void MoeHtmlRibbon::handleMessage(Json::Value& json)
{
	for (auto it = webMsgHandlers.begin(); it != webMsgHandlers.end(); it++)
	{
		std::string key = (*it).first;
		if (json.isMember(key))
		{
			(*it).second(json);
			return;
		}
	}
	/*
	if (json.isMember("cmd"))
	{
		int cmd = json["cmd"].asInt();
		moe()->postMessage(WM_COMMAND, cmd, 0);
		return;
	}
	if (json.isMember("msg"))
	{
		int msg = json["msg"].asInt();
		moe()->postMessage(msg, 0, 0);
		return;
	}
	if (json.isMember("action"))
	{
		std::string action = json["action"].asString();
		if (action == "recent")
		{
			if (json.isMember("recent"))
			{
				std::string path = json["recent"].asString();

				mol::punk<IMoeDocument> doc;
				moe()->moeDialogs->Open(mol::bstr(path), &doc);
			}
			return;
		}
		if (action == "enc")
		{
			if (json.isMember("enc"))
			{
				const int enc = atoi(json["enc"].asString().c_str());

				setActiveDocLongProperty(&IScintillAxProperties::put_Encoding, enc);
			}
			return;
		}
		if (action == "syntax")
		{
			if (json.isMember("syntax"))
			{
				const int syntax = atoi(json["syntax"].asString().c_str());

				setActiveDocLongProperty(&IScintillAxProperties::put_Syntax, syntax);
			}
		}
		if (action == "eol")
		{
			if (json.isMember("eol"))
			{
				const int eol = atoi(json["eol"].asString().c_str());

				setActiveDocLongProperty(&IScintillAxProperties::put_SysType, eol);
			}
		}
		if (action == "tabs")
		{
			if (json.isMember("tabs"))
			{
				const bool tabs = json["tabs"].asBool();

				setActiveDocBooleanProperty(&IScintillAxProperties::put_TabUsage, tabs);
			}
		}
		if (action == "tabindents")
		{
			if (json.isMember("tabindents"))
			{
				const bool tabindents = json["tabindents"].asBool();

				setActiveDocBooleanProperty(&IScintillAxProperties::put_TabIndents, tabindents);
			}
		}
		if (action == "backspaceunindents")
		{
			if (json.isMember("backspaceunindents"))
			{
				const bool backspaceunindents = json["backspaceunindents"].asBool();

				setActiveDocBooleanProperty(&IScintillAxProperties::put_BackSpaceUnindents, backspaceunindents);
			}
		}
		if (action == "tabwidth")
		{
			if (json.isMember("tabwidth"))
			{
				const long tabwidth = atoi(json["tabwidth"].asString().c_str());

				setActiveDocLongProperty(&IScintillAxProperties::put_TabWidth, tabwidth);
			}
		}
		if (action == "bom")
		{
			if (json.isMember("bom"))
			{
				const bool bom = json["bom"].asBool();

				setActiveDocBooleanProperty(&IScintillAxProperties::put_WriteBOM, bom);
			}
		}
		if (action == "lines")
		{
			if (json.isMember("lines"))
			{
				const bool lines = json["lines"].asBool();

				setActiveDocBooleanProperty(&IScintillAxProperties::put_ShowLineNumbers, lines);
			}
		}
		if (action == "script")
		{
			if (json.isMember("script"))
			{
				const std::string script = json["script"].asString();

				moe()->moeScript->Run(mol::bstr(script), mol::bstr("JScript"));
			}
		}
		if (action == "system")
		{
			if (json.isMember("system"))
			{
				const std::string system = json["system"].asString();

				moe()->moeScript->System(mol::bstr(system));
			}
		}
		if (action == "showexplorer")
		{
			if (json.isMember("showexplorer"))
			{
				const std::string showexplorer = json["showexplorer"].asString();

				VARIANT_BOOL vb = showexplorer == "true" ? VARIANT_TRUE : VARIANT_FALSE;

				moe()->moeConfig->put_ShowTreeView(vb);
			}
		}
		return;
	}
*/
}

void  MoeHtmlRibbon::onMessageReceived(ICoreWebView2* sender, ICoreWebView2WebMessageReceivedEventArgs* args)
{
	wchar_t* msg = 0;
	HRESULT hr = args->get_WebMessageAsJson(&msg);

	if (hr != S_OK)
		return;

	std::wstring message(msg);
	::CoTaskMemFree(msg);

	std::string utf8(mol::toUTF8(message));

	Json::Value json = JSON::parse(utf8);

	handleMessage(json);
}

void MoeHtmlRibbon::onCreateWebView(std::wstring target, ICoreWebView2Controller* controller)
{
	webViewController = controller;

	webViewController->get_CoreWebView2(&webView);

	mol::punk<IDispatch> disp(&external_);
	mol::variant obj(disp);
	webView->AddHostObjectToScript(L"external", &obj);

	webView->add_NavigationStarting(
		make_callback<ICoreWebView2NavigationStartingEventHandler>(
			[this](ICoreWebView2* webView, ICoreWebView2NavigationStartingEventArgs* args)
		{
			this->onNavigationStarted(args);
		}),
		&navigationStartingToken
	);

	webView->add_WebMessageReceived(
		make_callback<ICoreWebView2WebMessageReceivedEventHandler>(
			[this](ICoreWebView2* sender, ICoreWebView2WebMessageReceivedEventArgs* args)
		{
			this->onMessageReceived(sender,args);
		}),
		&webMessageReceivedToken
	);

	webView->add_NavigationCompleted(
		make_callback< ICoreWebView2NavigationCompletedEventHandler>(
			[this](ICoreWebView2* webView, ICoreWebView2NavigationCompletedEventArgs* args)
		{
			BOOL success = FALSE;
			args->get_IsSuccess(&success);
			if (success)
				this->onDocumentLoaded();
		}),
		&onDocumentLoadedToken
	);

	webView->Navigate(target.c_str());
}

void MoeHtmlRibbon::onDocumentLoaded()
{
	Json::Value result(Json::objectValue);
	result["action"] = "enc";

	Json::Value encodings(Json::arrayValue);
	for (auto it = codePages()->begin(); it != codePages()->end(); it++)
	{
		const int cp = (*it).first;
		std::wstring n = (*it).second;

		Json::Value codepage(Json::objectValue);
		codepage["value"] = cp;
		codepage["name"] = mol::toUTF8(n);

		encodings.append(codepage);
	}

	result["enc"] = encodings;

	std::string utf8 = JSON::stringify(result);

	webView->PostWebMessageAsJson(mol::towstring(utf8).c_str());

	if (onDocumentLoad)
	{
		onDocumentLoad(this);
	}
}

void MoeHtmlRibbon::onNavigationStarted(ICoreWebView2NavigationStartingEventArgs* args)
{
	/*
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
	*/
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

handle_msg(&MoeHtmlRibbon::OnSize, WM_SIZE)
void MoeHtmlRibbon::OnSize(WPARAM wParam, LPARAM lParam)
{
	if (webViewController)
	{
		RECT bounds;
		GetClientRect(hWnd_, &bounds);
		webViewController->put_Bounds(bounds);
	};

}

handle_msg(&MoeHtmlRibbon::OnClose, WM_CLOSE)
void MoeHtmlRibbon::OnClose()
{
	ODBGS("MoeHtmlRibbon::OnClose");
}

handle_msg(&MoeHtmlRibbon::OnNcDestroy, WM_NCDESTROY)
void MoeHtmlRibbon::OnNcDestroy()
{
	ODBGS("MoeHtmlRibbon::OnNcDestroy");

	if (webView)
	{
		webView->RemoveHostObjectFromScript(L"external");	

		webView->remove_WebMessageReceived(webMessageReceivedToken);
		webView->remove_NavigationStarting(navigationStartingToken);
		webView->remove_NavigationCompleted(onDocumentLoadedToken);
		webView.release();

		webViewController->Close();
		webViewController.release();
	}

	::CoDisconnectObject(((IExternalMoe*)&external_), 0);

	//delete this;
	ODBGS("~MoeFormWnd()OnNcDestroy --");
}


/////////////////////////////////////////////////////////////////////////////////////////////


int MoeHtmlRibbon::style()
{
	static int s = WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	return s | WS_VISIBLE | WS_CHILD;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
// external events called from script inside MoeWnd
/////////////////////////////////////////////////////////////////////////////////////////////

MoeHtmlRibbon::ExternalMoe::ExternalMoe()
{
}

MoeHtmlRibbon::ExternalMoe::~ExternalMoe()
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
	ODBGS("MoeHtmlRibbon::ExternalMoe ~");
}

HRESULT __stdcall MoeHtmlRibbon::ExternalMoe::get_Moe(IDispatch** disp)
{
	if (!disp)
		return E_INVALIDARG;

	HRESULT hr = ((IMoe*)(moe()))->QueryInterface(IID_IDispatch, (void**)disp);
	if (hr != S_OK)
		*disp = 0;

	return hr;
}



HRESULT __stdcall MoeHtmlRibbon::ExternalMoe::Close()
{
	ODBGS("MoeHtmlRibbon::ExternalMoe::Close()");
	moe()->postMessage(WM_CLOSE, 0, 0);
	return S_OK;
}

HRESULT __stdcall MoeHtmlRibbon::ExternalMoe::get_Frame(IMoeHtmlFrame** f)
{
	if (!f)
		return E_INVALIDARG;
	return E_NOTIMPL;
}


HRESULT __stdcall  MoeHtmlRibbon::ExternalMoe::Connect(IUnknown* obj, BSTR event, IDispatch* eventHandler)
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

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
