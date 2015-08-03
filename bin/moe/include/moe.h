#ifndef _MAINFRAME_WND_X_DEF_
#define _MAINFRAME_WND_X_DEF_

#include "commons.h"

class TreeWndSink;
class MoeDrop;
class UrlBox;
class UrlDlg;


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
friend class DocFactory;
friend class MoeFormWnd;
public:

	MoeWnd(); 
	~MoeWnd(); 

	// create wrapped Instance

	typedef mol::com_instance<MoeWnd> Instance;
	static Instance* CreateInstance();


	// moe COM subobjects

	mol::punk<IMoeScript>  moeScript;
	mol::punk<IMoeDialogs> moeDialogs;
	mol::punk<IMoeView>    moeView;
	mol::punk<IMoeConfig>  moeConfig;
	mol::punk<IScintillAxStyleSets> moeStyles;
	mol::punk<ShellTreeEvents> treeWndSink;
	//mol::punk<Script> scriptHost;

	boost::scoped_ptr<MoeDrop> moeDrop;
	boost::scoped_ptr<mol::SearchDlg> searchDlg;
	boost::scoped_ptr<UrlDlg> urlDlg;

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
    // dispatch to active child
	/////////////////////////////////////////////////////////////////////

	LRESULT OnDispatch(UINT, WPARAM, LPARAM );
	LRESULT OnDispatchTree(UINT, WPARAM, LPARAM );


	/////////////////////////////////////////////////////////////////////
	// Menu command handlers
	/////////////////////////////////////////////////////////////////////

	 void OnFileNew();
	 void OnFileNewUFS();
	 void OnFileNewRTF();
	 void OnFileOpen ();
	 void OnFileOpenHtml ();
     void OnFileOpenDir ();
     void OnFileOpenHex ();

	 void OnEditSettings();
	 void OnEditPrefs();
	 void OnEditUserStyles();
     void OnHelpAbout();
	 void OnFileExit ( );

	 // toggle dirview
	 void OnShowDirView();

	 // FX Shortcuts (F1 through F12)
	 void OnFx(int code, int id, HWND ctrl);

	 // open find and replace dialogs
	 void OnFind ();
	 void OnReplace ();

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
	virtual HRESULT __stdcall Print(BSTR txt);
    virtual HRESULT __stdcall Exit();


	virtual HRESULT __stdcall get_IDOK(long* d)			{ if(d) *d = IDOK; return S_OK; }
	virtual HRESULT __stdcall get_IDCANCEL(long* d)		{ if(d) *d =  IDCANCEL; return S_OK; }
	virtual HRESULT __stdcall get_IDABORT(long* d)		{ if(d) *d =  IDABORT; return S_OK; }
	virtual HRESULT __stdcall get_IDRETRY(long* d)		{ if(d) *d =  IDRETRY; return S_OK; }
	virtual HRESULT __stdcall get_IDIGNORE(long* d)		{ if(d) *d =  IDIGNORE; return S_OK; }
	virtual HRESULT __stdcall get_IDYES(long* d)		{ if(d) *d =  IDYES; return S_OK; }
	virtual HRESULT __stdcall get_IDNO(long* d)			{ if(d) *d =  IDNO; return S_OK; }
	virtual HRESULT __stdcall get_IDTRYAGAIN(long* d)	{ if(d) *d =  IDTRYAGAIN; return S_OK; }
	virtual HRESULT __stdcall get_IDCONTINUE(long* d)	{ if(d) *d =  IDCONTINUE; return S_OK; }

	virtual HRESULT __stdcall get_ANSI(long* d)			{ if(d) *d =  CP_ACP; return S_OK; }
	virtual HRESULT __stdcall get_UNICODE(long* d)		{ if(d) *d =  CP_WINUNICODE; return S_OK; }
	virtual HRESULT __stdcall get_UTF8(long* d)			{ if(d) *d =  CP_UTF8; return S_OK; }


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

	BOOL isDirty()			{ return true; } 
	void setDirty(BOOL d)	{ bDirty_ = d; }

	// OLE status messages override - display OLE status in moe status bar
	virtual HRESULT __stdcall IOleInPlaceFrame_SetStatusText(LPCOLESTR txt);

	// shared small moe icon
	mol::Icon						icon;

    HRESULT stdOut(BSTR* ret);

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	 // toolbars (winxp style only)

	 // freeze the toolbars
	 void OnFreezeToolBar();

	 // select syntax dropdown box
	 void OnSyntax(int code, int id, HWND ctrl);

	 // show toolbar switches
	 void OnShowToolBar(int code, int id, HWND ctrl);

	 bool toolbarFrozen() { return toolBarFrozen_ == 0; }

	 void OnScreenShot();


private:
	
	// load conf
	void loadPersistUIstate();

	// initial Ribbon UI setup
	void initRibbon(IStorage* store);

	// helpers
	void freezeConfig(const std::wstring& key);

	//void fullScreen(HWND hwnd);
	
	/////////////////////////////////////////////////////////////////////
	// data members
	/////////////////////////////////////////////////////////////////////

	// dirty flag
	BOOL							bDirty_;

	// UI data
	BYTE							toolBarFrozen_;
	mol::Stream						data_;

	// cookie into IRunningObjectTable for our running OLE server
	DWORD							activeObj_;

	mol::bstr						vttyOut_;
};

#endif


