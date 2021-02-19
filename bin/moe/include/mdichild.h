#ifndef MOE_COM_COMWNDIMPL_MDICHILD_DEF_GUARD_
#define MOE_COM_COMWNDIMPL_MDICHILD_DEF_GUARD_

#include "commons.h"
#include "resource.h"
#include "shared.h"
/////////////////////////////////////////////////////////////////////
//
// common mdi child window
//
/////////////////////////////////////////////////////////////////////

FILETIME getLastWriteTime(const std::wstring& path);


template<class C,class I, long T>
class DispatchMdiWindow
	: public mol::Dispatch<I>
{
public:

	typedef mol::com_instance<C> Instance;

	mol::punk<IMoeDocumentView> view;
	mol::punk<IDispatch> onCloseHandler;

	DispatchMdiWindow();

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
	   if (!This->oleObject)
		   return E_NOINTERFACE;

	   return This->oleObject->QueryInterface( IID_IDispatch, (void**)d );
   }


   virtual HRESULT __stdcall get_Model(IDispatch** d)
   {
	   if (!d)
		   return E_INVALIDARG;
	   *d = 0;

	   C* This = (C*)this;
	   if (!This->oleObject)
		   return E_NOINTERFACE;

	   return This->oleObject->QueryInterface(IID_IDispatch, (void**)d);
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
			std::wstring filename = This->getText();
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

   virtual HRESULT __stdcall SaveAsDialog()
   {
	   return E_NOTIMPL;
   }

   virtual HRESULT __stdcall put_onClose(IDispatch* disp)
   {
	   onCloseHandler = disp;
	   return S_OK;
   }

   virtual HRESULT __stdcall get_onClose(IDispatch** disp)
   {
	   if (!disp)
		   return E_INVALIDARG;
	   *disp = 0;

	   if (!onCloseHandler)
		   return S_FALSE;

	   return onCloseHandler.queryInterface(disp);
   }

};

template<class C, class T, long D, UINT M>
class MoeChild :
	public mol::MdiChildFrame<C,T>,
	public DispatchMdiWindow<C,IMoeDocument,D>,
	public mol::ProvideClassInfo<C>,
	public mol::interfaces< C, mol::implements< IDispatch, IMoeDocument, IProvideClassInfo> >

{
public:

	//using BaseWindowType = MoeChild<C, T, D, M>;

	LRESULT OnCloseAll()
	{

		LRESULT r = ::SendMessage(*this, WM_CLOSE, 0, 0);
		if (r == 0) {

			docs()->remove(this);

			long cnt = 0;
			docs()->get_Count(&cnt);
			if (cnt == 0)
			{
				moe()->Exit();
			}
		}
		return r;
	}

protected:

	void initializeMoeChild( const std::wstring& p)
	{
		// get client rectangle
		mol::Rect r;

		::GetClientRect( moe()->mdiClient(),&r);

		ODBGS1("initializeMoeChild2 r: ",r.right);
		ODBGS1("initializeMoeChild2 b: ",r.bottom);

		// determine window menu
		//HMENU m = mol::UI().Menu(M);
		//windowMenu_ = mol::UI().SubMenu( M ,IDM_VIEW_WINDOWS);
		statusBar()->status(40);

		// create
		moe()->setRedraw(false);
		this->create(p,0/*a(HMENU)m*/,r,*moe());
		this->show(SW_SHOW);	
		statusBar()->status(50);

		// taskbar thumbnail (win7)
		this->thumb = mol::taskbar()->addTab( *this,p );

		// maximize
		this->maximize();
		moe()->setRedraw(true);
		this->redraw();
	}
};


template<class C, long D, const CLSID* clsid, UINT M>
class MoeAxChild : public MoeChild<C,mol::AxWnd<C,mol::MdiChild,clsid>,D,M>
{
};

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

template<class C, class I, long T>
DispatchMdiWindow<C,I,T>::DispatchMdiWindow()
{
	C* This = (C*)this;
	MoeChildView::CreateInstance(This, &view);
}

class Script : public  mol::com_obj<mol::ScriptHost>//mol::ScriptHost
{
public:

	//typedef mol::com_obj<Script> Instance;
	typedef Script Instance;

	mol::Event completed;

	static Instance* CreateInstance()
	{
		Instance* s = new Instance;
		s->AddRef();
		return s;
	}

	Script();
	~Script();


	ULONG   virtual __stdcall AddRef()
	{
		::InterlockedIncrement((volatile long*)&molrefcount_);
		return molrefcount_;
	}

	ULONG   virtual __stdcall Release()
	{
		if (::InterlockedDecrement((volatile long*)&molrefcount_) == 0)
		{
			this->dispose();
			delete this;
			return 0;
		}
		return molrefcount_;
	}

	HRESULT init(const std::wstring& engine);

	void eval ( const std::wstring& engine, const std::wstring& script, IScintillAx* sci );
	void debug( const std::wstring& engine, const std::wstring& script, IScintillAx* sci );
	void call ( const std::wstring& engine, const std::wstring& func, const std::wstring& script );

	void quit();
	void wait();

	void formscript( const std::wstring& engine, const std::wstring& script, IDispatch* form );
	void formdebug( const std::wstring& engine, const std::wstring& script, IDispatch* form );
	void formcontrols( IUnknown* form );

    virtual HRESULT  __stdcall OnScriptError( IActiveScriptError *pscripterror);
	virtual HRESULT  __stdcall GetWindow(HWND *phwnd );

	bool done()
	{
		return quit_;
	}
private:

    IScintillAx* sci_;
	bool quit_ = true;
	mol::Timer timer_;
};


/////////////////////////////////////////////////////////////////////

typedef mol::punk<Script>		ScriptingHost;

class MoeImport :
	public mol::Dispatch<IMoeImport>,
	public mol::interfaces< MoeImport,
	mol::implements< IDispatch, IMoeImport> >
{
public:

	typedef mol::com_obj<MoeImport> Instance;
	typedef Script Host;

	void dispose();

	static Instance* CreateInstance(Host* host);

	virtual HRESULT __stdcall  Import(BSTR filename);
	virtual HRESULT __stdcall  Sleep(long ms);
	virtual HRESULT __stdcall  Wait( VARIANT_BOOL* vb);
	virtual HRESULT __stdcall  Quit();
	virtual HRESULT __stdcall  get_Dispatch(IDispatch** disp);
	virtual HRESULT __stdcall  Callback(BSTR name, IDispatch** disp);
	virtual HRESULT __stdcall  setTimeout(VARIANT f, VARIANT d, VARIANT* retval);
	virtual HRESULT __stdcall  clearTimeout(VARIANT t);

private:
	Host* host_;


};



#endif

