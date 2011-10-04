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
	bmp_.load(IDB_MOE);
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
	open_cmd_id = icmd;
	
	open_cmd      = 0;
	open_open_cmd = 1;
	open_html_cmd = 2;
	open_rtf_cmd  = 3;
	open_hex_cmd  = 4;
	open_tail_cmd = 5;
	open_as_cmd   = 6;
	

	cmd_indexes_.clear();
	cmd_labels_.clear();

	CmdLabel label1( _T("open with moe"), _T("open with moe") );
	cmd_labels_.insert( std::make_pair(icmd, label1) );
	cmd_indexes_.push_back(icmd);

	::InsertMenu( hmenu,
				  indexMenu,
				  MF_STRING|MF_BYPOSITION|MF_OWNERDRAW, 
				  icmd, 
				  _T("open with moe")
				);

	icmd++;	
	indexMenu++;

	
	mol::Menu menu;
	menu.createContext();
	menu.addItem(icmd,_T("open as ..."));

	CmdLabel label2( _T("open as ..."), _T("open with moe as ...") );
	cmd_labels_.insert( std::make_pair(icmd, label2) );
	cmd_indexes_.push_back(icmd);

	icmd++;

	menu.addItem(icmd,_T("show HTML"));
	CmdLabel label3( _T("show HTML"), _T("show in moes HTML viewer") );
	cmd_labels_.insert( std::make_pair(icmd, label3) );
	cmd_indexes_.push_back(icmd);

	icmd++;

	menu.addItem(icmd,_T("show RTF"));
	CmdLabel label4( _T("show RTF"), _T("show in moes RTF viewer") );
	cmd_labels_.insert( std::make_pair(icmd, label4) );
	cmd_indexes_.push_back(icmd);

	icmd++;

	menu.addItem(icmd,_T("show hexdump"));
	CmdLabel label5( _T("show hexdump"), _T("show in moes hexdump viewer") );
	cmd_labels_.insert( std::make_pair(icmd, label5) );
	cmd_indexes_.push_back(icmd);
	icmd++;

	menu.addItem(icmd,_T("tail -f log"));
	CmdLabel label6( _T("tail -f log"), _T("tail -f log") );
	cmd_labels_.insert( std::make_pair(icmd, label6) );
	cmd_indexes_.push_back(icmd);

	icmd++;
	
	open_as_cmd_id = icmd;

	::InsertMenu( hmenu,
				  indexMenu,
				  MF_STRING|MF_BYPOSITION|MF_POPUP, 
				  (UINT_PTR)(HMENU)(menu), 
				  _T("open with moe as ...")
				);
				
	CmdLabel label7( _T("open with moe as ..."), _T("open with moe as ...") );
	cmd_labels_.insert( std::make_pair(icmd, label7) );
	cmd_indexes_.push_back(icmd);

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
				std::wstring s = mol::towstring(cmd_labels_[cmd].second);
				lstrcpynW((LPWSTR)pszName, s.c_str(), cchMax);
			}
		}
		else
		{
			if ( idCmd < cmd_indexes_.size() )
			{
				UINT cmd = cmd_indexes_[idCmd];
				std::string s = mol::tostring(cmd_labels_[cmd].second);
				lstrcpynA((LPSTR)pszName, s.c_str(), cchMax);
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

			mol::punk<IMoeDialogs> pddialogs;
			moe->get_Dialogs(&pddialogs);

			mol::punk<IMoeDocument> pdoc;

			if ( cmd == open_tail_cmd )
			{
				pdocs->OpenTailDocument(mol::bstr(filepath_), &pdoc);
			}
			else if ( cmd == open_html_cmd )
			{
				pdocs->OpenHtmlFrame(mol::bstr(filepath_), &pdoc );
			}
			else if ( cmd == open_open_cmd )
			{
				pddialogs->Open(mol::bstr(filepath_),&pdoc );
			}
			else if ( cmd == open_cmd )
			{
				pdocs->Open(mol::bstr(filepath_), &pdoc );
			}
			else if ( cmd == open_hex_cmd )
			{
				pdocs->OpenHexEditor(mol::bstr(filepath_),VARIANT_TRUE, &pdoc );
			}
			else if ( cmd == open_rtf_cmd )
			{
				pdocs->OpenRTFDocument(mol::bstr(filepath_),&pdoc );
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
	else if (cmd == open_open_cmd )
	{
		oss << "moe-open:";
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
	oss << filepath_ << "\"";

	mol::io::exec_cmdline( oss.str() );
	return S_OK;
}

HRESULT __stdcall moeShell::HandleMenuMsg(UINT msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT dummy = 0;
	return HandleMenuMsgImpl(msg,wParam,lParam,&dummy);
}

HRESULT __stdcall moeShell::HandleMenuMsg2(UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* plResult)
{
	LRESULT dummy = 0;
	if ( !plResult )
		return HandleMenuMsgImpl(msg,wParam,lParam,&dummy);

	return HandleMenuMsgImpl(msg,wParam,lParam,plResult);
}

HRESULT __stdcall moeShell::HandleMenuMsgImpl(UINT uMsg,  WPARAM wParam,  LPARAM lParam,  LRESULT *plResult)
{
	switch ( uMsg )
	{
		case WM_MEASUREITEM:
		{
			return OnMeasureItem ( (MEASUREITEMSTRUCT*) lParam, plResult );
		}
		case WM_DRAWITEM:
		{
			return OnDrawItem ( (DRAWITEMSTRUCT*) lParam, plResult );
		}
	}
	return S_OK;
}

HRESULT __stdcall moeShell::OnMeasureItem ( MEASUREITEMSTRUCT* mis, LRESULT* pResult )
{
	if ( (mis->itemID != open_cmd_id) && (mis->itemID != open_as_cmd_id) )
		return S_OK;

	mol::string tmp = cmd_labels_[mis->itemID].second;

	SIZE s = {0,0};
	mol::DC dc(::GetDesktopWindow());
	::GetTextExtentPoint32(dc,tmp.c_str(), tmp.size(),&s);
    mis->itemWidth = s.cx+40; 
    mis->itemHeight = s.cy+10; 

	*pResult = TRUE;  // we handled the message
	return S_OK;
}

HRESULT __stdcall moeShell::OnDrawItem ( DRAWITEMSTRUCT* dis, LRESULT* pResult )
{
	if ( (dis->itemID != open_cmd_id) && (dis->itemID != open_as_cmd_id) )
		return S_OK;

	mol::string tmp = cmd_labels_[dis->itemID].second;

	int wCheckX = ::GetSystemMetrics(SM_CXMENUCHECK); 
    int nTextX = /*wCheckX +*/ dis->rcItem.left; 
	int nTextY = dis->rcItem.top; 

	COLORREF crBkgnd,crTxt;
	crBkgnd,crTxt = 0;

    if (dis->itemState & ODS_SELECTED) 
    { 
        crBkgnd = ::SetBkColor(dis->hDC, ::GetSysColor(COLOR_HIGHLIGHT)); 
		crTxt = ::SetTextColor(dis->hDC, ::GetSysColor(COLOR_HIGHLIGHTTEXT)); 
    } 
	else
	{
		crBkgnd = ::SetBkColor(dis->hDC, ::GetSysColor(COLOR_MENU)); 
		//crTxt = ::SetTextColor(dis->hDC, ::GetSysColor(COLOR_MENU)); 
	}

	// white bkg
	HBRUSH brush = ::GetSysColorBrush(crBkgnd);
	mol::Rect r2(dis->rcItem);
	r2.left=r2.left+24;
	::FillRect(dis->hDC,&r2,brush);

	// text
	::ExtTextOut(dis->hDC, nTextX + 30, nTextY+5,  ETO_OPAQUE, 
			&dis->rcItem, tmp.c_str(), tmp.size(), NULL); 


//	mol::Rect r(dis->rcItem);
//	r.right = r2.left;
//	::FillRect(dis->hDC,&r,::GetSysColorBrush(COLOR_BTNFACE));

//	if ( dis->itemState & ODS_SELECTED )
		//::FrameRect(dis->hDC,&dis->rcItem,(HBRUSH)::GetStockObject(GRAY_BRUSH));


	mol::DC mem = ::CreateCompatibleDC(dis->hDC);
	HGDIOBJ def = mem.select( (HGDIOBJ)(HBITMAP)bmp_);
	COLORREF c = ::GetPixel(mem,0,0);
	::TransparentBlt(dis->hDC,4,nTextY+5,16,16,mem,0,0,64,64,c);
	mem.select(def);
	
    SetBkColor(dis->hDC, crBkgnd); 
	if ( crTxt)
		SetTextColor(dis->hDC, crTxt); 

	*pResult = TRUE;
	return S_OK;
}


HRESULT __stdcall moeShell::About()
{
	return S_OK;
}

