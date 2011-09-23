#include "ole/ctrl.h"
#include "util/uni.h"

namespace mol {

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

HRESULT __stdcall RunnableObj::GetRunningClass(LPCLSID lpClsid)
{
	*lpClsid = GUID_NULL;
	return E_UNEXPECTED;
}

HRESULT __stdcall RunnableObj::Run(LPBINDCTX)
{
	return S_OK;
}

BOOL __stdcall  RunnableObj::IsRunning()
{
	return TRUE;
}

HRESULT __stdcall RunnableObj::LockRunning(BOOL fLock, BOOL fLastUnlockCloses)
{
	return S_OK;
}

HRESULT __stdcall RunnableObj::SetContainedObject(BOOL fContained)
{
	return S_OK;
}


/////////////////////////////////////////////////////////////////////
// OleObject
/////////////////////////////////////////////////////////////////////

namespace ole {


OleObjBase::OleObjBase()
{
	::CreateOleAdviseHolder(&adviseHolder_);
	::CreateDataAdviseHolder(&dataAdviseHolder_);
}

OleObjBase::~OleObjBase()
{

}

//IDataObject
HRESULT __stdcall OleObjBase::GetData( FORMATETC * pFormatetc, STGMEDIUM * pmedium )
{
	if (pmedium == NULL)
		return E_POINTER;

	memset(pmedium, 0, sizeof(STGMEDIUM));

	if ((pFormatetc->tymed & TYMED_MFPICT) == 0)
		return DATA_E_FORMATETC;

	SIZEL sizeMetric ;
	this->GetExtent(pFormatetc->dwAspect,&sizeMetric);

	SIZE s = { sizeMetric.cx,sizeMetric.cy };
	HIMETRICtoPixel(&s);
	RECTL rectl = {0 ,0, s.cx, s.cy};

	mol::DC dc;
	dc.createMetaFile();

	dc.save();
	dc.setWindowOrgEx(0,0);
	dc.setWindowExtEx(rectl.right,rectl.bottom);
	this->OnDraw(dc,&rectl,&rectl);
	dc.restore(-1);

	HMETAFILE metafile = dc.closeMetaFile();
	if (metafile == NULL)
		return E_UNEXPECTED;

	mol::global glob;
	glob.alloc(  sizeof(METAFILEPICT), GMEM_SHARE | GMEM_MOVEABLE );

	if ( !glob )
	{
		::DeleteMetaFile(metafile);
		return ResultFromScode(STG_E_MEDIUMFULL);
	}

	LPMETAFILEPICT pMeta =(LPMETAFILEPICT)(glob.lock());
	pMeta->hMF  = metafile;
	pMeta->mm   = MM_ANISOTROPIC;
	pMeta->xExt = sizeMetric.cx;
	pMeta->yExt = sizeMetric.cy;
	glob.unLock();

	pmedium->tymed = TYMED_MFPICT;
	pmedium->hGlobal = glob;
	pmedium->pUnkForRelease = NULL;

	glob.detach();

	return S_OK;
}

HRESULT __stdcall OleObjBase::GetDataHere( FORMATETC * pFormatetc, STGMEDIUM * pmedium  )
{
	return E_NOTIMPL;
}

HRESULT __stdcall OleObjBase::QueryGetData( FORMATETC * pFormatetc )
{
	return E_NOTIMPL;
}

HRESULT __stdcall OleObjBase::GetCanonicalFormatEtc( FORMATETC * pFormatetcIn, FORMATETC * pFormatetcOut )
{
	if ( pFormatetcIn!= NULL )
	{
		pFormatetcOut = NULL;
		return DATA_S_SAMEFORMATETC;
	}
	return S_FALSE;
}

HRESULT __stdcall OleObjBase::SetData(  FORMATETC * pFormatetc,  STGMEDIUM * pmedium,  BOOL fRelease )
{
	if ( fRelease )
		::ReleaseStgMedium(pmedium);
	return E_NOTIMPL;
}

HRESULT __stdcall OleObjBase::EnumFormatEtc(  DWORD dwDirection,  IEnumFORMATETC ** ppenumFormatetc )
{
	return OLE_S_USEREG;
}

HRESULT __stdcall OleObjBase::DAdvise( FORMATETC * pFormatetc,  DWORD advf, IAdviseSink * pAdvSink, DWORD * pdwConnection )
{
	return dataAdviseHolder_->Advise(this,pFormatetc,advf,pAdvSink,pdwConnection);
}

HRESULT __stdcall OleObjBase::DUnadvise( DWORD dwConnection )
{
	return dataAdviseHolder_->Unadvise(dwConnection);
}

HRESULT __stdcall OleObjBase::EnumDAdvise( IEnumSTATDATA ** ppenumAdvise )
{
	return dataAdviseHolder_->EnumAdvise(ppenumAdvise);
}

// IOleObject
HRESULT __stdcall OleObjBase::SetHostNames( LPCOLESTR szContainerApp,LPCOLESTR szContainerObj)
{
	if ( szContainerApp )
		appname_ = mol::toString(szContainerApp);
	if ( szContainerObj )
		docname_ = mol::toString(szContainerObj);
	return S_OK;
}

HRESULT __stdcall OleObjBase::GetMiscStatus( DWORD dwAspect,DWORD *pdwStatus) 
{
	return OLE_S_USEREG;
}

HRESULT __stdcall OleObjBase::SetClientSite( IOleClientSite *pClientSite)
{
	clientSite_ = pClientSite;
	return S_OK;
}

HRESULT __stdcall OleObjBase::GetClientSite( IOleClientSite **ppClientSite)
{
	if (!clientSite_)
	{
		*ppClientSite = NULL; 
		return S_OK;
	}
	return clientSite_.queryInterface(IID_IOleClientSite,(void**)ppClientSite);
}

HRESULT __stdcall OleObjBase::Close( DWORD dwSaveOption)
{
	bool save = false;
	switch (dwSaveOption)
	{
		case OLECLOSE_SAVEIFDIRTY:
		{
			if ( this->isDirty() )
				save = true;
			break;
		}
		case OLECLOSE_NOSAVE:
		{		
			break;
		}
		case OLECLOSE_PROMPTSAVE:
		{
			LRESULT result = ::MessageBox(0,_T("Save?"),_T("Object Dirty"),MB_YESNO);
			if ( result == IDOK )
				save = true;
			break;
		}
	}		

	if ( save )
	{
		if ( clientSite_)
			clientSite_->SaveObject();
		adviseHolder_->SendOnSave();
	}
	adviseHolder_->SendOnClose();
	this->inplaceDeactivate();
	HWND hwnd = this->getOleWindow();
	if ( hwnd && ::IsWindow(hwnd) )
		::DestroyWindow(hwnd);
	return S_OK;
}

HRESULT __stdcall OleObjBase::DoVerb( LONG iVerb,
										 LPMSG lpmsg,
										 IOleClientSite *pActiveSite,
										 LONG lindex,
										 HWND hwndParent,
										 LPCRECT lprcPosRect)
{
	clientSite_ = pActiveSite;
	hwndParent_ = hwndParent;
	if ( lprcPosRect )
	{
		setRects(*lprcPosRect,*lprcPosRect);
	}

	bDirty_ = true;

	if ( iVerb == OLEIVERB_HIDE )
	{
		return OleVerb_Hide( iVerb, lpmsg, pActiveSite, lindex, hwndParent, lprcPosRect);
	}
	else if ( iVerb == OLEIVERB_SHOW  )
	{
		return OleVerb_Show( iVerb, lpmsg, pActiveSite, lindex, hwndParent, lprcPosRect);
	}
	else if ( iVerb == OLEIVERB_OPEN )
	{
		return OleVerb_Open( iVerb, lpmsg, pActiveSite, lindex, hwndParent, lprcPosRect);
	}
	else if ( iVerb == OLEIVERB_PRIMARY )
	{
		return OleVerb_Primary( iVerb, lpmsg, pActiveSite, lindex, hwndParent, lprcPosRect);
	}
	if ( iVerb == OLEIVERB_INPLACEACTIVATE )
	{
		return OleVerb_InplaceActivate( iVerb, lpmsg, pActiveSite, lindex, hwndParent, lprcPosRect);
	}
	if ( iVerb ==  OLEIVERB_UIACTIVATE )
	{
		return OleVerb_UIActivate( iVerb, lpmsg, pActiveSite, lindex, hwndParent, lprcPosRect);
	}
	if ( iVerb ==  OLEIVERB_PROPERTIES )
	{
		return OleVerb_Properties( iVerb, lpmsg, pActiveSite, lindex, hwndParent, lprcPosRect);
	}
	return OleVerb( iVerb, lpmsg, pActiveSite, lindex, hwndParent, lprcPosRect);
}

HRESULT __stdcall OleObjBase::OleVerb( LONG iVerb,
										  LPMSG lpmsg,
										  IOleClientSite *pActiveSite,
										  LONG lindex,
										  HWND hwndParent,
										  LPCRECT lprcPosRect)
{
	return S_OK;
}

HRESULT __stdcall OleObjBase::OleVerb_Primary( LONG iVerb,
												  LPMSG lpmsg,
												  IOleClientSite *pActiveSite,
												  LONG lindex,
												  HWND hwndParent,
												  LPCRECT lprcPosRect)
{
	return OleVerb_Show( iVerb, lpmsg, pActiveSite, lindex, hwndParent, lprcPosRect);
}

HRESULT __stdcall OleObjBase::OleVerb_Open( LONG iVerb,
											   LPMSG lpmsg,
											   IOleClientSite *pActiveSite,
											   LONG lindex,
											   HWND hwndParent,
											   LPCRECT lprcPosRect)
{
	return OleVerb_Show(iVerb,lpmsg,pActiveSite,lindex,hwndParent,lprcPosRect);
}


HRESULT __stdcall OleObjBase::OleVerb_Show( LONG iVerb,
											   LPMSG lpmsg,
											   IOleClientSite *pActiveSite,
											   LONG lindex,
											   HWND hwndParent,
											   LPCRECT lprcPosRect)
{
	if ( clientSite_)
	{
			clientSite_->ShowObject();
			clientSite_->OnShowWindow(TRUE);
	}
	this->inplaceActivate();
	this->uiActivate();
	return S_OK;
}

HRESULT __stdcall OleObjBase::OleVerb_Hide( LONG iVerb,
											   LPMSG lpmsg,
											   IOleClientSite *pActiveSite,
											   LONG lindex,
											   HWND hwndParent,
											   LPCRECT lprcPosRect)
{
	if ( ::IsWindow(getOleWindow()) ) 
		::ShowWindow(getOleWindow(),SW_HIDE);
	if ( clientSite_ )
	{
		if ( site_ )
			this->inplaceDeactivate();
		clientSite_->OnShowWindow(FALSE);
	}
	return S_OK;
}

HRESULT __stdcall OleObjBase::OleVerb_InplaceActivate( LONG iVerb,
														  LPMSG lpmsg,
														  IOleClientSite *pActiveSite,
														  LONG lindex,
														  HWND hwndParent,
														  LPCRECT lprcPosRect)
{
	if ( clientSite_)
	{
			clientSite_->ShowObject();
			clientSite_->OnShowWindow(TRUE);
	}
	this->inplaceActivate();
	return S_OK;
}

HRESULT __stdcall OleObjBase::OleVerb_UIActivate(	  LONG iVerb,
														  LPMSG lpmsg,
														  IOleClientSite *pActiveSite,
														  LONG lindex,
														  HWND hwndParent,
														  LPCRECT lprcPosRect)
{
	if ( clientSite_)
	{
			clientSite_->ShowObject();
			clientSite_->OnShowWindow(TRUE);
	}
	this->inplaceActivate();
	this->uiActivate();
	return S_OK;
}

HRESULT __stdcall OleObjBase::OleVerb_Properties(	  LONG iVerb,
														  LPMSG lpmsg,
														  IOleClientSite *pActiveSite,
														  LONG lindex,
														  HWND hwndParent,
														  LPCRECT lprcPosRect)
{
	this->showProperties();
	return S_OK;
}

HRESULT __stdcall OleObjBase::EnumVerbs( IEnumOLEVERB **ppEnumOleVerb)
{
	return OLE_S_USEREG;
}

HRESULT __stdcall OleObjBase::Update( void)
{
	return S_OK;
}

HRESULT __stdcall OleObjBase::IsUpToDate( void)
{
	return S_OK;
}

HRESULT __stdcall OleObjBase::GetUserClassID( CLSID *pClsid) 
{
	return E_NOTIMPL;
}

HRESULT __stdcall OleObjBase::GetUserType( DWORD dwFormOfType,LPOLESTR *pszUserType)
{
	CLSID clsid;
	if ( S_OK == this->GetUserClassID(&clsid) )
		return ::OleRegGetUserType(clsid,dwFormOfType,pszUserType);
	return E_FAIL;
	return OLE_S_USEREG ;
}

HRESULT __stdcall OleObjBase::SetExtent( DWORD dwDrawAspect,SIZEL *psizel)
{
	sizel  = *psizel;
	sendOnDataChange();	
	return S_OK;
}

HRESULT __stdcall OleObjBase::GetExtent( DWORD dwDrawAspect,SIZEL *psizel)
{
	*psizel = sizel;
	return S_OK;
}

HRESULT __stdcall OleObjBase::Advise(IAdviseSink *pAdvSink,DWORD *pdwConnection)
{
	return adviseHolder_->Advise(pAdvSink,pdwConnection);
}

HRESULT __stdcall OleObjBase::Unadvise( DWORD dwConnection) 
{
	return adviseHolder_->Unadvise(dwConnection);	
}

HRESULT __stdcall OleObjBase::EnumAdvise( IEnumSTATDATA **ppenumAdvise) 
{
	return adviseHolder_->EnumAdvise(ppenumAdvise);
}

HRESULT __stdcall OleObjBase::SetMoniker( DWORD dwWhichMoniker,IMoniker *pmk)
{
	return S_OK;
}

HRESULT __stdcall OleObjBase::GetMoniker( DWORD dwAssign,DWORD dwWhichMoniker,IMoniker **ppmk)
{
	if(!clientSite_)
		return E_UNEXPECTED;
	return clientSite_->GetMoniker( dwAssign,dwWhichMoniker,ppmk );
}

HRESULT __stdcall OleObjBase::InitFromData( IDataObject *pDataObject,BOOL fCreation,DWORD dwReserved)
{
	return E_NOTIMPL;
}

HRESULT __stdcall OleObjBase::GetClipboardData( DWORD dwReserved,IDataObject **ppDataObject)
{
	*ppDataObject  = NULL;
	return E_NOTIMPL ;
}

HRESULT __stdcall OleObjBase::SetColorScheme( LOGPALETTE *pLogpal) 
{
	return E_NOTIMPL;
}

void OleObjBase::createOleWindow( HWND hwndParent, LPCRECT lprcPosRect ) 
{}

HWND OleObjBase::getOleWindow() 
{ 
		return 0; 
};

HRESULT OleObjBase::inplaceActivate()
{
		return S_OK;
}

HRESULT OleObjBase::uiActivate()
{
		return S_OK;
}

HRESULT OleObjBase::inplaceDeactivate()
{
		return S_OK;
}

HRESULT OleObjBase::uiDeactivate()
{
		return S_OK;
}

HRESULT OleObjBase::showProperties()
{
		return S_OK;
}

HRESULT OleObjBase::OnDraw( HDC hdcDraw, LPCRECTL lprcBounds, LPCRECTL lprcMFBounds)
{
	return S_OK;
}

void OleObjBase::sendOnDataChange()
{
	if ( dataAdviseHolder_ )
		dataAdviseHolder_->SendOnDataChange(this,0,0);
	setDirty(TRUE);
}

void OleObjBase::setRects( const RECT& pos, const RECT& clip )
{
	posRect_ = pos;
	RECT r;
	::IntersectRect(&r,&posRect_,&clip);

	HWND hwnd = this->getOleWindow();
	if ( hwnd && ::IsWindow(hwnd) )
	{
		//::SetWindowPos(hwnd,0,r.left,r.top,r.right-r.left,r.bottom-r.top, SWP_NOZORDER|SWP_NOACTIVATE);
		::MoveWindow( hwnd, r.left, r.top, r.right-r.left,r.bottom-r.top, TRUE );
	}
}
/////////////////////////////////////////////////////////////////////

OleCtrlBase::OleCtrlBase() 
{
	frozen_   = false;
	uiActive_ = false;
	active_   = new OleInPlaceActiveObj(this);

	sharedMenu_ = 0;
	holemenu_ = 0;
};

void OleCtrlBase::addEditMenu(const mol::string& title, HMENU menu)
{
	editMenus_.push_back(std::make_pair(title,menu));
}

void OleCtrlBase::addObjectMenu(const mol::string& title, HMENU menu)
{
	objectMenus_.push_back(std::make_pair(title,menu));
}

void OleCtrlBase::addHelpMenu(const mol::string& title, HMENU menu)
{
	helpMenus_.push_back(std::make_pair(title,menu));
}


void OleCtrlBase::createInplaceMenu()
{
	if ( editMenus_.empty() && objectMenus_.empty() && helpMenus_.empty() )
		return;

	OLEMENUGROUPWIDTHS widths;
	for(int i= 0; i < 6; i++)
		widths.width[i] = 0;

	HMENU menu = ::CreateMenu();
	HRESULT hr = frame_->InsertMenus(menu,&widths);
	if ( hr != S_OK )
	{
		::DestroyMenu(menu);
		return;
	}

	int pos = widths.width[0];
	//Edit Menu
	for ( unsigned int i = 0; i < editMenus_.size(); i++ )
	{
		::InsertMenu(menu,(UINT)pos,MF_BYPOSITION|MF_POPUP,(UINT_PTR)editMenus_.at(i).second,editMenus_.at(i).first.c_str());
		pos++;
	}
	widths.width[1] = (LONG)editMenus_.size();

	//Object Menu
	pos += widths.width[2];
	for ( unsigned int i = 0; i < objectMenus_.size(); i++ )
	{
		::InsertMenu(menu,(UINT)pos,MF_BYPOSITION|MF_POPUP,(UINT_PTR)objectMenus_.at(i).second,objectMenus_.at(i).first.c_str());
		pos++;
	}
	widths.width[3] = (LONG)objectMenus_.size();
	//Object
	
	//Help
	pos += widths.width[4];
	for ( unsigned int i = 0; i < helpMenus_.size(); i++ )
	{
		::InsertMenu(menu,(UINT)pos,MF_BYPOSITION|MF_POPUP,(UINT_PTR)helpMenus_.at(i).second,helpMenus_.at(i).first.c_str());
		pos++;
	}
	widths.width[5] = (LONG)helpMenus_.size();

	sharedMenu_ = menu;
	holemenu_ = ::OleCreateMenuDescriptor(menu,&widths);
	refreshInplaceMenu();
}

void OleCtrlBase::refreshInplaceMenu()
{
	frame_->SetMenu(sharedMenu_,holemenu_,this->getOleWindow());
}

void OleCtrlBase::removeInplaceMenu()
{
	if ( sharedMenu_ == NULL )
		return;

	frame_->SetMenu(0,0,0);
	::OleDestroyMenuDescriptor(holemenu_);
	holemenu_ = 0;

	int c = ::GetMenuItemCount(sharedMenu_);
	for ( int i = c; i>=0; i--)
	{
		HMENU tmp = ::GetSubMenu(sharedMenu_,i);

		for ( unsigned int j = 0; j < editMenus_.size(); j++ )
		{
			if ( tmp == editMenus_.at(j).second )
			{
				::RemoveMenu(sharedMenu_,i,MF_BYPOSITION);
				break;
			}
		}
		for ( unsigned int j = 0; j < objectMenus_.size(); j++ )
		{
			if ( tmp == objectMenus_.at(j).second )
			{
				::RemoveMenu(sharedMenu_,i,MF_BYPOSITION);
				break;
			}
		}
		for ( unsigned int j = 0; j < helpMenus_.size(); j++ )
		{
			if ( tmp == helpMenus_.at(j).second )
			{
				::RemoveMenu(sharedMenu_,i,MF_BYPOSITION);
				break;
			}
		}
	}
	frame_->RemoveMenus(sharedMenu_);
	::DestroyMenu(sharedMenu_);
	sharedMenu_ = 0;

}


void OleCtrlBase::createInplaceTools()
{
	BORDERWIDTHS widths;
	::SetRectEmpty(&widths);

	if ( uiWnd_ )
		uiWnd_->SetBorderSpace(&widths);

	if ( !frame_)
		return;

	if (!renegotiateInplaceTools())
	{
		frame_->SetBorderSpace(&widths);
		return;
	}
	
}

void OleCtrlBase::removeInplaceTools()
{

}

bool OleCtrlBase::renegotiateInplaceTools()
{
	return false;
}

// IOleWIndow

HRESULT __stdcall OleCtrlBase::GetWindow( HWND *phwnd)
{
	HWND wnd = this->getOleWindow();
	if ( ::IsWindow(wnd) )
	{
		*phwnd = wnd;
		return S_OK;
	}

	*phwnd = 0;
	return E_FAIL;
}

HRESULT __stdcall OleCtrlBase::ContextSensitiveHelp( BOOL fEnterMode) 
{
	return S_OK;
}

// IOleInPlaceObject
HRESULT __stdcall OleCtrlBase::InPlaceDeactivate( void)
{
	return this->inplaceDeactivate();
}

HRESULT __stdcall OleCtrlBase::UIDeactivate( void)
{
	return this->uiDeactivate();
}

HRESULT __stdcall OleCtrlBase::SetObjectRects( LPCRECT lprcPosRect, LPCRECT lprcClipRect)
{
	setRects(*lprcPosRect,*lprcClipRect);
	return S_OK;
}

HRESULT __stdcall OleCtrlBase::ReactivateAndUndo( void)
{
	return inplaceActivate();
}

// IOleInPlaceActiveObject

HRESULT __stdcall OleCtrlBase::OleInPlaceActiveObjBase::GetWindow( HWND *phwnd)
{
	HWND wnd =ctrl_->getOleWindow();
	if ( ::IsWindow(wnd) )
	{
		*phwnd = wnd;
		return S_OK;
	}
	*phwnd = 0;
	return E_FAIL;
}

HRESULT __stdcall OleCtrlBase::OleInPlaceActiveObjBase::ContextSensitiveHelp( BOOL fEnterMode) 
{
	return S_OK;
}
 
HRESULT __stdcall OleCtrlBase::OleInPlaceActiveObjBase::TranslateAccelerator(LPMSG lpmsg) 
{
	LRESULT res = 0;
	ctrl_->OnWindowMessage(lpmsg->message,lpmsg->wParam,lpmsg->lParam,&res);
	if ( res == 0 )
		return S_FALSE ;
	else
		return S_OK;
}

HRESULT __stdcall OleCtrlBase::OleInPlaceActiveObjBase::OnFrameWindowActivate(BOOL fActivate) 
{
	return OleCtrlBase::OleInPlaceActiveObjBase::OnDocWindowActivate(fActivate);
	return S_OK;
}

HRESULT __stdcall OleCtrlBase::OleInPlaceActiveObjBase::OnDocWindowActivate(BOOL fActivate) 
{
	if ( fActivate )
	{
		if ( ctrl_->frame_ )
		{
			ctrl_->frame_->SetActiveObject(this,0);
			if ( ctrl_->sharedMenu_ )
			{
				ctrl_->frame_->SetMenu(ctrl_->sharedMenu_,ctrl_->holemenu_,ctrl_->getOleWindow());
				ctrl_->createInplaceMenu();
			}
		}
	}
	else
	{
		if ( ctrl_->frame_ )
		{
			ctrl_->frame_->SetActiveObject(0,0);
		}
	}
	return S_OK;
}

HRESULT __stdcall OleCtrlBase::OleInPlaceActiveObjBase::ResizeBorder( LPCRECT prcBorder, IOleInPlaceUIWindow *pUIWindow, BOOL fFrameWindow) 
{
	return S_OK;
}

HRESULT __stdcall OleCtrlBase::OleInPlaceActiveObjBase::EnableModeless(BOOL fEnable) 
{
	return S_OK;
}

    
// IOleInPlaceObjectWindowless
HRESULT __stdcall OleCtrlBase::OnWindowMessage( UINT msg,WPARAM wParam,LPARAM lParam, LRESULT *plResult)
{
	HWND hwnd = getWindowlessWindow();
	bool handled = true;
	*plResult = this->wndlessProc(hwnd,msg,wParam,lParam,handled);
	if ( handled )
		return S_OK;
	return S_FALSE;
}
HRESULT __stdcall OleCtrlBase::GetDropTarget( IDropTarget **ppDropTarget)
{
	return E_NOTIMPL;
}

// IOleControl
HRESULT __stdcall OleCtrlBase::GetControlInfo( CONTROLINFO *pCI) 
{
	return E_NOTIMPL ;
}

HRESULT __stdcall OleCtrlBase::OnMnemonic( MSG *pMsg) 
{
	return E_NOTIMPL ;
}

HRESULT __stdcall OleCtrlBase::OnAmbientPropertyChange( DISPID dispID) 
{
	return S_OK;
}

HRESULT __stdcall OleCtrlBase::FreezeEvents( BOOL bFreeze) 
{
	frozen_ = ( (bFreeze == TRUE) ? true : false );
	return S_OK;
}
    
// ISpecifyPropertyPages
HRESULT __stdcall OleCtrlBase::GetPages( CAUUID *pPages) 
{
	initPropPages();

	pPages->cElems = (LONG)clsids_proppages_.size();
	pPages->pElems = 0;

	if ( clsids_proppages_.size() >  0 )
	{
		GUID* pGuids = (GUID*)::CoTaskMemAlloc(sizeof(GUID)*clsids_proppages_.size());

		int i = 0;
		for ( std::set<const CLSID*>::iterator it = clsids_proppages_.begin(); 
			  it != clsids_proppages_.end(); it++ )
		{
			pGuids[i] = *(*it);
			i++;
		}
		pPages->pElems = pGuids;
	}
	return S_OK;
}

HRESULT OleCtrlBase::createPropFrame(const mol::string& title, int x, int y)
{
	initPropPages();
	if ( clsids_proppages_.size() >  0 )
	{
		GUID* pGuids = new GUID[clsids_proppages_.size()];

		int i = 0;
		for ( std::set<const CLSID*>::iterator it = clsids_proppages_.begin(); 
			  it != clsids_proppages_.end(); it++ )
		{
			pGuids[i] = *(*it);
			i++;
		}

		std::wstring ws = mol::towstring(title);

		IUnknown* unknown = (ISpecifyPropertyPages*)this;
		if ( this->windowed_ )
			::OleCreatePropertyFrame( this->getOleWindow(),
			                          x,y,ws.c_str(),1,
									  &unknown,
									  (ULONG)clsids_proppages_.size(),pGuids,
									  LOCALE_SYSTEM_DEFAULT,0,0);
		else
			::OleCreatePropertyFrame( this->getWindowlessWindow(),
									  x,y,ws.c_str(),1,
									  &unknown,
									  (ULONG)clsids_proppages_.size(),pGuids,
									  LOCALE_SYSTEM_DEFAULT,0,0);
		delete[] pGuids;
	}
	return S_OK;
}

void OleCtrlBase::initPropPages()
{

}
// Inplaceactivation

HRESULT OleCtrlBase::inplaceActivate()
{
	RECT rPos,rClip;
	if (!clientSite_)
		return E_FAIL;

	if ( site_ )
	{
		return S_OK;
	}

	if ( !site_ )
	{
		//HRESULT hr = clientSite_.queryInterface(IID_IOleInPlaceSite,(void**)&site_);
		HRESULT hr = clientSite_.queryInterface(&site_);
		if ( hr != S_OK )
		{	
			return hr;
		}
	}

	HRESULT hr = site_->CanInPlaceActivate();
	if (hr != S_OK )
	{
		site_.release();
		return hr;
	}

	if ( (!siteWindowless_) && (windowed_ == false) )
	{
		windowed_ = true;
		//HRESULT hr = clientSite_.queryInterface( IID_IOleInPlaceSiteWindowless, (void**)&siteWindowless_);
		HRESULT hr = clientSite_.queryInterface( &siteWindowless_);
		if ( hr == S_OK )
		{
			if ( S_OK == siteWindowless_->CanWindowlessActivate() )
			{
				windowed_ = false;
				if ( S_OK != siteWindowless_->OnInPlaceActivateEx(NULL,ACTIVATE_WINDOWLESS) )
					return E_FAIL;
			}
		}
	}
	if ( windowed_ == true )
		site_->OnInPlaceActivate();

	HWND parent = 0;
	hr = site_->GetWindow(&parent);
	if (hr != S_OK )
	{
		site_.release();
		return hr;
	}

	frame_.release();
	uiWnd_.release();

	OLEINPLACEFRAMEINFO oipfi;
	::ZeroMemory(&oipfi,sizeof(oipfi));
	oipfi.cb = sizeof(oipfi);

	hr = site_->GetWindowContext(&frame_,&uiWnd_,&rPos,&rClip,&oipfi);
	if (hr != S_OK )
	{
		site_.release();
		return hr;
	}

	if ( !::IsWindow(getOleWindow() ) )
		createOleWindow(parent,&rPos,&rClip);

	HWND hwnd = getOleWindow();
	if ( ::IsWindow(getOleWindow() ) )
	{
		::SetParent(hwnd,parent);
		::ShowWindow(hwnd,SW_SHOW);
		::SetWindowPos(hwnd,HWND_TOP,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
		//::SetActiveWindow(hwnd);
		::SetFocus(hwnd);
	}
	clientSite_->ShowObject();
	if ( site_)
	{
		punk<IOleControlSite> iocs;//(site_);
		//if ( S_OK == site_.queryInterface(IID_IOleControlSite,(void**)&iocs) )
		if ( S_OK == site_.queryInterface(&iocs) )
			if ( iocs )
				iocs->OnFocus(TRUE);
		::SetFocus(hwnd);
	}
	return hr;
}
HRESULT OleCtrlBase::uiActivate()
{
	if ( uiActive_ )
		return S_OK;

	uiActive_ = true;
	if ( site_ )
		site_->OnUIActivate();

	if ( frame_ )
	{
		active_->AddRef();
		frame_->SetActiveObject((active_),0);
	}
	if ( uiWnd_ )
	{
		active_->AddRef();
		uiWnd_->SetActiveObject((active_),0);
	}
	
	HWND hwnd = getOleWindow();
	if ( ::IsWindow(hwnd ) )
	{
		::SetWindowPos(hwnd,HWND_TOP,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	}
	this->createInplaceMenu();
	return S_OK;
}

HRESULT OleCtrlBase::inplaceDeactivate()
{
	uiDeactivate();
	HWND wnd = getOleWindow();
	if ( ::IsWindow(wnd) )
		::ShowWindow(wnd,SW_HIDE);

	if ( site_ )
	{
		if ( siteWindowless_)
		{
			siteWindowless_->OnInPlaceDeactivateEx(TRUE);
		}
		else
			site_->OnInPlaceDeactivate();
	}
	if ( frame_ )
	{
		frame_.release();
	}
	if ( uiWnd_ )
	{
		uiWnd_.release();
	}
	if ( site_ )
	{
		site_.release();
	}
	if ( siteWindowless_ )
	{
		siteWindowless_.release();
	}
	if ( ::IsWindow(getOleWindow() ) )
		::SetWindowPos(getOleWindow(),HWND_BOTTOM,0,0,0,0,SWP_NOACTIVATE|SWP_NOMOVE|SWP_NOSIZE);

	return S_OK;
}

HRESULT OleCtrlBase::uiDeactivate()
{
	this->removeInplaceMenu();

	if ( frame_ )
	{
		frame_->SetActiveObject(0,0);
	}
	if ( uiWnd_ )
	{
		uiWnd_->SetActiveObject(0,0);
	}
	if ( site_ )
	{
		site_->OnUIDeactivate(TRUE);
	}

	uiActive_ = false;
	return S_OK ;
}

HWND OleCtrlBase::getWindowlessWindow()
{
	if ( siteWindowless_ )
	{
		HWND hwnd = 0;
		if ( S_OK == siteWindowless_->GetWindow(&hwnd) )
			return hwnd;
	}
	return 0;
}

void OleCtrlBase::freeze(bool f)
{
	frozen_ = f;
}

bool OleCtrlBase::frozen()
{
	return frozen_;
}

/////////////////////////////////////////////////////////////////////
// ViewObjectEx
/////////////////////////////////////////////////////////////////////

HRESULT __stdcall ViewObj2Base::Draw( DWORD dwDrawAspect, LONG lindex, void *pvAspect,DVTARGETDEVICE *ptd, HDC hdcTargetDev, HDC hdcDraw,LPCRECTL lprcBounds,LPCRECTL lprcWBounds, BOOL (__stdcall *)(ULONG_PTR), ULONG_PTR dwContinue) 
{
	return S_OK;
}
    
HRESULT __stdcall ViewObj2Base::GetColorSet( DWORD dwDrawAspect, LONG lindex, void *pvAspect, DVTARGETDEVICE *ptd, HDC hicTargetDev, LOGPALETTE **ppColorSet)
{
	*ppColorSet = NULL;
	return S_OK;
}
    
HRESULT __stdcall ViewObj2Base::Freeze( DWORD dwDrawAspect, LONG lindex,void *pvAspect,DWORD *pdwFreeze)
{
	return S_OK;
}
    
HRESULT __stdcall ViewObj2Base::Unfreeze( DWORD dwFreeze)
{
	return S_OK;
}
    
HRESULT __stdcall ViewObj2Base::SetAdvise( DWORD aspects, DWORD advf, IAdviseSink *pAdvSink)
{
	if ( pAdvSink == 0 )
	{
		adviseSink_.release();
		return S_OK;	
	}
	adviseAspect_ = aspects;
	adviseAdvf_   = advf;
	adviseSink_   = pAdvSink;
	return S_OK;
}
    
HRESULT __stdcall ViewObj2Base::GetAdvise( DWORD *pAspects, DWORD *pAdvf,IAdviseSink **ppAdvSink)
{
	if (!adviseSink_)
	{
		*ppAdvSink = NULL;
		return S_OK;
	}
	if ( pAspects )
		*pAspects = adviseAspect_;
	if ( pAdvf )
		*pAdvf    = adviseAdvf_;

	return adviseSink_.queryInterface(IID_IAdviseSink,(void**)ppAdvSink);
}
   
HRESULT __stdcall ViewObj2Base::GetExtent( DWORD dwAspect, LONG lindex, DVTARGETDEVICE *ptd,  LPSIZEL lpsizel )
{
	return S_OK;
}

void ViewObj2Base::sendOnViewChange()
{
	if ( adviseSink_ )
		adviseSink_->OnViewChange(DVASPECT_CONTENT,-1);
}

} // end namespace mol::win::ole
} // end namespace mol