#include "stdafx.h"
#include "NamespaceTree.h"
#include "ShellCtrl_Dispid.h"
#include "ole/Img.h"
#include "ole/Bstr.h"
#include "ole/enum.h"
#include "util/Str.h"
#include "thread/events.h"
#include "win/v7.h"
#include <windowsx.h>
#include <sstream>

///////////////////////////////////////////////////////////////////////
// NamespaceTree
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////

NamespaceTree::NamespaceTree() 
{
	sizel.cx = 200;
	sizel.cy = 400;
	adviseCookie_ = -1;
	lastClickTime_ = 0;

	doubleClickTimeout_ = ::GetDoubleClickTime()*2;

	mol::ole::PixeltoHIMETRIC(&sizel);
	eraseBackground_ = 1;
	useContext_ = true;

	foreCol_ = ::GetSysColor(COLOR_MENUTEXT);
	bgCol_ = ::GetSysColor(COLOR_WINDOW);

	bgBrush_ = ::CreateSolidBrush(bgCol_);
}

///////////////////////////////////////////////////////////////////////

NamespaceTree::~NamespaceTree()	
{
	::DeleteObject(bgBrush_);
	// free tree items + and associated data
	ODBGS("~ShellTree");
}
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
// Windows Message Handlers
///////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//
// OnDestroy - over and out
//
//////////////////////////////////////////////////////////////////////////////

LRESULT NamespaceTree::OnDestroy(UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (tree_)
    {
        if (adviseCookie_ != -1)
        {
            tree_->TreeUnadvise(adviseCookie_);
            adviseCookie_ = (DWORD)-1;
        }

        IUnknown_SetSite(tree_, NULL);
		tree_.release();
    }
	currentItem_.release();
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// OnCreate - init child Windows and UI
//
//////////////////////////////////////////////////////////////////////////////

LRESULT NamespaceTree::OnCreate(UINT msg, WPARAM wParam, LPARAM lParam)
{
	treeMenu_.load(IDM_TREE_DIR);
	getClientRect(clientRect_);

    RECT rc;
    getWindowRect(rc);
    MapWindowRect(HWND_DESKTOP, *this, &rc);

	HRESULT hr = tree_.createObject(CLSID_NamespaceTreeControl,CLSCTX_INPROC);
    if (SUCCEEDED(hr))
    {
        const NSTCSTYLE nsctsFlags = //NSTCS_HASEXPANDOS |            // Show expandos
                                       // NSTCS_ROOTHASEXPANDO |         // Root nodes have expandos
                                       // NSTCS_FADEINOUTEXPANDOS |      // Fade-in-out based on focus
                                       // NSTCS_NOINFOTIP |              // Don't show infotips
                                        //NSTCS_ALLOWJUNCTIONS |         // Show folders such as zip folders and libraries
                                        NSTCS_SHOWSELECTIONALWAYS|    // Show selection when NSC doesn't have focus
										//NSTCS_TABSTOP|
										//NSTCS_SINGLECLICKEXPAND|
										NSTCS_SHOWTABSBUTTON|
                                        NSTCS_FULLROWSELECT;           // Select full width of item
        hr = tree_->Initialize(*this, &rc, nsctsFlags);
        if (SUCCEEDED(hr))
        {
            // New Windows 7 features
			mol::punk<INameSpaceTreeControl2> tree2(tree_);
            if (tree2)
            {
                NSTCSTYLE2 nscts2Flags = //NSTCS2_DISPLAYPADDING |            // Padding between top-level nodes
                                            NTSCS2_NOSINGLETONAUTOEXPAND |     // Don't auto-expand nodes with a single child node
                                            NSTCS2_INTERRUPTNOTIFICATIONS |    // Register for interrupt notifications on a per-node basis
                                            NSTCS2_DISPLAYPINNEDONLY |         // Filter on pinned property
                                            NTSCS2_NEVERINSERTNONENUMERATED;   // Don't insert items with property SFGAO_NONENUMERATED
                hr = tree2->SetControlStyle2(nscts2Flags, nscts2Flags);
            }
            if (SUCCEEDED(hr))
            {
                tree_->TreeAdvise(static_cast<INameSpaceTreeControlEvents *>(this), &adviseCookie_);
                IUnknown_SetSite(tree_, static_cast<IServiceProvider *>(this));

				tree_->RemoveAllRoots();


				mol::punk<IShellItem> desktop;
				hr = ::SHCreateItemInKnownFolder(FOLDERID_Desktop, 0, NULL, IID_PPV_ARGS(&desktop));
				if (SUCCEEDED(hr))
				{
					// Add hidden root
					tree_->AppendRoot(desktop, SHCONTF_FOLDERS|SHCONTF_NONFOLDERS, NSTCRS_HIDDEN | NSTCRS_EXPANDED, NULL); // ignore result
				}
			}
        }
    }

	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// OnSize - resize child tree ctrl
//
//////////////////////////////////////////////////////////////////////////////

LRESULT NamespaceTree::OnSize(UINT msg, WPARAM wParam, LPARAM lParam)
{
	getClientRect(clientRect_);
		
	// get new width and height
	clientRect_.right  = LOWORD (lParam) ;
	clientRect_.bottom = HIWORD (lParam) ;

	HWND hwndTree;
	IUnknown_GetWindow(tree_, &hwndTree);

    RECT rc;
    getWindowRect(rc);
    MapWindowRect(HWND_DESKTOP, *this, &rc);
	SetWindowPos(hwndTree, NULL, rc.left, rc.top,  rc.right,rc.bottom, SWP_NOZORDER );
	return 0;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall NamespaceTree::QueryService(REFGUID /*guidService*/, REFIID riid, void **ppv)
{
	if ( riid == IID_INameSpaceTreeControlCustomDraw )
	{
		return this->QueryInterfaceImpl(riid,ppv);
	}

    HRESULT hr = E_NOINTERFACE;
    *ppv = NULL;
    return hr;
}

HRESULT __stdcall  NamespaceTree::OnItemClick(IShellItem * psi, NSTCEHITTEST nstceHitTest, NSTCECLICKTYPE nstceClickType) 
{ 
	HRESULT ret = S_OK;

	if( (nstceClickType & NSTCECT_LBUTTON) && psi && ( nstceHitTest & NSTCEHT_ONITEMTABBUTTON ) )
	{
		mol::CoStrBuf psz;
		HRESULT hr = psi->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &psz);
		if(hr==S_OK && psz)
		{
			SFGAOF sfgaof;
			hr = psi->GetAttributes(SFGAO_FOLDER,&sfgaof);
			if (SUCCEEDED(hr))
			{
				VARIANT_BOOL vb = sfgaof & SFGAO_FOLDER ? VARIANT_TRUE : VARIANT_FALSE;
				fire(DISPID_ISHELLTREEEVENTS_ONTREEDBLCLICK,mol::variant(psz),mol::variant(vb));
				ret = S_FALSE;
			}
		}
	}
	if ( (nstceClickType & NSTCECT_LBUTTON) && psi && ( nstceHitTest & NSTCEHT_ONITEM ) )
	{
		mol::CoStrBuf psz;
		HRESULT hr = psi->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &psz);
		if(hr==S_OK && psz)
		{
			DWORD now = ::GetTickCount();
			std::wstring ws(psz);
			if ( (ws == currentPath_.towstring()) && (now-lastClickTime_ < doubleClickTimeout_))
			{
				SFGAOF sfgaof;
				hr = psi->GetAttributes(SFGAO_FOLDER,&sfgaof);
				if (SUCCEEDED(hr))
				{
					VARIANT_BOOL vb = sfgaof & SFGAO_FOLDER ? VARIANT_TRUE : VARIANT_FALSE;
					if(vb == VARIANT_FALSE)
					{
						fire(DISPID_ISHELLTREEEVENTS_ONTREEDBLCLICK,mol::variant(psz),mol::variant(vb));
						ret = S_FALSE;
					}
					ret = S_FALSE;
				}
			}
			lastClickTime_ = ::GetTickCount();;
		}
	}
	return ret;  
}

HRESULT __stdcall  NamespaceTree::OnSelectionChanged(IShellItemArray *psiaSelection)
{
    IShellItem *psi;
    HRESULT hr = psiaSelection->GetItemAt(0, &psi);
    if (SUCCEEDED(hr))
    {
        IShellItem2 *psi2;
        hr = psi->QueryInterface(IID_PPV_ARGS(&psi2));
        if (SUCCEEDED(hr))
        {
			mol::CoStrBuf psz;
			HRESULT hr = psi->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &psz);
			if(hr==S_OK)
			{
				currentPath_ = psz;
				currentItem_ = psi;
				fire(DISPID_ISHELLTREEEVENTS_ONTREESELECTION,mol::variant(currentPath_));
			}
			psi2->Release();
		}
		psi->Release();
    }
    return S_OK;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
// COM Properties and members
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// displayfiles
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall NamespaceTree::get_DisplayFiles	( VARIANT_BOOL* vb )
{
	if ( vb )
	{
		if ( displayFiles_ )
			*vb = VARIANT_TRUE;
		else
			*vb = VARIANT_FALSE;
	}
	return S_OK;
}

HRESULT __stdcall NamespaceTree::put_DisplayFiles	( VARIANT_BOOL vb  )
{
	if ( S_OK != OnRequestEdit( 1 ) )
		return S_FALSE;

	if ( vb == VARIANT_TRUE )
		displayFiles_ = true;
	else
		displayFiles_ = false;

	this->OnChanged(1);
	return S_OK;
}
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall NamespaceTree::get_UseContext	( VARIANT_BOOL* vb )
{
	if ( vb )
	{
		if ( useContext_ )
			*vb = VARIANT_TRUE;
		else
			*vb = VARIANT_FALSE;
	}
	return S_OK;
}

HRESULT __stdcall NamespaceTree::put_UseContext	( VARIANT_BOOL vb  )
{
	if ( S_OK != OnRequestEdit( 15 ) )
		return S_FALSE;

	if ( vb == VARIANT_TRUE )
		useContext_ = true;
	else
		useContext_ = false;

	this->OnChanged(51);
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
// selection
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall NamespaceTree::get_Selection		( BSTR* dirname )
{
	*dirname = ::SysAllocString(currentPath_);
	return S_OK;
}




HRESULT __stdcall NamespaceTree::get_HasFocus( VARIANT_BOOL* vbHasFocus)
{
	if ( vbHasFocus )
	{
		HWND hwndTree;
		IUnknown_GetWindow(tree_, &hwndTree);

		const int TREEVIEW_ID = 0x64;
		HWND hTreeView = GetDlgItem(hwndTree, TREEVIEW_ID);

		HWND focus = ::GetFocus();
		if ( (focus == hwndTree) || (*this == focus) || (focus == hTreeView) )
		{
			*vbHasFocus = VARIANT_TRUE;
		}
		else
		{
			*vbHasFocus = VARIANT_FALSE;
		}
	}
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
// Remove network folder
///////////////////////////////////////////////////////////////////////

HRESULT NamespaceTree::RemoveFolder(BSTR dirname)
{
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
// add network folder
///////////////////////////////////////////////////////////////////////

HRESULT NamespaceTree::AddFolder(BSTR dirname)
{

	return S_OK;
}


//////////////////////////////////////////////////////////////////////////////
//
// Update focused dir
//
//////////////////////////////////////////////////////////////////////////////

HRESULT NamespaceTree::Update()
{
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// Cut selected tree item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT NamespaceTree::Cut ()
{
	InvokeVerb("cut");
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// Copy selected tree item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT NamespaceTree::Copy ()
{
	InvokeVerb("copy");
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// Paste into tree view
//
//////////////////////////////////////////////////////////////////////////////

HRESULT NamespaceTree::Paste ()
{
	InvokeVerb("paste");
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// rename selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT NamespaceTree::Rename()
{
	InvokeVerb("rename");
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// delete selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT NamespaceTree::Delete()
{
	InvokeVerb("delete");
//	mol::io::ShellFileOp sfo;
//	sfo.remove(*this,currentPath_.toString());
	return S_OK;
}


//////////////////////////////////////////////////////////////////////////////
//
// properties of selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT NamespaceTree::Properties()
{
	InvokeVerb("properties");
	//mol::io::execute_shell(currentPath_.toString(),_T("properties"),1,SEE_MASK_INVOKEIDLIST);
	return S_OK;
}


//////////////////////////////////////////////////////////////////////////////
//
// shellexecute selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT NamespaceTree::Execute()
{
	InvokeVerb("open");
//	mol::io::execute_shell(currentPath_.toString());
	return S_OK;
}
//////////////////////////////////////////////////////////////////////////////
HRESULT NamespaceTree::CreateDir()
{
	std::wstring tmp = _T("newDir_");	
	int i = 0;
	while(true)
	{
		std::wstring p(currentPath_.towstring());
		std::wstringstream oss;
		oss << tmp << i;
		p = mol::Path::append(p,oss.str());
		if ( !::CreateDirectory(p.c_str(),0) )
		{
			if ( ::GetLastError() == ERROR_ALREADY_EXISTS )
			{
				i++;
				continue;
			}
		}
		return 0;
	}
	return S_OK;
}

HRESULT __stdcall NamespaceTree::IsDir(BSTR path,VARIANT_BOOL* vb)
{
	if(vb==0)
		return E_INVALIDARG;

	*vb = mol::Path::isDir(mol::bstr(path).towstring()) ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall NamespaceTree::put_ForeColor( BSTR fPath)
{
	foreCol_ = mol::hex2rgb(mol::bstr(fPath).tostring());
	return S_OK;
}

HRESULT __stdcall NamespaceTree::get_ForeColor(  BSTR* fPath)
{
	if(!fPath)
		return E_INVALIDARG;

	*fPath = ::SysAllocString(mol::towstring(mol::rgb2hex(foreCol_)).c_str());
	return S_OK;
}

HRESULT __stdcall NamespaceTree::put_BackColor( BSTR fPath)
{
	bgCol_ = mol::hex2rgb(mol::bstr(fPath).tostring());
	if ( bgBrush_)
		::DeleteObject(bgBrush_);
	bgBrush_ = ::CreateSolidBrush(bgCol_);
	return S_OK;
}

HRESULT __stdcall NamespaceTree::get_BackColor(  BSTR* fPath)
{
	if(!fPath)
		return E_INVALIDARG;

	*fPath = ::SysAllocString(mol::towstring(mol::rgb2hex(bgCol_)).c_str());
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


HRESULT __stdcall NamespaceTree::Load( LPSTREAM pStm)
{
	pStm >> mol::property( mol::DispId(this,DISPID_ISHELLTREE_DISPLAYFILES,VT_BOOL) )
		 >> mol::property( currentPath_ )
		 >> mol::property( &sizel );

	return S_OK;
}

HRESULT __stdcall NamespaceTree::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	pStm << mol::property( mol::DispId(this,DISPID_ISHELLTREE_DISPLAYFILES,VT_BOOL) )
		<< mol::property( currentPath_ )
		 << mol::property( &sizel );

	return S_OK;
}

HRESULT __stdcall NamespaceTree::Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog)
{
	
	pPropBag >> mol::property( _T("displayfiles"), mol::DispId(this,DISPID_ISHELLTREE_DISPLAYFILES,VT_BOOL) )
			 >> mol::property( _T("cs"), &sizel );

	return S_OK;
}

HRESULT __stdcall NamespaceTree::Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties)
{
	
	pPropBag << mol::property( _T("displayfiles"), mol::DispId(this,DISPID_ISHELLTREE_DISPLAYFILES,VT_BOOL) )
			 << mol::property( _T("cs"), &sizel );

	return S_OK;
}


///////////////////////////////////////////////////////////////////////
// helper
///////////////////////////////////////////////////////////////////////

void NamespaceTree::InvokeVerb(const std::string& verb)
{
	if(!currentItem_)
		return;

	mol::punk<IContextMenu> cm;
    HRESULT hr = currentItem_->BindToHandler(NULL, BHID_SFUIObject, IID_IContextMenu, (void**)&cm);
    if (!SUCCEEDED(hr)) 
		return;

	mol::PopupMenu menu;
	if (menu) 
	{
		HRESULT hr = cm->QueryContextMenu(menu, 0, 1, 0x7FFF, CMF_NORMAL);
		if(SUCCEEDED(hr)) {
			CMINVOKECOMMANDINFO info = { 0 };
			info.cbSize = sizeof(info);
			info.lpVerb = verb.c_str();
			cm->InvokeCommand(&info);
		}
	}
}



//} // end namespace mol

