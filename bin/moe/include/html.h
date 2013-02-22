#ifndef _HTML_FRAME_WND_DEF_
#define _HTML_FRAME_WND_DEF_

/////////////////////////////////////////////////////////////////////////////////////////////

#include "widgets.h"

class TaskbarWnd;
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
class MoeWnd;
/////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////
	  
/////////////////////////////////////////////////////////////////////////////////////////////
// html form window
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeHtmlWnd 
	: public MoeChild<
				MoeHtmlWnd,
				mol::HtmlWnd<MoeHtmlWnd,mol::MdiChild>,
				MOE_DOCTYPE_HTML,
				IDM_MOE_HTML
			>
{
public:

	enum styles { TITLE = 1, NOSCROLL = 2, DIALOG = 4, STANDALONE = 8 };

	MoeHtmlWnd( );
	~MoeHtmlWnd();

	static  Instance* CreateInstance( const mol::string& location );

	void OnClose();
	void OnDestroy();
	void OnNcDestroy();

	void OnSearch( FINDREPLACE* find );

	void OnMDIActivate( HWND activated );

	// htmlwnd base class overrides - customize IE impl
	DWORD UIflags();
	HRESULT hideContextMenu();
	virtual HRESULT __stdcall IDocHostUIHandler_GetExternal( IDispatch **ppDispatch);

   virtual HRESULT __stdcall get_FilePath( BSTR *fname)
   {
		if ( fname  )
		{
			*fname = 0;
			*fname = ::SysAllocString( mol::towstring(location).c_str() );
		}
		return S_OK;
   }

protected:

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	class MoeFrame :
			public mol::Dispatch<IMoeHtmlFrame>,
			public mol::interfaces< MoeFrame, mol::implements< IDispatch, IMoeHtmlFrame> >
	{
	public:
		outer_this(MoeHtmlWnd,frame_)

		MoeFrame();
		~MoeFrame();


		mol::punk<IMoeDialogView> view;

		virtual HRESULT __stdcall get_Object( IDispatch **d);    
		virtual HRESULT __stdcall get_View(  IMoeDialogView **d);    
		virtual HRESULT __stdcall get_Scripts(  IDispatch **s);    
		virtual HRESULT __stdcall Eval(  BSTR src, BSTR scriptLanguage);    
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
			outer_this(MoeHtmlWnd,external_);

			ExternalMoe();
			~ExternalMoe();

			virtual HRESULT __stdcall get_Moe(IMoe** disp);
			virtual HRESULT __stdcall Close();
			virtual HRESULT __stdcall CreateObject( BSTR progId, IDispatch** disp);
			virtual HRESULT __stdcall get_Frame( IMoeHtmlFrame** f);
			virtual HRESULT __stdcall CodeBehind( BSTR fname );
			virtual HRESULT __stdcall get_Code( IDispatch** code );

		private:

	};
	mol::stack_obj<ExternalMoe>		external_;


	/////////////////////////////////////////////////////////////////////
	// webbrowser events
	/////////////////////////////////////////////////////////////////////

	class MoeHtmlWnd_htmlSink : 
		public mol::stack_obj<mol::ie::ie_event_sink>
	{
		public : 
			outer_this(MoeHtmlWnd,htmlSink);
			HRESULT virtual __stdcall BeforeNavigate2(IDispatch* pDisp, VARIANT* URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers, VARIANT_BOOL* Cancel);
			HRESULT virtual __stdcall DocumentComplete( IDispatch* pDisp,  VARIANT* URL);
			HRESULT virtual __stdcall WindowClosing( VARIANT_BOOL isChildWindow, VARIANT_BOOL* vbCancel );
	} htmlSink;
	
private:
	int							style_;
	mol::bstr					filename_;
	mol::string					location;

	bool load( const mol::string& loc );
};

#endif