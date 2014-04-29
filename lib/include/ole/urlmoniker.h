#ifndef MOL_URL_MON_DEF_GUARD_
#define MOL_URL_MON_DEF_GUARD_

#include "util/uni.h"
#include "win/res.h"
#include "util/str.h"
#include "ole/com.h"
#include "ole/punk.h"
#include "ole/obj.h"
#include "ole/ole.h"
#include "ole/bstr.h"

#include <sstream>
#include <Urlmon.h>
#include <MLang.h>

namespace mol {
namespace ie  {

typedef 
enum _tagINTERNETFEATURELIST
    {	FEATURE_OBJECT_CACHING	= 0,
	FEATURE_ZONE_ELEVATION	= ( FEATURE_OBJECT_CACHING + 1 ) ,
	FEATURE_MIME_HANDLING	= ( FEATURE_ZONE_ELEVATION + 1 ) ,
	FEATURE_MIME_SNIFFING	= ( FEATURE_MIME_HANDLING + 1 ) ,
	FEATURE_WINDOW_RESTRICTIONS	= ( FEATURE_MIME_SNIFFING + 1 ) ,
	FEATURE_WEBOC_POPUPMANAGEMENT	= ( FEATURE_WINDOW_RESTRICTIONS + 1 ) ,
	FEATURE_BEHAVIORS	= ( FEATURE_WEBOC_POPUPMANAGEMENT + 1 ) ,
	FEATURE_DISABLE_MK_PROTOCOL	= ( FEATURE_BEHAVIORS + 1 ) ,
	FEATURE_LOCALMACHINE_LOCKDOWN	= ( FEATURE_DISABLE_MK_PROTOCOL + 1 ) ,
	FEATURE_SECURITYBAND	= ( FEATURE_LOCALMACHINE_LOCKDOWN + 1 ) ,
	FEATURE_RESTRICT_ACTIVEXINSTALL	= ( FEATURE_SECURITYBAND + 1 ) ,
	FEATURE_VALIDATE_NAVIGATE_URL	= ( FEATURE_RESTRICT_ACTIVEXINSTALL + 1 ) ,
	FEATURE_RESTRICT_FILEDOWNLOAD	= ( FEATURE_VALIDATE_NAVIGATE_URL + 1 ) ,
	FEATURE_ADDON_MANAGEMENT	= ( FEATURE_RESTRICT_FILEDOWNLOAD + 1 ) ,
	FEATURE_PROTOCOL_LOCKDOWN	= ( FEATURE_ADDON_MANAGEMENT + 1 ) ,
	FEATURE_HTTP_USERNAME_PASSWORD_DISABLE	= ( FEATURE_PROTOCOL_LOCKDOWN + 1 ) ,
	FEATURE_SAFE_BINDTOOBJECT	= ( FEATURE_HTTP_USERNAME_PASSWORD_DISABLE + 1 ) ,
	FEATURE_UNC_SAVEDFILECHECK	= ( FEATURE_SAFE_BINDTOOBJECT + 1 ) ,
	FEATURE_GET_URL_DOM_FILEPATH_UNENCODED	= ( FEATURE_UNC_SAVEDFILECHECK + 1 ) ,
	FEATURE_TABBED_BROWSING	= ( FEATURE_GET_URL_DOM_FILEPATH_UNENCODED + 1 ) ,
	FEATURE_SSLUX	= ( FEATURE_TABBED_BROWSING + 1 ) ,
	FEATURE_DISABLE_NAVIGATION_SOUNDS	= ( FEATURE_SSLUX + 1 ) ,
	FEATURE_DISABLE_LEGACY_COMPRESSION	= ( FEATURE_DISABLE_NAVIGATION_SOUNDS + 1 ) ,
	FEATURE_FORCE_ADDR_AND_STATUS	= ( FEATURE_DISABLE_LEGACY_COMPRESSION + 1 ) ,
	FEATURE_XMLHTTP	= ( FEATURE_FORCE_ADDR_AND_STATUS + 1 ) ,
	FEATURE_DISABLE_TELNET_PROTOCOL	= ( FEATURE_XMLHTTP + 1 ) ,
	FEATURE_FEEDS	= ( FEATURE_DISABLE_TELNET_PROTOCOL + 1 ) ,
	FEATURE_BLOCK_INPUT_PROMPTS	= ( FEATURE_FEEDS + 1 ) ,
	FEATURE_ENTRY_COUNT	= ( FEATURE_BLOCK_INPUT_PROMPTS + 1 ) 
    } 	INTERNETFEATURELIST;



class BindCtx : public mol::punk<IBindCtx>
{
public:
    BindCtx()
    {
        ::CreateBindCtx(0,&interface_);
    }
};

class AsyncBindCtx : public mol::punk<IBindCtx>
{
public:
    AsyncBindCtx()
    {
    }

    AsyncBindCtx(IBindStatusCallback* cb)
    {
        create(cb);
    }

    void create(IBindStatusCallback* cb)
    {
        if ( S_OK == ::CreateAsyncBindCtx(0,cb,NULL,&interface_) )
        {
            mol::punk<IBindStatusCallback> prev;
            HRESULT hr = ::RegisterBindStatusCallback( interface_, cb, &prev, 0 );
        }
    }
};
    
class BaseUrl : public mol::com_obj<mol::ole::Moniker>
{
public:
	BaseUrl(const std::wstring& u, IStream* s);
	BaseUrl(const std::wstring& u, const std::wstring& mime, IStream* s);
    virtual HRESULT __stdcall BindToStorage( IBindCtx *pbc, IMoniker *pmkToLeft, REFIID riid, void **ppvObj) ;
    virtual HRESULT __stdcall GetDisplayName( IBindCtx *pbc, IMoniker *pmkToLeft, LPOLESTR *ppszDisplayName);

protected:
	std::wstring					mime_;
    std::wstring					url_;
    mol::punk<IStream>				stream_;
};


class AsyncUrl : 
	public IBindStatusCallback, 
	public IHttpNegotiate,
	public mol::interfaces< AsyncUrl, 
			mol::implements< IBindStatusCallback, IHttpNegotiate> >
{
public:
    AsyncUrl() {};
    virtual ~AsyncUrl() {};

	virtual void dispose() {}

    //IBindStatusCallback
    virtual HRESULT __stdcall OnStartBinding( DWORD grfBINDF, IBinding *pib);
    virtual HRESULT __stdcall GetPriority( LONG *pnPriority);
    virtual HRESULT __stdcall OnLowResource( DWORD reserved);
    virtual HRESULT __stdcall OnProgress( ULONG ulProgress,ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText);
    virtual HRESULT __stdcall OnStopBinding( HRESULT hresult,LPCWSTR szError);
    virtual HRESULT __stdcall GetBindInfo( DWORD *grfBINDF,BINDINFO *pbindinfo);
    virtual HRESULT __stdcall OnDataAvailable( DWORD grfBSCF,DWORD dwSize, FORMATETC *pformatetc,STGMEDIUM *pstgmed);
    virtual HRESULT __stdcall OnObjectAvailable( REFIID riid, IUnknown *punk);

    //IHttpNegotiate
    virtual HRESULT __stdcall BeginningTransaction(LPCWSTR szURL,LPCWSTR szHeaders,DWORD dwReserved,LPWSTR *pszAdditionalHeaders);
    virtual HRESULT __stdcall OnResponse( DWORD dwResponseCode,LPCWSTR szResponseHeaders,LPCWSTR szRequestHeaders,LPWSTR *pszAdditionalRequestHeaders);

protected:

	HRESULT startDownload(const std::wstring& url);

	std::wstring					location_;
    mol::punk<IMoniker>			mon_;
};

class HttpUrl : public mol::com_obj<AsyncUrl>
{
public:
    HttpUrl();
	HttpUrl(const std::wstring& loc, const std::wstring& h, DWORD m = BINDVERB_GET);
	HttpUrl(const std::wstring& loc, const std::wstring& p, const std::wstring& h, DWORD m = BINDVERB_POST);
    ~HttpUrl();

    HRESULT __stdcall OnDataAvailable( DWORD grfBSCF,DWORD dwSize, FORMATETC *pformatetc,STGMEDIUM *pstgmed);
    HRESULT __stdcall BeginningTransaction(LPCWSTR szURL,LPCWSTR szHeaders,DWORD dwReserved,LPWSTR *pszAdditionalHeaders);
    HRESULT __stdcall OnResponse( DWORD dwResponseCode,LPCWSTR szResponseHeaders,LPCWSTR szRequestHeaders,LPWSTR *pszAdditionalRequestHeaders);
    HRESULT __stdcall OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText);
    HRESULT __stdcall GetBindInfo(DWORD* pgrfBINDF, BINDINFO* pbindInfo);

    DWORD getMethod();
    bool  isRedirect();
	const std::wstring getLocation();
	const std::string getMime();
    const std::string getRequestHeaders();
    const std::string getResponseHeaders();
    
    std::string getPostData();
    int getPostDataSize();
    const std::string getHttpTransaction();

protected:

    std::string             location_;
    DWORD                   method_;
    DWORD                   fRedirect_;
    std::string             requestHeaders_;
    std::string             responseHeaders_;
    std::string             postdata_;
	std::string             mime_;
	mol::global				postdataGlob_;
    int                     postdatasize_;
    std::ostringstream      httpTransaction_;
};


} // end namespace mol::win::ie
} // end namespace mol

#endif