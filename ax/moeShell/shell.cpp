#include "stdafx.h"
#include "shell.h"
#include "win/io/path.h"
#include "shellCtrl_h.h"
#include "ScintillAX_h.h"
#include "xmoe_h.h"

#include "moeShell_i.c"
#include "xmoe_i.c"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
HRESULT __stdcall moeShell::Initialize( LPCITEMIDLIST pidlFolder, IDataObject *pdtobj, HKEY hkeyProgID )
{
	if ( pdtobj == NULL )
		return E_INVALIDARG;

	STGMEDIUM medium;
	FORMATETC fe = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	
	HRESULT hr = pdtobj->GetData( &fe,&medium );
	if ( FAILED(hr) )
	{
		return E_INVALIDARG;
	}
	::DragQueryFile( (HDROP)(medium.hGlobal), 0,   filename_,MAX_PATH );
	::ReleaseStgMedium(&medium);
	return hr;
}


HRESULT __stdcall moeShell::GetCommandString( UINT_PTR idCmd, UINT uFlags, UINT *pwReserved, LPSTR pszName, UINT cchMax )
{
	if ( uFlags & GCS_HELPTEXT )
	{
		if (uFlags & GCS_UNICODE)
		{
            lstrcpynW((LPWSTR)pszName, L"open with moe", cchMax);
		}
		else
		{
			lstrcpynA(pszName, "open with moe", cchMax);
		}
	}
	return S_OK;
}

HRESULT __stdcall moeShell::InvokeCommand(LPCMINVOKECOMMANDINFO pici)
{
	//check if moe is running
	mol::punk<IUnknown> punk;
	HRESULT hr = ::GetActiveObject( CLSID_Xmoe,0,&punk );
	if ( (hr == S_OK) )
	{
		mol::punk<IXmoe> moe(punk);
		if (moe)
		{
			// found running moe instance
			// open doc in moe
			mol::punk<IDoc> pdoc;
			moe->Open( mol::bstr(filename_), &pdoc );
			return S_OK;
		}
	}

	//else call new moe via cmdline
	mol::string p = mol::singleton<moeShellDll>().getModulePath();

	mol::stringstream oss;
	oss << "\"" 
		<< mol::Path::pathname(p) 
		<< "\\"
		<< "moe.exe" 
		<< "\" \"" 
		<< filename_ 
		<< "\"";

	mol::io::exec_cmdline( oss.str() );
	return S_OK;
}

HRESULT __stdcall moeShell::QueryContextMenu(HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags)
{
	UINT icmd = idCmdFirst;
	::InsertMenu( hmenu,
				  indexMenu++,
				  MF_STRING|MF_BYPOSITION , 
				  icmd++, 
				  _T("edit with moe")
				);

	return MAKE_HRESULT( 
				SEVERITY_SUCCESS,
				FACILITY_NULL,
				icmd-idCmdFirst
			);
}

HRESULT __stdcall moeShell::About()
{
	return S_OK;
}