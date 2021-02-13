#ifndef MOE_REBAR_DEF_GUARD_
#define MOE_REBAR_DEF_GUARD_

#include "widgets.h"

/////////////////////////////////////////////////////////////////////////////////////////////
// widgets for moe
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
// the document selector tab control
/////////////////////////////////////////////////////////////////////////////////////////////

class  MoeTabControl : public mol::Control< 
									mol::TabCtrl, 
									WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|TCS_BOTTOM|TCS_TOOLTIPS,
									0  > 
{
friend class Docs;
public:

	MoeTabControl();
	virtual ~MoeTabControl();

	void select( HWND d );
	
	// msg handlers
	void OnSelect();
	void OnRightClick();

	void OnMouseDown();
	void OnMouseUp();

	void OnTimer(int id,int unused);
	void OnGetObject(NMOBJECTNOTIFY* notify);

private:

	virtual void OnCtrlCreated();

	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	int  index ( HWND d );
	void remove( HWND d );
	void move  ( HWND what, HWND to );
	void rename( HWND d,const std::wstring& newpath, const std::wstring& name );

	
	// Drag&Drop COM Callback
	class MoeTabControl_Drop : public mol::stack_obj<mol::ole::DropTargetBase>
    {
        public : 
			HRESULT virtual __stdcall Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect);
			HRESULT virtual __stdcall DragEnter( IDataObject*, DWORD, POINTL, DWORD* );
			HRESULT virtual __stdcall DragOver( DWORD, POINTL, DWORD* );
			HRESULT virtual __stdcall DragLeave();
    } Drop;


	bool				isMouseDown_;
	CLIPFORMAT			dragTabFormat_;
};


/////////////////////////////////////////////////////////////////////////////////////////////
// html form window
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeHtmlRibbon :
	public mol::Frame<MoeHtmlRibbon,mol::Window,  WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,0>
{
public:

	mol::punk< ICoreWebView2Controller> webViewController;
	mol::punk< ICoreWebView2> webView;
	mol::punk<IMoeDialogView> view;

	MoeHtmlRibbon();
	~MoeHtmlRibbon();

	void onNavigationStarted(ICoreWebView2NavigationStartingEventArgs* args);
	void onCreateWebView(std::wstring target, ICoreWebView2Controller* controller);
	void onMessageReceived(ICoreWebView2* sender, ICoreWebView2WebMessageReceivedEventArgs* args);

	void handleMessage(Json::Value& json);
	void postMessageAsJSON(const Json::Value& json);
	/////////////////////////////////////////////////////////////////////
	// msg handlers
	/////////////////////////////////////////////////////////////////////

	void OnCreate();
	void OnSize(WPARAM wParam, LPARAM lParam);
	void OnClose();
	void OnNcDestroy();

	void load(mol::punk<ChromeEdge> edge);

	void setAppMode(const std::string& m);

	std::function<void(MoeHtmlRibbon*)> onDocumentLoad;

private:

	/////////////////////////////////////////////////////////////////////
	virtual int style();

	void onDocumentLoaded();

	/////////////////////////////////////////////////////////////////////

	int							style_;
	std::wstring				location_;

	EventRegistrationToken		webMessageReceivedToken;
	EventRegistrationToken		navigationStartingToken;
	EventRegistrationToken		onDocumentLoadedToken;

	/////////////////////////////////////////////////////////////////////
	// external events called from script inside MoeWnd
	/////////////////////////////////////////////////////////////////////

	class ExternalMoe :
		public mol::Dispatch<IExternalMoe>,
		public mol::interfaces< ExternalMoe,
		mol::implements< IDispatch, IExternalMoe> >

	{
	public:
		outer_this(MoeHtmlRibbon, external_);

		ExternalMoe();
		~ExternalMoe();

		virtual HRESULT __stdcall get_Moe(IDispatch** disp);
		virtual HRESULT __stdcall Close();
		virtual HRESULT __stdcall CreateObject(BSTR progId, IDispatch** disp);
		virtual HRESULT __stdcall get_Frame(IMoeHtmlFrame** f);
		virtual HRESULT __stdcall CodeBehind(BSTR fname);
		virtual HRESULT __stdcall get_Code(IDispatch** code);

	};

	mol::stack_obj<ExternalMoe>		external_;

};


/*
/////////////////////////////////////////////////////////////////////////////////////////////
// customizable toolbar
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeToolBar : public mol::Control< mol::CustomToolBar,
					  WS_CHILD|CCS_NORESIZE |CCS_NOPARENTALIGN|
					  CCS_NODIVIDER|TBSTYLE_FLAT|
					  WS_CLIPCHILDREN|TBSTYLE_TOOLTIPS|CCS_ADJUSTABLE ,
					  TBSTYLE_EX_MIXEDBUTTONS  >
{
public:

	// msg handler
	void OnRightClick(NMHDR* notify);

    LRESULT virtual wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)		
    {																					
            return mol::msgMap<MoeToolBar>().call(this,message,wParam,lParam);							
    }	
};

/////////////////////////////////////////////////////////////////////////////////////////////
// the syntax selector cobox control
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeComboBox : public mol::Control< mol::ComboBox, 
					  WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|
					  CBS_DROPDOWNLIST |CBS_HASSTRINGS,
					  0 > 
{};
*/
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// the moe rebar
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/*
class MoeBar : public mol::Control< 
						mol::ReBar,
						WS_CHILD|WS_VISIBLE|
						WS_CLIPCHILDREN|WS_CLIPSIBLINGS|CCS_NODIVIDER|
						RBS_BANDBORDERS|
						RBS_REGISTERDROP,
						WS_EX_TOOLWINDOW >
{
friend class MoeWnd;
public:
	MoeBar()
	{}

	~MoeBar();

    virtual HRESULT __stdcall Load( LPSTREAM pStm);
    virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);

	LRESULT wndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

};

*/
/////////////////////////////////////////////////////////////////////////////////////////////




#endif
