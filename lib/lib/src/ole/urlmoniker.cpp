
#include "ole/urlmoniker.h"
#include "util/str.h"
#include "util/regex.h"
#include <initguid.h>

namespace mol {
namespace ie  {

BaseUrl::BaseUrl( const mol::string& u, IStream* s )
{
	mime_   = mol::towstring("text/html");
    url_    = mol::towstring(u);
    stream_ = s;
}

BaseUrl::BaseUrl( const mol::string& u, const mol::string& mime, IStream* s )
{
	mime_   = mol::towstring(mime);
    url_    = mol::towstring(u);
    stream_ = s;
}

HRESULT __stdcall BaseUrl::BindToStorage( IBindCtx *pbc, IMoniker *pmkToLeft, REFIID riid, void **ppvObj) 
{ 
	HRESULT hr;
    if ( riid == IID_IStream )
    {
        hr = stream_->QueryInterface(IID_IStream,ppvObj);
		if (hr != S_OK )
			return E_FAIL;
    }
	return S_OK;
}

HRESULT __stdcall BaseUrl::GetDisplayName( IBindCtx *pbc, IMoniker *pmkToLeft, LPOLESTR *ppszDisplayName) 
{ 
    wchar_t* wc = (wchar_t*)::CoTaskMemAlloc( (url_.size()+1)*sizeof(wchar_t));
    ::wcsncpy(wc,url_.c_str(),url_.size());
    wc[url_.size()] = 0;
    *ppszDisplayName = wc;
    return S_OK; 
}

HRESULT __stdcall  AsyncUrl::OnStartBinding( DWORD grfBINDF, IBinding *pib)
{
    return S_OK;
};

HRESULT __stdcall  AsyncUrl::GetPriority( LONG *pnPriority)
{
    *pnPriority = THREAD_PRIORITY_NORMAL;
    return S_OK;
}

HRESULT __stdcall  AsyncUrl::OnLowResource( DWORD reserved)
{
    return S_OK;
}

HRESULT __stdcall  AsyncUrl::OnProgress( ULONG ulProgress,ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
{
    return S_OK;
}


HRESULT __stdcall  AsyncUrl::OnStopBinding( HRESULT hresult,LPCWSTR szError)
{
    return S_OK;
}

HRESULT __stdcall  AsyncUrl::GetBindInfo( DWORD *grfBINDF,BINDINFO *pbindinfo)
{
    *grfBINDF = BINDF_ASYNCHRONOUS|BINDF_FROMURLMON;
    return S_OK;
}

HRESULT __stdcall  AsyncUrl::OnDataAvailable( DWORD grfBSCF,DWORD dwSize, FORMATETC *pformatetc,STGMEDIUM *pstgmed)
{
    return S_OK;
}

HRESULT __stdcall  AsyncUrl::OnObjectAvailable( REFIID riid, IUnknown *punk)
{
    return S_OK;
}    

HRESULT __stdcall AsyncUrl::BeginningTransaction(LPCWSTR szURL,LPCWSTR szHeaders,DWORD dwReserved,LPWSTR *pszAdditionalHeaders)
{
    pszAdditionalHeaders = NULL;
    return S_OK;
}

HRESULT __stdcall AsyncUrl::OnResponse( DWORD dwResponseCode,LPCWSTR szResponseHeaders,LPCWSTR szRequestHeaders,LPWSTR *pszAdditionalRequestHeaders)
{
    pszAdditionalRequestHeaders = NULL;
    return S_OK;
}


HRESULT AsyncUrl::startDownload( const mol::string& url )
{
    location_ = url;

    if ( S_OK == ::CreateURLMoniker( NULL, mol::towstring(location_).c_str(), &mon_ ) )
    {
        AsyncBindCtx bind(this);
		mol::punk<IStream>  stream;
        HRESULT hr = mon_->BindToStorage( bind, NULL, IID_IStream, (void**)&stream);
        return S_OK;
    }
    return S_FALSE;
}

//////////////////////////////////////////////////////////////////////////

HttpUrl::HttpUrl() 
{}

HttpUrl::HttpUrl(const mol::string& loc, const mol::string& h, DWORD m)
:location_(mol::tostring(loc)),method_(m),fRedirect_(FALSE),requestHeaders_(tostring(h)),postdatasize_(0)
{
    httpTransaction_ << "GET " << location_ << " HTTP/1.1" << std::endl;
//    ODBGS((httpTransaction_.str().c_str()));
    startDownload(loc);
}

HttpUrl::HttpUrl(const mol::string& loc, const mol::string& p, const mol::string& h, DWORD m )
:location_(mol::tostring(loc)), method_(m), fRedirect_(FALSE), requestHeaders_(tostring(h)), postdata_(tostring(p))
{
    httpTransaction_ << "POST " << location_ << " HTTP/1.1" << std::endl;

    postdatasize_ = (int)postdata_.size();
    
    postdataGlob_.alloc(postdatasize_,GPTR);
    
    char* c=postdataGlob_.lock();
    memcpy(c,p.c_str(),postdatasize_);
    postdataGlob_.unLock();

    startDownload(loc);
}

HttpUrl::~HttpUrl()
{
    ODBGS("exitus");
}

HRESULT __stdcall  HttpUrl::OnDataAvailable( DWORD grfBSCF,DWORD dwSize, FORMATETC *pformatetc,STGMEDIUM *pstgmed)
{
    return S_FALSE;
}

HRESULT __stdcall HttpUrl::BeginningTransaction(LPCWSTR szURL,LPCWSTR szHeaders,DWORD dwReserved,LPWSTR *pszAdditionalHeaders)
{
    httpTransaction_ << mol::wstring2ansi(szHeaders) << std::endl;;

    if ( requestHeaders_.size() && (!fRedirect_) )
    {
        int len     = (int)requestHeaders_.size();
        wchar_t* wc = (wchar_t*)CoTaskMemAlloc( len*2+2);
        std::wstring ws = mol::ansi2wstring(requestHeaders_);
        wcsncpy(wc,ws.c_str(),len);
        (wc[len]) = (wchar_t)0;

        *pszAdditionalHeaders = wc;
        httpTransaction_ << requestHeaders_ << std::endl;
    }
    else
        pszAdditionalHeaders = NULL;

    if ( (!fRedirect_) && (method_ == BINDVERB_POST) )
    {
        httpTransaction_ << postdata_ << std::endl;
    }
    return S_OK;
}

HRESULT __stdcall HttpUrl::OnResponse( DWORD dwResponseCode,LPCWSTR szResponseHeaders,LPCWSTR szRequestHeaders,LPWSTR *pszAdditionalRequestHeaders)
{
    responseHeaders_ = mol::wstring2ansi(szResponseHeaders);
    httpTransaction_ << std::endl << responseHeaders_ << std::endl;
    pszAdditionalRequestHeaders = NULL;
    return S_OK;
}

HRESULT __stdcall HttpUrl::OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
{
    if ( ulStatusCode == BINDSTATUS_REDIRECTING )
    {
		fRedirect_ = TRUE;
    }
    if ( ulStatusCode == BINDSTATUS_MIMETYPEAVAILABLE  )
    {
		mime_ = mol::wstring2ansi(szStatusText);
    }
    return S_OK;
}

HRESULT __stdcall HttpUrl::GetBindInfo(DWORD* pgrfBINDF, BINDINFO* pbindInfo)
{
    if (fRedirect_ && BINDVERB_POST == method_)
    {
        // We're being redirected by the server. Stop posting
        method_ = BINDVERB_GET;
    }

    *pgrfBINDF = BINDF_FROMURLMON|BINDF_ASYNCHRONOUS | BINDF_ASYNCSTORAGE|BINDF_NEEDFILE;// | BINDF_PULLDATA;
    *pgrfBINDF |= BINDF_GETNEWESTVERSION;// | BINDF_NOWRITECACHE;

    // Set up the BINDINFO data structure
    pbindInfo->cbSize = sizeof(BINDINFO);
    pbindInfo->dwBindVerb = method_;
    pbindInfo->szExtraInfo = NULL;

    // Initialize the STGMEDIUM.
    memset(&pbindInfo->stgmedData, 0, sizeof(STGMEDIUM));
    pbindInfo->grfBindInfoF = 0;
    pbindInfo->szCustomVerb = NULL;

    // set up action-specific members
    switch(method_)
    {
        case BINDVERB_POST:
        {			
            *pgrfBINDF |= BINDF_FORMS_SUBMIT;
            pbindInfo->stgmedData.tymed          = TYMED_HGLOBAL; 
            pbindInfo->stgmedData.hGlobal        = postdataGlob_;
            pbindInfo->cbstgmedData              = postdatasize_;
            pbindInfo->iid                       = IID_IBindStatusCallback;
            pbindInfo->dwCodePage                = CP_ACP;
            pbindInfo->stgmedData.pUnkForRelease = (LPUNKNOWN)(LPBINDSTATUSCALLBACK)this;
            pbindInfo->stgmedData.pUnkForRelease->AddRef(); 
            break;
        }
        case BINDVERB_GET: 
            break;
        default: 
            return E_FAIL;
    }
    return S_OK;
}

// helpers & accessors

DWORD HttpUrl::getMethod()                       
{ 
    return method_; 
}

bool  HttpUrl::isRedirect()                      
{ 
    return fRedirect_ == TRUE; 
}

const mol::string HttpUrl::getLocation()        
{ 
	return mol::toString(location_); 
}

const std::string HttpUrl::getMime()        
{ 
    return mime_; 
}


const std::string HttpUrl::getRequestHeaders()  
{ 
    return requestHeaders_; 
}

const std::string HttpUrl::getResponseHeaders() 
{ 
    return responseHeaders_; 
}

std::string HttpUrl::getPostData()               
{ 
    return postdata_; 
}

int HttpUrl::getPostDataSize()               
{ 
    return postdatasize_; 
}

const std::string HttpUrl::getHttpTransaction() 
{ 
    return httpTransaction_.str(); 
}

///////////////////////////////////////////////////////////////////////
//
// encoding
//
///////////////////////////////////////////////////////////////////////


} // end namespace mol::win::ie
} // end namespace mol
