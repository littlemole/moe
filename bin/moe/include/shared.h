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


template<class C,class I>
class DispatchMidiWindow
	: public DispatchWindow<C,I>
{
public:

	virtual void dispose() {}

	static REFGUID getCoClassID()
	{
		return IID_IDoc;
	}

	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall get_Top( long* top)
	{
		if ( top )
		{
			RECT r;
			C* This = (C*)this;
			This->getWindowRect(r);
			mol::Point p(r.left,r.top);
			::ScreenToClient( This->mdiClient(), &p);
			*top = p.y;
		}
		return S_OK;
	}

	virtual HRESULT __stdcall put_Top( long top)
	{
		RECT r;
		C* This = (C*)this;
		This->getWindowRect(r);
		int w = r.right-r.left;
		int h = r.bottom-r.top;

		mol::Point p(r.left,r.top);
		::ScreenToClient(This->mdiClient(), &p);

		p.y = top;
		h  += top-p.y;

		This->move(p.x,p.y,w,h);
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
			mol::Point p(r.left,r.top);
			::ScreenToClient(This->mdiClient(), &p);
			*left = p.x;
		}
		return S_OK;
	}

	virtual HRESULT __stdcall put_Left( long left)
	{
		RECT r;
		C* This = (C*)this;
		This->getWindowRect(r);
		int w = r.right-r.left;
		int h = r.bottom-r.top;

		mol::Point p(r.left,r.top);
		::ScreenToClient(This->mdiClient(), &p);

		p.x = left;
		w += left-p.x;

		This->move(p.x,p.y,w,h);
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
		int w = width;
		int h = r.bottom-r.top;

		mol::Point p(r.left,r.top);
		::ScreenToClient(This->mdiClient(), &p);

		This->move(p.x, p.y, w, h);
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
		int w = r.right-r.left;
		int h = height;

		mol::Point p(r.left,r.top);
		::ScreenToClient(This->mdiClient(), &p);

		This->move(p.x, p.y, w, h);
		return S_OK;
	}


	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall get_App( IXmoe** m)
	{			
		return ((IXmoe*)moe())->QueryInterface(IID_IXmoe,(void**)m);
	}

	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall get_Document( IDispatch** doc)
	{
		if ( doc )
		{
			*doc = NULL;
			C* This = (C*)this;
			return This->oleObject.queryInterface(IID_IDispatch, (void**) doc);
		}
		return E_NOINTERFACE;
	}

	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall  Show()
	{
		C* This = (C*)this;
		This->show(SW_SHOW);
		return S_OK;
	}

	virtual HRESULT __stdcall  Hide()
	{
		C* This = (C*)this;
		This->show(SW_HIDE);
		return S_OK;
	}

	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall  Minimize()
	{
		C* This = (C*)this;
		This->show(SW_MINIMIZE);
		return S_OK;
	}

	virtual HRESULT __stdcall  Maximize()
	{
		C* This = (C*)this;
		This->show(SW_MAXIMIZE);
		return S_OK;
	}

	virtual HRESULT __stdcall  Restore()
	{
		C* This = (C*)this;
		This->show(SW_RESTORE);
		return S_OK;
	}

};


#endif