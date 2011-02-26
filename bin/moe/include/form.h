#ifndef _FORM_FRAME_WND_DEF_
#define _FORM_FRAME_WND_DEF_

/////////////////////////////////////////////////////////////////////////////////////////////

#include "shared.h"
#include "widgets.h"
//#include "ax/jre/jre_h.h"

/////////////////////////////////////////////////////////////////////////////////////////////

using namespace mol::win;
using namespace mol::ole;
using namespace mol;
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeWnd;

/////////////////////////////////////////////////////////////////////////////////////////////
// html form window
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeFormWnd  : 
	public mol::ChildFrame<MoeFormWnd,mol::HtmlWnd<MoeFormWnd,Window>>,
	public mol::Dispatch<IMoeHtmlFrame>,
	public interfaces< MoeFormWnd, implements< IDispatch, IMoeHtmlFrame> >
{
public:

	enum styles { TITLE = 1, NOSCROLL = 2, DIALOG = 4, STANDALONE = 8 };

	MoeFormWnd( );
	~MoeFormWnd();

	virtual void dispose() {}

	typedef mol::com_instance<MoeFormWnd> Instance;
	static  Instance* CreateInstance( const mol::string& location, int left,  int top, int width, int height, int style );

	DWORD UIflags();
	HRESULT hideContextMenu();

	mol::punk<IMoeDialogView> view;

    virtual HRESULT __stdcall get_Object( IDispatch **d);    
    virtual HRESULT __stdcall get_View(  IMoeDialogView **d);    
    virtual HRESULT __stdcall get_Scripts(  IDispatch **s);    
    virtual HRESULT __stdcall Eval(  BSTR src, BSTR scriptLanguage);    
    virtual HRESULT __stdcall OleCmd(  long cmd);    
    virtual HRESULT __stdcall get_FilePath(  BSTR *filename);

	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall IDocHostUIHandler_GetExternal( IDispatch **ppDispatch);

	/////////////////////////////////////////////////////////////////////
	// msg handlers
	/////////////////////////////////////////////////////////////////////

	void OnClose();
	void OnNcDestroy();

  private:

	/////////////////////////////////////////////////////////////////////
	void load( const mol::string& loc, int s, Rect& r );
	virtual int style();

	/////////////////////////////////////////////////////////////////////

	int							style_;
	mol::string					location_;

	/////////////////////////////////////////////////////////////////////
	// external events called from script inside MoeWnd
	/////////////////////////////////////////////////////////////////////

	class ExternalMoe : 
		public Dispatch<IExternalMoe>,
		public interfaces< ExternalMoe, 
				implements< IDispatch, IExternalMoe> >

	{
		public : 
			outer_this(MoeFormWnd,external_);

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

	stack_obj<ExternalMoe>		external_;


	/////////////////////////////////////////////////////////////////////
	// webbrowser events
	/////////////////////////////////////////////////////////////////////

	class MoeFormWnd_htmlSink : 
		public stack_obj<mol::ie::ie_event_sink>
	{
		public : 
			outer_this(MoeFormWnd,htmlSink_); 
			HRESULT virtual __stdcall BeforeNavigate2(IDispatch* pDisp, VARIANT* URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers, VARIANT_BOOL* Cancel);
			HRESULT virtual __stdcall DocumentComplete( IDispatch* pDisp,  VARIANT* URL);
			HRESULT virtual __stdcall WindowClosing( VARIANT_BOOL isChildWindow, VARIANT_BOOL* vbCancel );
	
	} htmlSink_;

};

#endif