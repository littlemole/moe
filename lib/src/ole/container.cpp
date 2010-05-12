#include "ole/container.h"

namespace mol {
namespace ole {

AxFrameBase::AxFrameBase()
{
	borderwidths_ = mol::Rect( 0,0,0,0 );
}

AxFrameBase::~AxFrameBase()
{
}


// IOleInPlaceFrame
HRESULT __stdcall AxFrameBase::IOleInPlaceFrame_GetWindow( HWND FAR* lphwnd)
{
	return E_NOTIMPL;
}

HRESULT __stdcall AxFrameBase::IOleInPlaceFrame_ContextSensitiveHelp( BOOL fEnterMode)
{
	return E_NOTIMPL ;
}

HRESULT __stdcall AxFrameBase::IOleInPlaceFrame_GetBorder( LPRECT lprectBorder)
{
	ODBGS("IOleInPlaceFrame_SetBorderSpace - E_NOTIMPL");
	return E_NOTIMPL ;
}
HRESULT __stdcall AxFrameBase::IOleInPlaceFrame_RequestBorderSpace( LPCBORDERWIDTHS pborderwidths)
{
	ODBGS("IOleInPlaceFrame_RequestBorderSpace - E_NOTIMPL");
	return E_NOTIMPL ;
}
HRESULT __stdcall AxFrameBase::IOleInPlaceFrame_SetBorderSpace( LPCBORDERWIDTHS pborderwidths)
{
	ODBGS("IOleInPlaceFrame_SetBorderSpace - E_NOTIMPL");
	return E_NOTIMPL ;
}
HRESULT __stdcall AxFrameBase::IOleInPlaceFrame_SetActiveObject( IOleInPlaceActiveObject *pActiveObject, LPCOLESTR pszObjName)
{
	activeObject = pActiveObject;
	if ( activeObject )
	{
		ODBGS1("IOleInPlaceFrame_SetActiveObject",(int)pActiveObject);
	}
	else
	{
		ODBGS1("IOleInPlaceFrame_SetActiveObject",(int)pActiveObject);
		//borderwidths_ = mol::Rect(0,0,0,0);
	}
	return S_OK;
}
HRESULT __stdcall AxFrameBase::IOleInPlaceFrame_InsertMenus( HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidths)
{
	return E_NOTIMPL;
}
HRESULT __stdcall AxFrameBase::IOleInPlaceFrame_SetMenu( HMENU hmenuShared, HOLEMENU holemenu, HWND hwndActiveObject)
{
	return S_OK ;
}
HRESULT __stdcall AxFrameBase::IOleInPlaceFrame_RemoveMenus( HMENU hmenuShared)
{
	return S_OK ;
}
HRESULT __stdcall AxFrameBase::IOleInPlaceFrame_SetStatusText( LPCOLESTR pszStatusText)
{
	return S_OK ;
}
HRESULT __stdcall AxFrameBase::IOleInPlaceFrame_EnableModeless( BOOL fEnable)
{
	return S_OK ;
}
HRESULT __stdcall AxFrameBase::IOleInPlaceFrame_TranslateAccelerator( LPMSG lpmsg, WORD wID)
{
	return E_NOTIMPL ;
}

HRESULT __stdcall  AxFrameBase::IOleCommandTarget_QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText)
{
	if (pguidCmdGroup != NULL)
		return OLECMDERR_E_UNKNOWNGROUP;
			
	if (prgCmds == NULL)
		return E_INVALIDARG;

	for (int i = 0; i < (int)cCmds; i++) 
	{
			prgCmds[i].cmdf = 0;
	}
	
	if (pCmdText) //(TODO) we don't deal with this yet...
	{
		pCmdText->cmdtextf = MSOCMDTEXTF_NONE;
		pCmdText->cwActual = 0;
	}

	return S_OK;
}

HRESULT __stdcall  AxFrameBase::IOleCommandTarget_Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANTARG *pvaIn, VARIANTARG *pvaOut)
{
	return S_OK;
}


////////////////////////////////////////////////////////////////
// OleContainerBase - adds merging of ole menus and toolbars
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

OleContainerBase::OleContainerBase()
{
	nMenus_			= 0;
	phMenus_		= 0;
	nHelpMenuItems_ = 0;
	winMenu_		= 0;
}

OleContainerBase::~OleContainerBase()
{
	ODBGS("OleContainerBase died ;)");
}

	//////////////////////////////////////////////////////////


void OleContainerBase::addFileMenu( HMENU m, const mol::string& txt )
{
	fileMenus_.push_back(std::make_pair(txt,m));
}

void OleContainerBase::addEditMenu( HMENU m, const mol::string& txt )
{
	editMenus_.push_back(std::make_pair(txt,m));
}

void OleContainerBase::addViewMenu( HMENU m, const mol::string& txt)
{
	viewMenus_.push_back(std::make_pair(txt,m));
}

void OleContainerBase::addObjectMenu( HMENU m, const mol::string& txt )
{
	objectMenus_.push_back(std::make_pair(txt,m));
}

void OleContainerBase::setWindowMenu( HMENU m )
{
	winMenu_ = m;
}

void OleContainerBase::addWindowMenu( HMENU m, const mol::string& txt )
{
	windowMenus_.push_back(std::make_pair(txt,m));
}

void OleContainerBase::addHelpMenu( HMENU m, const mol::string& txt )
{
	helpMenus_.push_back(std::make_pair(txt,m));
	if ( helpMenus_.size() )
		nHelpMenuItems_ = ::GetMenuItemCount(helpMenus_[0].second);
	else
		nHelpMenuItems_ = 0;
}

void OleContainerBase::addOlExecHandler( int oleCmdId, UINT cmd, GUID* cmdGroup  )
{
	OleCmd olecmd(cmd,cmdGroup,oleCmdId);
	this->oleCmds_.push_back(olecmd);
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// COM impl
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


HRESULT __stdcall OleContainerBase::handleGetBorder( mol::Rect r, LPRECT lprectBorder)
{
	mol::LayoutMgr* layout = this->getLayoutMgr();
	if ( layout )
		r = layout->availBorderRect(r);

	*lprectBorder = r;
	return S_OK;
}

HRESULT __stdcall OleContainerBase::handleRequestBorderSpace( mol::Rect r, LPCBORDERWIDTHS pborderwidths)
{
	HRESULT hr = S_OK;

	// We tell objects they can't have more than 50% of client area...
	if ((pborderwidths->left + pborderwidths->right > r.right/2) ||
		(pborderwidths->top + pborderwidths->bottom > r.bottom/2))
	{
		hr = INPLACE_E_NOTOOLSPACE;
	}
	return hr;
}

HRESULT __stdcall OleContainerBase::handleSetBorderSpace( LPCBORDERWIDTHS pborderwidths)
{		
	RECT& borderwidths = this->getBorderWidths();
    if (pborderwidths )
	{			
		ODBGS1(" SetBorderSpace - new top: ",pborderwidths->top);
		if ( borderwidths.left == pborderwidths->left && borderwidths.top == pborderwidths->top &&
			borderwidths.right == pborderwidths->right && borderwidths.bottom == pborderwidths->bottom )
		return S_OK;

		borderwidths = *pborderwidths;
		if ( borderwidths.left == 0 && borderwidths.top == 0 &&
			borderwidths.right == 0 && borderwidths.bottom == 0 )
		{
			ODBGS("IOleInPlaceFrame_SetBorderSpace ZERO");
		}
		else
		{
			ODBGS("IOleInPlaceFrame_SetBorderSpace");
		}

    }
	else
	{
		ODBGS("IOleInPlaceFrame_SetBorderSpace ZERO");
		borderwidths = mol::Rect(0,0,0,0);
	}
	
	ODBGS("<------IOleInPlaceFrame_SetBorderSpace END");

	return S_OK;
}


HRESULT __stdcall OleContainerBase::handleInsertMenus( HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidths)
{
	int nMenus = (int)(fileMenus_.size() + editMenus_.size() + viewMenus_.size() + objectMenus_.size() + windowMenus_.size() + helpMenus_.size());

	delete phMenus_;
	phMenus_ = new HMENU[nMenus];

	nMenus_  = 0;

	insertOleMenues( hmenuShared, fileMenus_ );
	insertOleMenues( hmenuShared, editMenus_ );
	insertOleMenues( hmenuShared, viewMenus_ );
	insertOleMenues( hmenuShared, objectMenus_ );
	insertOleMenues( hmenuShared, windowMenus_ );
	insertOleMenues( hmenuShared, helpMenus_ );

	// Groups handled by the container...
	lpMenuWidths->width[0] = (LONG)fileMenus_.size(); // File
	lpMenuWidths->width[2] = (LONG)viewMenus_.size(); // View
	lpMenuWidths->width[4] = (LONG)windowMenus_.size(); // Window

	// Groups handled by the server...
	lpMenuWidths->width[1] = (LONG) editMenus_.size(); // Edit
	lpMenuWidths->width[3] = (LONG)objectMenus_.size(); // Object/Insert
	lpMenuWidths->width[5] = (LONG)helpMenus_.size(); // Help

	return S_OK;
}

HRESULT __stdcall OleContainerBase::handleSetMenu( HMENU hmenuShared, HOLEMENU holemenu, HWND hwndActiveObject)
{
	if (hmenuShared)
	{
		hMenuActive_ = hmenuShared;
	}
	else
	{
		if (hMenuActive_ == origMenu_) 
			return S_OK;
		hMenuActive_ = origMenu_;
	}

	if ( !this->getMidiState() )
	{
		this->setFrameMenu( hMenuActive_, 0 );
	}
	else
	{
		HMENU wm = ::GetSubMenu(hMenuActive_,::GetMenuItemCount(hMenuActive_)-1);
		if ( winMenu_ )
			wm = winMenu_;
		else
		{
			if ( windowMenus_.size() > 0 )
			{
				wm = windowMenus_[0].second;
			}
		}

		this->setFrameMenu( hMenuActive_, wm );
	}

	HRESULT hr = ::OleSetMenuDescriptor(holemenu, this->getFrameWindow(), hwndActiveObject, NULL, NULL);

	::DrawMenuBar( this->getFrameWindow() );
	return hr;
}

HRESULT __stdcall OleContainerBase::handleRemoveMenus( HMENU hmenuShared)
{
	UINT    cItems;
	HMENU   hMenuTemp;

	if (!(hmenuShared) || (0 == (cItems = ::GetMenuItemCount(hmenuShared))))
		return S_OK;

	// Remove our added menus (in reverse order, since we remove by position)...
	for (int i = cItems; i >= 0; i--)
	{
		hMenuTemp = ::GetSubMenu(hmenuShared, i);

		/*
		if (hMenuTemp == helpMenus_[0].second )
		{
			for (int k = nHelpMenuItems_; k < GetMenuItemCount(hMenuTemp); k++)
			{
				char buf[256];
				::GetMenuString(hMenuTemp,k,buf,256,MF_BYPOSITION);
				RemoveMenu(hMenuTemp, k, MF_BYPOSITION);
			}
		}
		*/
		for (int j = 0; j < nMenus_; j++)
		{
			if (hMenuTemp == phMenus_[j])
			{
				RemoveMenu(hmenuShared,i, MF_BYPOSITION);
				break;
			}
		}
        
	}
	return S_OK;
}

HRESULT __stdcall  OleContainerBase::handleQueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText)
{
	if (pguidCmdGroup != NULL)
		return OLECMDERR_E_UNKNOWNGROUP;
			
	if (prgCmds == NULL)
		return E_INVALIDARG;

	for (int i = 0; i < (int)cCmds; i++) 
	{
		prgCmds[i].cmdf = 0;
		int s = (int)oleCmds_.size();
		for ( int c = 0; c < s; c++ )
		{
			if ( oleCmds_[c].cmdGroup_ == pguidCmdGroup )
			if ( oleCmds_[c].oleCmdId_ == prgCmds[i].cmdID )
			{
				prgCmds[i].cmdf = OLECMDF_ENABLED | OLECMDF_SUPPORTED; 
				break;
			}
		}
	}
	
	if (pCmdText) //(TODO) we don't deal with this yet...
	{
		pCmdText->cmdtextf = MSOCMDTEXTF_NONE;
		pCmdText->cwActual = 0;
	}

	return S_OK;
}

HRESULT __stdcall  OleContainerBase::handleExec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANTARG *pvaIn, VARIANTARG *pvaOut)
{
	if (pguidCmdGroup != NULL)
		return OLECMDERR_E_UNKNOWNGROUP;
	    
	if (nCmdexecopt == MSOCMDEXECOPT_SHOWHELP)
		return OLECMDERR_E_NOHELP;

	int nCmds = (int)oleCmds_.size();
	for ( int c = 0; c < nCmds; c++ )
	{
		if ( oleCmds_[c].cmdGroup_ == pguidCmdGroup )
		if ( oleCmds_[c].oleCmdId_ == nCmdID )
		{
			::PostMessage( this->getFrameWindow(), WM_COMMAND, oleCmds_[c].cmdId_, 0); 
			return S_OK;
		}
	}
	return OLECMDERR_E_NOTSUPPORTED; 
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

LRESULT OleContainerBase::OleContainerWndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	mol::LayoutMgr* layout = this->getLayoutMgr();
	IUnknown* axFrameSite = this->getAxFrameSiteUnknown();
	IOleInPlaceActiveObject* activeObject = this->getIOleInPlaceActiveObject();

	switch ( message )
	{
		case WM_EXITSIZEMOVE:
		{
			// end of sizing action
			// re-negotiate toolspace and repaint everything
			ODBGS("OleContainer::WM_EXITSIZEMOVE");
			mol::Rect clientRect = this->prepareClientRect();
			if (activeObject)
			{				
				mol::Rect r = clientRect;
				if ( layout )
					r = layout->availBorderRect(r);
				punk<IOleInPlaceFrame> uiwin;
				axFrameSite->QueryInterface(IID_IOleInPlaceFrame, (void**)&uiwin);
				if ( uiwin )
					activeObject->ResizeBorder( &r, uiwin,TRUE);
			}
			this->handleDoLayout( clientRect );
			this->redrawOleContainer();
			return 0;
		}
		case WM_ACTIVATEAPP :
		{
			//deactivation
			if ( activeObject && !wParam)
			{
				ODBGS("OleContainer::WM_ACTIVATEAPP FALSE");					
				return 0;
			}
			if ( activeObject && wParam)
			{
				ODBGS("OleContainer::WM_ACTIVATEAPP TRUE");
				return 0;
			}
			return 0;
		}
		//case WM_CLOSE :
		case WM_DESTROY :
		{
			// release COM stuff before HWND dies
			this->releaseOleContainer();
			return this->callOleContainerDefWndProc(hWnd,  message,  wParam,  lParam);
		}
	}
	return this->callOleContainerDefWndProc(hWnd,  message,  wParam,  lParam);
}



//////////////////////////////////////////////////////////

LRESULT OleContainerBase::handleOnLayout( UINT message, WPARAM wParam, LPARAM lParam)
{
	ODBGS("OleContainer::OnLayout");

	mol::LayoutMgr* layout = this->getLayoutMgr();
	IUnknown* axFrameSite = this->getAxFrameSiteUnknown();
	IOleInPlaceActiveObject* activeObject = this->getIOleInPlaceActiveObject();

	RECT clientRect = this->prepareClientRect();
	mol::Rect r = clientRect;
	// renegotiate toolspace
	if ( layout && activeObject )
	{
		layout->resize(0,MAKELPARAM(r.right,r.bottom));
		r = layout->availBorderRect(r);
		punk<IOleInPlaceFrame> uiwin;
		axFrameSite->QueryInterface(IID_IOleInPlaceFrame, (void**)&uiwin);
		if ( uiwin )
			activeObject->ResizeBorder( &r, uiwin, TRUE);
	}

	handleDoLayout( clientRect );
	ODBGS("<-------OleContainer::OnLayout END");
	return 0;
}

// layout helper, takes allocated borderwith into account
LRESULT OleContainerBase::handleDoLayout( mol::Rect r )
{
	mol::LayoutMgr* layout = this->getLayoutMgr();

	if ( layout )
		r = layout->availClientRect(r);

	RECT& borderwidths = this->getBorderWidths();
	r.top += borderwidths.top;
	r.bottom -= borderwidths.top;

	r.left += borderwidths.left;
	r.right -= borderwidths.left;

	r.bottom -= borderwidths.bottom;
	r.right -= borderwidths.right;

	if ( layout )
		layout->layout(r);

	ODBGS("<------OleContainer::doLayout END");
	return 0;
}

void OleContainerBase::insertOleMenues( HMENU shared, std::vector<namedMenu>& v )
{
	for ( unsigned int i = 0; i < v.size(); i++ )
	{
		phMenus_[nMenus_+i] = v[i].second;
		int index = nMenus_ + i;
		::InsertMenu( shared, index, MF_BYPOSITION | MF_POPUP,(UINT_PTR)v[i].second, v[i].first.c_str() );
	}
	nMenus_ += (int)v.size();
}


} // end namespace ole
} // end namespace mol