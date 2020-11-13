#ifndef _FORM2_FRAME_WND_DEF_
#define _FORM2_FRAME_WND_DEF_

/////////////////////////////////////////////////////////////////////////////////////////////

#include "widgets.h"

/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////

class MoeWnd;

/////////////////////////////////////////////////////////////////////////////////////////////
// html form window
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeForm2Wnd  : 
	public mol::ChildFrame<MoeForm2Wnd, mol::Window>,
	public mol::Dispatch<IMoeHtmlFrame>,
	public mol::interfaces< MoeForm2Wnd, mol::implements< IDispatch, IMoeHtmlFrame> >
{
public:

	enum styles { TITLE = 1, NOSCROLL = 2, DIALOG = 4, STANDALONE = 8 };

	mol::punk< ICoreWebView2Controller> webViewController;
	mol::punk< ICoreWebView2> oleObject;
	mol::punk<IMoeDialogView> view;

	MoeForm2Wnd( );
	~MoeForm2Wnd();

	virtual void dispose() {}

	typedef mol::com_instance<MoeForm2Wnd> Instance;
	static  Instance* CreateInstance( const std::wstring& location, int left,  int top, int width, int height, int style );

	void onDocumentTitleChanged();
	void onNavigationStarted(ICoreWebView2NavigationStartingEventArgs* args);
	void onPermissionRequest(ICoreWebView2PermissionRequestedEventArgs* args);
	void onCreateWebView(std::wstring target, ICoreWebView2Controller* controller);

	virtual HRESULT __stdcall get_onDocumentLoad(IDispatch** d);
	virtual HRESULT __stdcall put_onDocumentLoad(IDispatch* d);
	virtual HRESULT __stdcall get_onMessage(IDispatch** d);
	virtual HRESULT __stdcall put_onMessage(IDispatch* d);
	virtual HRESULT __stdcall PostMessage2WebView(BSTR json);
	virtual HRESULT __stdcall get_View(IMoeDialogView** d);
	virtual HRESULT __stdcall get_Scripts(IDispatch** s);
	virtual HRESULT __stdcall Eval(BSTR src, IDispatch* future);
	virtual HRESULT __stdcall OleCmd(long cmd);
	virtual HRESULT __stdcall get_FilePath(BSTR* filename);

	/////////////////////////////////////////////////////////////////////
	// msg handlers
	/////////////////////////////////////////////////////////////////////

	void OnClose();
	void OnNcDestroy();

	void cut();
	void copy();
	void paste();

  private:

	/////////////////////////////////////////////////////////////////////
	void load( const std::wstring& loc, int s, mol::Rect& r );
	virtual int style();

	void onDocumentLoad();

	/////////////////////////////////////////////////////////////////////

	int							style_;
	std::wstring					location_;

	EventRegistrationToken		documentTitleChangedToken;
	EventRegistrationToken		navigationStartingToken;
	EventRegistrationToken		permissionRequestToken;

	/////////////////////////////////////////////////////////////////////
	// external events called from script inside MoeWnd
	/////////////////////////////////////////////////////////////////////

	class ExternalMoe : 
		public mol::Dispatch<IExternalMoe>,
		public mol::interfaces< ExternalMoe, 
				mol::implements< IDispatch, IExternalMoe> >

	{
		public : 
			outer_this(MoeForm2Wnd,external_);

		ExternalMoe();
		~ExternalMoe();

		virtual HRESULT __stdcall get_Moe(IDispatch** disp);
		virtual HRESULT __stdcall Close();
		virtual HRESULT __stdcall CreateObject( BSTR progId, IDispatch** disp);
		virtual HRESULT __stdcall get_Frame( IMoeHtmlFrame** f);
		virtual HRESULT __stdcall CodeBehind( BSTR fname );
		virtual HRESULT __stdcall get_Code( IDispatch** code );

	};

	mol::stack_obj<ExternalMoe>		external_;

};



#endif

