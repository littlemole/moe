#include "StdAfx.h"
#include "httpAx.h"
#include "http/http.h"
#include "thread/thread.h"
#include "ole/cp.h"

HttpHeader::Instance* HttpHeader::CreateInstance(const std::string& n, const std::string& v)
{
	Instance* i = new Instance;
	i->put_Name(mol::bstr(n));
	i->put_Value(mol::bstr(v));
	return i;
}

HRESULT STDMETHODCALLTYPE HttpHeader::put_Name( BSTR m)
{
	name_ = m;
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE HttpHeader::get_Name( BSTR *m) 
{
	if (!m)
		return E_INVALIDARG;

	*m = ::SysAllocString(name_);
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE HttpHeader::put_Value( BSTR m) 
{
	value_ = m;
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE HttpHeader::get_Value( BSTR *m) 
{
	if (!m)
		return E_INVALIDARG;
	*m = ::SysAllocString(value_);
	return S_OK;
}



HttpHeaders::Instance* HttpHeaders::CreateInstance(std::vector<std::pair<std::string,std::string>>& v)
{
	Instance* i = new Instance;

	for ( std::vector<std::pair<std::string,std::string>>::iterator it = v.begin(); it != v.end(); it++)
	{
		mol::punk<IHttpHeader> header = HttpHeader::CreateInstance((*it).first,(*it).second);
		header->AddRef();
		i->headers_.push_back(header);
	}

	return i;
}

void HttpHeaders::dispose() 
{
	for( std::vector<IHttpHeader*>::iterator it = headers_.begin(); it != headers_.end(); it++)
	{
		(*it)->Release();
	}
}

HRESULT STDMETHODCALLTYPE HttpHeaders::_NewEnum( IEnumVARIANT **newEnum)
{
	return mol::make_enumVariant(headers_,newEnum);
}
        
HRESULT STDMETHODCALLTYPE HttpHeaders::Item(  VARIANT i, VARIANT *header)
{
	if (!header)
		return E_INVALIDARG;

	header->vt = VT_EMPTY;
	header->intVal = 0;

	if ( i.vt == VT_BSTR )
	{
		for ( std::vector<IHttpHeader*>::iterator it = headers_.begin(); it != headers_.end(); it++)
		{
			mol::bstr name;
			(*it)->get_Name(&name);
			if ( _wcsicmp( i.bstrVal, name.bstr_ ) == 0 ) 
			{
				header->vt = VT_DISPATCH;
				return (*it)->QueryInterface(IID_IDispatch,(void**)&(header->pdispVal));
			}
		}
		return S_FALSE;
	}

	mol::variant index(i);
	index.changeType(VT_I4);

	if ( index.lVal < 0 || index.lVal >= headers_.size() )
	{
		return S_FALSE;
	}

	header->vt = VT_DISPATCH;
	return headers_[index.lVal]->QueryInterface(IID_IDispatch,(void**)&(header->pdispVal));
}
        
HRESULT STDMETHODCALLTYPE HttpHeaders::Count( long *cnt)
{
	if(!cnt)
		return E_INVALIDARG;
	*cnt = (long) headers_.size();
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE HttpHeaders::Add( BSTR name, BSTR value)
{
	if(!name || !value)
		return E_INVALIDARG;

	mol::punk<IHttpHeader> header = HttpHeader::CreateInstance( mol::tostring(name), mol::tostring(value) );
	headers_.push_back(header);
	return S_OK;
}


void HttpRequest::dispose()
{
	mol::GIT git;
	if ( onResultCookie_ )
	{
		git.revokeInterface(onResultCookie_);
		onResultCookie_ = 0;
	}
	if ( onErrorCookie_ )
	{
		git.revokeInterface(onErrorCookie_);
		onErrorCookie_ = 0;
	}
}

HttpRequest::Instance* HttpRequest::CreateInstance()
{
	Instance* i = new Instance;
	i->put_Version(mol::bstr("HTTP/1.0"));
	i->onErrorCookie_ = 0;
	i->onResultCookie_ = 0;
	return i;
}



HRESULT STDMETHODCALLTYPE HttpRequest::put_onResult( IDispatch *cb)
{ 
	if(!cb)
		return E_INVALIDARG;

	mol::GIT git;
	if ( onResultCookie_ )
	{
		git.revokeInterface(onResultCookie_);
	}
	HRESULT hr = git.registerInterface(cb,&onResultCookie_);
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE HttpRequest::put_onError( IDispatch *cb)
{ 
	if(!cb)
		return E_INVALIDARG;

	mol::GIT git;
	if ( onErrorCookie_ )
	{
		git.revokeInterface(onErrorCookie_);
	}
	git.registerInterface(cb,&onErrorCookie_);
	return S_OK;
}

HRESULT STDMETHODCALLTYPE HttpRequest::put_Url( BSTR m)
{ 
	url_ = m;
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE HttpRequest::get_Url( BSTR *m)
{ 
	if(!m)
		return E_INVALIDARG;

	*m = ::SysAllocString(url_);
	return S_OK;
}

HRESULT STDMETHODCALLTYPE HttpRequest::put_Method( BSTR m)
{ 
	method_ = m;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE HttpRequest::get_Method( BSTR *m)
{ 
	if(!m)
		return E_INVALIDARG;
	*m = ::SysAllocString(method_);
	return S_OK;
}

HRESULT STDMETHODCALLTYPE HttpRequest::put_Version( BSTR m)
{ 
	version_ = m;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE HttpRequest::get_Version( BSTR *m)
{ 
	if(!m)
		return E_INVALIDARG;

	*m = ::SysAllocString(version_);
	return S_OK;
}

HRESULT STDMETHODCALLTYPE HttpRequest::put_Headers( IHttpHeaders *h)
{ 
	headers_ = h;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE HttpRequest::get_Headers( IHttpHeaders **h)
{ 
	if(!h)
		return E_INVALIDARG;

	if(!headers_)
	{
		std::vector<std::pair<std::string,std::string> > v;
		headers_ = HttpHeaders::CreateInstance(v);
	}
	return headers_.queryInterface(h);

}

HRESULT STDMETHODCALLTYPE HttpRequest::put_Body(  BSTR b)
{ 
	body_ = b;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE HttpRequest::get_Body(  BSTR *b)
{ 
	if(!b)
		return E_INVALIDARG;

	*b = ::SysAllocString(body_);
	return S_OK;
}

HRESULT STDMETHODCALLTYPE HttpRequest::Execute()
{ 
	AddRef();
	mol::thread( boost::bind( &HttpRequest::worker, this ) );
	return S_OK;
}

void HttpRequest::worker()
{
	::CoInitializeEx(0,COINIT_MULTITHREADED);

	mol::Http http;

	mol::HttpRequest request;
	request.uri = mol::Uri(url_.tostring());
	mol::HttpResponse response = http.send(request);

	mol::punk<IHttpResponse> resp = HttpResponse::CreateInstance();
	std::istringstream oss(response.headers.getStatus());
	long status = 0;
	oss >> status;
	resp->put_Status(status);
	resp->put_Body( mol::bstr( response.body.body() ) );

	std::vector<std::pair<std::string,std::string>> v(response.headers.begin(), response.headers.end());
	mol::punk<IHttpHeaders> headers = HttpHeaders::CreateInstance(v);
	resp->put_Headers(headers);

	
	if ( onResultCookie_ )
	{
		mol::punk<IUnknown> unk;
		mol::GIT git;
		HRESULT hr = git.getInterface(onResultCookie_,&unk);

		if ( hr == S_OK && unk )
		{
			mol::punk<IDispatch> disp(unk);
			if( disp )
			{
				//mol::disp_invoke(disp,DISPID_VALUE,mol::variant(resp));

				mol::variant var(resp);
				DISPPARAMS dps = {&var,0,1,0};

				UINT e = 0;
				EXCEPINFO ex;
				::ZeroMemory(&ex,sizeof(EXCEPINFO));

				hr = disp->Invoke( DISPID_VALUE, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dps, NULL, &ex, &e );
				if(hr!=S_OK)
				{
					if(ex.bstrDescription)
					{
						ODBGS(ex.bstrDescription);
					}
				}
			}
		}
	}

	Release();
	::CoUninitialize();
}



HttpResponse::Instance* HttpResponse::CreateInstance()
{
	Instance* i = new Instance;
	return i;
}

HRESULT STDMETHODCALLTYPE HttpResponse::get_Status( LONG *s)
{
	if(!s)
		return E_INVALIDARG;
	*s = status_;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE HttpResponse::put_Status( LONG s)
{
	status_ = s;
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE HttpResponse::get_Body(  BSTR *s)
{
	if(!s)
		return E_INVALIDARG;

	*s = ::SysAllocString(body_);
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE HttpResponse::put_Body(  BSTR b)
{
	body_ = b;
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE HttpResponse::get_Size( long *s)
{
	if(!s)
		return E_INVALIDARG;
	*s = ::SysStringLen(body_);
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE HttpResponse::put_Size( long b)
{
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE HttpResponse::put_Headers( IHttpHeaders *h) 
{
	headers_ = h;
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE HttpResponse::get_Headers( IHttpHeaders **h)
{
	if(!h)
		return E_INVALIDARG;

	return headers_.queryInterface(h);
}

HRESULT STDMETHODCALLTYPE Http::Get( BSTR url,IHttpRequest **request)
{
	if(!request)
		return E_INVALIDARG;

	*request = 0;

	HRESULT hr = Request(mol::bstr("GET"),request);
	if(hr!=S_OK || !*request)
		return hr;

	return (*request)->put_Url(url);
}
        
HRESULT STDMETHODCALLTYPE Http::Request( BSTR cmd, IHttpRequest **request)
{
	mol::punk<IHttpRequest> r = HttpRequest::CreateInstance();
	r->put_Method(cmd);
	return r.queryInterface(request);
}