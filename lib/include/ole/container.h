#ifndef MOL_OLE_HOST_CONTAINER_DEF_GUARD_
#define MOL_OLE_HOST_CONTAINER_DEF_GUARD_

#pragma once
#include "util/uni.h"
#include "win/Wnd.h"
#include "win/mdi.h"
#include "win/dlg.h"
#include "win/layout.h"
#include "ole/ole.h"
#include "ole/storage.h"
#include "ole/punk.h"
#include <mshtmhst.h>
#include <servprov.h>
#include <ocidl.h>

#include "ole/axhostimpl.h"

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// ActiveX Frame Support
//////////////////////////////////////////////////////////////////////

namespace mol {
namespace ole {

//////////////////////////////////////////////////////////////////////
// AX Base Frame Wnd - a reusable minimalistic OLE frame impl
// does NOT support menu/toolbar merging nor OleTargetExec
//////////////////////////////////////////////////////////////////////

class AxFrameBase
{
public:

	punk<IOleInPlaceActiveObject>	activeObject;
	punk<IUnknown>					axFrameSite;

	////////////////////////////////////////////////////////////////

    AxFrameBase();
    ~AxFrameBase();

protected:

    // IOleInPlaceFrame
    HRESULT virtual __stdcall IOleInPlaceFrame_GetWindow( HWND FAR* lphwnd);
    HRESULT virtual __stdcall IOleInPlaceFrame_ContextSensitiveHelp( BOOL fEnterMode);
    HRESULT virtual __stdcall IOleInPlaceFrame_GetBorder( LPRECT lprectBorder);
    HRESULT virtual __stdcall IOleInPlaceFrame_RequestBorderSpace( LPCBORDERWIDTHS pborderwidths);
    HRESULT virtual __stdcall IOleInPlaceFrame_SetBorderSpace( LPCBORDERWIDTHS pborderwidths);
    HRESULT virtual __stdcall IOleInPlaceFrame_SetActiveObject( IOleInPlaceActiveObject *pActiveObject, LPCOLESTR pszObjName);
    HRESULT virtual __stdcall IOleInPlaceFrame_InsertMenus( HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidths);
    HRESULT virtual __stdcall IOleInPlaceFrame_SetMenu( HMENU hmenuShared, HOLEMENU holemenu, HWND hwndActiveObject);
    HRESULT virtual __stdcall IOleInPlaceFrame_RemoveMenus( HMENU hmenuShared);
    HRESULT virtual __stdcall IOleInPlaceFrame_SetStatusText( LPCOLESTR pszStatusText);
    HRESULT virtual __stdcall IOleInPlaceFrame_EnableModeless( BOOL fEnable);
    HRESULT virtual __stdcall IOleInPlaceFrame_TranslateAccelerator( LPMSG lpmsg, WORD wID);
    HRESULT virtual __stdcall IOleCommandTarget_QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText);
    HRESULT virtual __stdcall IOleCommandTarget_Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANTARG *pvaIn, VARIANTARG *pvaOut);

	////////////////////////////////////////////////////////////////

protected:
	RECT borderwidths_;
	mol::Rect clientRect_;
};

}

////////////////////////////////////////////////////////////////
// simple AX Frame Wnd - a reusable minimalistic OLE frame impl
// does NOT support menu/toolbar merging nor OleTargetExec
////////////////////////////////////////////////////////////////

template<class C, class W>
class AxFrame : public W, public ole::AxFrameBase
{
	friend class mol::ole::AxFrameImpl<C>;
public:

	typedef com_obj<mol::ole::AxFrameImpl<C>> AxFrameSite;


	////////////////////////////////////////////////////////////////

    AxFrame()
	{
		punk<AxFrameSite> site = new AxFrameSite;
		if ( site )
		{
			//site->QueryInterface( IID_IUnknown, (void**) &axFrameSite);
			site.queryInterface(&axFrameSite);
			site->init( (C*)this );
		}
	}

    ~AxFrame()
	{
	}

protected:

    // IOleInPlaceFrame
    HRESULT virtual __stdcall IOleInPlaceFrame_GetWindow( HWND FAR* lphwnd)
	{
		C* that = (C*)this;
		*lphwnd = (HWND)(*that);
		return S_OK;
	}
};

//////////////////////////////////////////////////////////////////////
// FULL OleContainer Frame
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// OleContainerBase - adds merging of ole menus and toolbars
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

namespace ole {

class OleContainerBase 
{
public:
	typedef std::pair<mol::string,HMENU> namedMenu;

	OleContainerBase();
	~OleContainerBase();

	//////////////////////////////////////////////////////////

public:

	// public interface for menu merging and OleTargetExec setup
	void addFileMenu( HMENU m, const mol::string& txt );
	void addEditMenu( HMENU m, const mol::string& txt );
	void addViewMenu( HMENU m, const mol::string& txt);
	void addObjectMenu( HMENU m, const mol::string& txt );
	void setWindowMenu( HMENU m );
	void addWindowMenu( HMENU m, const mol::string& txt );
	void addHelpMenu( HMENU m, const mol::string& txt );
	void addOlExecHandler( int oleCmdId, UINT cmd, GUID* cmdGroup = 0  );


protected:

	// lazy merge of OLE menus helper
	void insertOleMenues( HMENU shared, std::vector<namedMenu>& v );

	// implementation of OLE interfaces for menu/toolbar merging and OleTargetExec
	HRESULT virtual __stdcall handleGetBorder( mol::Rect r, LPRECT lprectBorder);
    HRESULT virtual __stdcall handleRequestBorderSpace( mol::Rect r, LPCBORDERWIDTHS pborderwidths);
    HRESULT virtual __stdcall handleSetBorderSpace( LPCBORDERWIDTHS pborderwidths);
	HRESULT virtual __stdcall handleInsertMenus( HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidths);
    HRESULT virtual __stdcall handleSetMenu( HMENU hmenuShared, HOLEMENU holemenu, HWND hwndActiveObject);
    HRESULT virtual __stdcall handleRemoveMenus( HMENU hmenuShared);
    HRESULT virtual __stdcall handleQueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText);
    HRESULT virtual __stdcall handleExec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANTARG *pvaIn, VARIANTARG *pvaOut);

	// a windowProc impl for ole frames
	LRESULT virtual OleContainerWndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	// handle OnLayout handler - forwards to handleDoLayout
	LRESULT handleOnLayout( UINT message, WPARAM wParam, LPARAM lParam);

	// actully do the layouting stuff here
	LRESULT handleDoLayout( mol::Rect r );

	// forward to MSG to base window class
	LRESULT virtual callOleContainerDefWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;

	// virtual interfaces to communicate with derived class
	virtual RECT prepareClientRect() = 0;
	virtual HWND getFrameWindow() = 0;
	virtual bool getMidiState() = 0;
	virtual void redrawOleContainer() = 0;
	virtual void releaseOleContainer() = 0;
	virtual void setFrameMenu( HMENU newMenu, HMENU windowMenu   ) = 0;
	virtual RECT& getBorderWidths() = 0;
	virtual IUnknown* getAxFrameSiteUnknown() = 0;
	virtual IOleInPlaceActiveObject* getIOleInPlaceActiveObject() = 0;
	virtual mol::LayoutMgr* getLayoutMgr() = 0;

	// data members for full oleframe
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

	HMENU winMenu_;

	struct OleCmd {

		OleCmd( UINT cmdId, const GUID* cmdGroup = &GUID_NULL, int oleCmdId = 0 )
			: cmdId_(cmdId),
			  cmdGroup_(cmdGroup),
			  oleCmdId_(oleCmdId)

		{}

		UINT cmdId_;
		const GUID* cmdGroup_;
		int oleCmdId_;
	};

	std::vector<OleCmd> oleCmds_;
};

}; // end namespace ole

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// OleFrame - adds merging of ole menus and toolbars
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

template<class C, class W>
class OleContainer : public AxFrame<C,W>, public mol::ole::OleContainerBase
{
	friend class mol::ole::AxFrameImpl<C>;
public:

	//////////////////////////////////////////////////////////
	// c'tor/d'tor

	OleContainer()
	{}

	~OleContainer()
	{
		ODBGS("OleContainer died ;)");
	}

	//////////////////////////////////////////////////////////


protected:

	//////////////////////////////////////////////////////////
	// override simple COM impl from AxFrameBase to add
	// toolbar and menu merge as well as OleTargetExec
	// functionality. to reduce template bloat most
	// simply forward to implementation in OleContainerBase
	//////////////////////////////////////////////////////////

    HRESULT virtual __stdcall IOleInPlaceFrame_GetBorder( LPRECT lprectBorder)
	{
		return this->handleGetBorder( clientRect_, lprectBorder );
	}

    HRESULT virtual __stdcall IOleInPlaceFrame_RequestBorderSpace( LPCBORDERWIDTHS pborderwidths)
	{
		return this->handleRequestBorderSpace( clientRect_, pborderwidths );
	}

    HRESULT virtual __stdcall IOleInPlaceFrame_SetBorderSpace( LPCBORDERWIDTHS pborderwidths)
	{		
		HRESULT hr = this->handleSetBorderSpace(pborderwidths);

		doLayout();
		show(SW_SHOW);
		return hr;
	}


	HRESULT virtual __stdcall IOleInPlaceFrame_InsertMenus( HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidths)
	{
		return this->handleInsertMenus( hmenuShared, lpMenuWidths);
	}

    HRESULT virtual __stdcall IOleInPlaceFrame_SetMenu( HMENU hmenuShared, HOLEMENU holemenu, HWND hwndActiveObject)
	{
		return this->handleSetMenu(hmenuShared, holemenu, hwndActiveObject);
	}

    HRESULT virtual __stdcall IOleInPlaceFrame_RemoveMenus( HMENU hmenuShared)
	{
		return this->handleRemoveMenus(hmenuShared);
	}

    HRESULT virtual __stdcall  IOleCommandTarget_QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText)
	{
		return this->handleQueryStatus(pguidCmdGroup,  cCmds,  prgCmds, pCmdText);
	}

    HRESULT virtual __stdcall  IOleCommandTarget_Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANTARG *pvaIn, VARIANTARG *pvaOut)
	{
		return this->handleExec( pguidCmdGroup,  nCmdID,  nCmdexecopt, pvaIn, pvaOut);
	}

	//////////////////////////////////////////////////////////

public:

	//////////////////////////////////////////////////////////
	// OLE frame windowproc - actually implemented in
	// OleContainerBase
	//////////////////////////////////////////////////////////

    virtual LRESULT wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
		// let OleContainerWndProc try to handle that message
		// catch WM_NCDESTROY as we are always dead then:
		if ( message == WM_NCDESTROY ) 
		{
			// just let the base window do any necessary cleanup
			return W::wndProc(hWnd, message, wParam, lParam);
		}
		LRESULT l = this->OleContainerWndProc( hWnd, message, wParam, lParam );
		return l;
	}

	//////////////////////////////////////////////////////////
	// override OnSize and resize/relayout merged OLE
	// toolbar size
	//////////////////////////////////////////////////////////

	LRESULT OnSize( UINT msg, WPARAM wParam, LPARAM lParam)
	{
		ODBGS("OleContainer::OnSize");

		// track zero size (EXCEL!) - assume we are deactivating
		if ( LOWORD (lParam) == 0 && HIWORD (lParam) == 0 )
		{
			ODBGS("<-------OleContainer::OnSize END");
			return 0;
		}

		// get new width and height
		clientRect_ = mol::Rect(0,0,0,0);
		clientRect_.right  = LOWORD (lParam) ;
		clientRect_.bottom = HIWORD (lParam) ;		
		ODBGS1("new width :",clientRect_.right);
		ODBGS1("new height:",clientRect_.bottom);

		return this->handleOnLayout( msg, wParam, lParam );
	}

	//////////////////////////////////////////////////////////
	// even w/o resize we might have layout changes - trap it
	//////////////////////////////////////////////////////////

	LRESULT OnLayout( UINT message, WPARAM wParam, LPARAM lParam)
	{
		return this->handleOnLayout( message, wParam, lParam );
	}

	//////////////////////////////////////////////////////////
	// std mole framework createWindow override
	//////////////////////////////////////////////////////////

	HWND createWindow( const mol::string& windowName, HMENU id, const mol::Rect& r, HWND parent )
	{
		W::createWindow( windowName, id, r, parent );

		getClientRect( clientRect_);
		origMenu_= ::GetMenu(*this);

		return hWnd_;
	}

protected:
	
	// layout helper, takes allocated borderwith into account
	// forwards to OleContainerBase
	
	LRESULT doLayout()
	{
		ODBGS1("OleContainer::doLayout ",(int)(activeObject.interface_));

		RECT r = prepareClientRect();
		return this->handleDoLayout( r );
	}

	// communication with OleContainerBase

	virtual RECT& getBorderWidths()
	{
		return this->borderwidths_;
	}

	virtual RECT prepareClientRect()
	{
		RECT r;
		getClientRect(r);
		return r;
	}

	virtual HWND getFrameWindow()
	{
		return (HWND)*this;
	}

	virtual mol::LayoutMgr* getLayoutMgr()
	{
		return layout_;
	}

	virtual bool getMidiState()
	{
		return this->isMidi_;
	}

	virtual void redrawOleContainer()
	{
		this->redraw();
	}

	virtual IUnknown* getAxFrameSiteUnknown()
	{
		IUnknown* u = 0;
		if ( axFrameSite() ) 
		{
			u = axFrameSite;
		}
		return u;
	}

	virtual IOleInPlaceActiveObject* getIOleInPlaceActiveObject()
	{
		IOleInPlaceActiveObject* a =  0;
		if ( activeObject() ) 
		{
			a = activeObject;
		}
		return a;
	}

	virtual void releaseOleContainer()
	{
		activeObject.release();
		axFrameSite.release();
	}

	virtual void setFrameMenu( HMENU newMenu, HMENU windowMenu   ) 
	{
		this->setMenu( newMenu, windowMenu );
	}

	// route windows message to this windows base class window proc
	virtual LRESULT callOleContainerDefWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return W::wndProc(hWnd, message, wParam, lParam );
	}
};


} // end namespace mol

#endif
