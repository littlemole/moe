#include "stdafx.h"
#include "tree.h"
#include "moe.h"
#include "moeBar.h"
#include "xmlui.h"
#include "ribbonres.h"


//////////////////////////////////////////////////////////////////////////////
// tree events sink
//////////////////////////////////////////////////////////////////////////////

MoeTreeWnd::~MoeTreeWnd() 
{
	ODBGS("~MoeTreeWnd");
}
/*
void MoeTreeWnd::OnCreate()
{

}
*/

void MoeTreeWnd::OnTreeOpen()
{
	mol::bstr p;
	mol::punk<IShellTree> tree(oleObject);
	tree->get_Selection(&p);
	VARIANT_BOOL vb;
	tree->IsDir(p,&vb);
	treeWndSink()->OnTreeOpen(p,vb);
}

void MoeTreeWnd::OnTreeUpdate()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Update();
}			

void MoeTreeWnd::OnTreeRename()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Rename();
}

void MoeTreeWnd::OnTreeDelete()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Delete();
}

void MoeTreeWnd::OnTreeExecute()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Execute();
}

void MoeTreeWnd::OnTreeProperties()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Properties();
}

void MoeTreeWnd::OnTreeNewDir()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->CreateDir();
}

void MoeTreeWnd::OnEditCut()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Cut();
}

void MoeTreeWnd::OnEditCopy()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Copy();
}

void MoeTreeWnd::OnEditPaste()
{
	mol::punk<IShellTree> tree(oleObject);
	tree->Paste();
}


HRESULT __stdcall TreeWndSink::OnTreeSelection(BSTR filename)
{
	return moe()->IOleInPlaceFrame_SetStatusText(filename);
}

HRESULT __stdcall TreeWndSink::OnTreeDblClick(BSTR filename,VARIANT_BOOL vb)
{
	mol::string p(mol::toString(filename));
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
			statusBar()->status( mol::string(_T("failed to load ")) + p);
			return S_FALSE;
		}
	}
	return S_OK;
}

MOE_DOCTYPE index2DocType(int i)
{
	switch(i)
	{
		case 0 :
		{
			return MOE_DOCTYPE_DOC;
		}
		case 1 :
		{
			return MOE_DOCTYPE_HTML;
		}
		case 2 :
		{
			return MOE_DOCTYPE_RTF;
		}
		case 3 :
		{
			return MOE_DOCTYPE_HEX;
		}
		case 4 :
		{
			return MOE_DOCTYPE_TAIL;
		}
		default :
		{
			return MOE_DOCTYPE_DOC;
		}
	}
}

HRESULT __stdcall TreeWndSink::OnTreeOpen(BSTR filename,VARIANT_BOOL vb)
{
	mol::string p(mol::toString(filename));
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
				statusBar()->status( mol::string(_T("failed to load ")) + p);
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
					statusBar()->status( mol::string(_T("failed to load ")) + p);
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

		/*
		mol::FilenameDlg dlg(*moe());
		dlg.setFilter( InFilesFilter );	
		dlg.fileName(p);
		if ( !dlg.dlgOpen(OFN_ALLOWMULTISELECT | OFN_EXPLORER) )
			return S_OK;

		int s = dlg.selections();
		int c = dlg.index();
		for ( int i = 0; i < s; i++ )
		{
			mol::string f = dlg.fileName(i);
			statusBar()->status(f);


			bool result = ::docs()->open(f,index2DocType(c),-1,false,0);

			if (!result)
			{
				statusBar()->status( mol::string(_T("failed to load ")) + f);
				return S_OK;
			}
		}
		*/
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

	if ( mol::Ribbon::ribbon()->enabled() )
	{
		mol::Ribbon::ribbon()->showContextualUI( RibbonTreeViewContextMap, pt.x, pt.y);
		return 0;
	}

	mol::Menu sub = mol::UI().SubMenu(IDM_CONTEXT_TREE,IDM_TREE);

	moe()->showContext(sub);

	return S_OK;
/*
	int id = sub.returnTrackPopup(*moe(),pt.x-10,pt.y-10);
	switch ( id )
	{
		case IDM_TREE_OPEN:
		{
			OnTreeOpen(fname);
			break;
		}
		case IDM_TREE_UPDATE:
		{
			tree->Update();
			break;
		}
		case IDM_TREE_RENAME:
		{
			tree->Rename();
			break;
		}
		case IDM_TREE_DELETE:
		{
			tree->Delete();
			break;
		}
		case IDM_EDIT_CUT:
		{
			tree->Cut();
			break;
		}
		case IDM_EDIT_COPY:
		{
			tree->Copy();
			break;
		}
		case IDM_EDIT_PASTE:
		{
			tree->Paste();
			break;
		}
		case IDM_TREE_PROPERTIES:
		{
			tree->Properties();
			break;
		}
		case IDM_TREE_EXECUTE:
		{
			tree->Execute();
			break;
		}
		case IDM_TREE_NEWDIR:
		{
			tree->CreateDir();
			break;
		}
	}
	return S_OK;
	*/
}
