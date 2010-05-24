#ifndef MOE_COM_COMWNDIMPL_DEF_GUARD_
#define MOE_COM_COMWNDIMPL_DEF_GUARD_

#include "commons.h"
#include "Docs.h"

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
// shared Dispatch implementation for moewnd as well as moe mdi child 
// windows.
// 
// DispatchWindow<C,I> implements top,left,width,height COM properties for
// all moe windows and defines the Instance<C> typedef for obj 
// creation.
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

template<class COM>
class debug_com_instance : public COM
{
public:
    debug_com_instance()
    {
        molrefcount_ = 0;
		mol::win::AppBase::lock();        
    }
    virtual ~debug_com_instance() 
	{
		mol::win::AppBase::unlock();        
	}

	HRESULT virtual __stdcall QueryInterface(REFIID iid , LPVOID* ppv)
	{
		HRESULT hr = COM::QueryInterfaceImpl(iid,ppv);
		return hr;
	}

    ULONG   virtual __stdcall AddRef()
    {
		::InterlockedIncrement((volatile long*)&molrefcount_);
		ODBGS1("AddRef",molrefcount_);
		return molrefcount_;
    }

    ULONG   virtual __stdcall Release()
    {		
        if ( ::InterlockedDecrement((volatile long*)&molrefcount_) ==0 )
        {
			this->dispose();
			ODBGS1("Release",molrefcount_);
            delete this;
            return 0;
        }
		ODBGS1("Release",molrefcount_);
        return molrefcount_;
    }
protected:
    volatile DWORD molrefcount_;

};

/*
template<class C,class I>
class DispatchWindow
	: public mol::Dispatch<I>
{
public:
	typedef mol::com_instance<C> Instance;

	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall get_Top( long* top)
	{
		if ( top )
		{
			RECT r;
			C* This = (C*)this;
			This->getWindowRect(r);
			*top = r.top;
		}
		return S_OK;
	}

	virtual HRESULT __stdcall put_Top( long top)
	{
		RECT r;
		C* This = (C*)this;
		This->getWindowRect(r);
		r.bottom = r.bottom + ( top - r.top );
		r.top = top;

		This->move(r.left,r.top,r.right-r.left,r.bottom-r.top);
		return S_OK;
	}
	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall get_Left( long* left)
	{
		if ( left )
		{
			RECT r;
			C* This = (C*)this;
			This->getWindowRect(r);
			*left = r.left;
		}
		return S_OK;
	}

	virtual HRESULT __stdcall put_Left( long left)
	{
		RECT r;
		C* This = (C*)this;
		This->getWindowRect(r);
		r.right = r.right + ( left - r.left );
		r.left = left;
		This->move(r.left,r.top,r.right-r.left,r.bottom-r.top);
		return S_OK;
	}

	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall get_Width( long* width)
	{
		if ( width )
		{
			RECT r;
			C* This = (C*)this;
			This->getWindowRect(r);
			*width = r.right -r.left;
		}
		return S_OK;
	}

	virtual HRESULT __stdcall put_Width( long width)
	{
		RECT r;
		C* This = (C*)this;
		This->getWindowRect(r);
		r.right = r.left + width;
		This->move(r.left,r.top,r.right-r.left,r.bottom-r.top);
		return S_OK;
	}
	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall get_Height( long* height)
	{
		if ( height )
		{
			RECT r;
			C* This = (C*)this;
			This->getWindowRect(r);
			*height = r.bottom -r.top;
		}
		return S_OK;
	}

	virtual HRESULT __stdcall put_Height( long height)
	{
		RECT r;
		C* This = (C*)this;
		This->getWindowRect(r);
		r.bottom = r.top + height;
		This->move(r.left,r.top,r.right-r.left,r.bottom-r.top);
		return S_OK;
	}
};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
// shared dispatch implementation for moe mdi child windows
// derives from DispatchWindow<C,I>
// adds necessary COM plumbing for non-creatable Dispatch
// implementations (dispose,getCoClassID) and the Dispatch
// implementation for basic MDI functionality
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

*/
template<class C,class I, long T>
class DispatchMidiWindow
	: public mol::Dispatch<I>
{
public:

	mol::punk<IMoeDocumentView> view;

	typedef mol::com_instance<C> Instance;

	DispatchMidiWindow()
	{
		C* This = (C*)this;
		MoeChildView::CreateInstance( This, &view );
	}

	virtual ~DispatchMidiWindow()
	{}

	virtual void dispose() {}

	static REFGUID getCoClassID()
	{
		return CLSID_Application;
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
			*fname = ::SysAllocString( filename.c_str() );
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
/////////////////////////////////////////////////////////////////////


class MoeDialogView : 
	public mol::Dispatch<IMoeDialogView>,
	public mol::ProvideClassInfo<MoeDialogView>,
	public mol::interfaces< MoeDialogView, 
			mol::implements< 
				IDispatch, 
				IMoeDialogView, 
				IProvideClassInfo> >
{
private:

	mol::win::WndProc* wnd_;

public:

	virtual ~MoeDialogView();

	void init( mol::win::WndProc* wnd );

	typedef mol::stack_obj<MoeDialogView> Instance;

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
	virtual HRESULT __stdcall get_Title( BSTR* title );
	virtual HRESULT __stdcall put_Title( BSTR title );
};


class MoeView : 
	public mol::Dispatch<IMoeView>,
	public mol::ProvideClassInfo<MoeView>,
	public mol::interfaces< MoeView, 
			mol::implements< 
				IDispatch, 
				IMoeView, 
				IProvideClassInfo> >
{

private:

	WINDOWPLACEMENT					wpPrev_;
	void fullScreen(HWND hwnd);

public:

	virtual ~MoeView();

	typedef mol::com_obj<MoeView> Instance;

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

	/////////////////////////////////////////////////////////////////////

	virtual HRESULT __stdcall Show();
	virtual HRESULT __stdcall Hide();
	virtual HRESULT __stdcall Minimize();
	virtual HRESULT __stdcall  Maximize();
	virtual HRESULT __stdcall Restore();
	virtual HRESULT __stdcall Tile();
	virtual HRESULT __stdcall Cascade();
	virtual HRESULT __stdcall get_ShowTreeView( VARIANT_BOOL* vb );
	virtual HRESULT __stdcall put_ShowTreeView( VARIANT_BOOL vb );
	virtual HRESULT __stdcall put_Fullscreen( VARIANT_BOOL vb );
	virtual HRESULT __stdcall get_Fullscreen( VARIANT_BOOL* vb );
	virtual HRESULT __stdcall get_TreeView( IDispatch** tv);
};


class MoeDialogs 
	:
	public mol::Dispatch<IMoeDialogs>,
	public mol::ProvideClassInfo<MoeDialogs>,
	public mol::interfaces< MoeDialogs, 
			mol::implements< 
				IDispatch, 
				IMoeDialogs, 
				IProvideClassInfo> >
{

public:

	virtual ~MoeDialogs();

	typedef mol::com_obj<MoeDialogs> Instance;

	virtual void dispose();

	static REFGUID getCoClassID();

	virtual HRESULT __stdcall MsgBox( BSTR text, BSTR title, long flags, long* result);
	virtual HRESULT __stdcall Open(IMoeDocument** d);
	virtual HRESULT __stdcall OpenDir( IMoeDocument** d);
	virtual HRESULT __stdcall ChooseFile( BSTR* f );
	virtual HRESULT __stdcall ChooseDir( BSTR* d );

};



class MoeScript 
	:
	public mol::Dispatch<IMoeScript>,
	public mol::ProvideClassInfo<MoeScript>,
	public mol::interfaces< MoeScript, 
			mol::implements< 
				IDispatch, 
				IMoeScript, 
				IProvideClassInfo> >
{
public:

	virtual ~MoeScript();

	typedef mol::com_obj<MoeScript> Instance;

	virtual void dispose();

	static REFGUID getCoClassID();

	virtual HRESULT __stdcall Run( BSTR f, BSTR engine );
	virtual HRESULT __stdcall Eval( BSTR scrpt, BSTR scrptLanguage);
	virtual HRESULT __stdcall Debug( BSTR scrpt, BSTR scrptLanguage);
	virtual HRESULT __stdcall CreateObjectAdmin( BSTR progid, IDispatch** disp);
	virtual HRESULT __stdcall ShowHtmlForm( BSTR src, long l, int t, int w, int h, int formStyle );
	virtual HRESULT __stdcall ShowUserForm( BSTR pathname, IMoeUserForm** form );
	virtual HRESULT __stdcall DebugUserForm( BSTR pathname, IMoeUserForm** form );
	virtual HRESULT __stdcall System( BSTR f);

};

class MoeConfig 
	:
	public mol::Dispatch<IMoeConfig>,
	public mol::ProvideClassInfo<MoeConfig>,
	public mol::interfaces< MoeConfig, 
			mol::implements< 
				IDispatch, 
				IMoeConfig, 
				IProvideClassInfo> >
{
private:

	long							systype_;
	long							encoding_;
	long							tabwidth_;
	VARIANT_BOOL					tabUsage_;
	VARIANT_BOOL					tabIndents_;
	VARIANT_BOOL					fullScreen_;
	VARIANT_BOOL					backSpaceUnIndents_;

public:

	virtual ~MoeConfig();

	typedef mol::com_obj<MoeConfig> Instance;

	virtual void dispose();

	static REFGUID getCoClassID();

	virtual HRESULT __stdcall get_ConfigPath( BSTR* fPath);
	virtual HRESULT __stdcall get_ModulePath(  BSTR* fPath);
	virtual HRESULT __stdcall put_SysType( long typ);
	virtual HRESULT __stdcall get_SysType( long* typ);
	virtual HRESULT __stdcall put_Encoding( long typ);
	virtual HRESULT __stdcall get_Encoding( long* typ);
	virtual HRESULT __stdcall put_TabUsage( VARIANT_BOOL vbTabUsage);
	virtual HRESULT __stdcall get_TabUsage( VARIANT_BOOL* vbTabUsage);
	virtual HRESULT __stdcall put_TabIndents( VARIANT_BOOL vbTabIndents);
	virtual HRESULT __stdcall get_TabIndents( VARIANT_BOOL* vbTabIndents);
	virtual HRESULT __stdcall put_BackSpaceUnindents( VARIANT_BOOL vbBackSpaceIndents);
	virtual HRESULT __stdcall get_BackSpaceUnindents(  VARIANT_BOOL* vbBackSpaceIndents);
	virtual HRESULT __stdcall put_TabWidth( long width);
	virtual HRESULT __stdcall get_TabWidth(  long* width);
	virtual HRESULT __stdcall EditPreferences( );
	virtual HRESULT __stdcall EditSettings( );
	virtual HRESULT __stdcall ExportSettings( BSTR f );
	virtual HRESULT __stdcall ImportSettings( BSTR f );
	virtual HRESULT __stdcall InitializeEditorFromPreferences( IMoeDocument* d );

};



#endif

