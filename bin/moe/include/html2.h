#ifndef _HTML2_FRAME_WND_DEF_
#define _HTML2_FRAME_WND_DEF_

/////////////////////////////////////////////////////////////////////////////////////////////

#include "widgets.h"
#include "mdichild.h"

class TaskbarWnd;
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
class MoeWnd;
/////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// html form window
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeHtml2Wnd 
	: public MoeChild<
				MoeHtml2Wnd,
				mol::MdiChild,
				MOE_DOCTYPE_HTML,
				IDM_MOE_HTML
			>
{
public:

	enum styles { TITLE = 1, NOSCROLL = 2, DIALOG = 4, STANDALONE = 8 };

	mol::punk< ICoreWebView2Controller> webViewController;
	mol::punk< ICoreWebView2> oleObject;

	mol::punk<IDispatch> onDocumentLoadHandler;
	mol::punk<IDispatch> onMessageHandler;

	MoeHtml2Wnd( );
	~MoeHtml2Wnd();

	static  Instance* CreateInstance( const std::wstring& location );

	void OnClose();
	void OnDestroy();
	LRESULT OnNcDestroy();

	void OnSize(WPARAM wParam, LPARAM lParam);

	void OnSearch( FINDREPLACE* find );

	void OnMDIActivate( HWND activated );

	void onDocumentTitleChanged();
	void onNavigationStarted(ICoreWebView2NavigationStartingEventArgs* args);
	void onPermissionRequest(ICoreWebView2PermissionRequestedEventArgs* args);
	void onCreateWebView(std::wstring target, ICoreWebView2Controller* controller);

   virtual HRESULT __stdcall get_FilePath( BSTR *fname)
   {
		if ( fname  )
		{
			*fname = 0;
			*fname = ::SysAllocString( mol::towstring(location).c_str() );
		}
		return S_OK;
   }

   void back();
   void forward();
   void reload();
   void options();
   void print();
   void cut();
   void copy();
   void paste();
   void stop();

protected:

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	class MoeFrame :
			public mol::Dispatch<IMoeHtmlFrame>,
			public mol::interfaces< MoeFrame, mol::implements< IDispatch, IMoeHtmlFrame> >
	{
	public:
		outer_this(MoeHtml2Wnd,frame_)

		MoeFrame();
		~MoeFrame();


		mol::punk<IMoeDialogView> view;

		virtual HRESULT __stdcall get_onDocumentLoad( IDispatch **d);
		virtual HRESULT __stdcall put_onDocumentLoad(IDispatch* d);
		virtual HRESULT __stdcall get_onMessage(IDispatch** d);
		virtual HRESULT __stdcall put_onMessage(IDispatch* d);
		virtual HRESULT __stdcall PostMessage2WebView(BSTR json);
		virtual HRESULT __stdcall get_View(  IMoeDialogView **d);
		virtual HRESULT __stdcall get_Scripts(  IDispatch **s);    
		virtual HRESULT __stdcall Eval(  BSTR src,  IDispatch* future);    
		virtual HRESULT __stdcall OleCmd(  long cmd);    
		virtual HRESULT __stdcall get_FilePath(  BSTR *filename);

	};
	mol::stack_obj<MoeFrame> frame_;

	/////////////////////////////////////////////////////////////////////
	// external events called from script inside MoeWnd
	/////////////////////////////////////////////////////////////////////

	class ExternalMoe : 
		public mol::Dispatch<IExternalMoe>,
		public mol::interfaces< ExternalMoe, 
				mol::implements< IDispatch, IExternalMoe> >
	{
		public : 
			outer_this(MoeHtml2Wnd,external_);

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


	
private:
	int							style_;
	mol::bstr					filename_;
	std::wstring				location;
	EventRegistrationToken		documentTitleChangedToken;
	EventRegistrationToken		navigationStartingToken;
	EventRegistrationToken		permissionRequestToken;
	EventRegistrationToken		onDocumentLoadedToken;
	EventRegistrationToken		onMessageToken;

	bool load( const std::wstring& loc );

	void onDocumentLoad();
	void onMessage(LPCWSTR json);
};

#endif