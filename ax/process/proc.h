#ifndef _MOL_COM_DLL_COMTYPES_DEF_DEFINE_GUARD_
#define _MOL_COM_DLL_COMTYPES_DEF_DEFINE_GUARD_

#include "ole/ole.h"
#include "ole/ole.h"
#include "ole/obj.h"
#include "ole/cp.h"
#include "ole/Bstr.h"
#include "ole/typeinfo.h"
#include "ole/Factory.h"
#include "ole/aut.h"
#include "win/path.h"
#include "win/file.h"
#include "util/istr.h"
#include <msxml2.h>
#include <list>
#include <map>
#include <set>
#include <vector>

#include "process_h.h"
#include "win/process.h"

using namespace mol;

////////////////////////////////////////////////////////////////////////
/*
class GIT
{
public:
	GIT()
	{
		HRESULT hr = git_.createObject(CLSID_StdGlobalInterfaceTable);
	}

	~GIT()
	{
		
	}

	template<class T>
	HRESULT registerInterface( T* t, DWORD* cookie)
	{
		if ( !git_ )
			return E_FAIL;

		if (!cookie)
			return E_INVALIDARG;

		punk<IUnknown> pnk(t);
		if (!pnk)
			return E_NOINTERFACE;

		return git_->RegisterInterfaceInGlobal( pnk, mol::uuidof<T>(), cookie );
	}

	HRESULT revokeInterface(DWORD cookie)
	{
		if ( !git_ )
			return E_FAIL;

		return git_->RevokeInterfaceFromGlobal( cookie  );
	}

	template<class T>
	HRESULT getInterface(DWORD cookie, T** t)
	{
		if ( !git_ )
			return E_FAIL;

		return git_->GetInterfaceFromGlobal( cookie, mol::uuidof<T>(), (void**) t );
	}

private:

	punk<IGlobalInterfaceTable> git_;
};

////////////////////////////////////////////////////////////////////////

template<class T,class I>
class ThreadConnectionPoint : public mol::ole::ConnectionPointBase  
{
public:
	ThreadConnectionPoint()
	{
		T* t = (T*)this;
		((ConnectionPointContainer<T>*)t)->add(__uuidof(I),&inner_connection_point_);
	}

	virtual ~ThreadConnectionPoint()
	{}

	virtual HRESULT getConnectionInterface( IID *pIID) 
	{
		*pIID = __uuidof(I);
		return S_OK;
	}
	
	virtual HRESULT getConnectionPointContainer( IConnectionPointContainer **ppCPC)		
	{							
		T* t = (T*)this;
		return t->QueryInterfaceImpl(IID_IConnectionPointContainer, (void**)ppCPC);
	}	

	virtual HRESULT advise( IUnknown *pUnkSink, DWORD *pdwCookie) 
	{
		I* i = 0;
		if ( S_OK != pUnkSink->QueryInterface( __uuidof(I), (void**)&i ))
			return CONNECT_E_CANNOTCONNECT;

		punk<I> it(pUnkSink);

		if (!it)
			return CONNECT_E_CANNOTCONNECT;

		GIT git;
		git.registerInterface(it.interface_,pdwCookie);
		sinks_.push_back( *pdwCookie );
		return S_OK;
	}

	virtual HRESULT unadvise( DWORD dwCookie) 
	{
		GIT git;
		git.revokeInterface(dwCookie);

		for ( std::list<int>::iterator it = sinks_.begin(); it != sinks_.end(); it++ )
		{
			if ( *it  == dwCookie )
			{
				sinks_.erase(it);
				break;
			}
		}
		return S_OK;
	}

	void fire(DISPID dispIdMember)
	{
		for ( std::list<int>::iterator it = sinks_.begin(); it != sinks_.end(); it++)
		{
			punk<I> disp;
			GIT git;
			if ( (S_OK != git.getInterface( *it, &disp)) || (!disp) )
				continue;

			disp_invoke(disp,dispIdMember);
		}
	}

	template<class V>
	void fire(DISPID dispIdMember,  V& v)
	{
		for ( std::map<int,I*>::iterator it = sinks_.begin(); it != sinks_.end(); it++)
		{
			punk<I> disp;
			GIT git;
			if ( (S_OK != git.getInterface( *it, &disp)) || (!disp) )
				continue;

			disp_invoke(disp,dispIdMember,v);
		}
	}

	template<class V1, class V2>
	void fire(DISPID dispIdMember,  V1& v1, V2& v2)
	{
		for ( std::map<int,I*>::iterator it = sinks_.begin(); it != sinks_.end(); it++)
		{
			punk<I> disp;
			GIT git;
			if ( (S_OK != git.getInterface( *it, &disp)) || (!disp) )
				continue;

			disp_invoke(disp,dispIdMember,v1,v2);
		}
	}

	template<class V1, class V2, class V3>
	void fire(DISPID dispIdMember,  V1& v1, V2& v2, V3& v3)
	{
		for ( std::map<int,I*>::iterator it = sinks_.begin(); it != sinks_.end(); it++)
		{
			punk<I> disp;
			GIT git;
			if ( (S_OK != git.getInterface( *it, &disp)) || (!disp) )
				continue;

			disp_invoke(disp,dispIdMember,v1,v2,v3);
		}
	}

	template<class V1, class V2, class V3, class V4>
	void fire(DISPID dispIdMember,  V1& v1, V2& v2, V3& v3, V4& v4)
	{
		for ( std::map<int,I*>::iterator it = sinks_.begin(); it != sinks_.end(); it++)
		{
			punk<I> disp;
			GIT git;
			if ( (S_OK != git.getInterface( *it, &disp)) || (!disp) )
				continue;

			disp_invoke(disp,dispIdMember,v1,v2,v3,v4);
		}
	}

	template<class V1, class V2, class V3, class V4, class V5>
	void fire(DISPID dispIdMember,  V1& v1, V2& v2, V3& v3, V4& v4, V5& v5)
	{
		for ( std::map<int,I*>::iterator it = sinks_.begin(); it != sinks_.end(); it++)
		{
			punk<I> disp;
			GIT git;
			if ( (S_OK != git.getInterface( *it, &disp)) || (!disp) )
				continue;

			disp_invoke(disp,dispIdMember,v1,v2,v3,v4,v5);
		}
	}

	template<class V1, class V2, class V3, class V4, class V5, class V6>
	void fire(DISPID dispIdMember,  V1& v1, V2& v2, V3& v3, V4& v4, V5& v5, V6& v6)
	{
		for ( std::map<int,I*>::iterator it = sinks_.begin(); it != sinks_.end(); it++)
		{
			punk<I> disp;
			GIT git;
			if ( (S_OK != git.getInterface( *it, &disp)) || (!disp) )
				continue;

			disp_invoke(disp,dispIdMember,v1,v2,v3,v4,v5,v6);
		}
	}

protected:
	std::list<int> sinks_;

};
*/
////////////////////////////////////////////////////////////////////////

class PipedProcessAx;

////////////////////////////////////////////////////////////////////////


class PipedProcessAx : 
	public mol::com_registerobj<PipedProcessAx,CLSID_PipedProcessControl>,
	public mol::Dispatch<IPipedProcess>,
	public mol::ConnectionPointContainer<PipedProcessAx>,
	public mol::ConnectionPoint<
					PipedProcessAx,
					_IPipedProcessComplete,
					mol::ole::ConnectionPointAdviseMultiThreadPolicy<_IPipedProcessComplete>
				>,
	public mol::interfaces< PipedProcessAx,
			mol::implements<
				IPipedProcess,
				IDispatch,
				IConnectionPointContainer 
				> >
{
public:

	PipedProcessAx()
	{
		vbAsync_  = VARIANT_FALSE;
	}

	virtual void dispose()
	{
		shutdown();
	}

	HRESULT virtual __stdcall get_Async(VARIANT_BOOL* vb);

	HRESULT virtual __stdcall put_Async(VARIANT_BOOL  vb);

	HRESULT virtual __stdcall get_readyState(long* state);

	HRESULT virtual __stdcall get_Eof(VARIANT_BOOL* vb);

	HRESULT virtual __stdcall get_ErrEof(VARIANT_BOOL* vb);

	HRESULT virtual __stdcall Create( BSTR cmdline, VARIANT_BOOL* vbSuccess);

	HRESULT virtual __stdcall Write(BSTR s, VARIANT_BOOL* vbSuccess);

	HRESULT virtual __stdcall CloseOut();

	HRESULT virtual __stdcall ReadLine(BSTR* line);

	HRESULT virtual __stdcall ReadErrLine(BSTR* line );

	HRESULT virtual __stdcall Close();

	HRESULT virtual __stdcall Terminate();

	HRESULT virtual __stdcall put_onComplete(IDispatch* disp);

	void onDone();

private:

	void shutdown();
	bool init(const mol::string& p);

	class ProcessPipe : public mol::PipedProcess
	{
		public: 		
			void onDone()
			{
				mol::That(this,&PipedProcessAx::pProcess_)->onDone();
			}
	} 
	pProcess_;

	VARIANT_BOOL  vbAsync_;

	//punk<IDispatch>  dispEvent_;
	DWORD cookie_dispEvent_;
};

#endif