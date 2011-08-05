#include "ole/ole.h"
#include "Sddl.h"
namespace mol {

std::list<IUnknown*> ole_init::singletons_;

namespace ole {



/////////////////////////////////////////////////////////////////////////////////
// Himetric support stuff
/////////////////////////////////////////////////////////////////////////////////

#define HIMETRIC_PER_INCH   2540
#define MAP_PIX_TO_LOGHIM(x,ppli)   MulDiv(HIMETRIC_PER_INCH, (x), (ppli))
#define MAP_LOGHIM_TO_PIX(x,ppli)   MulDiv((ppli), (x), HIMETRIC_PER_INCH)

/////////////////////////////////////////////////////////////////////////////////

void PixeltoHIMETRIC(SIZE * size, HDC )
{
	int nPixelsPerInchX;
	int nPixelsPerInchY;

	HDC hDCScreen = GetDC(NULL);
	nPixelsPerInchX = GetDeviceCaps(hDCScreen, LOGPIXELSX);
	nPixelsPerInchY = GetDeviceCaps(hDCScreen, LOGPIXELSY);
	ReleaseDC(NULL, hDCScreen);

	size->cx = MAP_PIX_TO_LOGHIM(size->cx, nPixelsPerInchX);
	size->cy = MAP_PIX_TO_LOGHIM(size->cy, nPixelsPerInchY);
}
/////////////////////////////////////////////////////////////////////////////////

void HIMETRICtoPixel(SIZE* sz, HDC hdc )
{
	if ( hdc == 0 )
		hdc = ::GetWindowDC(NULL);
    int nMapMode;
    if ( (nMapMode = ::GetMapMode(hdc)) < MM_ISOTROPIC && nMapMode != MM_TEXT)
    {
        // when using a constrained map mode, map against physical inch

        ::SetMapMode(hdc,MM_HIMETRIC);
        POINT pt;
        pt.x = sz->cx;
        pt.y = sz->cy;
        ::LPtoDP(hdc,&pt,1);
        sz->cx = pt.x;
        sz->cy = pt.y;
        ::SetMapMode(hdc, nMapMode);
    }
    else
    {
        // map against logical inch for non-constrained mapping modes
        int cxPerInch, cyPerInch;
        cxPerInch = ::GetDeviceCaps(hdc,LOGPIXELSX);
        cyPerInch = ::GetDeviceCaps(hdc,LOGPIXELSY);
        sz->cx = MulDiv(sz->cx, cxPerInch, HIMETRIC_PER_INCH);
        sz->cy = MulDiv(sz->cy, cyPerInch, HIMETRIC_PER_INCH);
    }
    POINT pt;
    pt.x = sz->cx;
    pt.y = sz->cy;
    ::DPtoLP(hdc,&pt,1);
    sz->cx = pt.x;
    sz->cy = pt.y;
}

} // end namespace ole

//////////////////////////////////////////////////////////////////////////
// string from CLSID
//////////////////////////////////////////////////////////////////////////

mol::string stringFromCLSID(REFGUID guid)
{
	LPOLESTR clsid;
	::StringFromCLSID(guid,&clsid);

	mol::string classID = mol::toString(clsid);

	::CoTaskMemFree(clsid);
	return classID;
}
//////////////////////////////////////////////////////////////////////////
// convert BSTR to ascii char, drop BSTR
//////////////////////////////////////////////////////////////////////////

mol::string stringFromFreedBSTR( BSTR bstr )
{
	mol::string ret( mol::toString(bstr) );
    ::SysFreeString(bstr);
    bstr=0;
    return ret;
}

//////////////////////////////////////////////////////////////////////////
// convert BSTR to ascii char, keep BSTR
//////////////////////////////////////////////////////////////////////////

std::string BSTR2ansi( BSTR bstr )
{
    if (!bstr) return "";
    int len = ::SysStringLen(bstr);
    char*	buf = new char[len+1];
    ::WideCharToMultiByte(CP_ACP,0,bstr,len,buf,len ,0,0);
    buf[len]=0;
    std::string ret(buf);
    delete[] buf;
    return ret;
}

//////////////////////////////////////////////////////////////////////////
// string to BSTR - don't forget to ::SysFree(bstr) !
//////////////////////////////////////////////////////////////////////////

BSTR ansi2BSTR( const std::string& s )
{
	std::wstring ws = mol::towstring(s);
	BSTR bstr = ::SysAllocString(ws.c_str());
    return bstr;
}

HRESULT __stdcall CreateObjectAdmin( HWND hwnd, BSTR progid, IUnknown** unk)
{
	if (!unk )
		return E_INVALIDARG;

	if ( !progid )
		return E_INVALIDARG;

    BIND_OPTS3 bo;
    LPOLESTR wszCLSID;

	CLSID clsid;
	HRESULT hr = CLSIDFromProgID( progid, &clsid );
	if ( hr != S_OK )
		return hr;

    hr = StringFromCLSID(clsid, &wszCLSID); 
	if ( hr != S_OK )
		return hr;

	std::wstringstream oss;
	oss << L"Elevation:Administrator!new:" << wszCLSID;

	::CoTaskMemFree(wszCLSID);

    memset(&bo, 0, sizeof(bo));
    bo.cbStruct = sizeof(bo);
    bo.hwnd = hwnd;
    bo.dwClassContext  = CLSCTX_LOCAL_SERVER;
	hr = ::CoGetObject( oss.str().c_str(), &bo, IID_IUnknown, (void**)unk);

	return hr;
}

BOOL GetAccessPermissionsForLUAServer(SECURITY_DESCRIPTOR **ppSD)
{
	// Local call permissions to IU, SY
    LPWSTR lpszSDDL = L"O:BAG:BAD:(A;;0x3;;;IU)(A;;0x3;;;SY)";
    SECURITY_DESCRIPTOR *pSD;
    *ppSD = NULL;

    if (ConvertStringSecurityDescriptorToSecurityDescriptorW(lpszSDDL, SDDL_REVISION_1, (PSECURITY_DESCRIPTOR *)&pSD, NULL))
    {
        *ppSD = pSD;
        return TRUE;
    }

    return FALSE;
}

BOOL COInitializeSecurityVeryStrong(SECURITY_DESCRIPTOR *pSD)
{
	// Absolute SD values
	PSECURITY_DESCRIPTOR pAbsSD = NULL;
	DWORD AbsSdSize = 0;
	PACL  pAbsAcl = NULL;
	DWORD AbsAclSize = 0;
	PACL  pAbsSacl = NULL;
	DWORD AbsSaclSize = 0;
	PSID  pAbsOwner = NULL;
	DWORD AbsOwnerSize = 0;
	PSID  pAbsGroup = NULL;
	DWORD AbsGroupSize = 0;
	HRESULT hr = S_FALSE;

	MakeAbsoluteSD (
		pSD,
		pAbsSD,
		&AbsSdSize,
		pAbsAcl,
		&AbsAclSize,
		pAbsSacl,
		&AbsSaclSize,
		pAbsOwner,
		&AbsOwnerSize,
		pAbsGroup,
		&AbsGroupSize
	);

	if (ERROR_INSUFFICIENT_BUFFER == GetLastError())
	{
		pAbsSD = (PSECURITY_DESCRIPTOR)LocalAlloc(LMEM_FIXED, AbsSdSize);
		pAbsAcl = (PACL)LocalAlloc(LMEM_FIXED, AbsAclSize);
		pAbsSacl = (PACL)LocalAlloc(LMEM_FIXED, AbsSaclSize);
		pAbsOwner = (PSID)LocalAlloc(LMEM_FIXED, AbsOwnerSize);
		pAbsGroup = (PSID)LocalAlloc(LMEM_FIXED, AbsGroupSize);
		
		if ( ! (pAbsSD && pAbsAcl && pAbsSacl && pAbsOwner && pAbsGroup))
		{
			hr = E_OUTOFMEMORY;
			return FALSE;
		}
		if ( ! MakeAbsoluteSD(
			pSD,
			pAbsSD,
			&AbsSdSize,
			pAbsAcl,
			&AbsAclSize,
			pAbsSacl,
			&AbsSaclSize,
			pAbsOwner,
			&AbsOwnerSize,
			pAbsGroup,
			&AbsGroupSize
			))
		{
			hr = HRESULT_FROM_WIN32(GetLastError());
			return FALSE;
		}
	}
	else
	{
		hr = HRESULT_FROM_WIN32(GetLastError());
		return FALSE;
	}

	// Call CoinitilizeSecurity.

	::CoInitializeSecurity(pSD,0,0,0,0,0,0,0,0);

	return TRUE;
}

} // end namespace mol
