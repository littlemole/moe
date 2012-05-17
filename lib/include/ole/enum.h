#ifndef MOL_DEFINE_ENUM_DEF_GUARD_DEFINE_
#define MOL_DEFINE_ENUM_DEF_GUARD_DEFINE_

#include "ole/obj.h"
#include "util/X.h"
#include <vector>

namespace mol {
	
/////////////////////////////////////////////////////////////////////
// Enums 
/////////////////////////////////////////////////////////////////////

template<class I, class T> 
class enum_XXX : 
	public I, 
	public interfaces< enum_XXX<I,T>, implements<I> >
{
public:
	enum_XXX();
	virtual ~enum_XXX();

	virtual void dispose() {}

	void add(T& fe);

	HRESULT virtual __stdcall Next( ULONG celt, T* rgelt, ULONG * pceltFetched );
	HRESULT virtual __stdcall Skip( ULONG celt );
	HRESULT virtual __stdcall Reset(void);
	HRESULT virtual __stdcall Clone( I ** ppenum );

private:
	std::vector<T>						fe_;
	typename std::vector<T>::iterator	it_;
	mol::Mutex							mutex_;
};

/////////////////////////////////////////////////////////////////////

template<class I, class T>
enum_XXX<I,T>::enum_XXX()
:it_(fe_.end())
{
}

/////////////////////////////////////////////////////////////////////

template<class I, class T>
enum_XXX<I,T>::~enum_XXX()
{
	//ODBGS("EnumXXX destroyed");
}

/////////////////////////////////////////////////////////////////////

template<class I, class T>
void enum_XXX<I,T>::add(T& fe)
{
	//ODBGS("EnumXXX::add");
	LOCK(mutex_);
	fe_.push_back(fe);
	it_ = fe_.begin();
}

/////////////////////////////////////////////////////////////////////

template<class I, class T>
HRESULT __stdcall enum_XXX<I,T>::Next( ULONG celt, T* rgelt, ULONG * pceltFetched )
{
	//ODBGS("EnumXXX::Next");
	LOCK(mutex_);
	if ( it_ == fe_.end() )
	{
		if ( pceltFetched )
			*pceltFetched = 0;
		it_ = fe_.begin();
		return S_FALSE;
	}

	if ( celt == 0 )
	{
		if ( pceltFetched )
			*pceltFetched = 0;
		return S_OK;
	}

	if ( celt == 1 )
	{
		*rgelt = *it_;
		if ( pceltFetched )
			*pceltFetched = 1;
		it_++;
		return S_OK;
	}
	ULONG u = 0;
	for ( u; u < celt; u++ )
	{
		rgelt[u] = *it_;
		it_++;
		if ( it_ == fe_.end() )
		{
			if ( pceltFetched )
				*pceltFetched = u;
			return S_FALSE;
		}
	}

	if ( pceltFetched )
		*pceltFetched = u;

	return S_OK;
}

/////////////////////////////////////////////////////////////////////

template<class I, class T>
HRESULT __stdcall enum_XXX<I,T>::Skip( ULONG celt )
{
	//ODBGS("EnumXXX::Skip");
	LOCK(mutex_);
	ULONG u = 0;
	for ( u; u < celt; u++ )
	{
		it_++;
		if ( it_ == fe_.end() )
			return S_FALSE;
	}
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

template<class I, class T>
HRESULT __stdcall enum_XXX<I,T>::Reset(void)
{
	LOCK(mutex_);
	//ODBGS("EnumXXX::Reset");
	it_ = fe_.begin();
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

template<class I, class T>
HRESULT __stdcall enum_XXX<I,T>::Clone( I ** ppenum )
{
	//ODBGS("EnumXXX::Clone");
	LOCK(mutex_);
	punk<com_obj<enum_XXX<I,T> > > i = new com_obj<enum_XXX<I,T> >;
	for ( unsigned int x = 0; x < fe_.size(); x++ )
		i->add(fe_[x]);
	i->QueryInterface(uuidof<I>(),(void**)ppenum);
	return S_OK;
}
/////////////////////////////////////////////////////////////////////

typedef enum_XXX<IEnumFORMATETC,FORMATETC> enum_format;

/////////////////////////////////////////////////////////////////////
// IUnknown Enums 
/////////////////////////////////////////////////////////////////////

template<class I, class T> 
class unknown_enum : 
	public I,
	public interfaces< unknown_enum<I,T>, implements<I> >
{
public:
	unknown_enum();
	virtual ~unknown_enum();

	virtual void dispose() {}

	void add(T* t);

	HRESULT virtual __stdcall Next( ULONG celt, T** rgelt, ULONG * pceltFetched );
	HRESULT virtual __stdcall Skip( ULONG celt );
	HRESULT virtual __stdcall Reset(void);
	HRESULT virtual __stdcall Clone( I ** ppenum );

private:
	std::vector<T*>						interfaces_;
	typename std::vector<T*>::iterator	it_;
	mol::Mutex							mutex_;
};

/////////////////////////////////////////////////////////////////////

template<class I, class T>
unknown_enum<I,T>::unknown_enum()
:it_(interfaces_.end())
{
}

/////////////////////////////////////////////////////////////////////

template<class I, class T>
unknown_enum<I,T>::~unknown_enum()
{
	for ( unsigned int x = 0; x < interfaces_.size(); x++ )
	{
		interfaces_[x]->Release();
	}
	//ODBGS("UnknownEnum destroyed");
}

/////////////////////////////////////////////////////////////////////

template<class I, class T>
void unknown_enum<I,T>::add(T* t)
{
	//ODBGS("UnknownEnum::add");
	LOCK(mutex_);
	t->AddRef();
	interfaces_.push_back(t);
	it_ = interfaces_.begin();
}

/////////////////////////////////////////////////////////////////////

template<class I, class T>
HRESULT __stdcall unknown_enum<I,T>::Next( ULONG celt, T** rgelt, ULONG * pceltFetched )
{
	//ODBGS("EnumXXX::Next");
	LOCK(mutex_);
	if ( it_ == interfaces_.end() )
	{
		if ( pceltFetched )
			*pceltFetched = 0;
		it_ = interfaces_.begin();
		return S_FALSE;
	}

	if ( celt == 0 )
	{
		if ( pceltFetched )
			*pceltFetched = 0;
		return S_OK;
	}

	if ( celt == 1 )
	{
		(*it_)->AddRef();
		*rgelt = *it_;
		if ( pceltFetched )
			*pceltFetched = 1;
		it_++;
		return S_OK;
	}
	ULONG u = 0;
	for ( u; u < celt; u++ )
	{
		(*it_)->AddRef();
		rgelt[u] = *it_;
		it_++;
		if ( it_ == interfaces_.end() )
		{
			if ( pceltFetched )
				*pceltFetched = u;
			return S_FALSE;
		}
	}

	if ( pceltFetched )
		*pceltFetched = u;

	return S_OK;
}

/////////////////////////////////////////////////////////////////////

template<class I, class T>
HRESULT __stdcall unknown_enum<I,T>::Skip( ULONG celt )
{
	//ODBGS("EnumXXX::Skip");
	LOCK(mutex_);
	ULONG u = 0;
	for ( u; u < celt; u++ )
	{
		it_++;
		if ( it_ == interfaces_.end() )
			return S_FALSE;
	}
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

template<class I, class T>
HRESULT __stdcall unknown_enum<I,T>::Reset(void)
{
	LOCK(mutex_);
	//ODBGS("EnumXXX::Reset");
	it_ = interfaces_.begin();
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

template<class I, class T>
HRESULT __stdcall unknown_enum<I,T>::Clone( I ** ppenum )
{
	//ODBGS("EnumXXX::Clone");
	LOCK(mutex_);
	punk<com_obj<unknown_enum<I,T> > > i = new com_obj<unknown_enum<I,T> >;
	for ( unsigned int x = 0; x < interfaces_.size(); x++ )
		i->add(interfaces_[x]);
	i->QueryInterface( uuidof<I>(),(void**)ppenum);
	return S_OK;
}


//////////////////////////////////////////////////////////////////////




} // end namespace mol


#endif