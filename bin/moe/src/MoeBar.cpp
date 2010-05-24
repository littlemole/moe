#include "stdafx.h"
#include "widgets.h"
#include "app.h"
#include "xmlui.h"
#include "MoeBar.h"
#include "Docs.h"

using namespace mol::io;

using namespace mol;
using namespace mol::ole;
using namespace mol::win;
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

// simple app-internal dragDrop passing a simple string
class TxtDragDrop
{
public:

	// start drag drop
	static int doDragDrop( CLIPFORMAT format, const mol::string& content )
	{
		punk<IDropSource> source = new mol::DropSrc();

		punk<mol::DataTransferObj> ido = new mol::DataTransferObj(true);
		ido->addData(format,content);

		DWORD effect;
		if ( DRAGDROP_S_DROP == ::DoDragDrop( 
									ido, 
									source, 
									DROPEFFECT_COPY|DROPEFFECT_MOVE,
									&effect) 
			)
			return effect;

		return DROPEFFECT_NONE;
	}

	// determine wether custom format is avail
	static bool isTxtDragDropFormat( IDataObject* ido, CLIPFORMAT format ) 
	{
		format_etc fe( format );
		HRESULT hr = ido->QueryGetData( &fe);
		if (hr != S_OK )
		{
			return false;
		}
		return true;
	}

	// retrieve dragDrop txt value for custom format from IDataObject
	static mol::string getTxt( IDataObject* ido, CLIPFORMAT format )
	{
		format_etc fe( format );

		STGMEDIUM sm;
		HRESULT hr = ido->GetData( &fe, &sm );
		if (hr != S_OK )
			return _T("");

		if ( sm.tymed != TYMED_HGLOBAL || !sm.hGlobal )
			return _T("");

		mol::string txt;
		mol::global::get(sm.hGlobal,txt);

		::ReleaseStgMedium(&sm);
		return txt;
	}
};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

MoeTabControl::MoeTabControl()
{
	dragTabFormat_      = ::RegisterClipboardFormat( _T("MoeTabDragDropCustomClipBoardFormat") );
	isMouseDown_ = false;
}


MoeTabControl::~MoeTabControl()
{
}


void MoeTabControl::OnCtrlCreated()
{
	// enable tab ctrl drag drop support
	TabCtrl_SetExtendedStyle(*this,TCS_EX_REGISTERDROP );

	//::RegisterDragDrop(*this,&Drop);
}

// helpers

int MoeTabControl::index( const mol::string& path )
{
	for ( int i = 0; i < count(); i++ )
	{
		mol::string p = getItemTooltipText(i);
		if ( mol::icmp( path, p ) == 0 )
		{
			return i;
		}
	}
	return -1;
}

void MoeTabControl::select( const mol::string& path )
{
	for ( int i = 0; i < count(); i++ )
	{
		mol::string p = getItemTooltipText(i);
		if ( mol::icmp( path, p ) == 0 )
		{
			mol::TabCtrl::select(i);
			return;
		}
	}
}

void MoeTabControl::move( const mol::string& what, const mol::string& to )
{
	int iwhat = -1;
	int ito   = -1;

	for ( int i = 0; i < count(); i++ )
	{
		mol::string p = getItemTooltipText(i);
		if ( mol::icmp( what, p ) == 0 )
		{
			iwhat = i;
		}
		if ( mol::icmp( to, p ) == 0 )
		{
			ito = i;
		}
	}

	if ( ito == -1 || iwhat == -1 )
		return;

	mol::string name = getItemText(iwhat);
	removeItem(iwhat);
	insertItem( name, what, ito );
}

void MoeTabControl::remove( const mol::string& path )
{
	for ( int i = 0; i < count(); i++ )
	{
		mol::string p = getItemTooltipText(i);
		if ( mol::icmp( path, p ) == 0 )
		{
			removeItem(i);
			return;
		}
	}
}

void MoeTabControl::rename( const mol::string& oldpath,const mol::string& newpath, const mol::string& name )
{
	for ( int i = 0; i < count(); i++ )
	{
		mol::string path = getItemTooltipText(i);
		if ( mol::icmp( oldpath, path ) == 0 )
		{
			this->renameItem( name, i, newpath );
			return;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////
// override windowproc for drag drop support
//////////////////////////////////////////////////////////////////////////////////


LRESULT MoeTabControl::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{	
		case WM_NOTIFY : 
		{
			//break;
			mol::Crack msg(message,wParam,lParam);

			if ( msg.nmhdr()->code == TCN_GETOBJECT )
			{
				// return our drop source for a drag-drop event
				msg.notifyObject()->hResult = E_FAIL;
				IID iid = *msg.notifyObject()->piid;
				if ( ::IsEqualIID( IID_IDropTarget, *msg.notifyObject()->piid) )
				{
					msg.notifyObject()->pObject = (IUnknown*)&Drop;
					msg.notifyObject()->hResult = S_OK;
				}
			}
			break;
		}

		case WM_LBUTTONDOWN : 
		{
			isMouseDown_ = false;

			int i = tab()->hitTest();
			if ( i!= -1 )
			{
				// wait a bit might be a drag-drop
				isMouseDown_ = true;
				SetTimer( ID_TABDRAGDROPTIMER, 500 );
			}
			break;
		}

		case WM_TIMER : 
		{
			if ( wParam == ID_TABDRAGDROPTIMER && isMouseDown_)
			{
				KillTimer(ID_TABDRAGDROPTIMER);
				isMouseDown_ = false;
				int i = tab()->hitTest();
				if ( i!= -1 )
				{
					// do a simple dragDrop
					mol::string txt = tab()->getItemTooltipText(i);
					TxtDragDrop::doDragDrop( dragTabFormat_, txt );
				}
			}
			break;
		}

		case WM_LBUTTONUP : 
		{
			isMouseDown_ = false;
			break;
		}
	}

	return  mol::TabCtrl::wndProc( hwnd, message, wParam, lParam );
}


//////////////////////////////////////////////////////////////////////////////
//
// Drag & Drop_ Support 
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeTabControl::MoeTabControl_Drop::Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect)
{
	ODBGS("Tab Drop");
	// get the dropped tabs path
	mol::string path = TxtDragDrop::getTxt( pDataObject, tab()->dragTabFormat_ );

	if ( path.empty() )
		return S_OK;

	// determine drop target tab
	int index = tab()->hitTest();
	int cur = tab()->selection();
	/*
	if ( index == cur )
	{
		*pEffect = DROPEFFECT_NONE;
		return S_OK;
	}
	*/
	if ( index == -1 )
		index = (int)tab()->count()-1;
	if ( index == -1 )
		index = 0;

	// try find dest tab by path index
	bool result = false;
	mol::punk<IMoeDocument> doc;
	if ( S_OK == docs()->Item( mol::variant(path), &doc) && doc )
	{
		mol::string fn = tab()->getItemTooltipText(index);
		docs()->Move( mol::variant(path), mol::variant(fn) );
		result = true;
	}
	else 
	{
		*pEffect = DROPEFFECT_NONE;
		return S_OK;
	}

	// clear highlight bits from tabctrl
	for ( int i = 0; i < tab()->count(); i++ )
		tab()->postMessage(TCM_HIGHLIGHTITEM,i,false);

	*pEffect = DROPEFFECT_NONE;
	return S_OK;
}

HRESULT  __stdcall MoeTabControl::MoeTabControl_Drop::DragEnter( IDataObject* pDataObject, DWORD , POINTL , DWORD* pEffect )
{
	ODBGS("Tab Drag Enter");
	if ( !TxtDragDrop::isTxtDragDropFormat(pDataObject,tab()->dragTabFormat_) )
	{
		*pEffect = DROPEFFECT_NONE;
		 return S_OK;
	}
    return S_OK;
}

HRESULT __stdcall MoeTabControl::MoeTabControl_Drop::DragOver( DWORD, POINTL, DWORD* pEffect )
{
	ODBGS("Tab Drag Over");
	*pEffect &= DROPEFFECT_COPY;
    return S_OK;
}


HRESULT  __stdcall MoeTabControl::MoeTabControl_Drop::DragLeave()
{
	ODBGS("Tab Drag Leave");
    return S_OK;
}




/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

MoeBar::~MoeBar()
{
	ODBGS("~MoeBar");
}

HRESULT __stdcall MoeBar::Load( LPSTREAM pStm)
{
	mol::ReBar::Load(pStm);
	int n = this->count();

	if ( n > 0 )
	for ( int i = 0; i < n-1; i++)
		postMessage(RB_MAXIMIZEBAND,i, 0 );

	//redraw();
	return S_OK;
}

HRESULT __stdcall MoeBar::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	mol::ReBar::Save(pStm, fClearDirty);
	return S_OK;
}

LRESULT MoeBar::wndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_CREATE :
		{
			RECT r;
			::GetClientRect(*this,&r);
			postMessage(WM_SIZE,0,MAKELPARAM(r.right,r.bottom));
			redraw();
			break;
		}
	}
	/*
	switch(msg)
	{
		case WM_NOTIFY :
		{
			mol::Crack message(msg,wParam,lParam);
			if ( message.nmhdr()->code == TBN_DROPDOWN )
			{	
				Menu m(mol::UI().Menu(IDM_MOE),false);
					
				int index = message.nmtoolbar()->iItem;
		//		if ( index == IDM_MODE_EOL )
		//			createMenuFromConf(m,mol::UI().SubMenu(IDM_MOE,IDM_MODE_EOL));
		//		else
		//			createMenuFromConf(m,mol::UI().SubMenu(IDM_MOE,IDM_TOOLS));

				Menu context( mol::UI().SubMenu(IDM_MOE,index) );
				moe()->showContext(context);

		//		updateUI();
				return TBDDRET_DEFAULT;
				return 0;
			}
		}
	}
	*/
	return mol::ReBar::wndProc(wnd,msg,wParam,lParam);
}