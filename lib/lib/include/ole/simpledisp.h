#ifndef _MOL_DEF_DISPATCH_SIMPL_IMPL_DEF_GUARD_
#define _MOL_DEF_DISPATCH_SIMPL_IMPL_DEF_GUARD_

#include "win/ole/aut.h"
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

namespace mol {

////////////////////////////////////////////////////////////////////////

namespace ole {

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

template<class T, int N>
class DispatchSignature
{
public:

	typedef variant (T::*funcPtr)();

	DispatchSignature( funcPtr fp )
		: fp_(fp )
	{}

    HRESULT __stdcall Invoke( T* t, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn)
	{
		variant ret = (t->*fp_)();
		if ( pReturn )
			::VariantCopy(pReturn,&ret);
		return S_OK;
	}

private:
	funcPtr fp_;
};

////////////////////////////////////////////////////////////////////////

template<class T>
class DispatchSignature<T,1>
{
public:

	typedef variant (T::*funcPtr)(variant v1);

	DispatchSignature( funcPtr fp )
		: fp_(fp )
	{}

    HRESULT __stdcall Invoke( T* t, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn)
	{
		if ( pDisp->cArgs < 1 )
			return E_INVALIDARG;

		variant ret = t->(*fp_)->(pDisp->rgvarg[0]);
		if ( pReturn )
			::VariantCopy(pReturn,&ret);
		return S_OK;
	}
	
private:
	funcPtr fp_;
};

////////////////////////////////////////////////////////////////////////

template<class T>
class DispatchSignature<T,2>
{
public:

	typedef variant (T::*funcPtr)(variant v1, variant v2);

	DispatchSignature( funcPtr fp )
		: fp_(fp )
	{}

    HRESULT __stdcall Invoke( T* t, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn)
	{
		if ( pDisp->cArgs < 2 )
			return E_INVALIDARG;

		variant ret = t->(*fp_)->(pDisp->rgvarg[1],pDisp->rgvarg[0]);
		if ( pReturn )
			::VariantCopy(pReturn,&ret);
		return S_OK;
	}
	
private:
	funcPtr fp_;
};

template<class T>
class DispatchSignature<T,3>
{
public:

	typedef variant (T::*funcPtr)(variant v1, variant v2, variant v3);

	DispatchSignature( funcPtr fp )
		: fp_(fp )
	{}

    HRESULT __stdcall Invoke( T* t, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn)
	{
		if ( pDisp->cArgs < 3 )
			return E_INVALIDARG;

		variant ret = t->(*fp_)->(pDisp->rgvarg[2],pDisp->rgvarg[1],pDisp->rgvarg[0]);
		if ( pReturn )
			::VariantCopy(pReturn,&ret);
		return S_OK;
	}
	
private:
	funcPtr fp_;
};

////////////////////////////////////////////////////////////////////////

template<class T>
class DispatchSignature<T,4>
{
public:

	typedef variant (T::*funcPtr)(variant v1, variant v2, variant v3, variant v4);

	DispatchSignature( funcPtr fp )
		: fp_(fp )
	{}

    HRESULT __stdcall Invoke( T* t, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn)
	{
		if ( pDisp->cArgs < 4 )
			return E_INVALIDARG;

		variant ret = t->(*fp_)->(pDisp->rgvarg[3],pDisp->rgvarg[2],pDisp->rgvarg[1],pDisp->rgvarg[0]);
		if ( pReturn )
			::VariantCopy(pReturn,&ret);
		return S_OK;
	}
	
private:
	funcPtr fp_;
};

////////////////////////////////////////////////////////////////////////

template<class T>
class DispatchSignature<T,5>
{
public:

	typedef variant (T::*funcPtr)(variant v1, variant v2, variant v3, variant v4, variant v5);

	DispatchSignature( funcPtr fp )
		: fp_(fp )
	{}

    HRESULT __stdcall Invoke( T* t, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn)
	{
		if ( pDisp->cArgs < 5 )
			return E_INVALIDARG;

		variant ret = t->(*fp_)->(pDisp->rgvarg[4],pDisp->rgvarg[3],pDisp->rgvarg[2],pDisp->rgvarg[1],pDisp->rgvarg[0]);
		if ( pReturn )
			::VariantCopy(pReturn,&ret);
		return S_OK;
	}
	
private:
	funcPtr fp_;
};

////////////////////////////////////////////////////////////////////////

template<class T>
class DispatchSignature<T,6>
{
public:

	typedef variant (T::*funcPtr)(variant v1, variant v2, variant v3, variant v4, variant v5, variant v6);

	DispatchSignature( funcPtr fp )
		: fp_(fp )
	{}

    HRESULT __stdcall Invoke( T* t, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn)
	{
		if ( pDisp->cArgs < 6 )
			return E_INVALIDARG;

		variant ret = t->(*fp_)->(pDisp->rgvarg[5],pDisp->rgvarg[4],pDisp->rgvarg[3],pDisp->rgvarg[2],pDisp->rgvarg[1],pDisp->rgvarg[0]);
		if ( pReturn )
			::VariantCopy(pReturn,&ret);
		return S_OK;
	}
	
private:
	funcPtr fp_;
};

////////////////////////////////////////////////////////////////////////

template<class T>
class DispatchSignature<T,7>
{
public:

	typedef variant (T::*funcPtr)(variant v1, variant v2, variant v3, variant v4, variant v5, variant v6, variant v7);

	DispatchSignature( funcPtr fp )
		: fp_(fp )
	{}

    HRESULT __stdcall Invoke( T* t, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn)
	{
		if ( pDisp->cArgs < 7 )
			return E_INVALIDARG;

		variant ret = t->(*fp_)->(pDisp->rgvarg[6],pDisp->rgvarg[5],pDisp->rgvarg[4],pDisp->rgvarg[3],pDisp->rgvarg[2],pDisp->rgvarg[1],pDisp->rgvarg[0]);
		if ( pReturn )
			::VariantCopy(pReturn,&ret);
		return S_OK;
	}
	
private:
	funcPtr fp_;
};

////////////////////////////////////////////////////////////////////////

template<class T>
class DispatchSignature<T,8>
{
public:

	typedef variant (T::*funcPtr)(variant v1, variant v2, variant v3, variant v4, variant v5, variant v6, variant v7, variant v8);

	DispatchSignature( funcPtr fp )
		: fp_(fp )
	{}

    HRESULT __stdcall Invoke( T* t, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn)
	{
		if ( pDisp->cArgs < 8 )
			return E_INVALIDARG;

		variant ret = t->(*fp_)->(pDisp->rgvarg[7],pDisp->rgvarg[6],pDisp->rgvarg[5],pDisp->rgvarg[4],pDisp->rgvarg[3],pDisp->rgvarg[2],pDisp->rgvarg[1],pDisp->rgvarg[0]);
		if ( pReturn )
			::VariantCopy(pReturn,&ret);
		return S_OK;
	}
	
private:
	funcPtr fp_;
};

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

class DispatchMemberHolderBase
{
public:

	DispatchMemberHolderBase(DISPID di, const OLECHAR* n)
	{
		dispid_ = di;
		name_   = n;
	}

    HRESULT virtual __stdcall Invoke(void* obj, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn) = 0;

	DISPID dispid_;
	const OLECHAR* name_;
};

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


template<class T, int N>
class DispatchMemberHolder : public DispatchMemberHolderBase
{
public:
	typedef  DispatchSignature<T,N> Signature;

	DispatchMemberHolder( const OLECHAR* name, DISPID dispid, typename Signature::funcPtr fp )
		: DispatchMemberHolderBase( dispid, name ), sig_(fp)
	{
	//	sig_ = Signature(fp);
	}

    HRESULT virtual __stdcall Invoke(void* obj, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn)
	{
		return sig_.Invoke( (T*)obj, w, pDisp, pReturn );
	}

	Signature sig_;
};

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

template<class T>
DispatchMemberHolder<T,0>* 
makeDispatchMemberHolder( typename DispatchSignature<T,0>::funcPtr fp, const OLECHAR* name, DISPID dispid )
{
	return new DispatchMemberHolder<T,0>(name,dispid,fp);
}

template<class T>
DispatchMemberHolder<T,1>* 
makeDispatchMemberHolder( typename DispatchSignature<T,1>::funcPtr fp, const OLECHAR* name, DISPID dispid )
{
	return new DispatchMemberHolder<T,1>(name,dispid,fp);
}

template<class T>
DispatchMemberHolder<T,2>* 
makeDispatchMemberHolder( typename DispatchSignature<T,2>::funcPtr fp, const OLECHAR* name, DISPID dispid )
{
	return new DispatchMemberHolder<T,2>(name,dispid,fp);
}

template<class T>
DispatchMemberHolder<T,3>* 
makeDispatchMemberHolder( typename DispatchSignature<T,3>::funcPtr fp, const OLECHAR* name, DISPID dispid )
{
	return new DispatchMemberHolder<T,3>(name,dispid,fp);
}


template<class T>
DispatchMemberHolder<T,4>* 
makeDispatchMemberHolder( typename DispatchSignature<T,4>::funcPtr fp, const OLECHAR* name, DISPID dispid )
{
	return new DispatchMemberHolder<T,4>(name,dispid,fp);
}

template<class T>
DispatchMemberHolder<T,5>* 
makeDispatchMemberHolder( typename DispatchSignature<T,5>::funcPtr fp, const OLECHAR* name, DISPID dispid )
{
	return new DispatchMemberHolder<T,5>(name,dispid,fp);
}

template<class T>
DispatchMemberHolder<T,6>* 
makeDispatchMemberHolder( typename DispatchSignature<T,6>::funcPtr fp, const OLECHAR* name, DISPID dispid )
{
	return new DispatchMemberHolder<T,6>(name,dispid,fp);
}

template<class T>
DispatchMemberHolder<T,7>* 
makeDispatchMemberHolder( typename DispatchSignature<T,7>::funcPtr fp, const OLECHAR* name, DISPID dispid )
{
	return new DispatchMemberHolder<T,7>(name,dispid,fp);
}

template<class T>
DispatchMemberHolder<T,8>* 
makeDispatchMemberHolder( typename DispatchSignature<T,8>::funcPtr fp, const OLECHAR* name, DISPID dispid )
{
	return new DispatchMemberHolder<T,8>(name,dispid,fp);
}
////////////////////////////////////////////////////////////////////////

} // end namespace ole

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


template< class T, class I, const IID* iid= &__uuidof(I)>
class SimpleDispatch : public I
{
public:

	typedef T DispatchedClass;

    SimpleDispatch()
    {
	}

    HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo ) 
    { 
        *pctinfo = 1;
        return S_OK; 
    }

    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) 
    { 
        if ( ppTInfo )
			*ppTInfo = 0;
        return E_NOTIMPL; 
    }

    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
    { 
		for ( std::vector<mol::ole::DispatchMemberHolderBase*>::iterator it = dispatches_.begin();
			  it != dispatches_.end(); it++ )
		{
			if ( _wcsicmp( (*it)->name_, rgszNames[0] ) )
			{
				rgDispId[0] = (*it)->dispid_;
				return S_OK;
			}
		}
		rgDispId[0] = DISPID_UNKNOWN;
		return DISP_E_UNKNOWNNAME;
    }

    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
    { 
		for ( std::vector<mol::ole::DispatchMemberHolderBase*>::iterator it = dispatches_.begin();
			  it != dispatches_.end(); it++ )
		{
			if ( (*it)->dispid_ == dispIdMember )
			{
				variant retval;
				HRESULT hr;
				try 
				{
					hr = (*it)->Invoke( (void*)this, w, pDisp, &retval );
					if ( hr == S_OK && pReturn )
						::VariantCopy(pReturn, &retval);
				}
				catch(EXCEPINFO& x)
				{
					if ( ex )
					    *ex = x;
					return DISP_E_EXCEPTION;
				}
				return hr;
			}
		}
        return DISP_E_MEMBERNOTFOUND;
    }

	static std::vector<mol::ole::DispatchMemberHolderBase*>& getDispVector()
	{
		return dispatches_;
	}

protected:

	static std::vector<mol::ole::DispatchMemberHolderBase*> dispatches_;
};

////////////////////////////////////////////////////////////////////////

template< class T, class I, const IID* iid>
std::vector<mol::ole::DispatchMemberHolderBase*> SimpleDispatch<T,I,iid>::dispatches_;


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

#define DISPATCHED_METHOD(M,ID)													\
class AddDispFunc##M															\
{																				\
public:																			\
	AddDispFunc##M()															\
	{																			\
		static int i = init();													\
	}																			\
	static int init()															\
	{																			\
		DispatchedClass::getDispVector()										\
				.push_back( 													\
					mol::ole::makeDispatchMemberHolder<DispatchedClass>(		\
						&##DispatchedClass##::##M,								\
						L#M , 													\
						ID														\
					) 															\
				);																\
		return 1;																\
	}																			\
};																				\
AddDispFunc##M addDispFunc##M##_member;

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

} // end namespace mol

#endif


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


