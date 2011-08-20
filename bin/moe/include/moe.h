#ifndef _MAINFRAME_WND_X_DEF_
#define _MAINFRAME_WND_X_DEF_

#include "widgets.h"
#include "Docs.h"
#include "resource.h"


class MoeWnd;

extern mol::TCHAR  InFilesFilter[];

/////////////////////////////////////////////////////////////////////////
//
// Main Frame Wnd - UI Controller & COM App Obj
//
////////////////////////////////////////////////////////////////////////

class MoeWnd  :
	public mol::MainFrame< MoeWnd, mol::OleContainer<MoeWnd,mol::MdiFrame>>,
	public mol::com_registerobj< MoeWnd, CLSID_Application, CLSCTX_ALL>,
	public mol::Dispatch<IMoe>,
	public mol::ProvideClassInfo<MoeWnd>,
	public mol::PersistStream<MoeWnd>,
	public mol::PersistStorage<MoeWnd>,
	public mol::PersistFile<MoeWnd>,
	public mol::interfaces< MoeWnd, 
			mol::implements< IDispatch,
						IMoe,
						IProvideClassInfo,
						mol::interface_ex<IPersist,IPersistStream>,
						IPersistStream,
						IPersistStreamInit,
						IPersistStorage,
						IPersistFile > >
{
friend class Exec;
friend class Docs;
friend class MoeFormWnd;
public:

	MoeWnd(); 
	~MoeWnd(); 

	// create wrapped Instance

	typedef mol::com_instance<MoeWnd> Instance;
	static Instance* CreateInstance();


	// public members

	mol::punk<IMoeScript> moeScript;
	mol::punk<IMoeDialogs> moeDialogs;
	mol::punk<IMoeView> moeView;
	mol::punk<IMoeConfig> moeConfig;

	// shared small moe icon
	mol::Icon						icon;

	/////////////////////////////////////////////////////////////////////
	// std windows msgs - Creation / Activation / Destruction
	/////////////////////////////////////////////////////////////////////

	void OnCreate();
	void OnMDIActivate(HWND activated);
	void OnDestroy();
	void OnNcDestroy();

	LRESULT OnClose();
	LRESULT OnCloseAllButThis();
	LRESULT OnMenu(UINT, WPARAM, LPARAM );

	/////////////////////////////////////////////////////////////////////
	// Menu command handlers
	/////////////////////////////////////////////////////////////////////

	 void OnFileNew();
	 void OnFileNewUFS();
	 void OnFileOpen ();
	 void OnFileOpenHtml ();
     void OnFileOpenDir ();
     void OnFileOpenHex ();
	 void OnTreeOpen();

	 void OnFileExit ( );
	 void OnFind ();
	 void OnReplace ();

	 void OnEditSettings();
	 void OnEditPrefs();
     void OnHelpAbout();
	 void OnShowDirView();

	 LRESULT OnEditCut(UINT, WPARAM, LPARAM );
	 LRESULT OnEditCopy(UINT, WPARAM, LPARAM  );
	 LRESULT OnEditPaste(UINT, WPARAM, LPARAM );

	 void OnFreezeToolBar();
	 void OnSyntax(int code, int id, HWND ctrl);

	// FX Shortcuts (F1 through F12)
	void OnFx(int code, int id, HWND ctrl);

	// show toolbar switches
	 void OnShowToolBar(int code, int id, HWND ctrl);

	// tab-ctrl events
	 void OnTabCtrl( NMHDR* notify );

	// toolbar right click event
 	 void OnToolbarRightClick(NMHDR* notify );



	/////////////////////////////////////////////////////////////////////
    // dispatch to active child
	/////////////////////////////////////////////////////////////////////

	LRESULT OnDispatch(UINT, WPARAM, LPARAM );
	LRESULT OnDispatchTree(UINT, WPARAM, LPARAM );

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	// ribbon handlers
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

    void OnRecentItems();

	/////////////////////////////////////////////////////////////////////
	// COM section - implementation of public interface visible
	// to COM/Scripting clients
	/////////////////////////////////////////////////////////////////////


    virtual HRESULT __stdcall get_Documents( IMoeDocumentCollection **d);
    
    virtual HRESULT __stdcall get_View( IMoeView **d);
    
    virtual HRESULT __stdcall get_ActiveDoc( IMoeDocument **d);
    
    virtual HRESULT __stdcall get_Config( IMoeConfig **d);
    
    virtual HRESULT __stdcall get_Script( IMoeScript **d);
    
    virtual HRESULT __stdcall get_Dialogs( IMoeDialogs **d);
    
    virtual HRESULT __stdcall Exit();

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////
	// persistence
	/////////////////////////////////////////////////////////////////////

	virtual HRESULT __stdcall Save(	 IStorage * pStgSave, BOOL fSameAsLoad );
	virtual HRESULT __stdcall Load(	 IStorage * pStgLoad);
    virtual HRESULT __stdcall Load( LPSTREAM pStm) ;
    virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);
    virtual HRESULT __stdcall GetSizeMax( ULARGE_INTEGER *pCbSize);
    virtual HRESULT __stdcall InitNew();

	// Persistence Dirtyness support

	BOOL isDirty()			{ return true; } // bDirty_; }
	void setDirty(BOOL d)	{ bDirty_ = d; }

	// OLE status messages override - display OLE status in moe status bar
	virtual HRESULT __stdcall IOleInPlaceFrame_SetStatusText(LPCOLESTR txt);

private:
	
	// load conf
	void loadPersistUIstate();

	// initial Ribbon UI setup
	void initRibbon(IStorage* store);

	// helpers
	void freezeConfig(const mol::string& key);
	void fullScreen(HWND hwnd);
	
	/////////////////////////////////////////////////////////////////////
	// data members
	/////////////////////////////////////////////////////////////////////

	// document defaults
	long							systype_;
	long							encoding_;
	long							syntax_;
	long							tabwidth_;
	VARIANT_BOOL					tabUsage_;
	VARIANT_BOOL					tabIndents_;
	VARIANT_BOOL					fullScreen_;
	VARIANT_BOOL					backSpaceUnIndents_;

	// dirty flag
	BOOL							bDirty_;

	// UI data
	BYTE							toolBarFrozen_;
	mol::Stream						data_;

	// cookie into IRunningObjectTable for our running OLE server
	DWORD							activeObj_;

};

#endif


