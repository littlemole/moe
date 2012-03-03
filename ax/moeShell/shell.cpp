#include "stdafx.h"
#include "shell.h"
#include "win/path.h"
#include "shellCtrl_h.h"
#include "ScintillAX_h.h"
#include "moe_h.h"

#include "moeShell_i.c"
#include "moe_i.c"

#if defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else 
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

///////////////////////////////////////////////////////////////////////////////

REFIID mol::uuid_info<IContextMenu>::uuidof = IID_IContextMenu;

enum cmds {
	open_cmd = 0,
	open_open_cmd,
	open_html_cmd,
	open_rtf_cmd,
	open_hex_cmd,
	open_tail_cmd,
	open_as_cmd
};

///////////////////////////////////////////////////////////////////////////////

moeShell::moeShell() 
{
	ODBGS("moeShell::moeShell() ");
	bmp_.load(IDB_MOE);
	bmp2_.load(IDB_MOE2);
	//::DebugBreak();
};

moeShell::~moeShell() 
{
	ODBGS("moeShell::~moeShell() ");
}

void  moeShell::registerMenuItem( UINT& iCmd, const mol::string& proto, const mol::string& desc )
{
	moeShellMenuItem* cmd = new moeShellMenuItem(iCmd,proto,desc);
	menu_cmds_.insert( std::make_pair(iCmd, cmd) );
	cmd_indexes_.push_back(iCmd);
	iCmd++;
}

HRESULT __stdcall moeShell::Initialize( LPCITEMIDLIST pidlFolder, IDataObject *pdtobj, HKEY hkeyProgID )
{
	ODBGS("moeShell::Initialize() ");

	if ( pdtobj == NULL )
		return E_INVALIDARG;

	STGMEDIUM medium;
	FORMATETC fe = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	
	HRESULT hr = pdtobj->GetData( &fe,&medium );
	if ( FAILED(hr) )
	{
		return E_INVALIDARG;
	}

	mol::TCHAR filename[MAX_PATH];
	::DragQueryFile( (HDROP)(medium.hGlobal), 0, filename,MAX_PATH );
	filepath_ = mol::string(filename);

	::ReleaseStgMedium(&medium);
	return hr;
}

HRESULT __stdcall moeShell::QueryContextMenu(HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags)
{
	
	if ( (uFlags & CMF_DEFAULTONLY) ||
		 (uFlags & CMF_VERBSONLY) ||
		 (uFlags & CMF_NOVERBS) )
	{
		return MAKE_HRESULT(SEVERITY_SUCCESS, 0, 0);
	}
	
	UINT icmd = idCmdFirst;	
	
    MENUITEMINFO mii = { sizeof(mii) };
    mii.fMask = MIIM_BITMAP;
    mii.hbmpItem = bmp2_;

	cmd_indexes_.clear();
	menu_cmds_.clear();

	// menu item #1
	::InsertMenu( hmenu,
				  indexMenu,
				  MF_STRING|MF_BYPOSITION,
				  icmd, 
				  _T("open with moe")
				);

    ::SetMenuItemInfo(hmenu, indexMenu, TRUE, &mii);
	registerMenuItem(icmd,_T("moe:"),_T("open with moe") );
	indexMenu++;

	// submenu for menu item #2	
	mol::Menu menu;
	menu.createContext();
	menu.addItem(icmd,_T("open as ..."));
	registerMenuItem(icmd,_T("moe-open:"),_T("open as ...") );

	menu.addItem(icmd,_T("show HTML"));
	registerMenuItem(icmd,_T("moe-html:"),_T("show in moes HTML viewer") );

	menu.addItem(icmd,_T("show RTF"));
	registerMenuItem(icmd,_T("moe-rtf:"),_T("show in moes RTF viewer") );

	menu.addItem(icmd,_T("show hexdump"));
	registerMenuItem(icmd,_T("moe-hex:"),_T("show in moes hexdump viewer") );

	menu.addItem(icmd,_T("tail -f log"));
	registerMenuItem(icmd,_T("moe-tail:"),_T("tail -f log") );

	// menu item #2
	::InsertMenu( hmenu,
				  indexMenu,
				  MF_STRING|MF_BYPOSITION|MF_POPUP, 
				  (UINT_PTR)(HMENU)(menu), 
				  _T("open with moe as ...")
				);	
    ::SetMenuItemInfo(hmenu, indexMenu, TRUE, &mii);
	registerMenuItem(icmd,_T(""),_T("open with moe as ...") );

	// done
	menu.detach();
	return MAKE_HRESULT( 
				SEVERITY_SUCCESS,
				FACILITY_NULL,
				icmd-idCmdFirst
			);
}


HRESULT __stdcall moeShell::GetCommandString( UINT_PTR idCmd, UINT uFlags, UINT *pwReserved, LPSTR pszName, UINT cchMax )
{
	if ( uFlags & GCS_HELPTEXT )
	{
		if (uFlags & GCS_UNICODE)
		{
			if ( idCmd < cmd_indexes_.size() )
			{
				UINT cmd = cmd_indexes_[idCmd];
				std::wstring s = mol::towstring(menu_cmds_[cmd]->description);
				lstrcpynW((LPWSTR)pszName, s.c_str(), cchMax);
			}
		}
		else
		{
			if ( idCmd < cmd_indexes_.size() )
			{
				UINT cmd = cmd_indexes_[idCmd];
				std::string s = mol::tostring(menu_cmds_[cmd]->description);
				lstrcpynA((LPSTR)pszName, s.c_str(), cchMax);
			}
		}
	}
	return S_OK;
}

HRESULT __stdcall moeShell::InvokeCommand(LPCMINVOKECOMMANDINFO pici)
{
	if ( HIWORD(pici->lpVerb) != 0 )
		return E_FAIL;

	UINT cmd = (UINT)(pici->lpVerb);
	cmd = cmd_indexes_[cmd];
	return menu_cmds_[cmd]->InvokeCommand(filepath_,pici);
}



HRESULT __stdcall moeShellMenuItem::InvokeCommand(const mol::string& filepath, LPCMINVOKECOMMANDINFO pici)
{
	if ( HIWORD(pici->lpVerb) != 0 )
		return E_FAIL;

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

			mol::punk<IMoeDialogs> pddialogs;
			moe->get_Dialogs(&pddialogs);

			mol::punk<IMoeDocument> pdoc;

			if ( cmd == open_tail_cmd )
			{
				pdocs->OpenTailDocument(mol::bstr(filepath), &pdoc);
			}
			else if ( cmd == open_html_cmd )
			{
				pdocs->OpenHtmlFrame(mol::bstr(filepath), &pdoc );
			}
			else if ( cmd == open_open_cmd )
			{
				pddialogs->Open(mol::bstr(filepath),&pdoc );
			}
			else if ( cmd == open_cmd )
			{
				pdocs->Open(mol::bstr(filepath), &pdoc );
			}
			else if ( cmd == open_hex_cmd )
			{
				pdocs->OpenHexEditor(mol::bstr(filepath),VARIANT_TRUE, &pdoc );
			}
			else if ( cmd == open_rtf_cmd )
			{
				pdocs->OpenRTFDocument(mol::bstr(filepath),&pdoc );
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
	oss << _T("\"")
		<< mol::Path::pathname(p) 
		<< _T("\\")
		<< _T("moe.exe")
		<< _T("\" \"")
		<< proto 
		<< filepath << _T("\"");

	mol::io::exec_cmdline( oss.str() );
	return S_OK;
}



HRESULT __stdcall moeShell::About()
{
	return S_OK;
}

