#ifndef MOL_COM_FACTORY_POLICY_DEFINE_GUARD_DEF_
#define MOL_COM_FACTORY_POLICY_DEFINE_GUARD_DEF_

#pragma once

#include "conf.h"
#include "util/util.h"
#include "util/uni.h"
#include "ole/obj.h"

namespace mol {
namespace ole {

//////////////////////////////////////////////////////////////////////
// class factory policy impl
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// aggregation policies
//////////////////////////////////////////////////////////////////////

template<class T,class P  = mol::com_instance<T> >
class AggregationPolicyNonAggregable
{
public:

	static HRESULT __stdcall CreateInstance( IUnknown* pIUOuter, REFIID riid, void** ppVoid )
	{
			if ( pIUOuter != 0 )
				return CLASS_E_NOAGGREGATION;

			P* t = new P;

			t->AddRef();
			HRESULT hr = t->QueryInterface(riid,ppVoid);
			t->Release();
			return hr;
	}
};

//////////////////////////////////////////////////////////////////////

template<class T, class P  = mol::com_instance_agg<T> >
class AggregationPolicyAggregable
{
public:

	static HRESULT __stdcall CreateInstance( IUnknown* pIUOuter, REFIID riid, void** ppVoid )
	{
		if ( pIUOuter == 0 )
			return AggregationPolicyNonAggregable<T,mol::com_instance<T> >::CreateInstance( pIUOuter, riid, ppVoid );

		P* at = new P(pIUOuter);

		at->AddRef();
		HRESULT hr = at->QueryInterface(riid,ppVoid);
		at->Release();
		return hr;
	}
};


//////////////////////////////////////////////////////////////////////
// creation policies (multi or singleton)
//////////////////////////////////////////////////////////////////////

template<class T, class P=AggregationPolicyNonAggregable<T,mol::com_instance<T> > >
class ComCreatePolicy
{
public:

	HRESULT virtual __stdcall CreateInstance( IUnknown* pIUOuter, REFIID riid, void** ppVoid )
	{
		return P::CreateInstance( pIUOuter, riid, ppVoid );
	}
};

//////////////////////////////////////////////////////////////////////

template<class T>
class ComSingletonPolicy
{
public:
	ComSingletonPolicy()
	{}

	HRESULT virtual __stdcall CreateInstance( IUnknown* pIUOuter, REFIID riid, void** ppVoid )
	{
		if ( pIUOuter != 0 )
			return CLASS_E_NOAGGREGATION;

		singleton_.AddRef();
		HRESULT hr = singleton_.QueryInterface(riid,ppVoid);
		singleton_.Release();
		return hr;
	}

protected:

	com_singleton<T>	  singleton_;
};


} // end namespace ole
} // end namespace mole

#endif