#include "ole/cp.h"

namespace mol {
namespace ole {

//////////////////////////////////////////////////////////////////////
// CP
//////////////////////////////////////////////////////////////////////

ConnectionPointBase::ConnectionPointBase()
{}

HRESULT ConnectionPointBase::getConnectionInterface( IID *pIID) 
{
	*pIID = IID_NULL;
	return S_OK;
}

HRESULT ConnectionPointBase::getConnectionPointContainer( IConnectionPointContainer **ppCPC) 
{
	*ppCPC = 0;
	return S_OK;
}

HRESULT ConnectionPointBase::advise( IUnknown *pUnkSink, DWORD *pdwCookie) 
{
	return S_OK;
}

HRESULT ConnectionPointBase::unadvise( DWORD dwCookie) 
{
	return S_OK;
}

HRESULT __stdcall ConnectionPointBase::innerConnectionPoint::QueryInterface( REFIID riid, void** ppvObject)
{
	return this->QueryInterfaceImpl(riid, ppvObject);
}
    
ULONG __stdcall ConnectionPointBase::innerConnectionPoint::AddRef( void)
{
	return This()->AddRef();
}

ULONG __stdcall ConnectionPointBase::innerConnectionPoint::Release( void)
{
	return This()->Release();
}

HRESULT __stdcall ConnectionPointBase::innerConnectionPoint::GetConnectionInterface( IID *pIID) 
{
	return This()->getConnectionInterface(pIID);
}

HRESULT __stdcall ConnectionPointBase::innerConnectionPoint::GetConnectionPointContainer( IConnectionPointContainer **ppCPC) 
{
	return This()->getConnectionPointContainer(ppCPC);
}

HRESULT __stdcall ConnectionPointBase::innerConnectionPoint::Advise( IUnknown *pUnkSink, DWORD *pdwCookie) 
{
	return This()->advise(pUnkSink,pdwCookie);
}

HRESULT __stdcall ConnectionPointBase::innerConnectionPoint::Unadvise( DWORD dwCookie) 
{
	return This()->unadvise( dwCookie );
}

HRESULT __stdcall ConnectionPointBase::innerConnectionPoint::EnumConnections( IEnumConnections **ppEnum)
{
	return E_NOTIMPL;
}

DWORD Cookies::get()
{
	if ( !free_cookies_.empty() )
	{
		DWORD c = free_cookies_.front();
		free_cookies_.pop_front();
		return c;
	}

	DWORD c = (DWORD)cookies_.size()+1;
	cookies_.push_back(c);
	return c;
}

void Cookies::release(DWORD c)
{
	for ( std::list<DWORD>::iterator it = cookies_.begin(); it != cookies_.end(); it++)
	{
		if ( (*it) == c )
		{
			free_cookies_.push_back(c);
			cookies_.erase(it);
			return;
		}
	}
}


} // end namespace mol::win::ole
} // end namespace mol