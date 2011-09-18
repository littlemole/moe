#include "stdafx.h"
#include "shell.h"
#include "win/path.h"
#include "shellCtrl_h.h"
#include "ScintillAX_h.h"
#include "moe_h.h"

#include "moeShell_i.c"
#include "moe_i.c"


REFIID mol::uuid_info<IContextMenu>::uuidof = IID_IContextMenu;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

moeShell::moeShell() 
{
};

moeShell::~moeShell() 
{
}

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
			if ( idCmd == open_cmd )
			{
				lstrcpynW((LPWSTR)pszName, L"open with moe", cchMax);
			}
			else if ( idCmd == open_tail_cmd )
			{
				lstrcpynW((LPWSTR)pszName, L"open with tail -f", cchMax);
			}
			else if ( idCmd == open_html_cmd )
			{
				lstrcpynW((LPWSTR)pszName, L"preview HTML", cchMax);
			}
			else if ( idCmd == open_hex_cmd )
			{
				lstrcpynW((LPWSTR)pszName, L"view as hex dump", cchMax);
			}
			else if ( idCmd == open_utf8_cmd )
			{
				lstrcpynW((LPWSTR)pszName, L"open with moe (force UTF-8)", cchMax);
			}
			else if ( idCmd == open_rtf_cmd )
			{
				lstrcpynW((LPWSTR)pszName, L"view as as rtf", cchMax);
			}
		}
		else
		{
			if ( idCmd == open_cmd )
			{
				lstrcpynA(pszName, "open with moe", cchMax);
			}
			else if ( idCmd == open_tail_cmd )
			{
				lstrcpynA(pszName, "open with tail -f", cchMax);
			}
			else if ( idCmd == open_html_cmd )
			{
				lstrcpynA(pszName, "preview HTML", cchMax);
			}
			else if ( idCmd == open_hex_cmd )
			{
				lstrcpynA(pszName, "view as hex dump", cchMax);
			}
			else if ( idCmd == open_utf8_cmd )
			{
				lstrcpynA(pszName, "open with moe (force UTF-8)", cchMax);
			}
			else if ( idCmd == open_rtf_cmd )
			{
				lstrcpynA(pszName, "view as rtf", cchMax);
			}
		}
	}
	return S_OK;
}

HRESULT __stdcall moeShell::InvokeCommand(LPCMINVOKECOMMANDINFO pici)
{
	if ( HIWORD(pici->lpVerb) != 0 )
		return S_OK;

	UINT cmd = (UINT)(pici->lpVerb);

	//check if moe is running
	mol::punk<IUnknown> punk;
	HRESULT hr = ::GetActiveObject( CLSID_Application,0,&punk );
	if ( (hr == S_OK) )
	{
		mol::punk<IMoe> moe(punk);
		if (moe)
		{
			// found running moe instance
			// open doc in moe
			::CoAllowSetForegroundWindow(punk,0);
			mol::punk<IMoeDocumentCollection> pdocs;
			moe->get_Documents(&pdocs);

			mol::punk<IMoeDocument> pdoc;

			if ( cmd == open_tail_cmd )
			{
				pdocs->OpenTailDocument(mol::bstr(filename_), &pdoc);
			}
			else if ( cmd == open_html_cmd )
			{
				pdocs->OpenHtmlFrame(mol::bstr(filename_), &pdoc );
			}
			else if ( cmd == open_utf8_cmd )
			{
				pdocs->OpenUTF8(mol::bstr(filename_), &pdoc );
			}
			else if ( cmd == open_cmd )
			{
				pdocs->Open(mol::bstr(filename_), &pdoc );
			}
			else if ( cmd == open_hex_cmd )
			{
				pdocs->OpenHexEditor(mol::bstr(filename_),VARIANT_TRUE, &pdoc );
			}
			else if ( cmd == open_rtf_cmd )
			{
				pdocs->OpenRTFDocument(mol::bstr(filename_),&pdoc );
			}
			mol::punk<IMoeView> view;
			moe->get_View(&view);
			view->Show();
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
		<< "\" \"" ;

	if (cmd == open_tail_cmd )
	{
		oss << "moe-tail:";
	}
	else if (cmd == open_utf8_cmd )
	{
		oss << "moe-utf8:";
	}
	else if (cmd == open_html_cmd )
	{
		oss << "moe-html:";
	}
	else if (cmd == open_hex_cmd )
	{
		oss << "moe-hex:";
	}
	else if (cmd == open_rtf_cmd )
	{
		oss << "moe-rtf:";
	}
	oss << filename_ << "\"";

	mol::io::exec_cmdline( oss.str() );
	return S_OK;
}

HRESULT __stdcall moeShell::QueryContextMenu(HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags)
{
	
	if ( (uFlags & CMF_DEFAULTONLY) ||
		 (uFlags & CMF_VERBSONLY) ||
		 (uFlags & CMF_NOVERBS) )
	{
		return MAKE_HRESULT(SEVERITY_SUCCESS, 0, 0);
	}
	

/*	if ( uFlags )
	{
		return MAKE_HRESULT(SEVERITY_SUCCESS, 0, 0);
	}
	*/

	UINT icmd = idCmdFirst;

	open_cmd = 0;
	open_utf8_cmd = 1;
	open_html_cmd = 2;
	open_rtf_cmd  = 3;
	open_hex_cmd  = 4;
	open_tail_cmd = 5;

	::InsertMenu( hmenu,
				  indexMenu,
				  MF_STRING|MF_BYPOSITION, 
				  icmd, 
				  _T("open with moe")
				);

	icmd++;

	
	indexMenu++;

	
	mol::Menu menu;
	menu.createContext();
	menu.addItem(icmd,_T("force UTF8"));
	icmd++;

	menu.addItem(icmd,_T("show HTML"));
	icmd++;

	menu.addItem(icmd,_T("show RTF"));
	icmd++;

	menu.addItem(icmd,_T("show hexdump"));
	icmd++;

	menu.addItem(icmd,_T("tail -f log"));
	icmd++;

	
	::InsertMenu( hmenu,
				  indexMenu,
				  MF_STRING|MF_BYPOSITION|MF_POPUP, 
				  (UINT_PTR)(HMENU)(menu), 
				  _T("open with moe as ...")
				);
				

	menu.detach();
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

