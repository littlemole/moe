#ifndef _MAINFRAME_WND_X_DEF_
#define _MAINFRAME_WND_X_DEF_

#include "win/res.h"
#include "win/wnd.h"
#include "widgets.h"
#include "dot.h"
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
						/*
						IOleCommandTarget,
						IOleInPlaceFrame,
						IOleWindow,
						IOleInPlaceUIWindow,
						*/
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


	mol::punk<IMoeScript> moeScript;
	mol::punk<IMoeDialogs> moeDialogs;
	mol::punk<IMoeView> moeView;
	mol::punk<IMoeConfig> moeConfig;


	/////////////////////////////////////////////////////////////////////
	// std windows msgs - Creation / Activation / Destruction
	/////////////////////////////////////////////////////////////////////

	void OnCreate();
	void OnMDIActivate(HWND activated);
	void OnDestroy();
	void OnNcDestroy();
	LRESULT OnClose();

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


	 //		 LRESULT OnExecNet( UINT, WPARAM, LPARAM );

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

/*	virtual HRESULT __stdcall get_Docs( IDocs** docs);
	virtual HRESULT __stdcall get_ActiveDoc( IDoc** doc);
	virtual HRESULT __stdcall put_ShowTreeView(  VARIANT_BOOL vb);
	virtual HRESULT __stdcall get_ShowTreeView(  VARIANT_BOOL* vb);
	virtual HRESULT __stdcall get_TreeView( IDispatch** tree);
	virtual HRESULT __stdcall put_SysType( long type);
	virtual HRESULT __stdcall get_SysType( long* type);
	virtual HRESULT __stdcall put_Encoding( long enc);
	virtual HRESULT __stdcall get_Encoding( long* enc);
	virtual HRESULT __stdcall put_TabUsage( VARIANT_BOOL vbTabUsage);
	virtual HRESULT __stdcall get_TabUsage( VARIANT_BOOL* vbTabUsage);
	virtual HRESULT __stdcall put_TabIndents( VARIANT_BOOL vbTabIndents);
	virtual HRESULT __stdcall get_TabIndents( VARIANT_BOOL* vbTabIndents);
	virtual HRESULT __stdcall put_BackSpaceUnindents( VARIANT_BOOL vbBackSpaceIndents);
	virtual HRESULT __stdcall get_BackSpaceUnindents(  VARIANT_BOOL* vbBackSpaceIndents);
	virtual HRESULT __stdcall put_TabWidth( long width);
	virtual HRESULT __stdcall get_TabWidth(  long* width);
	virtual HRESULT __stdcall put_Syntax( long type);
	virtual HRESULT __stdcall get_Syntax( long* type);
	virtual HRESULT __stdcall get_ConfigPath( BSTR* path);
	virtual HRESULT __stdcall get_ModulePath( BSTR* path);
	virtual	HRESULT __stdcall put_Fullscreen( VARIANT_BOOL vbTabIndents);
	virtual	HRESULT __stdcall get_Fullscreen(  VARIANT_BOOL* vbTabIndents);

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////
	// methods: 
	/////////////////////////////////////////////////////////////////////
	
	virtual HRESULT __stdcall New(IDoc** doc);
	virtual HRESULT __stdcall Open( BSTR path,IDoc** doc);
	virtual HRESULT __stdcall OpenUTF8( BSTR path,IDoc** doc);
	virtual HRESULT __stdcall OpenDir(BSTR d, IDoc** doc);
	virtual HRESULT __stdcall ChooseDir(BSTR* d);
	virtual HRESULT __stdcall SaveAll();
	virtual HRESULT __stdcall CloseAll();
	virtual HRESULT __stdcall Show();
	virtual HRESULT __stdcall Hide();
	virtual HRESULT __stdcall Minimize();
	virtual HRESULT __stdcall Maximize();
	virtual HRESULT __stdcall Restore();
	virtual HRESULT __stdcall Tile();
	virtual HRESULT __stdcall Cascade();
	virtual HRESULT __stdcall SetStatus(BSTR status);
	virtual HRESULT __stdcall Help();
	virtual HRESULT __stdcall Exit();
	virtual HRESULT __stdcall Activate(VARIANT index);
	virtual HRESULT __stdcall Eval(BSTR script, BSTR engine);
	virtual HRESULT __stdcall Debug(BSTR script, BSTR engine);
	virtual HRESULT __stdcall ShowForm( BSTR html, long left, int top, int width, int height, int style );
	virtual HRESULT __stdcall get_Compiler( IDispatch** c );
	virtual HRESULT __stdcall Preferences( );
	virtual HRESULT __stdcall Settings( );
	virtual HRESULT __stdcall ExportSettings( BSTR f );
	virtual HRESULT __stdcall ImportSettings( BSTR f );
	virtual HRESULT __stdcall Run( BSTR f, BSTR engine );
	virtual HRESULT __stdcall System( BSTR f);
	virtual HRESULT __stdcall OpenHexEditor( BSTR f, VARIANT_BOOL vbReadOnly, IDoc** hex);
	virtual HRESULT __stdcall OpenHtmlFrame( BSTR f, IDoc** htmlWnd);
	virtual HRESULT __stdcall MsgBox( BSTR text, BSTR title, long flags, long* result);
	virtual HRESULT __stdcall CreateObjectAdmin( BSTR progid, IDispatch** disp);

	virtual HRESULT __stdcall EditUserForm( BSTR pathname, IDispatch** form );
	virtual HRESULT __stdcall ShowUserForm( BSTR pathname, IDispatch** form );
	virtual HRESULT __stdcall DebugUserForm( BSTR pathname, IDispatch** form );
*/
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

	// shared small moe icon
	mol::Icon						icon;

	// OLE status messages override - display status in moe status bar
	virtual HRESULT __stdcall IOleInPlaceFrame_SetStatusText(LPCOLESTR txt);


private:
	
	// user config tmp stream
	mol::Stream						data_;

	// initial Ribbon UI setup
	void initRibbon(IStorage* store);

	// helpers
	HRESULT getActiveEditor( IScintillAx** sci );
	HRESULT evalute_csharp(BSTR cs);
	void  freezeConfig(const mol::string& key);
	void fullScreen(HWND hwnd);
	
	/////////////////////////////////////////////////////////////////////
	// data members
	/////////////////////////////////////////////////////////////////////

//	punk<ICompiler>					compiler_;
	mol::punk<IUnknown>					compiler_;
	BOOL							bDirty_;
	long							systype_;
	long							encoding_;
	long							syntax_;
	long							tabwidth_;
	VARIANT_BOOL					tabUsage_;
	VARIANT_BOOL					tabIndents_;
	VARIANT_BOOL					fullScreen_;
	VARIANT_BOOL					backSpaceUnIndents_;
	BYTE							toolBarFrozen_;
	DWORD							activeObj_;

	WINDOWPLACEMENT					wpPrev_;
};

#endif


