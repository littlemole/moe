#include "stdafx.h"
#include "mtree.h"
#include "moe.h"
#include "docs.h"
#include "moeBar.h"
#include "xmlui.h"
#include "ribbonres.h"
#include "resource.h"

//////////////////////////////////////////////////////////////////////////////
// tree events sink
//////////////////////////////////////////////////////////////////////////////

MoeTreeWnd::~MoeTreeWnd() 
{
	ODBGS("~MoeTreeWnd");
}


bool MoeTreeWnd::hasFocus()      
{ 
	mol::punk<IShellTree> tree(oleObject);
	if(!tree)
		return false;

	VARIANT_BOOL vb;
    HRESULT hr = tree->get_HasFocus(&vb);
	if( hr != S_OK || vb == VARIANT_FALSE)
		return false;

	return true;
}

handle_cmd(&MoeTreeWnd::OnTreeOpen, IDM_TREE_OPEN)
void MoeTreeWnd::OnTreeOpen()
{
	mol::bstr p;
	mol::punk<IShellTree> tree(oleObject);
	tree->get_Selection(&p);
	VARIANT_BOOL vb;
	tree->IsDir(p,&vb);
	moe()->treeWndSink->OnTreeOpen(p,vb);
}

handle_cmd(&MoeTreeWnd::OnTreeUpdate, IDM_TREE_UPDATE)
void MoeTreeWnd::OnTreeUpdate()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Update();
}			

handle_cmd(&MoeTreeWnd::OnTreeRename, IDM_TREE_RENAME)
void MoeTreeWnd::OnTreeRename()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Rename();
}

handle_cmd(&MoeTreeWnd::OnTreeDelete, IDM_TREE_DELETE)
void MoeTreeWnd::OnTreeDelete()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Delete();
}

handle_cmd(&MoeTreeWnd::OnTreeExecute, IDM_TREE_EXECUTE)
void MoeTreeWnd::OnTreeExecute()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Execute();
}

handle_cmd(&MoeTreeWnd::OnTreeProperties, IDM_TREE_PROPERTIES)
void MoeTreeWnd::OnTreeProperties()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Properties();
}

handle_cmd(&MoeTreeWnd::OnTreeNewDir, IDM_TREE_NEWDIR)
void MoeTreeWnd::OnTreeNewDir()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->CreateDir();
}

handle_cmd(&MoeTreeWnd::OnEditCut, IDM_TREE_CUT)
handle_cmd(&MoeTreeWnd::OnEditCut, IDM_EDIT_CUT)
void MoeTreeWnd::OnEditCut()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Cut();
}

handle_cmd(&MoeTreeWnd::OnEditCopy, IDM_TREE_COPY)
handle_cmd(&MoeTreeWnd::OnEditCopy, IDM_EDIT_COPY)
void MoeTreeWnd::OnEditCopy()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Copy();
}

handle_cmd(&MoeTreeWnd::OnEditPaste, IDM_TREE_PASTE)
handle_cmd(&MoeTreeWnd::OnEditPaste, IDM_EDIT_PASTE)
void MoeTreeWnd::OnEditPaste()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Paste();
}


HWND MoeTreeWnd::createWindow( const std::wstring& windowName, HMENU id, const mol::Rect& r, HWND parent )
{
	mol::AxClientWnd<MoeTreeWnd,RTree>::createWindow( windowName, id, r, parent );
	show(SW_SHOW);
	getClientRect(clientRect_);
	const GUID* clsid = &CLSID_ShellTree;
	if ( mol::OS::has_uac() )
	{
		clsid = &CLSID_NamespaceTree;
	}
	loadObject(*clsid);
    return hWnd_;
}

HRESULT __stdcall TreeWndSink::OnTreeSelection(BSTR filename)
{
	return moe()->IOleInPlaceFrame_SetStatusText(filename);
}

HRESULT __stdcall TreeWndSink::OnTreeDblClick(BSTR filename,VARIANT_BOOL vb)
{
	std::wstring p(mol::towstring(filename));
	if ( !mol::Path::exists(p) && !mol::Path::isUNC(p) )
	{
		if ( p.size()>4 && p.substr(0,2) != _T("::") && p.substr(0,5) != _T("ssh:/") )
			return S_OK;
	}
	mol::punk<IShellTree> tree(treeWnd()->oleObject);
	if ( tree )
	{
		bool result = ::docs()->open(p,MOE_DOCTYPE_DOC,-1,false,0);
		statusBar()->status(p);
		if (!result)
		{
			statusBar()->status( std::wstring(_T("failed to load ")) + p);
			return S_FALSE;
		}
	}
	return S_OK;
}

HRESULT __stdcall TreeWndSink::OnTreeOpen(BSTR filename,VARIANT_BOOL vb)
{
	std::wstring p(mol::towstring(filename));
	if ( !mol::Path::exists(p) && !mol::Path::isUNC(p) )
	{
		if ( p.size()>4 && p.substr(0,2) != _T("::") && p.substr(0,5) != _T("ssh:/") )
			return S_OK;
	}

	mol::punk<IShellTree> tree(treeWnd()->oleObject);
	if ( tree )
	{
		if ( mol::Path::isDir( p) || p.substr(0,2) == _T("::") )
		{
			statusBar()->status(p);
			bool result = ::docs()->open(p,MOE_DOCTYPE_DIR,-1,false,0);

			if (!result)
			{
				statusBar()->status( std::wstring(_T("failed to load ")) + p);
				return S_OK;
			}
			return S_OK;
		}
		if ( p.substr(0,5) == _T("ssh:/") )
		{
			statusBar()->status(p);
			bool result = false;

			if ( vb == VARIANT_TRUE )
			{
				result = ::docs()->open(p,MOE_DOCTYPE_SFTP,-1,false,0);
	
				if (!result)
				{
					statusBar()->status( std::wstring(_T("failed to load ")) + p);
					return S_OK;
				}
				return S_OK;
			}
		}

		mol::punk<IMoeDialogs> dialogs;
		moe()->get_Dialogs(&dialogs);
		if ( dialogs )
		{
			dialogs->Open(filename,0);
		}
	}
	return S_OK;
}

HRESULT __stdcall TreeWndSink::OnContextMenu(BSTR fname,VARIANT_BOOL vb)
{
	mol::punk<IShellTree> tree(treeWnd()->oleObject);
	if ( !tree )
		return S_OK;

	POINT pt;
	::GetCursorPos(&pt);

	mol::Menu sub = mol::UI().SubMenu(IDM_CONTEXT_TREE,IDM_TREE);

	moe()->showContext(sub);

	return S_OK;

}

