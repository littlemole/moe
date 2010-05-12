#ifndef MOL_COM_VARIANT_DEF_GUARD_
#define MOL_COM_VARIANT_DEF_GUARD_

#pragma once

#include "util/uni.h"
#include "ole/obj.h"
#include "ole/bstr.h"
#include "util/x.h"
#include <oaidl.h>
#include <vector>
#include <list>

namespace mol {
namespace ole {

///////////////////////////////////////////////////////////////////////
// these VARIANTs, oh girl
///////////////////////////////////////////////////////////////////////


template<VARTYPE vt>
struct VariantTraits
{
public:
	typedef void*    type;
	static size_t    size() { return 0; }
};

///////////////////////////////////////////////////////////////////////

template<>
struct VariantTraits<VT_BOOL>
{
	typedef VARIANT_BOOL     type;
	static size_t			 size()
	{
		return sizeof(VARIANT_BOOL);
	}
};

///////////////////////////////////////////////////////////////////////

template<>
struct VariantTraits<VT_BSTR>
{
	typedef BSTR      type;
	static size_t     size()
	{
		return 0;
	}
};

///////////////////////////////////////////////////////////////////////

template<>
struct VariantTraits<VT_INT>
{
	typedef INT       type;
	static size_t     size()
	{
		return sizeof(INT);
	}
};

///////////////////////////////////////////////////////////////////////

template<>
struct VariantTraits<VT_UINT>
{
	typedef UINT      type;
	static size_t     size()
	{
		return sizeof(UINT);
	}
};

///////////////////////////////////////////////////////////////////////

template<>
struct VariantTraits<VT_I1>
{
	typedef CHAR      type;
	static size_t     size()
	{
		return sizeof(CHAR);
	}
};

///////////////////////////////////////////////////////////////////////

template<>
struct VariantTraits<VT_I2>
{
	typedef SHORT     type;
	static size_t     size()
	{
		return sizeof(SHORT);
	}
};

///////////////////////////////////////////////////////////////////////

template<>
struct VariantTraits<VT_I4>
{
	typedef LONG      type;
	static size_t     size()
	{
		return sizeof(LONG);
	}
};

///////////////////////////////////////////////////////////////////////

template<>
struct VariantTraits<VT_I8>
{
	typedef LONGLONG  type;
	static size_t     size()
	{
		return sizeof(LONGLONG);
	}
};

///////////////////////////////////////////////////////////////////////

template<>
struct VariantTraits<VT_UI1>
{
	typedef BYTE      type;
	static size_t     size()
	{
		return sizeof(BYTE);
	}
};

///////////////////////////////////////////////////////////////////////

template<>
struct VariantTraits<VT_UI2>
{
	typedef USHORT     type;
	static size_t      size()
	{
		return sizeof(USHORT);
	}
};

///////////////////////////////////////////////////////////////////////

template<>
struct VariantTraits<VT_UI4>
{
	typedef ULONG      type;
	static size_t      size()
	{
		return sizeof(ULONG);
	}
};

///////////////////////////////////////////////////////////////////////

template<>
struct VariantTraits<VT_UI8>
{
	typedef ULONGLONG  type;
	static size_t      size()
	{
		return sizeof(ULONGLONG);
	}
};

///////////////////////////////////////////////////////////////////////

template<>
struct VariantTraits<VT_R4>
{
	typedef FLOAT      type;
	static size_t      size()
	{
		return sizeof(FLOAT);
	}
};

///////////////////////////////////////////////////////////////////////

template<>
struct VariantTraits<VT_R8>
{
	typedef DOUBLE     type;
	static size_t      size()
	{
		return sizeof(DOUBLE);
	}
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template<class T>
struct VarTraits {
	static VARTYPE vt() { return VT_EMPTY };
};

template<>
struct VarTraits<VARIANT_BOOL> {
	static VARTYPE vt() { return VT_BOOL;}
};

template<>
struct VarTraits<VARIANT_BOOL*> {
	static VARTYPE vt() { return VT_BOOL|VT_BYREF;}
};

template<>
struct VarTraits<BSTR> {
	static VARTYPE vt() { return VT_BSTR;}
};


template<>
struct VarTraits<BSTR*> {
	static VARTYPE vt() { return VT_BSTR|VT_BYREF;}
};


template<>
struct VarTraits<INT> {
	static VARTYPE vt() { return VT_I4;} // changed from VT_INT
};

template<>
struct VarTraits<INT*> {
	static VARTYPE vt() { return VT_I4|VT_BYREF;} // changed from VT_INT
};

template<>
struct VarTraits<UINT> {
	static VARTYPE vt() { return VT_UI4;} // changed from VT_UINT
};

template<>
struct VarTraits<UINT*> {
	static VARTYPE vt() { return VT_UI4|VT_BYREF;} // changed from VT_UINT
};

template<>
struct VarTraits<CHAR> {
	static VARTYPE vt() { return VT_I1;}
};

template<>
struct VarTraits<CHAR*> {
	static VARTYPE vt() { return VT_I1|VT_BYREF;}
};

template<>
struct VarTraits<LONG> {
	static VARTYPE vt() { return VT_I4;}
};

template<>
struct VarTraits<LONG*> {
	static VARTYPE vt() { return VT_I4|VT_BYREF;}
};


template<>
struct VarTraits<LONGLONG> {
	static VARTYPE vt() { return VT_I8;}
};

template<>
struct VarTraits<LONGLONG*> {
	static VARTYPE vt() { return VT_I8|VT_BYREF;}
};

template<>
struct VarTraits<BYTE> {
	static VARTYPE vt() { return VT_UI1;}
};

template<>
struct VarTraits<BYTE*> {
	static VARTYPE vt() { return VT_UI1|VT_BYREF;}
};


template<>
struct VarTraits<USHORT> {
	static VARTYPE vt() { return VT_UI2;}
};

template<>
struct VarTraits<USHORT*> {
	static VARTYPE vt() { return VT_UI2|VT_BYREF;}
};

template<>
struct VarTraits<ULONG> {
	static VARTYPE vt() { return VT_UI4;}
};

template<>
struct VarTraits<ULONG*> {
	static VARTYPE vt() { return VT_UI4|VT_BYREF;}
};

template<>
struct VarTraits<ULONGLONG> {
	static VARTYPE vt() { return VT_UI8;}
};

template<>
struct VarTraits<ULONGLONG*> {
	static VARTYPE vt() { return VT_UI8|VT_BYREF;}
};

template<>
struct VarTraits<FLOAT> {
	static VARTYPE vt() { return VT_R4;}
};


template<>
struct VarTraits<FLOAT*> {
	static VARTYPE vt() { return VT_R4|VT_BYREF;}
};

template<>
struct VarTraits<DOUBLE> {
	static VARTYPE vt() { return VT_R8;}
};

template<>
struct VarTraits<DOUBLE*> {
	static VARTYPE vt() { return VT_R8|VT_BYREF;}
};

template<>
struct VarTraits<IUnknown*> {
	static VARTYPE vt() { return VT_UNKNOWN;}
};

template<>
struct VarTraits<IUnknown**> {
	static VARTYPE vt() { return VT_UNKNOWN|VT_BYREF;}
};

template<>
struct VarTraits<IDispatch*> {
	static VARTYPE vt() { return VT_DISPATCH;}
};

template<>
struct VarTraits<IDispatch**> {
	static VARTYPE vt() { return VT_DISPATCH|VT_BYREF;}
};

} // end namespace mol

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

class variant : public VARIANT
{
public:
    variant()  { ::VariantInit(this); }
    ~variant() { ::VariantClear(this); }

	explicit variant( VARENUM vt )  
	{ 
		::VariantInit(this); 
		changeType(vt); 
	}

    explicit variant( const VARIANT& v2)
    {
        ::VariantInit(this);
        VARIANT& tmp = (VARIANT&)v2;
        ::VariantCopy(this,&tmp);
    }

    variant( const variant& v2)
    {
        ::VariantInit(this);
        VARIANT& tmp = (VARIANT&)v2;
        ::VariantCopy(this,&tmp);
    }

    explicit variant( const std::string& str )
    {
		::VariantInit(this); 
        vt		= VT_BSTR;
        bstrVal = ansi2BSTR( str );
    }
    explicit variant( const std::wstring& str )
    {
		::VariantInit(this); 
        vt		= VT_BSTR;
        bstrVal = ::SysAllocString( str.c_str() );
    }
    explicit variant( const char* c )
    {
		::VariantInit(this); 
        vt		= VT_BSTR;
        bstrVal = ansi2BSTR( c );
    }
    explicit variant( const wchar_t* wc )
    {
		::VariantInit(this); 
        vt		= VT_BSTR;
        bstrVal = ::SysAllocString( wc );
    }

    explicit variant( long l )		    { ::VariantInit(this); vt =  VT_I4;	 lVal	 = l; }
    explicit variant( float f )		    { ::VariantInit(this);  vt =  VT_R4;	 fltVal	 = f; }
    explicit variant( double d )		{ ::VariantInit(this); vt =  VT_R8;	 dblVal	 = d; }
    explicit variant( VARIANT_BOOL b )	{ ::VariantInit(this); vt =  VT_BOOL; boolVal = b; }
    explicit variant( bool b )		    { ::VariantInit(this); vt =  VT_BOOL; boolVal = b ? VARIANT_TRUE : VARIANT_FALSE; }
    explicit variant( CY cy )		    { ::VariantInit(this); vt =  VT_CY;	 cyVal	 = cy;}
	explicit variant( BSTR b )		    { ::VariantInit(this); vt =  VT_BSTR; bstrVal = ::SysAllocString(b);}
    explicit variant( IUnknown* iu )
    {
		::VariantInit(this); 
        vt =  VT_UNKNOWN;
		punkVal = iu;
		if (iu)
			punkVal->AddRef();
    }
    explicit variant( IDispatch* di )
    {
		::VariantInit(this); 
        vt =  VT_DISPATCH;
		pdispVal = di;
		if (di)
			pdispVal->AddRef();
    }
    explicit variant( long* l )	        { ::VariantInit(this); vt =  VT_BYREF|VT_I4;	  plVal	   = l; }
    explicit variant( float* f )		{ ::VariantInit(this); vt =  VT_BYREF|VT_R4;	  pfltVal  = f; }
    explicit variant( double* d )		{ ::VariantInit(this); vt =  VT_BYREF|VT_R8;	  pdblVal  = d; }
    explicit variant( VARIANT_BOOL* b)	{ ::VariantInit(this); vt =  VT_BYREF|VT_BOOL; pboolVal = b; }
    explicit variant( CY* cy )		    { ::VariantInit(this); vt =  VT_BYREF|VT_CY;	  pcyVal   = cy;}
    explicit variant( BSTR* b )		    { ::VariantInit(this); vt =  VT_BYREF|VT_BSTR; pbstrVal = b; }
    explicit variant( IUnknown** iu )
    {
		::VariantInit(this); 
        vt =  VT_BYREF|VT_UNKNOWN;
		ppunkVal = iu;
		if (iu && *iu)
			(*ppunkVal)->AddRef();
    }
    explicit variant( IDispatch** di )
    {
		::VariantInit(this); 
        vt =  VT_BYREF|VT_DISPATCH;
		ppdispVal = di;
		if (di)
			(*ppdispVal)->AddRef();
    }
    explicit variant( VARIANT* vr )		{ ::VariantInit(this); vt =  VT_BYREF|VT_VARIANT; pvarVal = vr;}
    explicit variant( void* vo )		{ ::VariantInit(this); vt =  VT_BYREF;	 byref	= vo;}
    explicit variant( char c )		    { ::VariantInit(this); vt =  VT_I1;		 cVal	= c; }
    explicit variant( unsigned long l )	{ ::VariantInit(this); vt =  VT_UI4;		 ulVal	= l; }

//  changed type int to default to UI4, makes OLE happier
//  explicit variant( int i )		    { vt =  VT_INT;		 intVal	= i; }
//  explicit variant( unsigned int i )	{ vt =  VT_UINT;	 uintVal= i; }

    explicit variant( int i )		    { ::VariantInit(this); vt =  VT_I4;	 intVal	= i; }
    explicit variant( unsigned int i )	{ ::VariantInit(this); vt =  VT_UI4;	 uintVal= i; }

    explicit variant( unsigned long* l ){ ::VariantInit(this); vt =  VT_BYREF|VT_UI4; pulVal	= l; }

//  explicit variant( int* i )		    { vt =  VT_BYREF|VT_INT; pintVal= i; }
//  explicit variant( unsigned int* i)	{ vt = VT_BYREF|VT_UINT; puintVal= i;}

    explicit variant( int* i )		    { ::VariantInit(this); vt =  VT_BYREF|VT_I4; pintVal= i; }
    explicit variant( unsigned int* i)	{ ::VariantInit(this); vt = VT_BYREF|VT_UI4; puintVal= i;}

	template<VARTYPE VT>
	explicit variant( SAFEARRAY** sfa)	{ ::VariantInit(this); vt = VT_ARRAY|VT|VT_BYREF; pparray = sfa;}

	template<VARTYPE VT>
	explicit variant( SAFEARRAY* sfa)	{ ::VariantInit(this); vt = VT_ARRAY|VT; parray = sfa;}

    variant& operator=( const VARIANT& v2)
    {
        ::VariantClear(this);
        VARIANT& tmp = (VARIANT&) v2;
        ::VariantCopy(this,&tmp);
        return *this;
    }
	variant& operator=( const variant& v2)
    {
        ::VariantClear(this);
        VARIANT& tmp = (VARIANT&) v2;
        ::VariantCopy(this,&tmp);
        return *this;
    }

	void Copy( variant& v)
    {
        ::VariantClear(&v);
        ::VariantCopy(&v,this);
    }

    bool isType( VARTYPE VT)
    {
        return ( vt == VT );
    }

    void changeType( VARTYPE VT)
    {
        ::VariantChangeType( this, this, VARIANT_NOUSEROVERRIDE, VT);
    }

    std::string tostring()
    {
        if ( vt == VT_BSTR )
        {
            return BSTR2ansi( bstrVal );
        }
        if ( vt == (VT_BSTR|VT_BYREF) )
        {
            return BSTR2ansi( *pbstrVal );
        }
        changeType(VT_BSTR);
        return BSTR2ansi( bstrVal );
    }

    std::wstring towstring()
    {
        if ( vt == VT_BSTR )
        {
            return std::wstring( (wchar_t*)bstrVal ) ;
        }
        if ( vt == (VT_BSTR|VT_BYREF) )
        {
            return std::wstring( * (wchar_t**)pbstrVal );
        }
        changeType(VT_BSTR);
        return std::wstring( (wchar_t*)bstrVal ) ;
    }

    mol::string toString()
    {
#ifdef _UNICODE
		return towstring();
#else
		return tostring();
#endif
    }

	void toStream( IStream* stream );
	void fromStream( IStream* stream );

};

template<class T>
T& valueOf( mol::variant& v)
{
	if ( v.vt == mol::ole::VarTraits<T>::vt() )
	{
		return (T&)(*pintVal);
		return t;
	}
	mol::variant tmp(v);
	tmp.changeType(mol::ole::VarTraits<T>::vt());
	return (T&)(*tmp.pintVal);
}


mol::string valueOf( mol::variant& v);

//BSTR valueOf( mol::variant& v);


///////////////////////////////////////////////////////////////////////
// hate, hate, hate
///////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// encapsulate One-Dimensional SafeArrays
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// make SAFEARRAYBOUND more handsome
//////////////////////////////////////////////////////////////////////

struct ArrayBound : public SAFEARRAYBOUND 
{
	ArrayBound(long SZ, long LB = 0)
	{
		this->cElements = SZ;
		this->lLbound   = LB;
	}
};

namespace ole { 

//////////////////////////////////////////////////////////////////////
// wrap low-level API
//////////////////////////////////////////////////////////////////////

class SafeArrayBase
{
public:
	SafeArrayBase(void)
		:sfArray_(0)
	{}

	virtual ~SafeArrayBase()
	{}

	void Create( VARTYPE vt, UINT cdims, SAFEARRAYBOUND* sfb )
	{
		sfArray_ = ::SafeArrayCreate( vt, cdims, sfb );
	}

	void Create( VARTYPE vt, UINT cdims, const SAFEARRAYBOUND& sfb )
	{
		sfArray_ = ::SafeArrayCreate( vt, cdims, (SAFEARRAYBOUND*)&sfb );
	}

	void Create( VARTYPE vt, int i )
	{
		ArrayBound ab(i);
		sfArray_ = ::SafeArrayCreate( vt, 1, &ab );
	}

	void Attach(SAFEARRAY* a)
	{
		sfArray_ = a;
	}

	void Detach()
	{
		sfArray_ = 0;
	}

	void Destroy()
	{
		if (sfArray_)
		{
			HRESULT hr = ::SafeArrayDestroy(sfArray_);
			sfArray_ = 0;
		}
	}

	HRESULT Copy( SAFEARRAY **  ppsaOut  )
	{
		ArrayBound ab(size());
		if ( *ppsaOut )
			::SafeArrayRedim(*ppsaOut,&ab);
		else
		{
			VARTYPE vt;
			this->GetVartype(&vt);
			*ppsaOut = ::SafeArrayCreate(vt,1,&ab);
		}
		return ::SafeArrayCopy( sfArray_, ppsaOut );
	}

	HRESULT Copy( VARIANT& var  )
	{
		var.vt = var.vt | (VT_ARRAY|VT_VARIANT);
		if ( var.vt & VT_BYREF )
			return Copy(var.pparray);
		else
			return Copy( &(var.parray) );
	}
	
	UINT GetDim( )
	{
		return ::SafeArrayGetDim(sfArray_);
	}

	HRESULT GetElement( long Index, void *  pv )
	{
		return ::SafeArrayGetElement( sfArray_, &Index,  pv );
	}

	HRESULT GetElement( long* Index, void *  pv )
	{
		return ::SafeArrayGetElement( sfArray_, Index,  pv );
	}

	UINT GetElemsize()
	{
		return ::SafeArrayGetElemsize( sfArray_ );
	}

	HRESULT GetIID( GUID* pguid )
	{
		return ::SafeArrayGetIID( sfArray_, pguid );
	}

	HRESULT GetLBound( long* pLbound, long dim = 1 )
	{
		return ::SafeArrayGetLBound( sfArray_, dim, pLbound );
	}

	HRESULT GetUBound( long* pLbound, long dim = 1 )
	{
		return ::SafeArrayGetUBound( sfArray_, dim, pLbound );
	}

	HRESULT GetVartype(  VARTYPE *  pvt   )
	{
		return ::SafeArrayGetVartype( sfArray_, pvt );
	}

	HRESULT PutElement( long index, void* pv )
	{
		return ::SafeArrayPutElement( sfArray_, &index, pv );
	}

	HRESULT PutElement( long* index, void* pv )
	{
		return ::SafeArrayPutElement( sfArray_, index, pv );
	}

	HRESULT ReDim (SAFEARRAYBOUND *  psaboundNew)
	{
		return ::SafeArrayRedim( sfArray_, psaboundNew );
	}

	HRESULT ReDim (SAFEARRAYBOUND&  psaboundNew)
	{
		return ::SafeArrayRedim( sfArray_, (SAFEARRAYBOUND*)&psaboundNew );
	}

	HRESULT ReDim (int i)
	{
		ArrayBound ab(i);
		return ::SafeArrayRedim( sfArray_, &ab );
	}

	HRESULT SetIID( REFGUID guid )
	{
		return ::SafeArraySetIID( sfArray_, guid );
	}

	HRESULT AccessData( void ** ppData )
	{
		return ::SafeArrayAccessData( sfArray_, ppData );
	}

	HRESULT UnaccessData( )
	{
		return ::SafeArrayUnaccessData( sfArray_ );
	}

	operator SAFEARRAY*()
	{
		return sfArray_;
	}

	long size(int index = 0)
	{
		return sfArray_->rgsabound[index].cElements;
	}

	long ubound(int index = 0)
	{
		long ub=0;
		::SafeArrayGetUBound(sfArray_,index,&ub);
		return ub;
	}

	long lbound(int index = 0)
	{
		long lb=0;
		::SafeArrayGetLBound(sfArray_,index,&lb);
		return lb;
	}


protected:
    SAFEARRAY*		sfArray_;
};

} // end namespace ole

//////////////////////////////////////////////////////////////////////
// manage direct array access
//////////////////////////////////////////////////////////////////////

template<class T>
class SFAccess
{
public:

	SFAccess( SAFEARRAY* s )
		: data_(0)
	{
        sfb_.Attach(s);
		sfb_.AccessData( (void**) &data_ );
	}

	~SFAccess( )
	{
		if ( data_ )
			sfb_.UnaccessData();
		sfb_.Detach();
	}

	T* operator()()
	{
		return data_;
	}

	T& operator[] (int index)
	{
		return ((data_[index]));
	}

	long size()
	{
		return sfb_.size();
	}

private:
	mol::ole::SafeArrayBase		sfb_;
	T*							data_;
};

//////////////////////////////////////////////////////////////////////
// initialization helper
//////////////////////////////////////////////////////////////////////

template<VARTYPE VT> 
void SafeArrayInit( mol::ole::SafeArrayBase& sf, wchar_t** str, int s );

//////////////////////////////////////////////////////////////////////
// spec for BSTR
//////////////////////////////////////////////////////////////////////

template<>
void SafeArrayInit<VT_BSTR> ( mol::ole::SafeArrayBase& sf, wchar_t** str, int s );

//////////////////////////////////////////////////////////////////////

template<>
void SafeArrayInit<VT_VARIANT> ( mol::ole::SafeArrayBase& sf, wchar_t** str, int s );

//////////////////////////////////////////////////////////////////////
// one dimensional SafeArray of VARTYPE VT
//////////////////////////////////////////////////////////////////////

template<VARTYPE VT>
class SafeArray : public mol::ole::SafeArrayBase
{
public:
	SafeArray()
	{}

	SafeArray(SAFEARRAYBOUND& sfb)
	{
		this->Create(sfb);
	}

	SafeArray( SAFEARRAY* sf)
	{
		long ub,lb;
		::SafeArrayGetUBound(sf,1,&ub);
		::SafeArrayGetLBound(sf,1,&lb);
		ArrayBound ab(ub-lb+1,lb);
		this->Create(ab);
		::SafeArrayCopy( sf, &(this->sfArray_));
	}

	SafeArray(wchar_t** str, int s )
	{
		ArrayBound ab(s);
		this->Create(ab);
		SafeArrayInit<VT>(*this,str,s);
	}

	~SafeArray(void)
	{
		SafeArrayBase::Destroy();
	}

	SafeArray& operator=(const SAFEARRAY* sf)
	{
		this->Destroy();
		long ub,lb;
		::SafeArrayGetUBound((SAFEARRAY*)sf,1,&ub);
		::SafeArrayGetLBound((SAFEARRAY*)sf,1,&lb);
		ArrayBound ab(ub-lb+1,lb);
		this->Create(ab);
		::SafeArrayCopy((SAFEARRAY*)sf,&sfArray_);		
		return *this;
	}

	SafeArray& operator=(const VARIANT& var)
	{
		if ( var.vt & VT_BYREF )
			*this = *(var.pparray);
		else
			*this = (var.parray);

		return *this;
	}

	SAFEARRAY** operator&()
	{
		return &sfArray_;
	}

	operator SAFEARRAY*()
	{
		return sfArray_;
	}
	void Create( const SAFEARRAYBOUND& sfb )
	{
        if ( sfArray_ )
            Destroy();
		sfArray_ = ::SafeArrayCreate( VT, 1, (SAFEARRAYBOUND*)&sfb );
	}

};

/////////////////////////////////////////////////////////////////////
// Var Enums 
/////////////////////////////////////////////////////////////////////

class enum_variant : 
	public IEnumVARIANT,
	public interfaces< enum_variant, implements<IEnumVARIANT> >
{
public:
	enum_variant();
	virtual ~enum_variant();

	virtual void dispose() {}

	void add(VARIANT& var);

	HRESULT virtual __stdcall Next( ULONG celt, VARIANT* rgelt, ULONG * pceltFetched );
	HRESULT virtual __stdcall Skip( ULONG celt );
	HRESULT virtual __stdcall Reset(void);
	HRESULT virtual __stdcall Clone( IEnumVARIANT ** ppenum );

private:
	std::vector<VARIANT>						variants_;
	std::vector<VARIANT>::iterator				it_;
	mol::Mutex									mutex_;
};


class COMCollection
{
public:

	HRESULT virtual __stdcall _NewEnum(IEnumVARIANT** newEnum);
	HRESULT virtual __stdcall Item( VARIANT index, VARIANT* wnd);
	HRESULT virtual __stdcall Count( VARIANT* cnt);
	HRESULT virtual __stdcall Add( VARIANT var );
	HRESULT virtual __stdcall Insert( VARIANT index, VARIANT var );
	HRESULT virtual __stdcall InsertAt( VARIANT pos, VARIANT index, VARIANT var );
	HRESULT virtual __stdcall Remove( VARIANT index);
	HRESULT virtual __stdcall Rename( VARIANT index, VARIANT newIndex );
	HRESULT virtual __stdcall Move( VARIANT what, VARIANT to);

protected:

	typedef std::list<std::pair<variant,variant> > varlist;
	varlist	variants_;

	varlist::iterator iterator(VARIANT& index);

	int key2index( VARIANT& index );
};



} // end namespace mol


#endif