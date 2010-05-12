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

class AggregationPolicyNonAggregable
{
public:

	template<class T>
	static HRESULT __stdcall CreateInstance( IUnknown* pIUOuter, REFIID riid, void** ppVoid )
	{
			if ( pIUOuter != 0 )
				return CLASS_E_NOAGGREGATION;

			com_instance<T>* t = new com_instance<T>;

			t->AddRef();
			HRESULT hr = t->QueryInterface(riid,ppVoid);
			t->Release();
			return hr;
	}
};

//////////////////////////////////////////////////////////////////////

class AggregationPolicyAggregable
{
public:

	template<class T>
	static HRESULT __stdcall CreateInstance( IUnknown* pIUOuter, REFIID riid, void** ppVoid )
	{
		if ( pIUOuter == 0 )
			return AggregationPolicyNonAggregable::CreateInstance<T>( pIUOuter, riid, ppVoid );

		com_instance_agg<T>* at = new com_instance_agg<T>(pIUOuter);

		at->AddRef();
		HRESULT hr = at->QueryInterface(riid,ppVoid);
		at->Release();
		return hr;
	}
};


//////////////////////////////////////////////////////////////////////
// creation policies (multi or singleton)
//////////////////////////////////////////////////////////////////////

template<class T, class P=AggregationPolicyNonAggregable>
class ComCreatePolicy
{
public:

	HRESULT virtual __stdcall CreateInstance( IUnknown* pIUOuter, REFIID riid, void** ppVoid )
	{
		return P::CreateInstance<T>( pIUOuter, riid, ppVoid );
	}
};

//////////////////////////////////////////////////////////////////////

template<class T>
class ComSingletonPolicy
{
public:
	HRESULT virtual __stdcall CreateInstance( IUnknown* pIUOuter, REFIID riid, void** ppVoid )
	{
		if ( pIUOuter != 0 )
			return CLASS_E_NOAGGREGATION;

		if ( !singleton_ ) 
			singleton_ = new mol::com_instance<T>;

		singleton_->AddRef();
		HRESULT hr = singleton_->QueryInterface(riid,ppVoid);
		singleton_->Release();
		return hr;
	}

protected:

	com_instance<T>*	  singleton_;
};

} // end namespace ole
} // end namespace mole

#endif