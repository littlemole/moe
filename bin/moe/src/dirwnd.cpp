#include "stdafx.h"
#include "dirwnd.h"
#include "app.h"


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

using namespace mol::io;

DirChildImpl::DirChildImpl( DirChild* dc ) 
{
	dirchild_ = dc;
	eraseBackground_ = 1;
}

void DirChildImpl::setIcon(int icon)
{
    icon_.load(icon,16,16);
	wndClass().setIcon(icon_); 
	wndClass().hIconSm(icon_); 

}

//////////////////////////////////////////////////////////////////////////////

DirChildImpl::~DirChildImpl() 
{
	if ( icon_ )
		::DestroyIcon(icon_);

	ODBGS("~DirChildImpl dropped dead");
};



//////////////////////////////////////////////////////////////////////////////
//
// WM_CREATE
//
//////////////////////////////////////////////////////////////////////////////

HWND DirChildImpl::createWindow( const mol::string& windowName, int id, const mol::Rect& r, HWND parent )
{
	BASE::createWindow( windowName, id, r, parent );

	getClientRect(clientRect_);
	show(SW_SHOW);
	activate();

	punk<IShellList> list(oleObject);
	sink.Advise(list);

	advise<_IShellListEvents>(oleObject,&(app<MoeApp>().moe->dirSink),cookie_);
	return hWnd_;
}

/*LRESULT DirChildImpl::OnCreate(UINT msg, WPARAM wParam, LPARAM lParam)
{
	getClientRect(clientRect_);
//    dirList.create( IDC_DIR_VIEW, clientRect_, *this);


//	FillLayout* layout = setLayout(new FillLayout);
//	layout->add(dirList);



	return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////
//
// OnDestroy - over and out
//
//////////////////////////////////////////////////////////////////////////////
LRESULT DirChildImpl::OnDestroy(UINT msg, WPARAM wParam, LPARAM lParam)
{
	sink.UnAdvise(oleObject);
	unadvise<_IScintillAxEvents>(oleObject,cookie_);

	BASE::wndProc(*this,msg,  wParam,  lParam);

//	::CoDisconnectObject(((IDoc*)dirchild_),0);
//	((IDoc*)dirchild_)->Release();
	
    return 0;
}

LRESULT DirChildImpl::OnNcDestroy(UINT msg, WPARAM wParam, LPARAM lParam)
{
//	BASE::wndProc(*this,msg,  wParam,  lParam);

	::CoDisconnectObject(((IDoc*)dirchild_),0);
	((IDoc*)dirchild_)->Release();
	
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Child gets activated
//
//////////////////////////////////////////////////////////////////////////////


LRESULT DirChildImpl::OnMDIActivate(UINT msg, WPARAM wParam, LPARAM lParam)
{
	//dirList.setFocus();
	return BASE::wndProc(*this,msg,  wParam,  lParam);
	return MdiChild::wndProc( hWnd_, msg, wParam, lParam );
}


//////////////////////////////////////////////////////////////////////////////
//
// open dir element
//
//////////////////////////////////////////////////////////////////////////////

LRESULT DirChildImpl::OnEditUpdate(UINT msg, WPARAM wParam, LPARAM lParam)
{
	oleObject->Update();
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// show context
//
//////////////////////////////////////////////////////////////////////////////

LRESULT DirChildImpl::OnEditCut(UINT msg, WPARAM wParam, LPARAM lParam)
{
	punk<IShellList> list(oleObject);
	if (list )
		list->Cut();
	return 0;
}

LRESULT DirChildImpl::OnEditCopy(UINT msg, WPARAM wParam, LPARAM lParam)
{
	punk<IShellList> list(oleObject);
	if (list )
		list->Copy();
	return 0;
}

LRESULT DirChildImpl::OnEditPaste(UINT msg, WPARAM wParam, LPARAM lParam)
{
	punk<IShellList> list(oleObject);
	if (list )
		list->Paste();
	return 0;
}


//////////////////////////////////////////////////////////////////////////////
// dirlist events sink
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DirChildImpl::DirChild_sink::OnListDblClick(BSTR filename)
{
	punk<IShellList> list(This()->oleObject);
	if ( list )
	{
		mol::string p(mol::toString(filename));
		if ( mol::Path::exists(p) )
		{		
			if ( mol::Path::isDir(p) )
			{
				return list->put_Selection(variant(p));
			}
			app<MoeApp>().moe->Open(bstr(p),0);
		}
	}
	return S_OK;
}
