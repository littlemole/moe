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
	//icon_.load(IDI_SHELLCTRL,16,16);
};


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
				lstrcpynW((LPWSTR)pszName, L"tail with moe", cchMax);
			}
			else if ( idCmd == open_html_cmd )
			{
				lstrcpynW((LPWSTR)pszName, L"view HTML with moe", cchMax);
			}
			else if ( idCmd == open_utf8_cmd )
			{
				lstrcpynW((LPWSTR)pszName, L"open with moe (force UTF-8)", cchMax);
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
				lstrcpynA(pszName, "tail with moe", cchMax);
			}
			else if ( idCmd == open_html_cmd )
			{
				lstrcpynA(pszName, "view HTML with moe", cchMax);
			}
			else if ( idCmd == open_utf8_cmd )
			{
				lstrcpynA(pszName, "open with moe (force UTF-8)", cchMax);
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
	oss << filename_ << "\"";

	mol::io::exec_cmdline( oss.str() );
	return S_OK;
}

HRESULT __stdcall moeShell::QueryContextMenu(HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags)
{
	UINT icmd = idCmdFirst;

	open_cmd = 0;
	open_utf8_cmd = 1;
	open_html_cmd = 2;
	open_tail_cmd = 3;

	open_id = icmd;

	/*
	MENUITEMINFO mi;
	::ZeroMemory( &mi, sizeof(mi) );
	mi.cbSize = sizeof(mi);
	mi.wID = (int)icmd;
	mi.fType = MFT_OWNERDRAW;
	mi.dwItemData = (ULONG_PTR)0;
	mi.fMask = MIIM_TYPE|MIIM_ID;
	*/

	::InsertMenu( hmenu,
				  indexMenu,
				  MF_STRING|MF_BYPOSITION,//|MF_OWNERDRAW , 
				  icmd, 
				  _T("open with moe")
				);
				

//	::InsertMenuItem( hmenu, indexMenu, TRUE, &mi);

	icmd++;
	indexMenu++;


	
	open_utf8_id = icmd;
	mol::Menu menu;
	menu.createContext();
	menu.addItem(icmd,_T("force UTF8"));
	icmd++;

	open_html_id = icmd;
	menu.addItem(icmd,_T("show HTML"));
	icmd++;

	open_tail_id = icmd;
	menu.addItem(icmd,_T("tail -f log"));
	icmd++;

	
	::InsertMenu( hmenu,
				  indexMenu,
				  MF_STRING|MF_BYPOSITION|MF_POPUP,//|MF_OWNERDRAW , 
				  (UINT_PTR)(HMENU)(menu), 
				  _T("open with moe as ...")
				);
				

	//mi.wID = 0;
	//mi.fType = MFT_OWNERDRAW|MF_POPUP
	//::InsertMenuItem( hmenu, indexMenu, TRUE, &mi);

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

HRESULT __stdcall moeShell::HandleMenuMsg(UINT uMsg,  WPARAM wParam,  LPARAM lParam)
{
	return HandleMenuMsgImpl(uMsg,wParam,lParam,0);
}

HRESULT __stdcall moeShell::HandleMenuMsg2(UINT uMsg,  WPARAM wParam,  LPARAM lParam,  LRESULT *plResult)
{
	return HandleMenuMsgImpl(uMsg,wParam,lParam,plResult);
}

HRESULT __stdcall moeShell::HandleMenuMsgImpl(UINT uMsg,  WPARAM wParam,  LPARAM lParam,  LRESULT *plResult)
{
	if (plResult)
		plResult = 0;

	switch( uMsg )
	{
		case WM_MEASUREITEM :
		{
			mol::string text = _T("open with moe as ...");

			LPMEASUREITEMSTRUCT lpmis = (LPMEASUREITEMSTRUCT) lParam; 
			if ( lpmis->itemID == open_id )
			{
				text = _T("open with moe");
			}


			SIZE s = {0,0};
			mol::DC dc(::GetDesktopWindow());
			::GetTextExtentPoint32(dc,text.c_str(), (int)text.size(),&s);
			lpmis->itemWidth = s.cx+40; 
			lpmis->itemHeight = s.cy+10; 

			if (plResult)
				*plResult = TRUE;
			return S_OK;
		}
		case WM_DRAWITEM :
		{
			LPDRAWITEMSTRUCT lpdis = (LPDRAWITEMSTRUCT) lParam; 

			mol::string text = _T("open with moe as ...");

			if ( lpdis->itemID == open_id )
			{
				text = _T("open with moe");
			}
 
			int wCheckX = GetSystemMetrics(SM_CXMENUCHECK); 
			int nTextX = /*wCheckX +*/ lpdis->rcItem.left; 
			int nTextY = lpdis->rcItem.top; 

			COLORREF crBkgnd,crTxt;
			crBkgnd,crTxt = 0;

			crBkgnd = SetBkColor(lpdis->hDC, ::GetSysColor(COLOR_MENU)); 
			crTxt = SetTextColor(lpdis->hDC, ::GetSysColor(COLOR_MENUTEXT)); 

			// white bkg
			HBRUSH brush = (HBRUSH)::GetStockObject(BLACK_BRUSH);//::GetSysColorBrush(COLOR);
			mol::Rect r2(lpdis->rcItem);
			r2.left=r2.left+24;
			::FillRect(lpdis->hDC,&r2,brush);

			// text
			::ExtTextOut(lpdis->hDC, nTextX + 30, nTextY+5,  ETO_OPAQUE, 
					&lpdis->rcItem, text.c_str(), (int) text.size(), NULL); 


			//mol::Rect r(lpdis->rcItem);
			//r.right = r2.left;
			//::FillRect(lpdis->hDC,&r,::GetSysColorBrush(COLOR_BTNFACE));

			//::DrawIcon(lpdis->hDC,4,nTextY+5,icon_);

//			mol::DC mem = ::CreateCompatibleDC(lpdis->hDC);
//			HGDIOBJ def = mem.select( (HGDIOBJ)(HBITMAP)bitmap_);
//			int x = icon_*16;
//			COLORREF c = ::GetPixel(mem,0,0);
//			::TransparentBlt(lpdis->hDC,4,nTextY+5,16,16,mem,x,0,16,16,c);
//			mem.select(def);

			/*
			if ( icon_ != -1 )
			{
				mol::DC mem = ::CreateCompatibleDC(lpdis->hDC);
				HGDIOBJ def = mem.select( (HGDIOBJ)(HBITMAP)bitmap_);
				int x = icon_*16;
				COLORREF c = ::GetPixel(mem,0,0);
				::TransparentBlt(lpdis->hDC,4,nTextY+5,16,16,mem,x,0,16,16,c);
				mem.select(def);
			}

			UINT state = lpdis->itemState;
			if ( state & ODS_CHECKED )
			{
				DrawCheckMark(lpdis->hDC,5,nTextY+5,RGB(64,64,128));
			}
			*/
			SetBkColor(lpdis->hDC, crBkgnd); 
			SetTextColor(lpdis->hDC, crTxt); 
//			return 0;

			if (plResult)
				*plResult = TRUE;
			return S_OK;
		}
	}

	return S_OK;
}