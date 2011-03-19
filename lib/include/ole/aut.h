#ifndef MOL_DEF_OLE_AUTOMATION_DEF_GUARD_DEFINE_
#define MOL_DEF_OLE_AUTOMATION_DEF_GUARD_DEFINE_

#include "ole/variant.h"
#include "ole/typelib.h"
#include <ocidl.h>
#include <olectl.h>
#include <oaidl.h>

namespace mol {

/////////////////////////////////////////////////////////////////////
// ProvideClassInfo Impl
/////////////////////////////////////////////////////////////////////

template<class T>
class ProvideClassInfo : public IProvideClassInfo
{
public:

	ProvideClassInfo ()
	{
		TypeLib typelib_;
		typelib_.load();
		if ( S_OK != typelib_->GetTypeInfoOfGuid(T::getCoClassID(),&ti_) )
			cry();
	}

	virtual ~ProvideClassInfo()
	{}

    virtual HRESULT __stdcall GetClassInfo( ITypeInfo **ppTI) 
	{
		if ( ti_ )
			return ti_.queryInterface(ppTI);
		return E_FAIL;
	}

protected:
	punk<ITypeInfo> ti_;
};

/////////////////////////////////////////////////////////////////////
// ProvideClassInfo2 Impl
/////////////////////////////////////////////////////////////////////

template<class T, REFGUID G>
class ProvideClassInfo2 : public IProvideClassInfo2
{
public:

	ProvideClassInfo2 ()
	{
		TypeLib typelib_;
		typelib_.load();
		if ( S_OK != typelib_->GetTypeInfoOfGuid(T::getCoClassID(),&ti_) )
			cry();
	}

	virtual ~ProvideClassInfo2()
	{}

    virtual HRESULT __stdcall GetClassInfo( ITypeInfo **ppTI) 
	{
		if ( ti_ )
			return ti_.queryInterface(ppTI);
		return E_FAIL;
	}
    virtual HRESULT __stdcall GetGUID( DWORD dwGuidKind, GUID * pGUID )
	{
		if ( pGUID )
			*pGUID = G;
		return S_OK;
	}

protected:
	punk<ITypeInfo> ti_;
};

//////////////////////////////////////////////////////////////////////
// TypeLib based IDispatch Impl
//////////////////////////////////////////////////////////////////////

template< class C, const IID* iid= &__uuidof(C), const GUID* libid = &GUID_NULL, int major = 1, int minor = 0>
class Dispatch : public C
{
public:

    Dispatch()
    {
		typeInfo_ = 0;
		TypeLib tl;
		if ( ::IsEqualGUID(*libid,GUID_NULL) )
		{
			tl.load();
		}
		else
		{
			tl.load(*libid,major,minor);
		}
		if ( !tl )
			return;

		HRESULT hr = tl->GetTypeInfoOfGuid(*iid,&typeInfo_);
        if ( hr != S_OK )
		{
            //cry();
		}
	}

    HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo ) 
    { 
        *pctinfo = 1;
        return S_OK; 
    }

    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) 
    { 
        typeInfo_.queryInterface(ppTInfo );
        return S_OK; 
    }

    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
    { 
        return ::DispGetIDsOfNames(typeInfo_,rgszNames,cNames, rgDispId);
    }

    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
    { 
        HRESULT hr = ::DispInvoke( this, typeInfo_, dispIdMember, w, pDisp, pReturn, ex, i);
        return hr;
    }

protected:
    punk<ITypeInfo> typeInfo_;
};

///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
// invoke void Automation methods via IDispatch
///////////////////////////////////////////////////////////

void disp_invoke( IDispatch* disp, DISPID dispIdMember);

variant disp_call( IDispatch* disp, DISPID dispIdMember);

template<class V>
void disp_invoke( IDispatch* disp, DISPID dispIdMember, V& v)
{
	variant var(v);
	DISPPARAMS dps = {&var,0,1,0};
	disp->Invoke( dispIdMember, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dps, NULL, NULL, NULL );
}

template<class V>
variant disp_call( IDispatch* disp, DISPID dispIdMember, V& v)
{
	variant var(v);
	DISPPARAMS dps = {&var,0,1,0};

	variant varResult;
	disp->Invoke( dispIdMember, IID_NULL, 
				  LOCALE_SYSTEM_DEFAULT, 
				  DISPATCH_METHOD, 
				  &dps, 
				  &varResult, NULL, NULL 
				 );
	return varResult;
}

template<class V1, class V2>
void disp_invoke( IDispatch* disp, DISPID dispIdMember, V1& v1, V2& v2)
{
	variant var[] = { variant(v2), variant(v1) };
	DISPPARAMS dps = {var,0,2,0};
	
	disp->Invoke( dispIdMember, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dps, NULL, NULL, NULL );
}

template<class V1, class V2>
variant disp_call( IDispatch* disp, DISPID dispIdMember, V1& v1, V2& v2)
{
	variant var[] = { variant(v2), variant(v1) };
	DISPPARAMS dps = {&var,0,2,0};

	variant varResult;
	disp->Invoke( dispIdMember, IID_NULL, 
				  LOCALE_SYSTEM_DEFAULT, 
				  DISPATCH_METHOD, 
				  &dps, 
				  &varResult, NULL, NULL 
				 );
	return varResult;
}

template<class V1, class V2, class V3>
void disp_invoke( IDispatch* disp, DISPID dispIdMember, V1& v1, V2& v2, V3& v3)
{
	variant var[] = { variant(v3), variant(v2), variant(v1) };
	DISPPARAMS dps = {var,0,3,0};
	
	disp->Invoke( dispIdMember, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dps, NULL, NULL, NULL );
}


template<class V1, class V2, class V3>
variant disp_call( IDispatch* disp, DISPID dispIdMember, V1& v1, V2& v2, V3& v3)
{
	variant var[] = { variant(v2), variant(v1), variant(v3) };
	DISPPARAMS dps = {&var,0,3,0};

	variant varResult;
	disp->Invoke( dispIdMember, IID_NULL, 
				  LOCALE_SYSTEM_DEFAULT, 
				  DISPATCH_METHOD, 
				  &dps, 
				  &varResult, NULL, NULL 
				 );
	return varResult;
}

template<class V1, class V2, class V3, class V4>
void disp_invoke( IDispatch* disp, DISPID dispIdMember, V1& v1, V2& v2, V3& v3, V4& v4)
{
	variant var[] = { variant(v4), variant(v3), variant(v2), variant(v1) };
	DISPPARAMS dps = {var,0,4,0};
	
	disp->Invoke( dispIdMember, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dps, NULL, NULL, NULL );
}


template<class V1, class V2, class V3, class V4>
variant disp_call( IDispatch* disp, DISPID dispIdMember, V1& v1, V2& v2, V3& v3, V4& v4)
{
	variant var[] = { 
							variant(v4), variant(v3), 
							variant(v2), variant(v1) };
	DISPPARAMS dps = {&var,0,4,0};

	variant varResult;
	disp->Invoke( dispIdMember, IID_NULL, 
				  LOCALE_SYSTEM_DEFAULT, 
				  DISPATCH_METHOD, 
				  &dps, 
				  &varResult, NULL, NULL 
				 );
	return varResult;
}

template<class V1, class V2, class V3, class V4, class V5>
void disp_invoke( IDispatch* disp, DISPID dispIdMember, V1& v1, V2& v2, V3& v3, V4& v4, V5& v5)
{
	variant var[] = { variant(v5), variant(v4), variant(v3), 
						   variant(v2), variant(v1) };
	DISPPARAMS dps = {var,0,5,0};
	
	disp->Invoke( dispIdMember, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dps, NULL, NULL, NULL );
}


template<class V1, class V2, class V3, class V4, class V5>
variant disp_call( IDispatch* disp, DISPID dispIdMember, V1& v1, V2& v2, V3& v3, V4& v4, V5& v5)
{
	variant var[] = {  variant(v5),
							variant(v4), variant(v3), 
							variant(v2), variant(v1) };
	DISPPARAMS dps = {&var,0,5,0};

	variant varResult;
	disp->Invoke( dispIdMember, IID_NULL, 
				  LOCALE_SYSTEM_DEFAULT, 
				  DISPATCH_METHOD, 
				  &dps, 
				  &varResult, NULL, NULL 
				 );
	return varResult;
}

template<class V1, class V2, class V3, class V4, class V5, class V6>
void disp_invoke( IDispatch* disp, DISPID dispIdMember, V1& v1, V2& v2, V3& v3, V4& v4, V5& v5, V6& v6)
{
	variant var[] = { variant(v6), variant(v5), variant(v4), 
						   variant(v3), variant(v2), variant(v1) };
	DISPPARAMS dps = {var,0,6,0};
	
	disp->Invoke( dispIdMember, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dps, NULL, NULL, NULL );
}


template<class V1, class V2, class V3, class V4, class V5, class V6>
variant disp_call( IDispatch* disp, DISPID dispIdMember, V1& v1, V2& v2, V3& v3, V4& v4, V5& v5, V6& v6)
{
	variant var[] = {  variant(v6), variant(v5),
							variant(v4), variant(v3), 
							variant(v2), variant(v1) };
	DISPPARAMS dps = {&var,0,6,0};

	variant varResult;
	disp->Invoke( dispIdMember, IID_NULL, 
				  LOCALE_SYSTEM_DEFAULT, 
				  DISPATCH_METHOD, 
				  &dps, 
				  &varResult, NULL, NULL 
				 );
	return varResult;
}

///////////////////////////////////////////////////////////
// get/set Automation properties via IDispatch
///////////////////////////////////////////////////////////

HRESULT get    ( IDispatch* disp, DISPID id, variant* var );
HRESULT put    ( IDispatch* disp, DISPID id, variant* var );
HRESULT put_ref( IDispatch* disp, DISPID id, variant* var );


// oh my god ...

/////////////////////////////////////////////////////////////////////
// disp_font
/////////////////////////////////////////////////////////////////////

class disp_font
{
public:
	disp_font( IUnknown* unknwn )
		:ifont_(unknwn),font_(0)
	{
		if ( ifont_ )
		{
			if ( S_OK == ifont_->get_hFont(&font_) )
			{
				ifont_->AddRefHfont(font_); 
			}
		}
	}

	virtual ~disp_font()
	{
		if ( ifont_ && font_ )
		{
			ifont_->ReleaseHfont(font_);
		}
	}
	
	HFONT getFont()
	{
		return font_;
	}

	operator HFONT()
	{
		return getFont();
	}

protected:
	punk<IFont>				ifont_;
	HFONT                   font_;
};


inline void com_throw( const std::wstring& err, REFGUID guid, const std::wstring& src )
{
	mol::punk<ICreateErrorInfo> creator;

	if ( S_OK != ::CreateErrorInfo( &creator ) )
		return;

	if ( S_OK != creator->SetDescription( (LPOLESTR) err.c_str()) )
		return;

	if ( S_OK != creator->SetGUID( guid ) )
		return;

	if ( S_OK != creator->SetSource( (LPOLESTR) src.c_str()) )
		return;

	mol::punk<IErrorInfo> err_info(creator);
	::SetErrorInfo( 0, err_info  );
}

inline void com_throw( const std::string& err, REFGUID guid, const std::string& src )
{
	com_throw( mol::towstring(err), guid, mol::towstring(src) );
}

} // end namespace mole

#endif

