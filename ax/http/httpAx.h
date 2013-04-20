#ifndef _MOL_DEF_GUARD_AX_HTTP_CTRL_DEF_GUARD_DEFINE_
#define _MOL_DEF_GUARD_AX_HTTP_CTRL_DEF_GUARD_DEFINE_

#include "ole/factory.h"
#include "ole/aut.h"
#include "http_h.h"

class HttpHeader : 
	public mol::Dispatch<IHttpHeader>,
	public mol::interfaces< HttpHeader, 
				mol::implements< IDispatch, IHttpHeader> >
{
public:

	virtual void dispose() {};

	typedef mol::com_obj<HttpHeader> Instance;
	static Instance* CreateInstance(const std::string& n, const std::string& v);

    virtual HRESULT STDMETHODCALLTYPE put_Name( BSTR m);
    virtual HRESULT STDMETHODCALLTYPE get_Name( BSTR *m);
    virtual HRESULT STDMETHODCALLTYPE put_Value( BSTR m);
    virtual HRESULT STDMETHODCALLTYPE get_Value( BSTR *m);

private:
	mol::bstr name_;
	mol::bstr value_;
};


class HttpHeaders : 
	public mol::Dispatch<IHttpHeaders>,
	public mol::interfaces< HttpHeaders, 
				mol::implements< IDispatch, IHttpHeaders> >
{
public:

	typedef mol::com_obj<HttpHeaders> Instance;
	static Instance* CreateInstance(std::vector<std::pair<std::string,std::string>>& v);

	virtual void dispose();

    virtual HRESULT STDMETHODCALLTYPE _NewEnum( IEnumVARIANT **newEnum);        
    virtual HRESULT STDMETHODCALLTYPE Item(  VARIANT i, VARIANT *header);        
    virtual HRESULT STDMETHODCALLTYPE Count( long *cnt);
    virtual HRESULT STDMETHODCALLTYPE Add( BSTR name, BSTR value);

private:

	std::vector<IHttpHeader*> headers_;
};



class HttpRequest : 
	public mol::Dispatch<IHttpRequest>,
	public mol::interfaces< HttpRequest, 
				mol::implements< IDispatch, IHttpRequest> >
{
public:

	virtual void dispose();

	typedef mol::com_obj<HttpRequest> Instance;
	static Instance* CreateInstance();

    virtual HRESULT STDMETHODCALLTYPE put_onResult( IDispatch *cb);      
    virtual HRESULT STDMETHODCALLTYPE put_onError( IDispatch *cb);
        
    virtual HRESULT STDMETHODCALLTYPE put_Url( BSTR m);        
    virtual HRESULT STDMETHODCALLTYPE get_Url( BSTR *m);
        
    virtual HRESULT STDMETHODCALLTYPE put_Method( BSTR m);
    virtual HRESULT STDMETHODCALLTYPE get_Method( BSTR *m);
        
    virtual HRESULT STDMETHODCALLTYPE put_Version( BSTR m);
    virtual HRESULT STDMETHODCALLTYPE get_Version( BSTR *m);
        
    virtual HRESULT STDMETHODCALLTYPE put_Headers( IHttpHeaders *h);
    virtual HRESULT STDMETHODCALLTYPE get_Headers( IHttpHeaders **h);
        
    virtual HRESULT STDMETHODCALLTYPE put_Body(  BSTR b);
    virtual HRESULT STDMETHODCALLTYPE get_Body(  BSTR *b);
        
    virtual HRESULT STDMETHODCALLTYPE Execute();
        
private:

	void worker();

	DWORD onResultCookie_;
	DWORD onErrorCookie_;

	mol::punk<IHttpHeaders> headers_;
	mol::bstr url_;
	mol::bstr method_;
	mol::bstr version_;
	mol::bstr body_;
};



class HttpResponse : 
	public mol::Dispatch<IHttpResponse>,
	public mol::interfaces< HttpResponse, 
				mol::implements< IDispatch, IHttpResponse> >
{
public:

	typedef mol::com_obj<HttpResponse> Instance;
	static Instance* CreateInstance();

	virtual void dispose() {}

    virtual HRESULT STDMETHODCALLTYPE get_Status( LONG *s);
    virtual HRESULT STDMETHODCALLTYPE put_Status( LONG s);
        
    virtual HRESULT STDMETHODCALLTYPE get_Body(  BSTR *s);
    virtual HRESULT STDMETHODCALLTYPE put_Body(  BSTR b);
        
    virtual HRESULT STDMETHODCALLTYPE get_Size( long *s);        
    virtual HRESULT STDMETHODCALLTYPE put_Size( long b);
        
    virtual HRESULT STDMETHODCALLTYPE put_Headers( IHttpHeaders *h);        
    virtual HRESULT STDMETHODCALLTYPE get_Headers( IHttpHeaders **h);
        
private:

	long status_;
	mol::bstr body_;
	mol::punk<IHttpHeaders> headers_;
};

class Http : 
	public mol::com_registerobj<Http,CLSID_Client,CLSCTX_INPROC_SERVER,mol::MULTITHREADED, REGCLS_MULTIPLEUSE>,
	public mol::Dispatch<IHttp>,
	public mol::interfaces< Http,
			mol::implements<
				IHttp,
				IDispatch > >
{
public:

	virtual void dispose() {}

	virtual  HRESULT STDMETHODCALLTYPE Get( BSTR url,IHttpRequest **request);        

	virtual HRESULT STDMETHODCALLTYPE Request( BSTR cmd, IHttpRequest **request);
};

#endif
