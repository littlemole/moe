#ifndef _HTML_FRAME_WND_DEF_
#define _HTML_FRAME_WND_DEF_

/////////////////////////////////////////////////////////////////////////////////////////////

#include "Dot.h"
#include "shared.h"
#include "widgets.h"
#include "ax/jre/jre_h.h"


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
class MoeWnd;
/////////////////////////////////////////////////////////////////////////////////////////////

//using namespace mol::win;
//using namespace mol::ole;
//using namespace mol;

/////////////////////////////////////////////////////////////////////////////////////////////
	  
/////////////////////////////////////////////////////////////////////////////////////////////
// html form window
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeHtmlWnd  : 
	public mol::MdiChildFrame<MoeHtmlWnd,mol::HtmlWnd<MoeHtmlWnd,mol::MdiChild>>,
	public DispatchMidiWindow<MoeHtmlWnd,IMoeDocument,MOE_DOCTYPE_HTML>,
	public mol::ProvideClassInfo<MoeHtmlWnd>,
	public mol::interfaces< MoeHtmlWnd, 
			mol::implements< 
				IDispatch, 
				IMoeDocument, 
				IProvideClassInfo> >
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

	/////////////////////////////////////////////////////////////////////
	// public COM api
	/////////////////////////////////////////////////////////////////////
/*
	virtual HRESULT __stdcall get_Filename( BSTR* filename);
	virtual HRESULT __stdcall get_Path( BSTR* dirpath);
	virtual HRESULT __stdcall get_Type( long* type);
	virtual HRESULT __stdcall Close();
	virtual HRESULT __stdcall Activate();
*/
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

		/////////////////////////////////////////////////////////////////////
/*
		virtual HRESULT __stdcall get_Top( long* top);
		virtual HRESULT __stdcall put_Top( long top);
		virtual HRESULT __stdcall get_Left( long* left);
		virtual HRESULT __stdcall put_Left( long left);
		virtual HRESULT __stdcall get_Width( long* width);
		virtual HRESULT __stdcall put_Width( long width);
		virtual HRESULT __stdcall get_Height( long* width);
		virtual HRESULT __stdcall put_Height( long width);

		virtual HRESULT __stdcall Eval( BSTR src, BSTR scrptLanguage );
		virtual HRESULT __stdcall get_Document( IDispatch** doc);
		virtual HRESULT __stdcall get_Title( BSTR* title);
		virtual HRESULT __stdcall put_Title( BSTR  title);
		virtual HRESULT __stdcall Close();
		virtual HRESULT __stdcall get_Scripts( IDispatch** s);
		virtual HRESULT __stdcall put_CodeBehind( IDispatch* code);
		virtual HRESULT __stdcall OleCmd( long cmd );
*/
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
	// compiler events
	/////////////////////////////////////////////////////////////////////
/*
	class MoeHtmlWnd_compilerSink : public stack_obj<CompilerEvents>
	{
		public : 
			outer_this(MoeHtmlWnd,compilerSink_); 
			HRESULT virtual __stdcall ErrorMsg(BSTR error);
			HRESULT virtual __stdcall Success();
	} compilerSink_;
*/
	/////////////////////////////////////////////////////////////////////
	// webbrowser events
	/////////////////////////////////////////////////////////////////////

	class MoeHtmlWnd_htmlSink : public mol::stack_obj<mol::ie::ie_event_sink>
	{
		public : 
			outer_this(MoeHtmlWnd,htmlSink); 
			HRESULT virtual __stdcall BeforeNavigate2(IDispatch* pDisp, VARIANT* URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers, VARIANT_BOOL* Cancel);
			HRESULT virtual __stdcall DocumentComplete( IDispatch* pDisp,  VARIANT* URL);
			HRESULT virtual __stdcall WindowClosing( VARIANT_BOOL isChildWindow, VARIANT_BOOL* vbCancel );
	} htmlSink;
	
private:
	int							style_;
//	mol::punk<IDispatch>		codeBehind_;
//	mol::punk<ICompiler>		compiler_;
	mol::punk<IDispatch>		codeBehind_;
	mol::punk<IUnknown>		compiler_;
	Domain*						domain_;
	//punk<IJVM>					jvm_;
	mol::punk<IUnknown>					jvm_;
	mol::bstr					filename_;
	mol::string					location;

	bool load( const mol::string& loc );
};

#endif