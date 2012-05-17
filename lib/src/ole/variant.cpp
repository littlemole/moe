#include "ole/variant.h"
#include "ole/punk.h"

namespace mol {


mol::string valueOf( mol::variant& v)
{
	return v.toString();
}

/*
BSTR valueOf( mol::variant& v)
{
	if ( v.vt == VT_BSTR )
	{
		return ::SysAllocString(v.bstrVal);
	}
	mol::variant tmp(v);
	tmp.changeType(VT_BSTR);
	return ::SysAllocString(tmp.bstrVal);
}
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//variant to stream
//////////////////////////////////////////////////////////////////////////

void Variant_toStream( VARIANT& var, IStream* stream )
{
	ULONG len = 0;
	switch (var.vt)
	{
		case VT_EMPTY :
		{
			break;
		}
		case VT_BSTR :
		{
			ULONG cnt = ::SysStringByteLen(var.bstrVal);
			stream->Write((void*)&cnt,sizeof(cnt),&len);
			if ( cnt )
				stream->Write((void*)var.bstrVal, cnt, &len );
			break;
		}
		case VT_INT :
		{
			stream->Write((void*)&var.intVal,sizeof(INT),&len);
			break;
		}
		case VT_UINT :
		{
			stream->Write((void*)&var.uintVal,sizeof(UINT),&len);
			break;
		}
		case VT_I1 :
		{
			stream->Write((void*)&var.cVal,sizeof(CHAR),&len);
			break;
		}
		case VT_I2 :
		{
			stream->Write((void*)&var.iVal,sizeof(SHORT),&len);
			break;
		}
		case VT_I4 :
		{
			stream->Write((void*)&var.lVal,sizeof(LONG),&len);
			break;
		}
		case VT_I8 :
		{
			stream->Write((void*)&var.llVal,sizeof(LONGLONG),&len);
			break;
		}
		case VT_UI1 :
		{
			stream->Write((void*)&var.bVal,sizeof(BYTE),&len);
			break;
		}
		case VT_UI2 :
		{
			stream->Write((void*)&var.uiVal,sizeof(USHORT),&len);
			break;
		}
		case VT_UI4 :
		{
			stream->Write((void*)&var.ulVal,sizeof(ULONG),&len);
			break;
		}
		case VT_UI8 :
		{
			stream->Write((void*)&var.ullVal,sizeof(ULONGLONG),&len);
			break;
		}
		case VT_R4 :
		{
			stream->Write((void*)&var.fltVal,sizeof(FLOAT),&len);
			break;
		}
		case VT_R8 :
		{
			stream->Write((void*)&var.dblVal,sizeof(DOUBLE),&len);
			break;
		}
		case VT_BOOL :
		{
			stream->Write((void*)&var.boolVal,sizeof(VARIANT_BOOL),&len);
			break;
		}
	}
}

void Variant_fromStream( VARIANT& var, IStream* stream )
{
	ULONG len = 0;
	switch (var.vt)
	{
		case VT_EMPTY :
		{
			break;
		}
		case VT_BSTR:
		{
			ULONG cnt;				
			stream->Read( (void*)&cnt,sizeof(cnt),&len);
			if ( cnt )
			{
				char* buf = new char[cnt+2];
				stream->Read( (void*)buf, cnt, &len );
				buf[len]   = 0;
				buf[len+1] = 0;

				if ( var.bstrVal )
					::SysFreeString(var.bstrVal);
				var.bstrVal = ::SysAllocString( (OLECHAR*)buf );
				delete[] buf;
			}
			else
				var.bstrVal = 0;
			break;
		}
		case VT_INT :
		{
			stream->Read((void*)&var.intVal,sizeof(INT),&len);			
			break;
		}
		
		case VT_UINT :
		{
			stream->Read((void*)&var.uintVal,sizeof(UINT),&len);
			break;
		}
		case VT_I1 :
		{
			stream->Read((void*)&var.cVal,sizeof(CHAR),&len);
			break;
		}
		case VT_I2 :
		{
			stream->Read((void*)&var.iVal,sizeof(SHORT),&len);
			break;
		}
		case VT_I4 :
		{
			stream->Read((void*)&var.lVal,sizeof(LONG),&len);
			break;
		}
		case VT_I8 :
		{
			stream->Read((void*)&var.llVal,sizeof(LONGLONG),&len);
			break;
		}
		case VT_UI1 :
		{
			stream->Read((void*)&var.bVal,sizeof(BYTE),&len);
			break;
		}
		case VT_UI2 :
		{
			stream->Read((void*)&var.uiVal,sizeof(USHORT),&len);
			break;
		}
		case VT_UI4 :
		{
			stream->Read((void*)&var.ulVal,sizeof(ULONG),&len);
			break;
		}
		case VT_UI8 :
		{
			stream->Read((void*)&var.ullVal,sizeof(ULONGLONG),&len);
			break;
		}
		case VT_R4 :
		{
			stream->Read((void*)&var.fltVal,sizeof(FLOAT),&len);
			break;
		}
		case VT_R8 :
		{
			stream->Read((void*)&var.dblVal,sizeof(DOUBLE),&len);
			break;
		}
		case VT_BOOL :
		{
			stream->Read((void*)&var.boolVal,sizeof(VARIANT_BOOL),&len);
			break;
		}

		
	} // end switch
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//variant
//////////////////////////////////////////////////////////////////////////

template<VARTYPE VT>
void safeArray_toStream(SAFEARRAY* psfa, IStream* stream)
{
	ULONG len;
	mol::ole::SafeArrayBase sa;
	sa.Attach( psfa );

	long l,u;
	sa.GetLBound(&l);
	sa.GetUBound(&u);
	ULONG cnt = u-l+1;
	stream->Write((void*)&cnt,sizeof(ULONG),&len);

	SFAccess<mol::ole::VariantTraits<VT>::type> sfa(sa);
	for ( long i = l; i <= u; i++ )
	{
		stream->Write((void*)&sfa[i], (ULONG)mol::ole::VariantTraits<VT>::size(), &len );
	}	
	sa.Detach();
}

template<VARTYPE VT>
void safeArray_fromStream(SAFEARRAY* psfa, IStream* stream)
{
	ULONG len;
	ULONG cnt = 0;
	if ( S_OK != stream->Read((void*)&cnt,sizeof(ULONG),&len) )
		return;

	ArrayBound            ab(cnt);
	SafeArray<VT>		   sa(ab);
	SFAccess<mol::ole::VariantTraits<VT>::type>   sfa(sa);
 
	for ( unsigned long i = 0; i < cnt; i++ )
	{
		stream->Read((void*)&sfa[i], (ULONG)mol::ole::VariantTraits<VT>::size(), &len );
	}	
	psfa = sa;
	sa.Detach();
}

void variant::toStream( IStream* stream )
{
	ULONG len;
	if ( vt & VT_ARRAY )
	{
		VARTYPE t = vt - VT_ARRAY;
		switch (t)
		{
			case VT_VARIANT :
			{
				mol::ole::SafeArrayBase sa;
				sa.Attach( parray );

				long l,u;
				sa.GetLBound(&l);
				sa.GetUBound(&u);
				ULONG cnt = u-l+1;
				stream->Write((void*)&cnt,sizeof(ULONG),&len);

				SFAccess<VARIANT> sfa(sa);
				for ( long i = l; i <= u; i++ )
				{
					stream->Write((void*)&sfa[i].vt,sizeof(VARTYPE),&len);
					Variant_toStream(sfa[i],stream);
				}
				sa.Detach();
				return;
			}

			case VT_BSTR :
			{
				mol::ole::SafeArrayBase sa;
				sa.Attach( parray );

				long l,u;
				sa.GetLBound(&l);
				sa.GetUBound(&u);
				ULONG cnt = u-l+1;
				stream->Write((void*)&cnt,sizeof(ULONG),&len);

				SFAccess<BSTR> sfa(sa);
				for ( long i = l; i <= u; i++ )
				{
					ULONG cnt = ::SysStringByteLen(sfa[i]);
					stream->Write((void*)&cnt,sizeof(cnt),&len);

					if ( cnt )
						stream->Write((void*)sfa[i], cnt, &len );
				}
				sa.Detach();
				return;
			}

			case VT_INT :
			{
				safeArray_toStream<VT_INT>(parray,stream);
				return ;
			}
			case VT_UINT :
			{
				safeArray_toStream<VT_UINT>(parray,stream);
				return ;
			}
			case VT_I1 :
			{
				safeArray_toStream<VT_I1>(parray,stream);
				return ;
			}
			case VT_I2 :
			{
				safeArray_toStream<VT_I2>(parray,stream);
				return ;
			}
			case VT_I4 :
			{
				safeArray_toStream<VT_I4>(parray,stream);
				return ;
			}
			case VT_I8 :
			{
				safeArray_toStream<VT_I8>(parray,stream);
				return ;
			}
			case VT_UI1 :
			{
				safeArray_toStream<VT_UI1>(parray,stream);
				return ;
			}
			case VT_UI2 :
			{
				safeArray_toStream<VT_UI2>(parray,stream);
				return ;
			}
			case VT_UI4 :
			{
				safeArray_toStream<VT_UI4>(parray,stream);
				return ;
			}
			case VT_UI8 :
			{
				safeArray_toStream<VT_UI8>(parray,stream);
				return ;
			}
			case VT_R4 :
			{
				safeArray_toStream<VT_UI4>(parray,stream);
				return ;
			}
			case VT_R8 :
			{
				safeArray_toStream<VT_UI8>(parray,stream);
				return ;
			}
		} // end switch vt
		return;
	}
	else if ( (vt == VT_UNKNOWN) || (vt == (VT_UNKNOWN|VT_BYREF)) )
	{
		VARIANT v = *this;
		if ( v.vt & VT_BYREF )
		{
			v.vt = v.vt - VT_BYREF;
			v.punkVal = *ppunkVal;
		}

		punk<IPersistStream> ps(v.punkVal);
		if ( ps )
			::OleSaveToStream(ps,stream);
		return;
	}
	else if ( (vt == VT_DISPATCH) || (vt == (VT_DISPATCH|VT_BYREF)) )
	{
		VARIANT v = *this;
		if ( v.vt & VT_BYREF )
		{
			v.vt = v.vt - VT_BYREF;
			v.punkVal = *ppdispVal;
		}
		punk<IPersistStream> ps(v.pdispVal);
		HRESULT hr;
		if ( ps )
		{
			CLSID clsid;
			hr = ps->GetClassID(&clsid);
			hr = ::WriteClassStm(stream,clsid);
			hr = ps->Save(stream,FALSE);
		}
		return;
	}
	// no array - stream variant
	Variant_toStream( *this, stream );
}

void variant::fromStream( IStream* stream )
{
	VARTYPE t = vt;
	//::VariantClear(this); ouch ?
	vt = t;

	ULONG len;

	if ( t & VT_ARRAY )
	{
		t = t - VT_ARRAY;

		switch ( t )
		{
			case VT_VARIANT :
			{
				ULONG cnt = 0;
				if ( S_OK != stream->Read((void*)&cnt,sizeof(ULONG),&len) )
					return;

				ArrayBound            ab(cnt);
				SafeArray<VT_VARIANT> sa(ab);
				SFAccess<VARIANT>     sfa(sa);

				for ( unsigned long i = 0; i < cnt; i++ )
				{		
					stream->Read((void*)&sfa[i].vt,sizeof(VARTYPE),&len);
					Variant_fromStream(sfa[i],stream);
				}

				parray = sa;
				sa.Detach();
				return;
			}

			case VT_BSTR :
			{
				ULONG cnt = 0;
				if ( S_OK != stream->Read((void*)&cnt,sizeof(ULONG),&len) )
					return;

				ArrayBound         ab(cnt);
				SafeArray<VT_BSTR> sa(ab);
				SFAccess<BSTR>     sfa(sa);

				for ( unsigned long i = 0; i < cnt; i++ )
				{
					ULONG cnt = 0;
					stream->Read((void*)&cnt,sizeof(cnt),&len);
					if ( cnt )
					{
						char* buf = new char[cnt+2];
						stream->Read( (void*)buf, cnt, &len );
						buf[len]   = 0;
						buf[len+1] = 0;

						sfa[i] = ::SysAllocString( (OLECHAR*)buf );
						delete[] buf;
					}
				}
				parray = sa;
				sa.Detach();
				return;
			}
			case VT_INT:
			{	
				safeArray_fromStream<VT_INT>( parray,stream );
				return;
			}
			case VT_UINT:
			{	
				safeArray_fromStream<VT_UINT>( parray,stream );
				return;
			}
			case VT_I1:
			{	
				safeArray_fromStream<VT_I1>( parray,stream );
				return;
			}
			case VT_I2:
			{	
				safeArray_fromStream<VT_I2>( parray,stream );
				return;
			}
			case VT_I4:
			{	
				safeArray_fromStream<VT_I4>( parray,stream );
				return;
			}
			case VT_I8:
			{	
				safeArray_fromStream<VT_UI8>( parray,stream );
				return;
			}
			case VT_UI1:
			{	
				safeArray_fromStream<VT_UI1>( parray,stream );
				return;
			}
			case VT_UI2:
			{	
				safeArray_fromStream<VT_UI2>( parray,stream );
				return;
			}
			case VT_UI4:
			{	
				safeArray_fromStream<VT_UI4>( *pparray,stream );
				return;
			}
			case VT_UI8:
			{	
				safeArray_fromStream<VT_UI8>( parray,stream );
				return;
			}
			case VT_R4:
			{	
				safeArray_fromStream<VT_R4>( parray,stream );
				return;
			}
			case VT_R8:
			{	
				safeArray_fromStream<VT_R8>( parray,stream );
				return;
			}
		} // end switch
		return;
	}
	else if ( (vt == VT_UNKNOWN) || (vt == (VT_UNKNOWN|VT_BYREF)) )
	{
		VARIANT v = *this;
		if ( v.vt & VT_BYREF )
		{
			v.vt = v.vt - VT_BYREF;
			v.punkVal = *ppunkVal;
		}
		if ( S_OK == ::OleLoadFromStream(stream, IID_IDispatch, (void**)&(v.pdispVal) ))
			*this = v;
		return;
	}
	else if ( (vt == VT_DISPATCH) || (vt == (VT_DISPATCH|VT_BYREF)) )
	{
		VARIANT v = *this;
		if ( v.vt & VT_BYREF )
		{
			v.vt = v.vt - VT_BYREF;
			v.punkVal = *ppdispVal;
		}
		HRESULT hr;
		CLSID clsid;
		hr = ::ReadClassStm(stream,&clsid);
		hr = ::CoCreateInstance(clsid,0,CLSCTX_ALL,IID_IDispatch,(void**)&(v.pdispVal));
		punk<IPersistStream> ps(v.pdispVal);
		if ( ps )
		{
			hr = ps->Load(stream);
			if ( hr == S_OK )
				*this = v;
		}
		return;
	}
	Variant_fromStream(*this,stream);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<VARTYPE VT> 
void SafeArrayInit( mol::ole::SafeArrayBase& sf, wchar_t** str, int s )
{
	// no generic impl! specialize!
};

// spec for BSTR
template<>
void SafeArrayInit<VT_BSTR> ( mol::ole::SafeArrayBase& sf, wchar_t** str, int s )
{
	SFAccess<BSTR> sfa(sf);
	for ( int i = 0; i < s; i++ )
	{
		sfa[i] = ::SysAllocString( (str[i]) );
	}
};

template<>
void SafeArrayInit<VT_VARIANT> ( mol::ole::SafeArrayBase& sf, wchar_t** str, int s )
{
	SFAccess<VARIANT> sfa(sf);
	for ( int i = 0; i < s; i++ )
	{
		::VariantInit( &(sfa[i]) );
		sfa[i].vt = VT_BSTR;
		sfa[i].bstrVal = ::SysAllocString( (str[i]) );
	}
};


/////////////////////////////////////////////////////////////////////

enum_variant::enum_variant()
:it_(variants_.end())
{
}

/////////////////////////////////////////////////////////////////////

enum_variant::~enum_variant()
{
	for ( unsigned int i = 0; i < variants_.size(); i++ )
	{
		::VariantClear(&(variants_[i]));
	}
}

/////////////////////////////////////////////////////////////////////

void enum_variant::add(VARIANT& var)
{
	//ODBGS("Enumvar::add");
	LOCK(mutex_);
	VARIANT v;
	::VariantInit(&v);
	::VariantCopy(&v,&var);
	variants_.push_back(v);
	it_ = variants_.begin();
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall enum_variant::Next( ULONG celt, VARIANT* rgelt, ULONG * pceltFetched )
{
	//ODBGS("EnumVar::Next");
	LOCK(mutex_);
	if ( it_ == variants_.end() )
	{
		if ( pceltFetched )
			*pceltFetched = 0;
		it_ = variants_.begin();
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
		::VariantInit(rgelt);
		::VariantCopy(rgelt,&(*it_));
		//*rgelt = *it_;
		if ( pceltFetched )
			*pceltFetched = 1;
		it_++;
		return S_OK;
	}
	ULONG u = 0;
	for ( u; u < celt; u++ )
	{
		::VariantInit(&(rgelt[u]));
		::VariantCopy(&(rgelt[u]),&(*it_));
		//rgelt[u] = *it_;
		it_++;
		if ( it_ == variants_.end() )
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

HRESULT __stdcall enum_variant::Skip( ULONG celt )
{
	//ODBGS("EnumVariant::Skip");
	LOCK(mutex_);
	ULONG u = 0;
	for ( u; u < celt; u++ )
	{
		it_++;
		if ( it_ == variants_.end() )
			return S_FALSE;
	}
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall enum_variant::Reset(void)
{
	LOCK(mutex_);
	//ODBGS("EnumVariant::Reset");
	it_ = variants_.begin();
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall enum_variant::Clone( IEnumVARIANT ** ppenum )
{
	//ODBGS("EnumVariant::Clone");
	LOCK(mutex_);
	punk<com_obj<enum_variant> > i = new com_obj<enum_variant>;
	for ( unsigned int x = 0; x < variants_.size(); x++ )
		i->add(variants_[x]);
	i->QueryInterface(IID_IEnumVARIANT,(void**)ppenum);
	return S_OK;
}




////////////////////////////////////////////////////////////////////


HRESULT __stdcall  COMCollection::_NewEnum(IEnumVARIANT** newEnum)
{
	punk<com_obj<enum_variant> > ev = new com_obj<enum_variant>;
	for ( std::list<std::pair<variant,variant> >::iterator it = variants_.begin(); it != variants_.end(); it++)
	{
		ev->add((*it).second);
	}
	return ev->QueryInterface(IID_IEnumVARIANT,(void**)newEnum);
}

HRESULT __stdcall  COMCollection::Count( VARIANT* cnt)
{
	if ( cnt )
	{
		variant v((int)variants_.size());
		::VariantCopy(cnt,&v);
	}
	return S_OK;
}

HRESULT __stdcall  COMCollection::Item( VARIANT index, VARIANT* item)
{
	if ( item )
		::VariantInit(item);

	varlist::iterator& it = iterator(index);
	if ( it == variants_.end() )
		return S_FALSE;

	HRESULT hr = ::VariantCopy( item, &((*it).second) );
	return hr == S_OK ? S_OK : S_FALSE;

}

HRESULT __stdcall COMCollection::Remove( VARIANT index )
{
	varlist::iterator& it = iterator(index);
	if ( it == variants_.end() )
		return S_FALSE;

	variants_.erase(it);
	return S_OK;
}

HRESULT __stdcall COMCollection::Add( VARIANT var)
{
	if (var.vt == VT_EMPTY )
		return S_FALSE;

	variants_.push_back( std::make_pair( "", var) );

	return S_OK;
}

HRESULT __stdcall COMCollection::Insert( VARIANT index, VARIANT var)
{
	if ( (var.vt == VT_EMPTY) || (index.vt == VT_EMPTY) )
		return S_FALSE;

	varlist::iterator& it = iterator(index);
	if ( it != variants_.end() )
		variants_.erase(it);

	variants_.push_back( std::make_pair( index, var) );
	return S_OK;
}

HRESULT __stdcall COMCollection::InsertAt( VARIANT pos, VARIANT index, VARIANT var)
{
	if ( (var.vt == VT_EMPTY) || (index.vt == VT_EMPTY) )
		return S_FALSE;

	varlist::iterator& it = iterator(index);
	if ( it != variants_.end() )
		variants_.erase(it);

	it = iterator(pos);
	if ( it == variants_.end() )
		return S_FALSE;

	variants_.insert(it,std::make_pair( index, var) );
	return S_OK;
}

HRESULT __stdcall COMCollection::Rename( VARIANT index, VARIANT newIndex )
{
	varlist::iterator it = iterator(index);
	if ( it == variants_.end() )
		return S_FALSE;

	(*it).first = newIndex;
	return S_OK;
}

HRESULT __stdcall COMCollection::Move( VARIANT what, VARIANT to )
{
	varlist::iterator it = iterator(what);
	if ( it == variants_.end() )
		return S_FALSE;

	varlist::iterator jt = iterator(to);
	if ( jt == variants_.end() )
		return S_FALSE;

	mol::variant key( (*it).first );
	mol::variant val( (*it).second );

	variants_.erase(it);

	return InsertAt( to, key, val );
}

int COMCollection::key2index( VARIANT& index )
{
	std::list<std::pair<variant,variant> >::iterator it = variants_.begin();
	int c = 0;
	if ( (index.vt == VT_BSTR) && (index.bstrVal) )
	{
		for ( it; it != variants_.end(); it++ )
		{
			variant key = (*it).first;
			key.changeType(VT_BSTR);
			if ( key.bstrVal )
			{
				int hr = _wcsicmp( key.bstrVal, index.bstrVal );
				if ( hr == 0)
				{				
					return c;
				}
			}
			c++;
		}
	}

	c = 0;
	variant i(index);
	i.changeType( VT_INT );
	if ( i.vt != VT_INT )
		return -1;

	if ( i.intVal > (int)variants_.size()-1 )
		return -1;
	return i.intVal;
}

COMCollection::varlist::iterator COMCollection::iterator(VARIANT& index)
{
	int pos = key2index(index);
	if ( pos == -1 )
		return variants_.end();

	std::list<std::pair<variant,variant> >::iterator it = variants_.begin();

	for ( int i = 0; i < pos; i++ )
		it++;

	return it;
}

} // end namespace mol
