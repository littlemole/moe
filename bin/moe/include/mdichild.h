#ifndef MOE_COM_COMWNDIMPL_MDICHILD_DEF_GUARD_
#define MOE_COM_COMWNDIMPL_MDICHILD_DEF_GUARD_

#include "commons.h"
#include "resource.h"

/////////////////////////////////////////////////////////////////////
//
// common mdi child window
//
/////////////////////////////////////////////////////////////////////

FILETIME getLastWriteTime(const mol::string& path);


template<class C,class I, long T>
class DispatchMdiWindow
	: public mol::Dispatch<I>
{
public:

	typedef mol::com_instance<C> Instance;

	mol::punk<IMoeDocumentView> view;

	DispatchMdiWindow()
	{
		C* This = (C*)this;
		MoeChildView::CreateInstance( This, &view );
	}

	virtual ~DispatchMdiWindow()
	{

	}

	virtual void dispose() {}

	static REFGUID getCoClassID()
	{
		return IID_IMoeDocument;
	}

   virtual HRESULT __stdcall get_Object( IDispatch **d)
   {
	   if ( !d )
		   return E_INVALIDARG;
	   *d = 0;

	   C* This = (C*)this;
	   return This->oleObject->QueryInterface( IID_IDispatch, (void**)d );
   }

   virtual HRESULT __stdcall get_View(  IMoeDocumentView **d)
   {
	   if ( !d )
		   return E_INVALIDARG;
	   *d = 0;
	   return view->QueryInterface( IID_IDispatch, (void**)d );
   }

   virtual HRESULT __stdcall get_FilePath( BSTR *fname)
   {
		if ( fname  )
		{
			*fname = 0;
			C* This = (C*)this;
			mol::string filename = This->getText();
			*fname = ::SysAllocString( mol::towstring(filename).c_str() );
		}
		return S_OK;
   }

   virtual HRESULT __stdcall get_Type(long *typ)
   {
	   if ( !typ )
		   return E_INVALIDARG;

	   *typ = T;
	   return S_OK;
   }

   virtual HRESULT __stdcall Save( )
   {
	   return E_NOTIMPL;
   }

   virtual HRESULT __stdcall SaveAs( BSTR f)
   {
	   return E_NOTIMPL;
   }

};

template<class C, class T, long D, UINT M>
class MoeChild :
	public mol::MdiChildFrame<C,T>,
	public DispatchMdiWindow<C,IMoeDocument,D>,
	public mol::ProvideClassInfo<C>,
	public mol::interfaces< C, mol::implements< IDispatch, IMoeDocument, IProvideClassInfo> >

{
protected:

	void initializeMoeChild( const mol::string& p)
	{
		// get client rectangle
		mol::Rect r;

		::GetClientRect( moe()->mdiClient(),&r);

		ODBGS1("initializeMoeChild2 r: ",r.right);
		ODBGS1("initializeMoeChild2 b: ",r.bottom);

		// determine window menu
		HMENU m = mol::UI().Menu(M);
		windowMenu_ = mol::UI().SubMenu( M ,IDM_VIEW_WINDOWS);
		statusBar()->status(40);

		// create
		moe()->setRedraw(false);
		create(p,(HMENU)m,r,*moe());
		show(SW_SHOW);	
		statusBar()->status(50);

		// taskbar thumbnail (win7)
		thumb = mol::taskbar()->addTab( *this,p );

		// maximize
		maximize();
		moe()->setRedraw(true);
		redraw();
	}
};


template<class C, long D, const CLSID* clsid, UINT M>
class MoeAxChild : public MoeChild<C,mol::AxWnd<C,mol::MdiChild,clsid>,D,M>
{};

/////////////////////////////////////////////////////////////////////
//
// common mdi child view impl
//
/////////////////////////////////////////////////////////////////////


class MoeChildView : 
	public mol::Dispatch<IMoeDocumentView>,
	public mol::ProvideClassInfo<MoeChildView>,
	public mol::interfaces< MoeChildView, 
			mol::implements< 
				IDispatch, 
				IMoeDocumentView, 
				IProvideClassInfo> >
{
private:

	mol::MdiChild* wnd_;

public:

	virtual ~MoeChildView();

	typedef mol::com_obj<MoeChildView> Instance;

	static bool CreateInstance( mol::MdiChild* wnd, IMoeDocumentView** v );

	virtual void dispose();

	static REFGUID getCoClassID();

	/////////////////////////////////////////////////////////////////////

	virtual HRESULT __stdcall get_Top( long* top);
	virtual HRESULT __stdcall put_Top( long top);
	virtual HRESULT __stdcall get_Left( long* left);
	virtual HRESULT __stdcall put_Left( long left);
	virtual HRESULT __stdcall get_Width( long* width);
	virtual HRESULT __stdcall put_Width( long width);
	virtual HRESULT __stdcall get_Height( long* height);
	virtual HRESULT __stdcall put_Height( long height);

	virtual HRESULT __stdcall Show();
	virtual HRESULT __stdcall Hide();
	virtual HRESULT __stdcall Close();
	virtual HRESULT __stdcall Minimize();
	virtual HRESULT __stdcall Maximize();
	virtual HRESULT __stdcall Restore();
	virtual HRESULT __stdcall Activate();

};


class Script : public mol::com_obj<mol::ScriptHost>
{
public:

	static Script* CreateInstance()
	{
		Script* s = new Script;
		s->AddRef();
		return s;
	}

	HRESULT init(const mol::string& engine);

	void eval ( const mol::string& engine, const mol::string& script, IScintillAx* sci );
	void debug( const mol::string& engine, const mol::string& script, IScintillAx* sci );
	void call ( const mol::string& engine, const mol::string& func, const mol::string& script );

	void formscript( const mol::string& engine, const mol::string& script, IDispatch* form );
	void formdebug( const mol::string& engine, const mol::string& script, IDispatch* form );
	void formcontrols( IUnknown* form );

    virtual HRESULT  __stdcall OnScriptError( IActiveScriptError *pscripterror);
	virtual HRESULT  __stdcall GetWindow(HWND *phwnd );

private:

	Script();
	~Script();
    IScintillAx* sci_;
};

/////////////////////////////////////////////////////////////////////

typedef mol::punk<Script>		ScriptingHost;



#endif

