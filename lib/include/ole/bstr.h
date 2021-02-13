#ifndef MOL_COM_BSTR_DEF_GUARD_
#define MOL_COM_BSTR_DEF_GUARD_

#include "util/str.h"
#include "util/X.h"
#include "ole/com.h"

namespace mol {

///////////////////////////////////////////////////////////////////////
// these BSTRs, oh boy
///////////////////////////////////////////////////////////////////////

class bstr
{
public:
    bstr () 
		: bstr_(0) 
	{}

    bstr( const bstr& b ) 
		: bstr_(::SysAllocString(b.bstr_)) 
	{}

	explicit bstr( BSTR b ) 
		: bstr_(::SysAllocString(b)) 
	{}

    explicit bstr ( const std::string& str )  
		: bstr_(   ansi2BSTR(str) ) 
	{}

    explicit bstr ( const std::wstring& str ) 
		: bstr_( ::SysAllocString(str.c_str()) ) 
	{}

    ~bstr() 
	{ 
		if (bstr_) ::SysFreeString(bstr_); 
	}

    std::string tostring() 	
	{
		if ( !bstr_ )
			return "";
		return BSTR2ansi(bstr_); 
	}

    std::wstring towstring() 	
	{ 
		if ( !bstr_ )
			return L"";
		return std::wstring(bstr_); 
	}

	/*
    std::wstring toString() 	
	{ 
#ifdef _UNICODE
		return towstring();
#else
		return tostring();
#endif
	}
	*/

    bstr& operator=( const bstr& b )
    {
        if (bstr_) ::SysFreeString(bstr_);
        bstr_ = ::SysAllocString( b.bstr_  );
        return *this;
    }
    bstr& operator=( const BSTR& b )
    {
        if (bstr_) ::SysFreeString(bstr_);
        bstr_ = ::SysAllocString( b );
        return *this;
    }
    bstr& operator=( const std::string& str )
    {
        if (bstr_) ::SysFreeString(bstr_);
        bstr_ = ansi2BSTR( str );
        return *this;
    }
    bstr& operator=( const std::wstring wstr )
    {
        if (bstr_) ::SysFreeString(bstr_);
        bstr_ = ::SysAllocString( wstr.c_str() );
        return *this;
    }

    operator BSTR()           
	{ 
		return bstr_; 
	}

    BSTR* operator &()        
	{ 
		return &bstr_; 
	}

    BSTR	bstr_;
};



} // end namespace mol


#endif