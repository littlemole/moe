#ifndef MOL_OLE_HOST_DEF_GUARD_
#define MOL_OLE_HOST_DEF_GUARD_

#pragma once
#include "util/uni.h"
#include "win/Wnd.h"
#include "win/dlg.h"
#include "ole/ole.h"
#include "ole/storage.h"
#include "ole/punk.h"
#include <mshtmhst.h>
#include <servprov.h>
#include <ocidl.h>

#include "ole/axhostimpl.h"

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// ActiveX Frame
//////////////////////////////////////////////////////////////////////

namespace mol {
//////////////////////////////////////////////////////////////////////
// AX Base Frame Wnd
//
// 
//////////////////////////////////////////////////////////////////////

template<class C, class W>
class AxFrame : public W 
{
	friend class mol::ole::AxFrameImpl<C>;
public:

	typedef com_obj<mol::ole::AxFrameImpl<C>> AxFrameSite;

	punk<AxFrameSite>				axFrameSite;
	punk<IOleInPlaceActiveObject>	activeObject;

	////////////////////////////////////////////////////////////////

    AxFrame()
	{
		axFrameSite = new AxFrameSite;
		axFrameSite->init( (C*)this );
		borderwidths_ = mol::Rect( 0,0,0,0 );
	}

    ~AxFrame()
	{
	}

	////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////
	// COM impl
	////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////

protected:

    // IOleInPlaceFrame
    HRESULT virtual __stdcall IOleInPlaceFrame_GetWindow( HWND FAR* lphwnd)
	{
		C* that = (C*)this;
		*lphwnd = (HWND)(*that);
		return S_OK;
	}
    HRESULT virtual __stdcall IOleInPlaceFrame_ContextSensitiveHelp( BOOL fEnterMode)
	{
		return E_NOTIMPL ;
	}

    HRESULT virtual __stdcall IOleInPlaceFrame_GetBorder( LPRECT lprectBorder)
	{
		ODBGS("IOleInPlaceFrame_SetBorderSpace - E_NOTIMPL");
		return E_NOTIMPL ;
	}
    HRESULT virtual __stdcall IOleInPlaceFrame_RequestBorderSpace( LPCBORDERWIDTHS pborderwidths)
	{
		ODBGS("IOleInPlaceFrame_RequestBorderSpace - E_NOTIMPL");
		return E_NOTIMPL ;
	}
    HRESULT virtual __stdcall IOleInPlaceFrame_SetBorderSpace( LPCBORDERWIDTHS pborderwidths)
	{
		ODBGS("IOleInPlaceFrame_SetBorderSpace - E_NOTIMPL");
		return E_NOTIMPL ;
	}
    HRESULT virtual __stdcall IOleInPlaceFrame_SetActiveObject( IOleInPlaceActiveObject *pActiveObject, LPCOLESTR pszObjName)
	{
		activeObject = pActiveObject;
		if ( activeObject )
		{
			ODBGS1("IOleInPlaceFrame_SetActiveObject",pActiveObject);
		}
		else
		{
			ODBGS1("IOleInPlaceFrame_SetActiveObject",pActiveObject);
			borderwidths_ = mol::Rect(0,0,0,0);
		}
		return S_OK;
	}
    HRESULT virtual __stdcall IOleInPlaceFrame_InsertMenus( HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidths)
	{
		return E_NOTIMPL;
	}
    HRESULT virtual __stdcall IOleInPlaceFrame_SetMenu( HMENU hmenuShared, HOLEMENU holemenu, HWND hwndActiveObject)
	{
		return S_OK ;
	}
    HRESULT virtual __stdcall IOleInPlaceFrame_RemoveMenus( HMENU hmenuShared)
	{
		return S_OK ;
	}
    HRESULT virtual __stdcall IOleInPlaceFrame_SetStatusText( LPCOLESTR pszStatusText)
	{
		return S_OK ;
	}
    HRESULT virtual __stdcall IOleInPlaceFrame_EnableModeless( BOOL fEnable)
	{
		return S_OK ;
	}
    HRESULT virtual __stdcall IOleInPlaceFrame_TranslateAccelerator( LPMSG lpmsg, WORD wID)
	{
		return E_NOTIMPL ;
	}

    HRESULT virtual __stdcall  IOleCommandTarget_QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText)
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

    HRESULT virtual __stdcall  IOleCommandTarget_Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANTARG *pvaIn, VARIANTARG *pvaOut)
	{
		return S_OK;
	}

	////////////////////////////////////////////////////////////////

protected:
	RECT borderwidths_;
	mol::Rect clientRect_;
};

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// OleFrame - adds merging of ole menus and toolbars
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

template<class C, class W>
class OleContainer : public AxFrame<C,W>
{
	friend class mol::ole::AxFrameImpl<C>;
public:
	typedef std::pair<std::string,HMENU> namedMenu;

	OleContainer()
	{
		nMenus_			= 0;
		phMenus_		= 0;
		nHelpMenuItems_ = 0;
		deactivated_	= false;
		activating_		= false;
	}

	~OleContainer()
	{
		ODBGS("OleFrame died ;)");
	}

	//////////////////////////////////////////////////////////

public:

	void addFileMenu( HMENU m, const std::string& txt )
	{
		fileMenus_.push_back(std::make_pair(txt,m));
	}
	void addEditMenu( HMENU m, const std::string& txt )
	{
		editMenus_.push_back(std::make_pair(txt,m));
	}
	void addViewMenu( HMENU m, const std::string& txt)
	{
		viewMenus_.push_back(std::make_pair(txt,m));
	}
	void addObjectMenu( HMENU m, const std::string& txt )
	{
		objectMenus_.push_back(std::make_pair(txt,m));
	}
	void addWindowMenu( HMENU m, const std::string& txt )
	{
		windowMenus_.push_back(std::make_pair(txt,m));
	}
	void addHelpMenu( HMENU m, const std::string& txt )
	{
		helpMenus_.push_back(std::make_pair(txt,m));
		if ( helpMenus_.size() )
			nHelpMenuItems_ = ::GetMenuItemCount(helpMenus_[0].second);
		else
			nHelpMenuItems_ = 0;
	}

	void addOlExecHandler( int oleCmdId, UINT cmd, GUID* cmdGroup = 0  )
	{
		OleCmd olecmd(cmd,cmdGroup,oleCmdId);
		this->oleCmds_.push_back(olecmd);
	}

	////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////
	// COM impl
	////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////

protected:

    HRESULT virtual __stdcall IOleInPlaceFrame_GetBorder( LPRECT lprectBorder)
	{
		mol::Rect r = clientRect_;
		if ( this->layout_ )
			r = layout_->availBorderRect(r);

		*lprectBorder = r;
		return S_OK;
	}

    HRESULT virtual __stdcall IOleInPlaceFrame_RequestBorderSpace( LPCBORDERWIDTHS pborderwidths)
	{
		HRESULT hr = S_OK;
		RECT r = clientRect_;
		// We tell objects they can't have more than 50% of client area...
		if ((pborderwidths->left + pborderwidths->right > r.right/2) ||
			(pborderwidths->top + pborderwidths->bottom > r.bottom/2))
		{
			hr = INPLACE_E_NOTOOLSPACE;
		}
		return hr;
	}

    HRESULT virtual __stdcall IOleInPlaceFrame_SetBorderSpace( LPCBORDERWIDTHS pborderwidths)
	{		
	    if (pborderwidths )
		{
			ODBGS1(" SetBorderSpace - new top: ",pborderwidths->top);
			if ( borderwidths_.left == pborderwidths->left && borderwidths_.top == pborderwidths->top &&
				borderwidths_.right == pborderwidths->right && borderwidths_.bottom == pborderwidths->bottom )
			return S_OK;

			borderwidths_ = *pborderwidths;
			if ( borderwidths_.left == 0 && borderwidths_.top == 0 &&
				borderwidths_.right == 0 && borderwidths_.bottom == 0 )
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
			borderwidths_ = mol::Rect(0,0,0,0);
		}
		
		doLayout();
		show(SW_SHOW);
		ODBGS("<------IOleInPlaceFrame_SetBorderSpace END");

		return S_OK;
	}


	HRESULT virtual __stdcall IOleInPlaceFrame_InsertMenus( HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidths)
	{
		int nMenus = fileMenus_.size() + editMenus_.size() + viewMenus_.size() + objectMenus_.size() + windowMenus_.size() + helpMenus_.size();

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
		lpMenuWidths->width[0] = fileMenus_.size(); // File
		lpMenuWidths->width[2] = viewMenus_.size(); // View
		lpMenuWidths->width[4] = windowMenus_.size(); // Window

		// Groups handled by the server...
		lpMenuWidths->width[1] = editMenus_.size(); // Edit
		lpMenuWidths->width[3] = objectMenus_.size(); // Object/Insert
		lpMenuWidths->width[5] = helpMenus_.size(); // Help

		return S_OK;
	}

    HRESULT virtual __stdcall IOleInPlaceFrame_SetMenu( HMENU hmenuShared, HOLEMENU holemenu, HWND hwndActiveObject)
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

		if ( !isMidi_ )
		{
			::SetMenu( *this, hMenuActive_ );
		}
		else
		{
			HMENU wm;
			wm = this->windowMenus_[0].second;
			this->setMenu( hMenuActive_, wm );
		}

		HRESULT hr = ::OleSetMenuDescriptor(holemenu, *this, hwndActiveObject, NULL, NULL);

		::DrawMenuBar(*((C*)this));
		return hr;
	}

    HRESULT virtual __stdcall IOleInPlaceFrame_RemoveMenus( HMENU hmenuShared)
	{
		UINT    cItems;
		HMENU   hMenuTemp;

		if (!(hmenuShared) || (0 == (cItems = ::GetMenuItemCount(hmenuShared))))
			return S_OK;

		// Remove our added menus (in reverse order, since we remove by position)...
		for (int i = cItems; i >= 0; i--)
		{
			hMenuTemp = ::GetSubMenu(hmenuShared, i);

			if (hMenuTemp == helpMenus_[0].second )
			{
				for (int k = nHelpMenuItems_; k < GetMenuItemCount(hMenuTemp); k++)
				{
					char buf[256];
					::GetMenuString(hMenuTemp,k,buf,256,MF_BYPOSITION);
					RemoveMenu(hMenuTemp, k, MF_BYPOSITION);
				}
			}

			for (int j = 0; j < nMenus_; j++)
			{
				if (hMenuTemp == phMenus_[j])
				{
					char buf[256];
					::GetMenuString(hmenuShared,j,buf,256,MF_BYPOSITION);
					RemoveMenu(hmenuShared,i, MF_BYPOSITION);
					break;
				}
			}
	        
		}
		return S_OK;
	}

    HRESULT virtual __stdcall  IOleCommandTarget_QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText)
	{
		if (pguidCmdGroup != NULL)
			return OLECMDERR_E_UNKNOWNGROUP;
				
		if (prgCmds == NULL)
			return E_INVALIDARG;

		for (int i = 0; i < (int)cCmds; i++) 
		{
			prgCmds[i].cmdf = 0;
			int s = oleCmds_.size();
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
    HRESULT virtual __stdcall  IOleCommandTarget_Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANTARG *pvaIn, VARIANTARG *pvaOut)
	{
		if (pguidCmdGroup != NULL)
			return OLECMDERR_E_UNKNOWNGROUP;
		    
		if (nCmdexecopt == MSOCMDEXECOPT_SHOWHELP)
			return OLECMDERR_E_NOHELP;
	
		int nCmds = oleCmds_.size();
		for ( int c = 0; c < nCmds; c++ )
		{
			if ( oleCmds_[c].cmdGroup_ == pguidCmdGroup )
			if ( oleCmds_[c].oleCmdId_ == nCmdID )
			{
				::PostMessage(*this, WM_COMMAND, oleCmds_[c].cmdId_, 0); 
				return S_OK;
			}
		}
		return OLECMDERR_E_NOTSUPPORTED; 
	}

	//////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////

public:

    virtual LRESULT wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
		switch ( message )
		{
			case WM_EXITSIZEMOVE:
			{
				// end of sizing action
				// re-negotiate toolspace and repaint everything
				ODBGS("OleContainer::WM_EXITSIZEMOVE");
				if (activeObject)
				{
					mol::Rect r = clientRect_;
					if ( layout_ )
						r = layout_->availBorderRect(r);
					activeObject->ResizeBorder( &r, axFrameSite,TRUE);
				}
				doLayout();
				redraw();
				return 0;
			}
			case WM_ACTIVATEAPP :
			{
				//deactivation
				if ( activeObject && !wParam)
				{
					// set de-activation flags
					activating_  = false;
					deactivated_ = true;
					ODBGS("OleContainer::WM_ACTIVATEAPP FALSE");					
					return 0;
				}
				if ( activeObject && wParam)
				{
					// now activating
					activating_ = true;
					ODBGS("OleContainer::WM_ACTIVATEAPP TRUE");
					return 0;

				}
				return 0;
			}
			case WM_CLOSE :
			{
				// release COM stuff before HWND dies
				activeObject.release();
				axFrameSite.release();
				return W::wndProc(hWnd,  message,  wParam,  lParam);
			}
		}
		return W::wndProc(hWnd, message, wParam, lParam );
	}

	//////////////////////////////////////////////////////////

	LRESULT OnSize( UINT msg, WPARAM wParam, LPARAM lParam)
	{
		ODBGS("OleContainer::OnSize");

		// track zero size (EXCEL!) - assume we are deactivating
		if ( LOWORD (lParam) == 0 && HIWORD (lParam) == 0 )
		{
			deactivated_ = true;
			ODBGS("<-------OleContainer::OnSize END");
			return 0;
		}

		// get new width and height
		clientRect_ = mol::Rect(0,0,0,0);
		clientRect_.right  = LOWORD (lParam) ;
		clientRect_.bottom = HIWORD (lParam) ;		
		ODBGS1("new width :",clientRect_.right);
		ODBGS1("new height:",clientRect_.bottom);

		mol::Rect r = clientRect_;

		// need layout
		if ( layout_ )
		{		
			if ( activeObject )
			{			
				// are we just restoring the wnd after minimize?
				if ( deactivated_ && activating_)
				{
					// reset de-activation flags
					deactivated_ = false;
					activating_ = false;
					ODBGS("activeObject->OnFrameWindowActivate(TRUE)");

					// resize our own toolbars now
					layout_->resize(wParam,lParam);
					ODBGS("<-------OleContainer::OnSize END");
					return 0;
				}
				// resize event
				ODBGS("activeObject->ResizeBorder()");
				
				//resize our toolbars
				layout_->resize(wParam,lParam);

				//re-regotiate toolspace
				r = layout_->availBorderRect(clientRect_);
				activeObject->ResizeBorder( &r, axFrameSite,TRUE);
				doLayout();
				ODBGS("<-------OleContainer::OnSize END");
				return 0;
			}

			// no active object, have to do re-layout on our own
			layout_->resize(wParam,lParam);
		}
		doLayout();
		ODBGS("<-------OleContainer::OnSize END");
		return 0;
	}

	//////////////////////////////////////////////////////////

	LRESULT OnLayout( UINT message, WPARAM wParam, LPARAM lParam)
	{
		ODBGS("OleContainer::OnLayout");
		getClientRect(clientRect_);

		// renegotiate toolspace
		mol::Rect r = clientRect_;
		if ( layout_ && activeObject )
		{
			layout_->resize(0,MAKELPARAM(clientRect_.right,clientRect_.bottom));
			r = layout_->availBorderRect(clientRect_);
			activeObject->ResizeBorder( &r, axFrameSite,TRUE);
		}

		doLayout();
		ODBGS("<-------OleContainer::OnLayout END");
		return 0;
	}


	HWND createWindow( const mol::string& windowName, int id, const mol::Rect& r, HWND parent )
	{
		W::createWindow( windowName, id, r, parent );

		getClientRect( clientRect_);
		origMenu_= ::GetMenu(*this);

		return hWnd_;
	}
protected:
	
	// layout helper, takes allocated borderwith into account
	LRESULT doLayout()
	{
		ODBGS1("OleContainer::doLayout ",activeObject.interface_);
		mol::Rect r = clientRect_;
		if ( layout_ )
			r = layout_->availClientRect(r);

		r.top += borderwidths_.top;
		r.bottom -= borderwidths_.top;

		r.left += borderwidths_.left;
		r.right -= borderwidths_.left;

		r.bottom -= borderwidths_.bottom;
		r.right -= borderwidths_.right;

		if ( layout_ )
			layout_->layout(r);

		ODBGS("<------OleContainer::doLayout END");
		return 0;
	}

private:

	void insertOleMenues( HMENU shared, std::vector<namedMenu>& v )
	{
		for ( unsigned int i = 0; i < v.size(); i++ )
		{
			phMenus_[nMenus_+i] = v[i].second;
			int index = nMenus_ + i;
			::InsertMenu( shared, index, MF_BYPOSITION | MF_POPUP,(UINT_PTR)v[i].second, v[i].first.c_str() );
		}
		nMenus_ += v.size();
	}

protected:

	std::vector<namedMenu> fileMenus_;
	std::vector<namedMenu> editMenus_;
	std::vector<namedMenu> viewMenus_;
	std::vector<namedMenu> objectMenus_;
	std::vector<namedMenu> windowMenus_;
	std::vector<namedMenu> helpMenus_;

	HMENU* phMenus_;
	HMENU origMenu_;
	HMENU hMenuActive_;

	int nMenus_;
	int nHelpMenuItems_;

	bool activating_;
	bool deactivated_;


	struct OleCmd {

		OleCmd( UINT cmdId, GUID* cmdGroup = &GUID_NULL, int oleCmdId = 0 )
			: cmdId_(cmdId),
			  cmdGroup_(cmdGroup),
			  oleCmdId_(oleCmdId)

		{}

		UINT cmdId_;
		GUID* cmdGroup_;
		int oleCmdId_;
	};

	std::vector<OleCmd> oleCmds_;
};

//////////////////////////////////////////////////////////////////////
// AX Client Wnd
//////////////////////////////////////////////////////////////////////

template<class C, class W>
class AxClientWnd : public W
{
	friend class mol::ole::AxClientSiteImpl<C,W>;
public:

	// the ole client site
	typedef com_obj<mol::ole::AxClientSiteImpl<C,W>> AxClientSite;
	punk<AxClientSite> axClientSite;

	// the ole frame
	punk<IOleInPlaceFrame> oleFrame;

	// the embedded object
    punk<IOleObject>	 oleObject;

	// the embedded objects view
	punk<IOleDocumentView> documentView;

	// active object
	punk<IOleInPlaceActiveObject> activeObject;

public:

    AxClientWnd()
	{
		axClientSite = new AxClientSite;
		frameWnd_ = 0;
		eraseBackground_ = 1;
		dummyFrame_ = 0;
		isInplaceActive_ = false;;
		isUIActive = false;
		isShuttingDown_ = false;
	}

    ~AxClientWnd()
	{
		ODBGS("AxClientWnd died :o");
		delete dummyFrame_;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	template<class T>
    HWND create( mol::string windowName, int id=0, const Rect& r=stdRect, T* frame = 0 )
	{
		C* This = (C*)this;
		return This->createWindow( windowName, id, r, frame );
	}

	template<class T>
    HWND create( int id=0, const Rect& r=stdRect, T* frame = 0 )
	{
		return create(  _T(""), id, r, frame );
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	template<class T>
	HWND createWindow( const mol::string& windowName, int id, const mol::Rect& r, T* frame )
	{
		W::createWindow( windowName, id, r, (HWND)(*frame) );

		getClientRect( clientRect_);
		frameWnd_ = (HWND)(*frame);
		oleFrame  = (IOleInPlaceFrame*)(frame->axFrameSite);
		return hWnd_;
	}

	HWND createWindow( const mol::string& windowName, int id, const mol::Rect& r, HWND frame )
	{
		W::createWindow( windowName, id, r, frame );

		getClientRect( clientRect_);
		frameWnd_ = frame;
		oleFrame  = 0;
		return hWnd_;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

public:

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool loadObjectFromStorage( REFCLSID iid, IStorage* store )
	{
		// embedd the COM server
		if ( !instantiateObject(iid) )
			return false;

		// load object from structured storage
		try
		{	
			mol::punk<IPersistStorage> ps(oleObject);
			if ( ps )
			{
				HRESULT hr;
				mol::punk<IStorage> s;
				hr = copyStorageTemp(store,&s);
				if ( hr == S_OK && s )
				{
					hr = ps->Load(s);
					if ( hr == S_OK )
						if (embeddObject())
							return true;
				}
			}
		}
		catch (mol::X x)
		{
			oleObject->Close(OLECLOSE_NOSAVE);
			throw x;
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	// load object from stream
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool loadObjectFromStream( REFCLSID iid, IStream* stream)
	{
		// embedd the COM server
		if ( !instantiateObject(iid) )
			return false;

		if (!embeddObject())
			return false;
		
		// try to load via IPersistStreamInit
		try
		{	
			mol::punk<IPersistStream> ps(oleObject);
			if ( !ps )
				return false;
			
			if ( S_OK == ps->Load(stream) )
					return true;
		}
		catch (mol::X x)
		{
			oleObject->Close(OLECLOSE_NOSAVE);
			throw x;
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	// load object from plain file
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool loadObjectFromPersistFile( REFCLSID iid, const std::string& file)
	{
		// embedd the COM server
		if ( !instantiateObject(iid) )
			return false;

		if (!embeddObject())
			return false;

		// try to load via IPersistFile
		try
		{	
			mol::punk<IPersistFile> pf(oleObject);
			if ( !pf )
				return false;
			
			if ( S_OK == pf->Load(mol::bstr(file),STGM_READWRITE))
				return true;
		}
		catch (mol::X x)
		{
			oleObject->Close(OLECLOSE_NOSAVE);
			throw x;
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool newObjectFromStorage( REFCLSID iid )
	{
		// embedd the COM server
		if ( !instantiateObject(iid) )
			return false;

		// load object from structured storage
		try
		{	

			mol::TCHAR  path[MAX_PATH];
			mol::TCHAR file[MAX_PATH];
			::GetTempPath(255,path);
			::GetTempFileName( path, _T("new_"), 0, file );
	
			punk<IStorage> store;
			if ( S_OK == ::StgCreateDocfile( mol::towstring(file).c_str(), STGM_TRANSACTED|STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE,0,&store) )
			{
				mol::punk<IPersistStorage> ps(oleObject);
				if ( ps )
				{
					if ( S_OK == ps->InitNew(store) )
					{
						if (!embeddObject())
							return false;

						return true;
					}
				}
			}
		}
		catch (mol::X x)
		{
			oleObject->Close(OLECLOSE_NOSAVE);
			throw x;
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool loadObjectFromShell( const std::string& file)
	{
		if ( !instantiateObject(CLSID_WebBrowser) )
			return false;

		try
		{	
			if (!embeddObject())
				return false;

			HRESULT hr;
			mol::punk<IWebBrowser2> wb(oleObject);
			if (!wb)
				return false;

			mol::variant v(file);
			hr = wb->Navigate2( &v,0,0,0,0);
			if ( hr == S_OK )
			{
				return true;
			}
			return false;
		}
		catch (mol::X x)
		{
			oleObject->Close(OLECLOSE_NOSAVE);
			throw x;
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool loadObject( REFCLSID iid )
	{
		if ( instantiateObject( iid ) )
			if ( embeddObject() )
				return true;
		return false;
	}

	bool loadObjectFromMoniker( const std::string& path )
	{
		CLSID clsid; 
		std::wstring			file(mol::ansi2wstring(path));
		punk<IMoniker>			moniker;

		// get a file moniker
		HRESULT hr = ::CreateFileMoniker(file.c_str(), &moniker);
		if (hr != S_OK) 
			return false;

		// get CLSID
		hr = ::GetClassFile(file.c_str(), &clsid);
		if (hr != S_OK) 
			return false;

		// instantiate but not create
		if (!instantiateObject(clsid,false))
			return false;

		// prepare bind ctx	
		BIND_OPTS bopts = {sizeof(BIND_OPTS), BIND_MAYBOTHERUSER, 0, 10000};
	    bopts.grfMode = (STGM_TRANSACTED | STGM_SHARE_DENY_WRITE | STGM_READWRITE);

		punk<IBindCtx> ctx;
		::CreateBindCtx(0,&ctx);
		ctx->SetBindOptions(&bopts);

		// bind the object
		hr = moniker->BindToObject(ctx,NULL,IID_IOleObject,(void**)&oleObject);
		if ( hr != S_OK )
			return false;

		// embedd it
		return embeddObject();
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	// COM impl
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

protected:
    // IOleInPlaceUIWindow
    HRESULT virtual __stdcall IOleInPlaceUIWindow_GetWindow( HWND FAR* lphwnd)
	{
		C* that = (C*)this;
		*lphwnd = (HWND)(*that);
		return S_OK;
	}
    HRESULT virtual __stdcall IOleInPlaceUIWindow_ContextSensitiveHelp( BOOL fEnterMode)
	{
		return E_NOTIMPL ;
	}

    HRESULT virtual __stdcall IOleInPlaceUIWindow_GetBorder( LPRECT lprectBorder)
	{
		return E_NOTIMPL ;
	}
    HRESULT virtual __stdcall IOleInPlaceUIWindow_RequestBorderSpace( LPCBORDERWIDTHS pborderwidths)
	{
		return E_NOTIMPL ;
	}
    HRESULT virtual __stdcall IOleInPlaceUIWindow_SetBorderSpace( LPCBORDERWIDTHS pborderwidths)
	{
		return E_NOTIMPL ;
	}
    HRESULT virtual __stdcall IOleInPlaceUIWindow_SetActiveObject( IOleInPlaceActiveObject *pActiveObject, LPCOLESTR pszObjName)
	{
		ODBGS("IOleInPlaceUIWindow_SetActiveObject");
		activeObject = pActiveObject;
		return S_OK;
	}

	// IOleDocumentSite Implementation
	HRESULT virtual __stdcall  IOleDocumentSite_ActivateMe(IOleDocumentView* pViewToActivate)
	{
		HRESULT          hr   = E_FAIL;
		IOleDocument*    piod = NULL;
		RECT             rc;    
		GetClientRect(*((W*)this), &rc);

		if (pViewToActivate)
		{
			pViewToActivate->SetInPlaceSite(static_cast<IOleInPlaceSite*>(axClientSite));
			documentView = pViewToActivate;
		}
		else
		{
			documentView.release();
			if ((!this->oleObject) || FAILED(this->oleObject->QueryInterface(IID_IOleDocument, (void **)&piod)))
				return E_FAIL;

			hr = piod->CreateView(static_cast<IOleInPlaceSite*>(axClientSite), NULL, 0, &documentView);
			piod->Release();

			if (FAILED(hr)) return E_OUTOFMEMORY;
		}

		hr = documentView->SetInPlaceSite(static_cast<IOleInPlaceSite*>(axClientSite));
		if ( hr != S_OK )
			return hr;

		hr = documentView->UIActivate(TRUE);
		if ( hr != S_OK )
			return hr;

		hr = documentView->SetRect(&clientRect_);
		if ( hr != S_OK )
			return hr;

		// It's show time!!...
		hr = documentView->Show(TRUE);    
		return hr;
	}

    // styles
    virtual int style()   { return WS_CHILD | WS_CLIPSIBLINGS|WS_VISIBLE; }

   //IOleClientSite
    HRESULT virtual __stdcall IOleClientSite_SaveObject( )
	{ 
		return 	S_OK ;
	}
    HRESULT virtual __stdcall IOleClientSite_GetMoniker( DWORD dwAssign, DWORD dwWhichMoniker, IMoniker ** ppmk )
	{
		return E_NOTIMPL ;
	}
    HRESULT virtual __stdcall IOleClientSite_GetContainer( LPOLECONTAINER FAR* ppContainer )
	{
		ppContainer = 0;
		return E_NOINTERFACE ;
	}

    HRESULT virtual __stdcall IOleClientSite_ShowObject()
	{
		return 	S_OK ;
	}
    HRESULT virtual __stdcall IOleClientSite_OnShowWindow( BOOL fShow  )
	{
		return 	S_OK ;
	}
    HRESULT virtual __stdcall IOleClientSite_RequestNewObjectLayout ()
	{
		return E_NOTIMPL ;
	}
    HRESULT virtual __stdcall IOleClientSite_ShowContextMenu( DWORD dwID, POINT *ppt, IUnknown *pcmdtReserved, IDispatch *pdispReserved)
	{
		// DONT SHOW 
		return S_OK;
	}

    //IOleInPlaceSite
    HRESULT virtual __stdcall IOleInPlaceSite_GetWindow( HWND FAR* lphwnd)
	{
		C* that = (C*)this;
		*lphwnd = (HWND)(*that);
		return S_OK;
	}

	HRESULT __stdcall IOleInPlaceSite_GetWindowContext( LPOLEINPLACEFRAME FAR* lplpFrame,
                                LPOLEINPLACEUIWINDOW FAR* lplpDoc,
                                LPRECT lprcPosRect,
                                LPRECT lprcClipRect,
                                LPOLEINPLACEFRAMEINFO lpFrameInfo)
	{
		*lplpFrame   = 0;
		*lplpDoc     = 0;

		if ( S_OK != oleFrame->QueryInterface(IID_IOleInPlaceFrame, (void**) lplpFrame) )
			return E_FAIL;

		if ( !isMidi_ )
			lpFrameInfo->fMDIApp       = FALSE;
		else
			lpFrameInfo->fMDIApp       = TRUE;

		if ( frameWnd_ )
		{
			lpFrameInfo->hwndFrame     = frameWnd_;
		}
		else
			lpFrameInfo->hwndFrame     = *(this);

		if ( S_OK != this->axClientSite->QueryInterface(IID_IOleInPlaceUIWindow, (void**) lplpDoc) )
			return E_FAIL;


		lpFrameInfo->haccel        = 0;
		lpFrameInfo->cAccelEntries = 0;

		*lprcPosRect = clientRect_;
		*lprcClipRect = clientRect_;

		return S_OK;
	}

    HRESULT virtual __stdcall IOleInPlaceSite_ContextSensitiveHelp( BOOL fEnterMode)
	{
		return E_NOTIMPL ;
	}
    HRESULT virtual __stdcall IOleInPlaceSite_CanInPlaceActivate()
	{
		return 	S_OK ;
	}
    HRESULT virtual __stdcall IOleInPlaceSite_OnInPlaceActivate()
	{
		isInplaceActive_ = true;

		return 	S_OK ;
	}
    HRESULT virtual __stdcall IOleInPlaceSite_OnUIActivate()
	{
		ODBGS("IOleInPlaceSite_OnUIActivate");
		isUIActive = true;

		return 	S_OK ;
	}

	HRESULT virtual __stdcall IOleInPlaceSite_Scroll( SIZE scrollExtent)
	{
		return E_NOTIMPL ;
	}
    HRESULT virtual __stdcall IOleInPlaceSite_OnUIDeactivate( BOOL fUndoable)
	{
		isUIActive = false;

		return 	S_OK ;
	}
    HRESULT virtual __stdcall IOleInPlaceSite_OnInPlaceDeactivate()
	{
		isInplaceActive_ = false;
		return 	S_OK ;
	}
    HRESULT virtual __stdcall IOleInPlaceSite_DiscardUndoState()
	{
		return E_NOTIMPL ;
	}
    HRESULT virtual __stdcall IOleInPlaceSite_DeactivateAndUndo()
	{
		return E_NOTIMPL ;
	}
    HRESULT virtual __stdcall IOleInPlaceSite_OnPosRectChange( LPCRECT lprcPosRect)
	{
		return 	S_OK ;
	}

    //DocHostUiHandler - meaningfull for IE explorer
    HRESULT virtual __stdcall IDocHostUIHandler_GetHostInfo( DOCHOSTUIINFO *pInfo)
	{
		// set appeareance flags (meaningful only in hosting IE context)	
		pInfo->cbSize = sizeof(DOCHOSTUIINFO);
		pInfo->dwFlags = DOCHOSTUIFLAG_NO3DBORDER|DOCHOSTUIFLAG_DIALOG |DOCHOSTUIFLAG_FLAT_SCROLLBAR;
		pInfo->dwDoubleClick = DOCHOSTUIDBLCLK_DEFAULT;

		return S_OK;
	}
    HRESULT virtual __stdcall IDocHostUIHandler_ShowUI( DWORD dwID, IOleInPlaceActiveObject *pActiveObject, IOleCommandTarget *pCommandTarget, IOleInPlaceFrame *pFrame, IOleInPlaceUIWindow *pDoc)
	{
		//return S_FALSE;
		return 	S_OK ;
	}
    HRESULT virtual __stdcall IDocHostUIHandler_HideUI()
	{
		return 	S_OK ;
	}
    HRESULT virtual __stdcall IDocHostUIHandler_UpdateUI()
	{
		return 	S_OK ;
	}
    HRESULT virtual __stdcall IDocHostUIHandler_EnableModeless( BOOL fEnable)
	{
		return 	S_OK ;
	}
    HRESULT virtual __stdcall IDocHostUIHandler_OnDocWindowActivate( BOOL fActivate)
	{
		return 	S_OK ;
	}
    HRESULT virtual __stdcall IDocHostUIHandler_OnFrameWindowActivate( BOOL fActivate)
	{
		return 	S_OK ;
	}
    HRESULT virtual __stdcall IDocHostUIHandler_ResizeBorder( LPCRECT prcBorder, IOleInPlaceUIWindow *pUIWindow, BOOL fRameWindow)
	{
		return 	S_OK ;
	}
    HRESULT virtual __stdcall IDocHostUIHandler_TranslateAccelerator( LPMSG lpMsg, const GUID *pguidCmdGroup, DWORD nCmdID)
	{
		return 	S_FALSE ;
	}
    HRESULT virtual __stdcall IDocHostUIHandler_GetOptionKeyPath( LPOLESTR *pchKey, DWORD dw)
	{
		return 	S_FALSE ;
	}
    HRESULT virtual __stdcall IDocHostUIHandler_GetDropTarget( IDropTarget *pDropTarget, IDropTarget **ppDropTarget)
	{
		*ppDropTarget = 0;
		return 	S_FALSE ;
	}
    HRESULT virtual __stdcall IDocHostUIHandler_GetExternal( IDispatch **ppDispatch)
	{
		*ppDispatch = 0;
		return 	S_OK ;
	}
    HRESULT virtual __stdcall IDocHostUIHandler_TranslateUrl( DWORD dwTranslate, OLECHAR *pchURLIn, OLECHAR **ppchURLOut)
	{
		*ppchURLOut = 0;
		return 	S_FALSE ;
	}
    HRESULT virtual __stdcall IDocHostUIHandler_FilterDataObject( IDataObject *pDO, IDataObject **ppDORet)
	{
		*ppDORet = 0;
		return 	S_FALSE ;
	}

    //IDocHostShowUI Interface
    HRESULT virtual __stdcall IDocHostShowUI_ShowHelp( HWND hwnd, LPOLESTR pszHelpFile, UINT uCommand, DWORD dwData, POINT ptMouse, IDispatch* pDispatchObjectHit )
	{
		return 	S_FALSE ;
	}
    HRESULT virtual __stdcall IDocHostShowUI_ShowMessage( HWND hwnd, LPOLESTR lpstrText, LPOLESTR lpstrCaption, DWORD dwType, LPOLESTR lpstrHelpFile, DWORD dwHelpContext, LRESULT* plResult )
	{
		return 	S_FALSE ;
	}

	// IServiceProvicer
	HRESULT virtual __stdcall IServiceProvider_QueryService( REFGUID guidService, REFIID riid, void** ppvObject)
	{
		*ppvObject = 0;
		return 	E_NOINTERFACE ;
	}

	//IOleControlSite
    HRESULT virtual __stdcall IOleControlSite_OnControlInfoChanged( void)
	{
		return S_OK;
	}
    HRESULT virtual __stdcall IOleControlSite_LockInPlaceActive( BOOL fLock)
	{
		return S_OK;
	}
    HRESULT virtual __stdcall IOleControlSite_GetExtendedControl( IDispatch **ppDisp)
	{
		return S_OK;
	}
    HRESULT virtual __stdcall IOleControlSite_TransformCoords( POINTL *pPtlHimetric,POINTF *pPtfContainer,DWORD dwFlags)
	{
		return S_OK;
	}
    HRESULT virtual __stdcall IOleControlSite_TranslateAccelerator( MSG *pMsg,DWORD grfModifiers)
	{
		return S_OK;
	}
    HRESULT virtual __stdcall IOleControlSite_OnFocus( BOOL fGotFocus)
	{
		return S_OK;
	}
    HRESULT virtual __stdcall IOleControlSite_ShowPropertyFrame( void)
	{
		return S_OK;
	}

	//ISimpleFrameSite
    HRESULT virtual __stdcall ISimpleFrameSite_PreMessageFilter( HWND hWnd, UINT msg, WPARAM wp, LPARAM lp,LRESULT *plResult, DWORD *pdwCookie)
	{
		return S_OK;
	}
    HRESULT virtual __stdcall ISimpleFrameSite_PostMessageFilter( HWND hWnd, UINT msg, WPARAM wp, LPARAM lp,LRESULT *plResult,DWORD dwCookie)
	{
		return S_OK;
	}

    HRESULT virtual __stdcall  IOleCommandTarget_QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText)
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

    HRESULT virtual __stdcall  IOleCommandTarget_Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANTARG *pvaIn, VARIANTARG *pvaOut)
	{
		return S_OK;
	}


	//IAdviseSink
	void virtual __stdcall IAdviseSink_OnDataChange( FORMATETC *pFormatetc, STGMEDIUM *pStgmed) 
	{
	}
        
	void virtual __stdcall IAdviseSink_OnViewChange( DWORD dwAspect,LONG lindex)
	{
	}
        
	void virtual __stdcall IAdviseSink_OnRename( IMoniker *pmk) 
	{
	}
	        
	void virtual __stdcall IAdviseSink_OnSave( void) 
	{
	}
	        
	void virtual __stdcall IAdviseSink_OnClose( void)
	{
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

public:

    virtual LRESULT wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{		
			case WM_MDIACTIVATE:
			{
				int tmp = (HWND)(lParam)== (HWND)(*this);
				ODBGS1("WM_MDIACTIVATE ",tmp);
				if ( (HWND)(lParam)== (HWND)(*this) )
				{				
					if ( activeObject.interface_ != 0 )
					{
						oleFrame->SetActiveObject(activeObject,0);
						activeObject->OnDocWindowActivate(TRUE);												
					}

					if ( oleObject )
					{
						Rect r;
						getClientRect(r);				

						if ( !this->isInplaceActive_)
							this->inplaceActivate(TRUE);
						else
							if ( !this->isUIActive)
								this->inplaceActivate(TRUE);
					}
				}
				else // deactivate
				{
					if ( isShuttingDown_ == true )
					{
						return 0;
					}
					if ( oleObject && activeObject.interface_ )
					{
						activeObject->OnDocWindowActivate(FALSE);		
					}						
				}	

				W::wndProc(*this,message,wParam,lParam);

				// redraw oleframe
				mol::win::WndProc* f = mol::wndFromHWND<mol::win::WndProc>(getParent());
				f->OnLayout(0,0,0);
				f->redraw();

				ODBGS("<----WM_MDIACTIVATE END");
/*
				WINDOWPLACEMENT wp;
				::ZeroMemory(&wp,sizeof(wp));
				wp.length = sizeof(wp);
				::GetWindowPlacement(*this,&wp);
				if ( wp.showCmd == SW_SHOWNORMAL )//&& isMidi_)
				{
					show(SW_HIDE);
					show(SW_SHOW);
				}
*/
				return 0;
			}
			case WM_MOVE:
			{
				ODBGS("WM_MOVE");
				return BaseWindowType::wndProc(*this,message,wParam,lParam);
			}
			
			case WM_CLOSE:
			{
				// we must do this before HWND dies
				isShuttingDown_ = true;
				// reset any object toolspace border on the oleFrame
				mol::Rect r(0,0,0,0);

				if ( oleObject )
				{	
					ODBGS("WM_CLOSE");

					//assure frame has no more active obj

					// anounce de-activation to active obj
					if ( activeObject)
						activeObject->OnDocWindowActivate(FALSE);
					this->inplaceDeActivate(TRUE);

				}
				if ( oleObject )
				{	
					ODBGS("WM_DESTROY");

					// release active obj ref
					activeObject.release();

					// shutdown oleobj
					oleObject->Close(OLECLOSE_NOSAVE);
					oleObject->SetClientSite(0);
					::OleLockRunning(oleObject,FALSE,FALSE);

					// release interfaces
					axClientSite.release();					
					oleObject.release();		
					oleFrame.release();
				}
				W::wndProc(hWnd, message, wParam, lParam );
				return 0;
			}
			case WM_DESTROY:
			{
				if ( isShuttingDown_ != true )
				{
					mol::win::WndProc* f = mol::wndFromHWND<mol::win::WndProc>(getParent());
					if ( f )
					{
						f->OnLayout(0,0,0);
						f->redraw();
					}
				}
				W::wndProc(hWnd, message, wParam, lParam );
				return 0;
			}

			default:
			{
				return W::wndProc(hWnd, message, wParam, lParam );
			}
		}
		return 0;
	}


	//////////////////////////////////////////////////////////////////////
	// called by childwindow to trigger new layout
	//////////////////////////////////////////////////////////////////////

	LRESULT OnLayout( UINT message, WPARAM wParam, LPARAM lParam)
	{
		ODBGS("AxClient OnLayout");
		getClientRect(clientRect_);
		doLayout();
		return 0;
	}
protected:

	void SetObjectSize(RECT& r)
	{
		// if we have an embedded obj
		if ( oleObject )
		{
			// find inplact obj ref and set the dimension
			punk<IOleInPlaceObject> oip(oleObject);
			if ( oip )
			{
				oip->SetObjectRects(&r,&r);
			}
			else
			{
				if ( this->activeObject.interface_ )
				if ( S_OK == activeObject->QueryInterface(IID_IOleInPlaceObject,(void**)&oip) )
				{
					oip->SetObjectRects(&r,&r);
				}
			}
		}
	}

	void updateObject()
	{
		// if we have an embedded obj
		if ( oleObject )
		{
			// find inplact obj ref and set the dimension
			punk<IOleInPlaceObject> oip(oleObject);
			if ( oip )
			{
				HWND w = 0;
				if ( S_OK == oip->GetWindow(&w) && w && ::IsWindow(w) )
				{
					::InvalidateRect(w,0,TRUE);
					::UpdateWindow(w);
					ODBGS("U.P.D.A.T.E O.L.E. W.I.N.D.O.W");
				}
			}
			else
			{
				if ( this->activeObject.interface_ )
				if ( S_OK == activeObject->QueryInterface(IID_IOleInPlaceObject,(void**)&oip) )
				{
					HWND w = 0;
					if ( S_OK == oip->GetWindow(&w) && w && ::IsWindow(w) )
					{
						::InvalidateRect(w,0,TRUE);
						::UpdateWindow(w);
						ODBGS("U.P.D.A.T.E O.L.E. W.I.N.D.O.W");
					}
				}
			}
		}
	}
	// trap WM_SIZE events and keep clientRect_ uptodate
	// then do a re-layout
	LRESULT OnSize( UINT message, WPARAM wParam, LPARAM lParam)
	{
		ODBGS("AxClient OnSize");
		if ( wParam == SIZE_MINIMIZED )
			return 0;

		clientRect_.left = clientRect_.top = 0;
		clientRect_.right  = LOWORD (lParam) ;
		clientRect_.bottom = HIWORD (lParam) ;

		doLayout();
		return 0;
	}

	// layout helper, resizes the embedded ax obj
	mol::Rect  doLayout()
	{
		ODBGS("AxClient doLayout");

		// determine avail rect
		mol::Rect r = clientRect_;
		if ( layout_ )
			r = layout_->availClientRect(r);

		// if we have an embedded obj
		SetObjectSize(r);

		// do a relayout
		if ( layout_ )
			layout_->layout(r);

		ODBGS("<------AxClient doLayout END");
		return r;
	}

	bool instantiateObject( REFCLSID iid , bool create = true )
	{
		HRESULT hr;
		try
		{	
			// check if we have an oleFrame
			if ( !oleFrame )
			{
				// prepare dummy instance (doing nothing)
				dummyFrame_ = new DummyFrame_;
				dummyFrame_->attach(*this);
				oleFrame = dummyFrame_->axFrameSite;
			}

			// initialize client site
			axClientSite->init( (C*)this );

			// cleanup any existing hosted objects
			if ( oleObject )
			{
				oleObject->Close(OLECLOSE_NOSAVE);	
				oleObject.release();
			}

			// create the COM server obj
			if ( create )
			{
				hr = oleObject.createObject(iid,CLSCTX_ALL);
				if ( hr != S_OK )
				{
					throw mol::X("OleCreate failed!");
				}
				// wait a bit to give clumsy servers a chance to load
				Sleep(250);
			}
			return true;
		}
		catch (mol::X x)
		{
			oleObject->Close(OLECLOSE_NOSAVE);
			throw x;
		}
		return false;
	}

	bool embeddObject()
	{
		try
		{
			DWORD dwMiscStatus;
			HRESULT hr = oleObject->GetMiscStatus(DVASPECT_CONTENT, &dwMiscStatus);
			if (dwMiscStatus & OLEMISC_SETCLIENTSITEFIRST)
				hr = oleObject->SetClientSite((IOleClientSite*)axClientSite);

			// set embedden obj into running state
			hr = OleRun((struct IUnknown *)oleObject);
			if ( hr != S_OK )
				throw mol::X("OleRun failed");

			// lock it
			if ( S_OK != OleLockRunning((struct IUnknown *)oleObject, TRUE, FALSE))
				throw mol::X("OleLockRunning failed");

			// check if obj wants clientsite now
			//DWORD dwMiscStatus;
			hr = oleObject->GetMiscStatus(DVASPECT_CONTENT, &dwMiscStatus);
			if (!(dwMiscStatus & OLEMISC_SETCLIENTSITEFIRST))
			{
				hr = oleObject->SetClientSite((IOleClientSite*)axClientSite);

				if ( hr != S_OK )
				{
					throw mol::X("OleCreate failed!");
				}
			}

			// set the stupid unused hostname to keep protocol compliance
			if ( S_OK != oleObject->SetHostNames( L"AxHostWnd",L"AxHostWnd"))
				throw mol::X("Ole Sethostname failed");

			// notify obj of being contained
			if (S_OK != ::OleSetContainedObject((struct IUnknown *)oleObject, TRUE) )
				throw mol::X("OleSetContainedObject failed");

			// obj creation succeeded - get client rect for activation
			getClientRect(clientRect_);

			// activate it in-place!
			inplaceActivate(TRUE);

			return true;
		}
		catch (mol::X x)
		{
			oleObject->Close(OLECLOSE_NOSAVE);
			throw x;
		}
		return false;
	}

	HRESULT copyStorageTemp(IStorage* src, IStorage** copy)
	{
		if ( !src || !copy )
			return E_POINTER;

		*copy = 0;
		mol::TCHAR  path[MAX_PATH];
		mol::TCHAR file[MAX_PATH];
		::GetTempPath(255,path);
		::GetTempFileName( path, _T("JsHost_"), 0, file );


		punk<IStorage> store;
		if ( S_OK == ::StgCreateDocfile( mol::towstring(file).c_str(), STGM_TRANSACTED|STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE,0,&store) )
		{
			HRESULT hr = src->CopyTo(0,0,0,store);
			return store->QueryInterface( IID_IStorage, (void**)copy);
		}
		return E_FAIL;
	}
	public:
	bool inplaceActivate(bool withUI)
	{
		// activate it in-place!
		ODBGS1("inplaceActivate ",withUI);

		if ( this->documentView )
			if ( S_OK == this->documentView->UIActivate(TRUE))
				return true;

		if ( this->axClientSite->ActivateMe(0) == S_OK )
			return true;

		HRESULT hr = S_OK;
		if ( withUI )
		{
			hr = oleObject->DoVerb(OLEIVERB_UIACTIVATE, NULL, axClientSite, (UINT)-1, *this, &clientRect_);
			if (hr == S_OK)
				return true;
		}
			
		hr = oleObject->DoVerb(OLEIVERB_INPLACEACTIVATE, NULL, axClientSite, (UINT)-1, *this, &clientRect_);
		if (hr == OLEOBJ_E_INVALIDVERB)
		{
			hr = oleObject->DoVerb(OLEIVERB_SHOW, NULL, axClientSite, (UINT)-1, *this, &clientRect_);
			if ( hr == S_OK )
			{
				return true;
			}
		}
		return hr == S_OK;
	}

	// inplaceactivate obj
	bool inplaceDeActivate(bool full)
	{
		ODBGS1("inplaceDeActivate ",full);
		// check if to go inactive (true) or UI-inactive only (false)
		if ( !full )
		{
			// UI deactivate only

			// if we have a view interface, use it for deactivation
			if ( this->documentView)
			{
				this->documentView->UIActivate(FALSE);
				return true;
			}
			// go the old way
			if ( this->activeObject)
			{
				punk<IOleInPlaceObject> ipo(activeObject);
				if(!ipo)
					oleObject->QueryInterface(IID_IOleInPlaceObject,(void**)&ipo);
				if(ipo)
					ipo->UIDeactivate();
				return true;
			}
			return false;
		}
		// FULL deactivation

		punk<IOleDocumentView> v;
		if ( this->documentView )						
		{
			documentView->QueryInterface(IID_IOleDocumentView,(void**)&v);
			this->documentView.release();

			if ( v )
			{
				if (this->activeObject)
				{
					v->UIActivate(FALSE);
					if (this->activeObject)
					{
						punk<IOleInPlaceObject> p(activeObject);
						if ( p )
							p->InPlaceDeactivate();
					}
				}
				v->Show(FALSE);
				v->CloseView(0);
			}
		}
		return true;
	}

	HWND					frameWnd_;
    RECT					clientRect_;

	class DummyFrame_ 
		: public AxFrame<DummyFrame_,W>
	{};

	DummyFrame_* dummyFrame_;

	bool isInplaceActive_;
	bool isUIActive;
	bool isShuttingDown_;

};


//////////////////////////////////////////////////////////////////////
// AX Wnd Template
//////////////////////////////////////////////////////////////////////

template<class C, class W, const GUID* G>
class AxWnd : public AxClientWnd<C,W>
{
public:

	HWND createWindow( const mol::string& windowName, int id, const mol::Rect& r, HWND parent )
    {
		AxClientWnd<C,W>::createWindow( windowName, id, r, parent );
		show(SW_SHOW);
		getClientRect(clientRect_);
		loadObject(*G);
        return hWnd_;
    }

	template<class T>
	HWND createWindow( const mol::string& windowName, int id, const mol::Rect& r, T* parent )
    {
		AxClientWnd<C,W>::createWindow( windowName, id, r, parent );
		show(SW_SHOW);
		getClientRect(clientRect_);
		loadObject(*G);
        return hWnd_;
    }
};


} // end namespace mol

#endif
