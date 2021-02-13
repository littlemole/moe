#ifndef MOL_CONNECTION_POINT_DEF_GUARD_
#define MOL_CONNECTION_POINT_DEF_GUARD_

#pragma once
#include "util/uni.h"
#include "ole/punk.h"
#include "ole/enum.h"
#include "ole/aut.h"

#include <ocidl.h>
#include <olectl.h>
#include <map>
#include <list>

namespace mol {

HRESULT findSourceOnCP(IUnknown* punk, IID* piid);

/////////////////////////////////////////////////////////////////////
// eventsinking helpers for containers 
/////////////////////////////////////////////////////////////////////

template<class I>
HRESULT advise(IUnknown* object, IUnknown* eventSink, DWORD& cookie )
{
    punk<IConnectionPointContainer>	icPc(object);
    punk<IConnectionPoint>			icP;

    HRESULT hr = icPc->FindConnectionPoint( __uuidof(I), &icP);
    if( S_OK == hr )
    {
        hr = icP->Advise( eventSink,&cookie);
    }
    return hr;
}

//////////////////////////////////////////////////////////////////////

template<class I>
    HRESULT unadvise(IUnknown* object, DWORD cookie )
{
    punk<IConnectionPointContainer>	icPc(object);
    punk<IConnectionPoint>			icP;

    HRESULT hr = icPc->FindConnectionPoint( __uuidof(I), &icP);
    if( S_OK == hr )
    {
        hr = icP->Unadvise( cookie );
    }
    return hr;
}

//////////////////////////////////////////////////////////////////////
// Dispatch EventSink Dummy - Override Invoke to catch events
//////////////////////////////////////////////////////////////////////

template <class I>
class event_sink : 
	public I,
	public interfaces< event_sink<I>, implements< IDispatch, I> >
{
public:
    event_sink() : cookie_(0) {}

    // IDispatch
    HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo ) { return E_NOTIMPL; }
    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) { return E_NOTIMPL; }
    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) { return E_NOTIMPL; }
    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID, LCID, WORD, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO *, UINT *) { return E_NOTIMPL; }

    HRESULT Advise(IUnknown* object )
    {
        return this->Advise(object,cookie_);
    }
    HRESULT UnAdvise(IUnknown* object )
    {
        return this->UnAdvise(object,cookie_);
    }
    HRESULT Advise(IUnknown* object, DWORD& cookie )
    {
        return mol::advise<I>(object,this,cookie);
    }
    HRESULT UnAdvise(IUnknown* object, DWORD cookie )
    {
        return mol::unadvise<I>(object,cookie);
    }

protected:
    DWORD	cookie_;
};

//////////////////////////////////////////////////////////////////////
// CPC impl
//////////////////////////////////////////////////////////////////////

template<class T>
class ConnectionPointContainer : public IConnectionPointContainer 
{
public:

    virtual HRESULT __stdcall  EnumConnectionPoints( IEnumConnectionPoints **ppEnum)
	{
		com_obj<unknown_enum<IEnumConnectionPoints,IConnectionPoint> >* ue = 
			new com_obj<unknown_enum<IEnumConnectionPoints,IConnectionPoint> >;

		T* t = (T*)this;

		for ( std::map<const IID*,IConnectionPoint*>::iterator it = connectionPointMap_.begin();
			  it != connectionPointMap_.end(); it++)
		{
			ue->add( (*it).second );
		}
		return ue->QueryInterface(IID_IEnumConnectionPoints,(void**)ppEnum);
	}
    
    virtual HRESULT __stdcall  FindConnectionPoint( REFIID riid,IConnectionPoint **ppCP)
	{
		T* t = (T*)this;
		for ( std::map<const IID*,IConnectionPoint*>::iterator it = connectionPointMap_.begin();
			  it != connectionPointMap_.end(); it++)
		{
			if ( ::IsEqualIID( *(*it).first, riid ) )
				return (*it).second->QueryInterface(IID_IConnectionPoint,(void**)ppCP);
		}
		ppCP = NULL;
		return CONNECT_E_NOCONNECTION;
	}

	void add(REFIID riid,IConnectionPoint* cp)
	{
		connectionPointMap_[&riid] = cp;
	}

protected:

	std::map<const IID*,IConnectionPoint*> connectionPointMap_;
};


template<class T>
class com_eventsrc : public ConnectionPointContainer<T> 
{};

//////////////////////////////////////////////////////////////////////
// GIT impl
//////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////
// CP impl
//////////////////////////////////////////////////////////////////////

namespace ole {

class ConnectionPointBase : public IUnknown
{
public:
	ConnectionPointBase();
	
	virtual HRESULT getConnectionInterface( IID *pIID);
	virtual HRESULT getConnectionPointContainer( IConnectionPointContainer **ppCPC);
	virtual HRESULT advise( IUnknown *pUnkSink, DWORD *pdwCookie);
	virtual HRESULT unadvise( DWORD dwCookie);

protected:

	// inner class to provide own COM identity
	class innerConnectionPoint : 
		public IConnectionPoint,
		public interfaces< innerConnectionPoint, implements<IConnectionPoint> >
	{
		public:
			outer_this(ConnectionPointBase,inner_connection_point_);

			virtual HRESULT __stdcall QueryInterface( REFIID riid, void** ppvObject);
			virtual ULONG   __stdcall AddRef( void);
			virtual ULONG   __stdcall Release( void);
			virtual HRESULT __stdcall GetConnectionInterface( IID *pIID);
			virtual HRESULT __stdcall GetConnectionPointContainer( IConnectionPointContainer **ppCPC);
			virtual HRESULT __stdcall Advise( IUnknown *pUnkSink, DWORD *pdwCookie);
			virtual HRESULT __stdcall Unadvise( DWORD dwCookie);
			virtual HRESULT __stdcall EnumConnections( IEnumConnections **ppEnum);

	} inner_connection_point_;

};
///////////////////////////////////////////////////////////

class Cookies
{
	public:
		DWORD get();
		void release(DWORD c);
	
	protected:
		std::list<DWORD> cookies_;
		std::list<DWORD> free_cookies_;

};

///////////////////////////////////////////////////////////


class ConnectionPointNoFreezePolicy
{
public:

	template<class T>
	static bool freeze_events( T* t) 
	{
		return true;
	}

	template<class T>
	static void thaw_events( T* t)
	{}
};


class ConnectionPointFreezePolicy
{
public:

	template<class T>
	static bool freeze_events( T* t) 
	{	
		if ( t->frozen() )
			return false;

		punk<IOleControlSite> cs;
		punk<IOleInPlaceSite>& site = t->site();
		if ( site )
		//if ( S_OK == site.queryInterface(IID_IOleControlSite,(void**)&cs) )
		if ( S_OK == site.queryInterface(&cs) )
		{
			cs->LockInPlaceActive(TRUE);
		}
		return true;
	}

	template<class T>
	static void thaw_events( T* t)
	{
		punk<IOleControlSite> cs;
		punk<IOleInPlaceSite>& site = t->site();
		if ( site )
		//if ( S_OK == site.queryInterface(IID_IOleControlSite,(void**)&cs) )
		if ( S_OK == site.queryInterface(&cs) )
		{
			cs->LockInPlaceActive(TRUE);
		}
	}
};

template<class I>
class ConnectionPointAdviseSingleThreadPolicy
{
public:

	HRESULT advise( IUnknown *pUnkSink, DWORD *pdwCookie) 
	{
		I* i = 0;
		if ( S_OK != pUnkSink->QueryInterface( __uuidof(I), (void**)&i ))
			return CONNECT_E_CANNOTCONNECT;

		*pdwCookie = cookies_.get();
		sinks_.insert( std::make_pair(*pdwCookie,i) );
		return S_OK;
	}

	HRESULT unadvise( DWORD dwCookie) 
	{
		if ( sinks_.count(dwCookie) > 0 )
		{
			sinks_[dwCookie]->Release();
			sinks_.erase(dwCookie);
			cookies_.release(dwCookie);
		}
		return S_OK;
	}

	typedef typename std::map<DWORD,I*>::iterator SinkIterator;

	SinkIterator begin()
	{
		return sinks_.begin();
	}

	SinkIterator end()
	{
		return sinks_.end();
	}

	template<class T>
	HRESULT getSinkInterface(SinkIterator index, T** t)
	{
		return ((*index).second)->QueryInterface( uuidof<T>(), (void**)t);
	}

private:
	std::map<DWORD,I*> sinks_;
	Cookies			 cookies_;
};

template<class I>
class ConnectionPointAdviseMultiThreadPolicy
{
public:

	virtual HRESULT advise( IUnknown *pUnkSink, DWORD *pdwCookie) 
	{
		I* i = 0;
		if ( S_OK != pUnkSink->QueryInterface( __uuidof(I), (void**)&i ))
			return CONNECT_E_CANNOTCONNECT;
		
		GIT git;
		if ( S_OK == git.registerInterface( i, pdwCookie) )
		{
			sinks_.push_back(*pdwCookie);
			return S_OK;
		}
		return CONNECT_E_CANNOTCONNECT;
	}

	virtual HRESULT unadvise( DWORD dwCookie) 
	{		
		for ( std::list<DWORD>::iterator it = sinks_.begin(); it != sinks_.end(); it++ )
		{
			if ( *it  == dwCookie )
			{
				sinks_.erase(it);
				break;
			}
		}		
		GIT git;
		return git.revokeInterface(dwCookie);
	}

	typedef typename std::list<DWORD>::iterator SinkIterator;

	SinkIterator begin()
	{
		return sinks_.begin();
	}

	SinkIterator end()
	{
		return sinks_.end();
	}

	template<class T>
	HRESULT getSinkInterface(SinkIterator index, T** t )
	{
		GIT git;
		return git.getInterface(*index,t);
	}

private:
	std::list<DWORD> sinks_;
};

///////////////////////////////////////////////////////////

} // end namespace ole

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
// connection points
///////////////////////////////////////////////////////////

template< class T,
          class I, 
		  class P = mol::ole::ConnectionPointAdviseSingleThreadPolicy<I>,
		  class F = mol::ole::ConnectionPointNoFreezePolicy >

class ConnectionPoint : public mol::ole::ConnectionPointBase  
{
public:
	typedef I Interface;
	typedef T ConnectionPointType;



	ConnectionPoint()
	{
		T* t = (T*)this;
		((ConnectionPointContainer<T>*)t)->add(__uuidof(I),&inner_connection_point_);
	}
	virtual ~ConnectionPoint()
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
		return Policy_.advise(pUnkSink,pdwCookie);
	}

	virtual HRESULT unadvise( DWORD dwCookie) 
	{
		return Policy_.unadvise(dwCookie);
	}

	void fire(DISPID dispIdMember)
	{
		T* t = (T*)this;	
		if ( !F::freeze_events(t) )
			return;

		for ( typename P::SinkIterator it = Policy_.begin(); it != Policy_.end(); it++)
		{
			punk<IDispatch> disp;
			if ( S_OK == Policy_.getSinkInterface(it,&disp) )
			{
				disp_invoke(disp,dispIdMember);
			}
		}
		F::thaw_events(t);
	}

	template<class V>
	void fire(DISPID dispIdMember,  V v)
	{
		T* t = (T*)this;	
		if ( !F::freeze_events(t) )
			return;

		for ( typename P::SinkIterator it = Policy_.begin(); it != Policy_.end(); it++)
		{
			punk<IDispatch> disp;
			if ( S_OK == Policy_.getSinkInterface(it,&disp) )
			{
				disp_invoke(disp,dispIdMember,v);
			}
		}
		F::thaw_events(t);
	}

	template<class V1, class V2>
	void fire(DISPID dispIdMember,  V1 v1, V2 v2)
	{
		T* t = (T*)this;	
		if ( !F::freeze_events(t) )
			return;

		for ( typename P::SinkIterator it = Policy_.begin(); it != Policy_.end(); it++)
		{
			punk<IDispatch> disp;
			if ( S_OK == Policy_.getSinkInterface(it,&disp) )
			{
				disp_invoke(disp,dispIdMember,v1,v2);
			}
		}
		F::thaw_events(t);
	}

	template<class V1, class V2, class V3>
	void fire(DISPID dispIdMember,  V1 v1, V2 v2, V3 v3)
	{
		T* t = (T*)this;	
		if ( !F::freeze_events(t) )
			return;

		for ( typename P::SinkIterator it = Policy_.begin(); it != Policy_.end(); it++)
		{
			punk<IDispatch> disp;
			if ( S_OK == Policy_.getSinkInterface(it,&disp) )
			{
				disp_invoke(disp,dispIdMember,v1,v2,v3);
			}
		}
		F::thaw_events(t);
	}

	template<class V1, class V2, class V3, class V4>
	void fire(DISPID dispIdMember,  V1 v1, V2 v2, V3 v3, V4 v4)
	{
		T* t = (T*)this;	
		if ( !F::freeze_events(t) )
			return;

		for ( typename P::SinkIterator it = Policy_.begin(); it != Policy_.end(); it++)
		{
			punk<IDispatch> disp;
			if ( S_OK == Policy_.getSinkInterface(it,&disp) )
			{
				disp_invoke(disp,dispIdMember,v1,v2,v3,v4);
			}
		}
		F::thaw_events(t);
	}

	template<class V1, class V2, class V3, class V4, class V5>
	void fire(DISPID dispIdMember,  V1 v1, V2 v2, V3 v3, V4 v4, V5 v5)
	{
		T* t = (T*)this;	
		if ( !F::freeze_events(t) )
			return;

		for ( typename P::SinkIterator it = Policy_.begin(); it != Policy_.end(); it++)
		{
			punk<IDispatch> disp;
			if ( S_OK == Policy_.getSinkInterface(it,&disp) )
			{
				disp_invoke(disp,dispIdMember,v1,v2,v3,v4,v5);
			}
		}
		F::thaw_events(t);
	}

	template<class V1, class V2, class V3, class V4, class V5, class V6>
	void fire(DISPID dispIdMember,  V1 v1, V2 v2, V3 v3, V4 v4, V5 v5, V6 v6)
	{
		T* t = (T*)this;	
		if ( !F::freeze_events(t) )
			return;

		for ( typename P::SinkIterator it = Policy_.begin(); it != Policy_.end(); it++)
		{
			punk<IDispatch> disp;
			if ( S_OK == Policy_.getSinkInterface(it,&disp) )
			{
				disp_invoke(disp,dispIdMember,v1,v2,v3,v4,v5,v6);
			}
		}
		F::thaw_events(t);
	}

protected:
	P Policy_;
};

template<class T,class I>
class com_events : public ConnectionPoint<T,I>  
{};

template<class T,class I, class P=mol::ole::ConnectionPointAdviseSingleThreadPolicy<I>, class F = mol::ole::ConnectionPointFreezePolicy>
class CtrlConnectionPoint : public ConnectionPoint<T,I,P,F>  
{};


template<class T,class I>
class ctrl_events : public CtrlConnectionPoint<T,I>  
{};

} // end namespace mol


#endif

