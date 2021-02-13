#ifndef MOL_COM_PERSISTANCE_DEF_GUARD_
#define MOL_COM_PERSISTANCE_DEF_GUARD_

#pragma once
#include "util/uni.h"
#include "ole/punk.h"
#include "ole/aut.h"
#include "ole/variant.h"
#include <ocidl.h>
#include <vector>
//#include "boost/call_traits.hpp"

namespace mol {



class DispId
{
public:
	DispId( IDispatch* d, int i, VARTYPE t )
		: disp(d), id(i), vt(t)
	{}

	IDispatch* disp;
	int id;
	VARTYPE vt;
};

namespace persist {

template<class T>
class Property
{
public:

	Property( T* t)
		: t_(t)
	{}

	Property( const std::wstring& name, T* t)
		: name_(name), t_(t)
	{}

	void write( IPropertyBag* bag )
	{
		mol::variant v( *t_ );
		bag->Write( mol::towstring(name_).c_str(), &v );
	}

	void load( IPropertyBag* bag )
	{
		mol::variant v;
		bag->Read( mol::towstring(name_).c_str(),&v, 0 );

		*t_ = mol::valueOf<T>(v);
	}

	void write( IStream* stream )
	{
		ULONG written = 0;
		HRESULT hr = stream->Write( t_, sizeof(T), &written );
	}

	void read( IStream* stream )
	{
		ULONG read = 0;
		HRESULT hr = stream->Read( t_, sizeof(T), &read );
	}

private:
	std::wstring name_;
	T* t_;
};

template<>
class Property<SIZEL>
{
public:

	Property( SIZEL* t)
		: t_(t)
	{}

	Property( const std::wstring& name, SIZEL* t)
		: name_(name), t_(t)
	{}

	void write( IPropertyBag* bag )
	{
		std::ostringstream oss;
		oss << t_->cx << "|" << t_->cy;

		mol::variant v( oss.str() );
		bag->Write( mol::towstring(name_).c_str(), &v );
	}

	void load( IPropertyBag* bag )
	{
		mol::variant v;
		bag->Read( mol::towstring(name_).c_str(),&v, 0 );

		std::string s = mol::valueOf<std::string>(v);
		std::vector<std::string> xy = mol::split(s,"|");

		if ( xy.size() > 1 )
		{
			std::istringstream x(xy[0]);
			x >> t_->cx;
			std::istringstream y(xy[1]);
			y >> t_->cy;
		}
	}


	void write( IStream* stream )
	{
		ULONG written = 0;
		HRESULT hr = stream->Write( t_, sizeof(SIZEL), &written );
	}

	void read( IStream* stream )
	{
		ULONG read = 0;
		HRESULT hr = stream->Read( t_, sizeof(SIZEL), &read );
	}

private:
	std::wstring name_;
	SIZEL* t_;
};

template<>
class Property<mol::bstr>
{
public:

	Property( mol::bstr& b)
		: bstr_(b)
	{}

	Property( const std::wstring& name, mol::bstr& b)
		: name_(name), bstr_(b)
	{}

	void write( IPropertyBag* bag )
	{
		mol::variant v( bstr_ );
		bag->Write( mol::towstring(name_).c_str(), &v );
	}

	void load( IPropertyBag* bag )
	{
		mol::variant v;
		bag->Read( mol::towstring(name_).c_str(),&v, 0 );
		bstr_ = v.bstrVal;
	}


	void write( IStream* stream )
	{
		ULONG written = 0;
		int len = ::SysStringByteLen(bstr_);
		HRESULT hr = stream->Write( &len, sizeof(int), &written );
		if ( len > 0 )
		{
			hr = stream->Write( bstr_.bstr_, len, &written );
		}
	}

	void read( IStream* stream )
	{
		ULONG read = 0;
		int len = 0;
		HRESULT hr = stream->Read( &len, sizeof(len), &read );
		if ( len > 0 )
		{
			mol::cbuff buf(len+2);
			hr = stream->Read( buf, len, &read );
			buf[len]   = 0;
			buf[len+1] = 0;
			bstr_ = ::SysAllocString( (OLECHAR*)(char*)buf );
		}
	}

private:
	mol::bstr& bstr_;
	std::wstring name_;
};


template<>
class Property<std::string>
{
public:

	Property( std::string& s)
		: str_(s)
	{}

	Property( const std::wstring& name, std::string& s)
		: name_(name), str_(s)
	{}

	void write( IPropertyBag* bag )
	{
		mol::variant v( str_ );
		bag->Write( mol::towstring(name_).c_str(), &v );
	}

	void load( IPropertyBag* bag )
	{
		mol::variant v;
		bag->Read( mol::towstring(name_).c_str(),&v, 0 );
		str_ = v.tostring();
	}


	void write( IStream* stream )
	{
		ULONG written = 0;
		size_t len = str_.size();
		HRESULT hr = stream->Write( &len, sizeof(int), &written );
		if ( len > 0 )
		{
			hr = stream->Write( str_.c_str(), (ULONG)len, &written );
		}
	}

	void read( IStream* stream )
	{
		ULONG read = 0;
		int len = 0;
		HRESULT hr = stream->Read( &len, sizeof(len), &read );
		if ( len > 0 )
		{
			mol::cbuff buf(len+1);
			hr = stream->Read( buf, len, &read );
			buf[len]   = 0;
			str_ = buf.toString(len);
		}
	}

private:
	std::string& str_;
	std::wstring name_;
};



template<>
class Property<std::wstring>
{
public:

	Property( std::wstring& s)
		: str_(s)
	{}

	Property( const std::wstring& name, std::wstring& s)
		: name_(name), str_(s)
	{}

	void write( IPropertyBag* bag )
	{
		mol::variant v( str_ );
		bag->Write( mol::towstring(name_).c_str(), &v );
	}

	void load( IPropertyBag* bag )
	{
		mol::variant v;
		bag->Read( mol::towstring(name_).c_str(),&v, 0 );
		str_ = v.towstring();
	}

	void write( IStream* stream )
	{
		ULONG written = 0;
		size_t len = str_.size();
		HRESULT hr = stream->Write( &len, sizeof(int), &written );
		if ( len > 0 )
		{
			hr = stream->Write( str_.c_str(), (ULONG)(len * sizeof(wchar_t)), &written );
		}
	}

	void read( IStream* stream )
	{
		ULONG read = 0;
		int len = 0;
		HRESULT hr = stream->Read( &len, sizeof(len), &read );
		if ( len > 0 )
		{
			mol::wbuff buf(len+1);
			hr = stream->Read( (void*)buf, len* sizeof(wchar_t), &read );
			buf[len]   = 0;
			str_ = buf.toString(len);
		}
	}
private:
	std::wstring& str_;
	std::wstring name_;
};


template<>
class Property<mol::DispId>
{
public:
	Property( const std::wstring& name, mol::DispId id)
		: name_(name), id_(id)
	{}

	Property( mol::DispId id)
		: id_(id)
	{}

	void write( IPropertyBag* bag )
	{
		mol::variant v;
		HRESULT hr = mol::get( id_.disp, id_.id, &v );
		if ( hr == S_OK )
		{
			bag->Write( mol::towstring(name_).c_str(), &v );
		}
	}

	void load( IPropertyBag* bag )
	{
		mol::variant v;
		bag->Read( mol::towstring(name_).c_str(),&v, 0 );

		HRESULT hr = mol::put( id_.disp, id_.id, &v);
	}

	void write( IStream* stream )
	{
		mol::variant v;
		HRESULT hr = mol::get( id_.disp, id_.id, &v );
		v.toStream(stream);
	}

	void read( IStream* stream )
	{
		variant v((BSTR)0);
		v.vt = id_.vt;
		v.fromStream(stream);

		HRESULT hr = mol::put( id_.disp, id_.id, &v);
	}

private:
	std::wstring name_;
	mol::DispId id_;
};

	
} // end namespace persist
} // end namespace mol

template<class T>
IPropertyBag* operator<<( IPropertyBag* bag, mol::persist::Property<T> prop ) 
{
	prop.write(bag);
	return bag;
}

template<class T>
IPropertyBag* operator>>( IPropertyBag* bag, mol::persist::Property<T> prop ) 
{
	prop.load(bag);
	return bag;
}


template<class T>
IStream* operator<<( IStream* stream, mol::persist::Property<T> prop ) 
{
	prop.write(stream);
	return stream;
}

template<class T>
IStream* operator>>( IStream* stream, mol::persist::Property<T> prop ) 
{
	prop.read(stream);
	return stream;
}

namespace mol {

template<class T>
mol::persist::Property<T> property( const std::wstring& name, T* t)
{
	return mol::persist::Property<T>(name,t);
}

template<class T>
mol::persist::Property<T> property( T* t)
{
	return mol::persist::Property<T>(t);
}


inline mol::persist::Property<mol::DispId> property( const std::wstring& name, mol::DispId t)
{
	return mol::persist::Property<mol::DispId>(name,t);
}

inline mol::persist::Property<mol::DispId> property( mol::DispId t)
{
	return mol::persist::Property<mol::DispId>(t);
}

inline mol::persist::Property<mol::bstr> property( mol::bstr t)
{
	return mol::persist::Property<mol::bstr>(t);
}

inline mol::persist::Property<mol::bstr> property( const std::wstring& name, mol::bstr& t)
{
	return mol::persist::Property<mol::bstr>(name,t);
}

namespace ole {

/////////////////////////////////////////////////////////////////////
// Persistence 
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
// Persist Property Support
/////////////////////////////////////////////////////////////////////
/*
class IProperty
{
public:

	virtual const GUID*  prop_guid() = 0;

	virtual HRESULT __stdcall Load( IDispatch* disp, LPSTREAM pStm) = 0;
	virtual HRESULT __stdcall Save( IDispatch* disp, LPSTREAM pStm) = 0;
    virtual HRESULT __stdcall GetSizeMax( IDispatch* disp,ULARGE_INTEGER *pCbSize) = 0;
    virtual HRESULT __stdcall InitNew(IDispatch* disp) = 0;
	virtual HRESULT __stdcall Load( IDispatch* disp,IPropertyBag *pPropBag) = 0;
	virtual HRESULT __stdcall Save( IDispatch* disp,IPropertyBag *pPropBag) = 0;
};


template<class T>
class ClassProperties
{
public:

	void add( IProperty* prop )
	{
		properties_.push_back(prop);
	}

	std::vector<IProperty*>& get()
	{
		return properties_;
	}

private:
	std::vector<IProperty*> properties_;
};

template<class T>
ClassProperties<T>& properties()
{
	return mol::singleton<ClassProperties<T>>();
}

/////////////////////////////////////////////////////////////////////

template<class T,class S>
class TProperty : public IProperty
{
public:

	typedef mol::MemberPtr<T,S> Ptr;

	TProperty( Ptr p, const char* k )
		:ptr(p), key(k)
	{}

	virtual ~TProperty()
	{}

	virtual const GUID*  prop_guid() 
	{
		return &CLSID_NULL;
	}

	virtual HRESULT __stdcall Load( IDispatch* disp, LPSTREAM pStm) 
	{
		variant v;
		v.fromStream(pStm);	
		S* s = dynamic_cast<S*>(disp);
		T* t = ptr(s);
		*t = valueOf<T>(v);
		return S_OK;
	}

	virtual HRESULT __stdcall Save( IDispatch* disp, LPSTREAM pStm)
	{
		S* s = dynamic_cast<S*>(disp);
		T* t = ptr(s);
		variant v(*t);
		v.toStream(pStm);
		return S_OK;
	}

    virtual HRESULT __stdcall GetSizeMax( IDispatch* disp, ULARGE_INTEGER *pCbSize)
	{
		pCbSize->QuadPart += sizeof(variant);
		return S_OK;
	}

    virtual HRESULT __stdcall InitNew(IDispatch* disp)
	{
		return S_OK;
	}

	virtual HRESULT __stdcall Load( void* disp, IPropertyBag *pPropBag) 
	{
		variant v((BSTR)0);
		if ( S_OK == pPropBag->Read( mol::ansi2wstring(key).c_str(), &v, NULL ) )
		{
			S* s = dynamic_cast<S*>(disp);
			T* t = ptr(s);
			*t = valueOf<T>(v);
		}
		return S_OK;
	}

	virtual HRESULT __stdcall Save( IDispatch* disp, IPropertyBag *pPropBag) 
	{
		S* s = dynamic_cast<S*>(disp);
		T* t = ptr(s);
		variant v(*t);
		v.changeType(VT_BSTR);
		pPropBag->Write( mol::ansi2wstring(key).c_str(), &v );
		return S_OK;
	}

	Ptr				ptr;
	const char*		key;
};
/////////////////////////////////////////////////////////////////////

template<class S>
class TProperty<SIZEL,S> : public IProperty
{
public:

	typedef mol::MemberPtr<SIZEL,S> Ptr;

	TProperty( Ptr p, const char* k )
		:ptr(p), key(k)
	{}

	virtual ~TProperty()
	{}

	virtual const GUID*  prop_guid() 
	{
		return &CLSID_NULL;
	}

	virtual HRESULT __stdcall Load( IDispatch* disp, LPSTREAM pStm) 
	{
		S* s = dynamic_cast<S*>(disp);
		SIZEL* t = ptr(s);
		ULONG len = 0;
		return pStm->Read( (void*)t, sizeof(SIZEL), &len);
	}

	virtual HRESULT __stdcall Save( IDispatch* disp, LPSTREAM pStm)
	{
		S* s = dynamic_cast<S*>(disp);
		SIZEL* t = ptr(s);
		ULONG len = 0;
		return pStm->Write( (void*)t, sizeof(SIZEL), &len);
	}

    virtual HRESULT __stdcall GetSizeMax( IDispatch* disp, ULARGE_INTEGER *pCbSize)
	{
		pCbSize->QuadPart += sizeof(SIZEL);
		return S_OK;
	}

    virtual HRESULT __stdcall InitNew(IDispatch* disp)
	{
		S* s = dynamic_cast<S*>(disp);
		SIZEL* t = ptr(s);
		t->cx = (LONG)0;
		t->cy = (LONG)0;
		return S_OK;
	}

	virtual HRESULT __stdcall Load( IDispatch* disp, IPropertyBag *pPropBag) 
	{
		variant v((BSTR)0);
		if ( S_OK == pPropBag->Read( mol::ansi2wstring(key).c_str(), &v, NULL ) )
		{
			std::wstring s = v.toString();
			std::vector<std::string> xy = mol::split(mol::tostring(s),"|");
			if ( xy.size() > 1 )
			{
				S* s = dynamic_cast<S*>(disp);
				SIZEL* t = ptr(s);
				std::istringstream x(mol::tostring(xy[0]));
				x >> t->cx;
				std::istringstream y(mol::tostring(xy[1]));
				y >> t->cy;
			}
		}
		return S_OK;
	}

	virtual HRESULT __stdcall Save( IDispatch* disp, IPropertyBag *pPropBag) 
	{
		S* s = dynamic_cast<S*>(disp);
		SIZEL* t = ptr(s);
		
		std::ostringstream oss;
		oss << t->cx << "|" << t->cy;
		variant v(oss.str());
		pPropBag->Write( mol::ansi2wstring(key).c_str(), &v );
		return S_OK;
	}

	Ptr				ptr;
	const char*		key;
};

/////////////////////////////////////////////////////////////////////
// COM visible properties
/////////////////////////////////////////////////////////////////////

class GetPutProperty : public IProperty
{
public:

	GetPutProperty( const char* k, DISPID i,  VARTYPE v, const GUID* p );

	virtual ~GetPutProperty();

	virtual const GUID*  prop_guid() 
	{
		return guid;
	}

	virtual HRESULT __stdcall Load( IDispatch* d,LPSTREAM pStm);
	virtual HRESULT __stdcall Save( IDispatch* d,LPSTREAM pStm);
    virtual HRESULT __stdcall GetSizeMax( IDispatch* d,ULARGE_INTEGER *pCbSize);
    virtual HRESULT __stdcall InitNew(IDispatch* d);
	virtual HRESULT __stdcall Load( IDispatch* d,IPropertyBag *pPropBag);
	virtual HRESULT __stdcall Save( IDispatch* d,IPropertyBag *pPropBag);

	VARTYPE         vt;
	DISPID			diid;
	const char*		key;
	const GUID*		guid;
};

template<class T,class S>
TProperty<T,S>* make_property( T S::* mp , const char* key )
{
	return new TProperty<T,S>( mp, key );
}

GetPutProperty* make_property( const char* key, DISPID d, VARTYPE v, const GUID* g );

/////////////////////////////////////////////////////////////////////
// helper macro to declare an inner class which sole purpose
// is to add an entry to the property map on construction of the
// outer class
/////////////////////////////////////////////////////////////////////

#define persist_member( k, mfp )										\
class MOL_PROP_IMPL_##C##_##k##_										\
{																		\
public:																	\
	MOL_PROP_IMPL_##C##_##k##_()										\
	{																	\
		static int i = init();											\
	}																	\
																		\
	static int init()													\
	{																	\
		mol::ole::properties<com_creatable_type>()						\
		.add(mol::ole::make_property( &com_creatable_type::##mfp, #k ));\
		return 0;														\
	}																	\
} k##_member_;

/////////////////////////////////////////////////////////////////////
// and same for COM properties w get/set impl
/////////////////////////////////////////////////////////////////////

#define persist_property( d, vt, p )									\
class MOL_PROP_IMPL_##C##_##d##_										\
{																		\
public:																	\
	MOL_PROP_IMPL_##C##_##d##_()										\
	{																	\
		static int i = init();											\
	}																	\
																		\
	static int init()													\
	{																	\
		mol::ole::properties<com_creatable_type>()						\
			.add(mol::ole::make_property(								\
					#d,													\
					d,													\
					vt,													\
					p													\
				));														\
		return 0;														\
	}																	\
} d##_member_;
*/
///////////////////////////////////////////////////////////

} // end namespace ole

class enum_statstg : public punk<IEnumSTATSTG>
{
public:
	enum_statstg()
	{
		//::ZeroMemory(&stats,sizeof(stats));
	}

	~enum_statstg()
	{
		//if ( stats->pwcsName )
			//::CoTaskMemFree(stats.pwcsName);
	}

	bool next()
	{		
		stats.clear();
		if ( S_OK == interface_->Next(1,&stats,0) )
		{
			return true;
		}
		return false;
	}

	//STATSTG stats;
	CoSTATSTGBuf stats;
};

///////////////////////////////////////////////////////////

class Storage : public punk<IStorage>
{
public:

    Storage() {}									
    Storage( IUnknown* iUnknown)					
        : punk<IStorage>(iUnknown) {}		
    Storage( punk<IStorage>& iUnknown )		
        : punk<IStorage>(iUnknown) {}		
    virtual ~Storage() {}							
    Storage& operator=( Storage& c )				
    {											
        if ( c == *this )                       
            return *this;                       
        release();								
        interface_ = c.interface_ ;		    
		interface_->AddRef();
        return *this;							
	}

	bool create( const std::wstring& path, DWORD flags = STGM_READWRITE | STGM_SHARE_EXCLUSIVE|STGM_CREATE )
	{
		release();
		if ( S_OK == ::StgCreateDocfile(mol::towstring(path).c_str(),flags ,0,&interface_) )
			return true;
		return false;
	}

	bool open( const std::wstring& path, DWORD flags = STGM_READ | STGM_SHARE_EXCLUSIVE )
	{
		release();
		HRESULT hr = ::StgOpenStorage( mol::towstring(path).c_str(), NULL,flags,0,0,&interface_);
		if ( S_OK == hr )
			return true;
		return false;
	}

	bool read( IUnknown* unk )
	{
		punk<IPersistStorage> ps(unk);
		if ( ps )
			if ( S_OK == ps->Load(interface_) )
				return true;
		return false;
	}

	bool write( IUnknown* unk )
	{
		punk<IPersistStorage> ps(unk);
		if ( ps )
			if ( S_OK == ps->Save(interface_,FALSE) )
				return true;
		return false;
	}

	REFCLSID clsid()
	{
		if ( interface_ )
		{		
			if ( S_OK == ::ReadClassStg(interface_,&clsid_) )
				return clsid_;
		}
		return CLSID_NULL;
	}

	bool clsid( REFCLSID clsid)
	{
		if ( S_OK == ::WriteClassStg(interface_,clsid) )
			return true;
		return false;
	}

	HRESULT enumerator(IEnumSTATSTG** enumStat)
	{
		return interface_->EnumElements(0,0,0,enumStat);
	}

private:

	CLSID clsid_;
	enum_statstg enum_;
};

/////////////////////////////////////////////////////////////////////
// Property Bags
/////////////////////////////////////////////////////////////////////

template<class T>
class PersistPropertybag : public IPersistPropertyBag
{
public:

	PersistPropertybag()
	{}

	virtual ~PersistPropertybag()
	{}

    virtual HRESULT __stdcall GetClassID( CLSID * pClassID)
	{
		*pClassID = T::getCoClassID();
		return S_OK;
	}
	virtual HRESULT __stdcall InitNew() 
	{
		T* t = (T*)this;
/*
		std::vector<mol::ole::IProperty*>& props = mol::ole::properties<T>().get();

		for ( unsigned int i = 0; i < props.size(); i++ )
		{
			props[i]->InitNew(t);
		}
*/
		t->setDirty(FALSE);
		return S_OK;
	}
/*
	virtual HRESULT __stdcall Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog) 
	{
		T* t = (T*)this;

		/*
		std::vector<mol::ole::IProperty*>& props = mol::ole::properties<T>().get();
		for ( unsigned int i = 0; i < props.size(); i++ )
		{
			props[i]->Load(t,pPropBag);
		}
		* /
		t->setDirty(FALSE);
		return S_OK;
	}

	virtual HRESULT __stdcall Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties) 
	{
		T* t = (T*)this;
		/*
		std::vector<mol::ole::IProperty*>& props = mol::ole::properties<T>().get();
		for ( unsigned int i = 0; i < props.size(); i++ )
		{
			props[i]->Save(t,pPropBag);
		}
		* /
		t->setDirty(FALSE);
		return S_OK;
	}
	*/
};

/////////////////////////////////////////////////////////////////////
// Persist Stream
/////////////////////////////////////////////////////////////////////

template<class T>
class PersistStream : public IPersistStreamInit
{
public:

	PersistStream()	{}
	virtual ~PersistStream() {}

    virtual HRESULT __stdcall IsDirty( void)
	{
		T* t = (T*)this;
		return t->isDirty() == TRUE ? S_OK : S_FALSE;
	}
    /*
    virtual HRESULT __stdcall Load( LPSTREAM pStm) 
	{
		T* t = (T*)this;
		/*
		std::vector<mol::ole::IProperty*>& props = mol::ole::properties<T>().get();
		for ( unsigned int i = 0; i < props.size(); i++ )
		{
			props[i]->Load(t,pStm);		
		}
		* /
		t->setDirty(FALSE);
		return S_OK;
	}
    
    virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty)
	{
		T* t = (T*)this;
		/*
		std::vector<mol::ole::IProperty*>& props = mol::ole::properties<T>().get();
		for ( unsigned int i = 0; i < props.size(); i++ )
		{
			props[i]->Save(t,pStm);		
		}
		* /
		t->setDirty(FALSE);
		return S_OK;
	}
	*/
    
    virtual HRESULT __stdcall GetSizeMax( ULARGE_INTEGER *pCbSize)
	{
		pCbSize->QuadPart = 0;
		T* t = (T*)this;
		/*
		std::vector<mol::ole::IProperty*>& props = mol::ole::properties<T>().get();
		for ( unsigned int i = 0; i < props.size(); i++ )
		{
			props[i]->GetSizeMax(t,pCbSize);
		}
		*/
		return S_OK;
	}
    
    virtual HRESULT __stdcall InitNew() 
	{
		T* t = (T*)this;
		/*
		std::vector<mol::ole::IProperty*>& props = mol::ole::properties<T>().get();
		for ( unsigned int i = 0; i < props.size(); i++ )
		{
			props[i]->InitNew(t);
		}
		*/
		t->setDirty(FALSE);
		return S_OK;
	}

    virtual HRESULT __stdcall GetClassID( CLSID * pClassID)
	{
		*pClassID = T::getCoClassID();
		return S_OK;
	}
};

/////////////////////////////////////////////////////////////////////
// Persist Storage
/////////////////////////////////////////////////////////////////////

template<class T>
class PersistStorage : public IPersistStorage
{
public:

	PersistStorage()
	{}

	virtual ~PersistStorage()
	{}

    virtual HRESULT __stdcall IsDirty( void)
	{
		T* t = (T*)this;
		return t->isDirty() == TRUE ? S_OK : S_FALSE;
	}
    
    virtual HRESULT __stdcall Load( IStorage *pStg) 
	{
		static LPCOLESTR con = OLESTR("Contents");
		T* t = (T*)this;

		punk<IPersistStreamInit> ipsi;
		if ( S_OK == ((IPersistStorage*)(t))->QueryInterface(IID_IPersistStreamInit,(void**)&ipsi) )
		{
			punk<IStream> stream;
			HRESULT hr = pStg->OpenStream( con, NULL, STGM_DIRECT|STGM_SHARE_EXCLUSIVE,0,&stream);
			if ( ipsi && (hr == S_OK) )
			{
				CLSID clsid;
				::ReadClassStm(stream,&clsid);
				t->setDirty(FALSE);
				return ipsi->Load(stream);
			}
		}
		return S_OK;
	}
    
    virtual HRESULT __stdcall Save( IStorage *pStgSave, BOOL fSameAsLoad)
	{
		static LPCOLESTR con = OLESTR("Contents");
		T* t = (T*)this;

		punk<IPersistStreamInit> ipsi;
		if ( S_OK == ((IPersistStorage*)(t))->QueryInterface(IID_IPersistStreamInit,(void**)&ipsi) )
		{
			punk<IStream> stream;
			HRESULT hr = pStgSave->CreateStream( con, STGM_WRITE|STGM_SHARE_EXCLUSIVE|STGM_CREATE,0,0,&stream);
			if ( ipsi && (hr == S_OK) )
			{
				::WriteClassStm(stream,T::getCoClassID());
				t->setDirty(FALSE);
				return ipsi->Save(stream,TRUE);
			}
		}
		return S_OK;
	}
    
    virtual HRESULT __stdcall SaveCompleted( IStorage *pStgNew)
	{
		return S_OK;
	}
        
    virtual HRESULT __stdcall HandsOffStorage( void)
	{
		return S_OK;
	}
        
    virtual HRESULT __stdcall InitNew(IStorage *pStg) 
	{
		T* t = (T*)this;
		/*
		std::vector<mol::ole::IProperty*>& props = mol::ole::properties<T>().get();
		for ( unsigned int i = 0; i < props.size(); i++ )
		{
			props[i]->InitNew((IDispatch*)t);
		}
		*/
		t->setDirty(FALSE);
		return S_OK;
	}

    virtual HRESULT __stdcall GetClassID( CLSID * pClassID)
	{
		*pClassID = T::getCoClassID();
		return S_OK;
	}
};

/////////////////////////////////////////////////////////////////////


template<class T>
class PersistFile : public IPersistFile
{
public:

	PersistFile() : filename_(_T(""))
	{}

	virtual ~PersistFile()
	{}

    virtual HRESULT __stdcall GetClassID( CLSID * pClassID)
	{
		*pClassID = T::getCoClassID();
		return S_OK;
	}

    virtual HRESULT __stdcall IsDirty( void)
	{
		T* t = (T*)this;
		return t->isDirty() == TRUE ? S_OK : S_FALSE;
	}

    virtual HRESULT __stdcall Load ( LPCOLESTR pszFileName, DWORD dwMode )
	{
		T* t = (T*)this;
		if ( pszFileName )
		{
			Storage store;
			std::wstring file = mol::towstring(pszFileName);
			if ( store.open(file,dwMode|STGM_SHARE_EXCLUSIVE) )
			{
				filename_ = file;
				if ( ::IsEqualGUID( store.clsid(), t->getCoClassID()) )
				{
					punk<IPersistStorage> ps(t);
					if ( ps )
					{
						return ps->Load(store);
						return S_OK;
					}
				}
			}
		}
		return E_FAIL;
	}

    virtual HRESULT __stdcall Save( LPCOLESTR pszFileName, BOOL fRemember )
	{
		T* t = (T*)this;
		if ( pszFileName )
		{
			Storage store;
			std::wstring file = mol::towstring(pszFileName);
			if ( store.create(file) )
			{
				store.clsid(t->getCoClassID());
				punk<IPersistStorage> ps(t);
				if ( ps )
				{
					ps->Save(store,FALSE);
					if ( fRemember )
						filename_ = file;
					return S_OK;
				}
			}
		}
		return E_FAIL;		
	}


    virtual HRESULT __stdcall SaveCompleted( LPCOLESTR pszFileName)
	{
		return S_OK;
	}

    virtual HRESULT __stdcall GetCurFile( LPOLESTR * ppszFileName)
	{
		std::wstring file = mol::towstring(filename_);
		*ppszFileName = (LPOLESTR)::CoTaskMemAlloc( (file.size()+1)*sizeof(wchar_t));
		wcsncpy(*ppszFileName,file.c_str(),file.size()+1);
		return S_OK;
	}

protected:
	std::wstring				filename_;
};


} // end namespace mol


#endif