#ifndef _MAINFRAME_WND_IMPL_DEF_
#define _MAINFRAME_WND_IMPL_DEF_

#include "commons.h"
#include "moewidgets.h"
#include "resource.h"

using namespace mol;

class MoeWnd;

extern int MoeWndOleCmds[];

/////////////////////////////////////////////////////////////////////////
//
// Main Frame Wnd - UI Controller & COM App Obj
//
////////////////////////////////////////////////////////////////////////

class MoeWndImpl :
	public MainFrame< MoeWndImpl, mol::OleContainer<MoeWndImpl,MdiFrame>>
{
friend class Docs;
friend class MoeFormWnd;
public:

	typedef mol::OleContainer<MoeWndImpl,MdiFrame>
		BASE;

	MoeWndImpl(MoeWnd* mwnd); 
	~MoeWndImpl(); 


	/////////////////////////////////////////////////////////////////////
	// COM event sinks
	/////////////////////////////////////////////////////////////////////

	// DropTarget COM Callback
    class MoeWnd_Drop : public stack_obj<DropTargetBase>
    {
        public : outer_this(MoeWndImpl,Drop);
			HRESULT virtual __stdcall Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect);
			HRESULT virtual __stdcall DragEnter( IDataObject*, DWORD, POINTL, DWORD* );
			HRESULT virtual __stdcall DragOver( DWORD, POINTL, DWORD* );
			HRESULT virtual __stdcall DragLeave();
    } Drop;

	// tree events sink
    class TreeWnd_sink : public stack_obj<ShellTreeEvents>
    {
        public : outer_this(MoeWndImpl,treeSink); 
		HRESULT virtual __stdcall OnTreeSelection(BSTR filename);
		HRESULT virtual __stdcall OnTreeDblClick(BSTR filename);
		HRESULT virtual __stdcall OnTreeOpen(BSTR filename); 
    } treeSink;


	/////////////////////////////////////////////////////////////////////
	// std windows msgs
	/////////////////////////////////////////////////////////////////////

	msg_handler( WM_CREATE,	OnCreate)
		 LRESULT OnCreate( UINT, WPARAM, LPARAM );

	msg_handler( WM_CLOSE, OnClose )
		 LRESULT OnClose( UINT, WPARAM, LPARAM );

	msg_handler( WM_NCDESTROY, OnNcDestroy )
		 LRESULT OnNcDestroy( UINT, WPARAM, LPARAM );

	msg_handler( WM_MDIACTIVATE, OnMDIActivate )
	     LRESULT OnMDIActivate( UINT, WPARAM, LPARAM );

	msg_handler( WM_INITMENUPOPUP, OnMenu )
		 LRESULT OnMenu (UINT, WPARAM, LPARAM );

	/////////////////////////////////////////////////////////////////////
	// commands
	/////////////////////////////////////////////////////////////////////

    cmd_handler( IDM_FILE_NEW, OnFileNew )
		 LRESULT OnFileNew (UINT, WPARAM, LPARAM );

    cmd_handler( IDM_FILE_OPEN, OnFileOpen )
		 LRESULT OnFileOpen (UINT, WPARAM, LPARAM );

    cmd_handler( IDM_FILE_OPENHTML, OnFileOpenHtml )
		 LRESULT OnFileOpenHtml (UINT, WPARAM, LPARAM );

    cmd_handler( IDM_FILE_OPENDIR, OnFileOpenDir   )
	     LRESULT OnFileOpenDir (UINT, WPARAM, LPARAM );

    cmd_handler( IDM_FILE_HEXEDIT, OnFileOpenHex   )
	     LRESULT OnFileOpenHex (UINT, WPARAM, LPARAM );

	cmd_handler( IDM_FILE_EXIT,	OnFileExit      )
		 LRESULT OnFileExit (UINT, WPARAM, LPARAM );

    cmd_handler( IDM_EDIT_FIND, OnFind )
		 LRESULT OnFind (UINT, WPARAM, LPARAM );

	cmd_handler( IDM_EDIT_REPLACE, OnReplace )
		 LRESULT OnReplace (UINT, WPARAM, LPARAM );

	cmd_handler( IDM_EDIT_EXECUTESCRIPT, OnExecScript )
		 LRESULT OnExecScript(UINT, WPARAM, LPARAM );

//	cmd_handler( ID_TOOLS_EXECUTE_NET, OnExecNet )
//		 LRESULT OnExecNet( UINT, WPARAM, LPARAM );

	cmd_handler( IDM_USER_FORM, OnExecForm )
		 LRESULT OnExecForm( UINT, WPARAM, LPARAM );

	cmd_range_handler( IDM_EDIT_16BYTES, IDM_EDIT_32BYTES, OnDispatch )
//		 LRESULT OnDispatch( UINT, WPARAM, LPARAM );

	cmd_handler( IDM_MODE_EDITSETTINGS, OnEditSettings  )
		 LRESULT OnEditSettings(UINT, WPARAM, LPARAM );

	cmd_handler( IDM_MODE_PREFERENCES, OnEditPrefs )
		 LRESULT OnEditPrefs(UINT, WPARAM, LPARAM );
	
	cmd_handler( IDM_HELP_ABOUT, OnHelpAbout )
	     LRESULT OnHelpAbout(UINT, WPARAM, LPARAM );

	notify_handler( IDC_TAB_CTRL, OnTabCtrl)
		 LRESULT OnTabCtrl(UINT, WPARAM, LPARAM );

	cmd_handler( IDM_VIEW_DIRVIEW, OnShowDirView )
		 LRESULT OnShowDirView(UINT, WPARAM, LPARAM );

	cmd_range_handler(ID_FIRST_USER_SCRIPT,ID_LAST_USER_SCRIPT,  OnUserScript )
		 LRESULT OnUserScript(UINT, WPARAM, LPARAM );

	cmd_range_handler(ID_FIRST_USER_BATCH,ID_LAST_USER_BATCH,  OnUserBatch )
		 LRESULT OnUserBatch(UINT, WPARAM, LPARAM );

	cmd_range_handler(ID_FIRST_USER_FORM,ID_LAST_USER_FORM,  OnUserForm )
		 LRESULT OnUserForm(UINT, WPARAM, LPARAM );

    cmd_handler( IDM_EDIT_CUT,OnDispatch)
		 LRESULT OnEditCut(UINT, WPARAM, LPARAM );

	cmd_handler( IDM_EDIT_COPY,OnDispatch)
		 LRESULT OnEditCopy(UINT, WPARAM, LPARAM );

	cmd_handler( IDM_EDIT_PASTE,OnDispatch)
		 LRESULT OnEditPaste(UINT, WPARAM, LPARAM );

	notify_code_handler( TBN_DROPDOWN, OnToolbarDropDown)
	 	 LRESULT OnToolbarDropDown(UINT, WPARAM, LPARAM );

	notify_code_handler( NM_RCLICK, OnToolbarRightClick)
	 	 LRESULT OnToolbarRightClick(UINT, WPARAM, LPARAM );

	cmd_range_handler( IDM_TOOLBARS_FILEBAR, IDM_TOOLBARS_DIRVIEW, OnShowToolBar)
		 LRESULT OnShowToolBar(UINT, WPARAM, LPARAM );

	cmd_handler( IDM_TOOLBARS_FREEZE, OnFreezeToolBar)
		 LRESULT OnFreezeToolBar(UINT, WPARAM, LPARAM );

	cmd_handler( IDC_SYNTAX_BOX, OnSyntax)
		 LRESULT OnSyntax(UINT, WPARAM, LPARAM );

	/////////////////////////////////////////////////////////////////////
    // dispatch these to active child
	/////////////////////////////////////////////////////////////////////

	cmd_handler( IDM_FILE_PRINT,							OnDispatch      )
    msg_handler( WM_SEARCH_MSG,								OnDispatch      )
    cmd_handler( IDM_FILE_SAVE_AS,							OnDispatch      )
    cmd_handler( IDM_FILE_SAVE,								OnDispatch      )
    cmd_handler( IDM_MODE_UNIX,								OnDispatch	    )
    cmd_handler( IDM_MODE_WIN32,							OnDispatch	    )
    cmd_handler( IDM_MODE_USETABS,							OnDispatch	    )
    cmd_handler( IDM_MODE_DONT_USE_TABS,					OnDispatch	    )
    cmd_handler( IDM_MODE_SETTINGS,						    OnDispatch	    )
    cmd_handler( IDM_LEXER_HTML,							OnDispatch		)
    cmd_handler( IDM_LEXER_PERL,							OnDispatch		)
    cmd_handler( IDM_LEXER_CPP,								OnDispatch		)
    cmd_handler( IDM_LEXER_CSS,								OnDispatch		)
    cmd_handler( IDM_LEXER_JAVA,							OnDispatch		)
    cmd_handler( IDM_LEXER_JAVASCRIPT,						OnDispatch		)
    cmd_handler( IDM_LEXER_VB,						        OnDispatch		)
    cmd_handler( IDM_LEXER_SHELL,						    OnDispatch		)
    cmd_handler( IDM_LEXER_SQL,						        OnDispatch		)
    cmd_handler( IDM_LEXER_PLAIN,							OnDispatch		)
	cmd_handler( IDM_LEXER_CSHARP,							OnDispatch		)
    cmd_handler( IDM_MODE_EOL,							    OnDispatch		)
    cmd_handler( IDM_EDIT_COLOR,						    OnDispatch      )
    cmd_handler( IDM_EDIT_UNDO,								OnDispatch		)
    cmd_handler( IDM_EDIT_REDO,								OnDispatch		)
//	cmd_handler( IDM_EDIT_BACK,								OnDispatch		)
//	cmd_handler( IDM_EDIT_FORWARD,							OnDispatch		)
	cmd_handler( IDM_EDIT_STOP,								OnDispatch		)
	cmd_handler( IDM_EDIT_UPDATE,							OnDispatch		)
    cmd_handler( IDM_EDIT_INDENTION,						OnDispatch      )
    cmd_range_handler(ID_FIRST_USER_CMD,ID_LAST_USER_CMD,   OnDispatch      )
		LRESULT OnDispatch(UINT, WPARAM, LPARAM );

	// FX Shortcuts (F1 through F12)
    cmd_range_handler(ID_F1,ID_F12,   OnFx      )

		LRESULT OnFx(UINT, WPARAM, LPARAM );

	/////////////////////////////////////////////////////////////////////
    // these have default implementation in base class which calls 
	// win32 mdi def behaviour
	/////////////////////////////////////////////////////////////////////

    cmd_handler( IDM_VIEW_MAXIMIZE,							OnMaximize	    )
    cmd_handler( IDM_VIEW_MINIMIZE,							OnMinimize	    )
    cmd_handler( IDM_VIEW_TILE,								OnTileHorizontal)
    cmd_handler( IDM_VIEW_CASCADE,							OnCascade	    )
    cmd_handler( IDM_VIEW_NEXT,								OnNext		    )
    cmd_handler( IDM_VIEW_CLOSE,							OnCloseChild	)
    cmd_handler( IDM_VIEW_CLOSEALL, 						OnCloseAll	    )

	/////////////////////////////////////////////////////////////////////
	// persistence
	/////////////////////////////////////////////////////////////////////

    virtual HRESULT __stdcall Load( LPSTREAM pStm) ;
    virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);
    virtual HRESULT __stdcall GetSizeMax( ULARGE_INTEGER *pCbSize);
    virtual HRESULT __stdcall InitNew();

	BOOL isDirty()			{ return bDirty_; }
	void setDirty(BOOL d)	{ bDirty_ = d; }

	/////////////////////////////////////////////////////////////////////
	// children factory 
	/////////////////////////////////////////////////////////////////////

	bool openPath( const mol::string& dir, bool utf8, bool readOnly, IDoc** doc  );
	bool openPathHex( const mol::string& file, bool readOnly, IDoc** doc );
	bool openPathHtml( const mol::string& file, IDoc** doc );
	/////////////////////////////////////////////////////////////////////
	// helpers
	/////////////////////////////////////////////////////////////////////

	MoeTabControl&			tabCtrl()		{ return this->tabCtrl_;   }
	MoeComboBox&			syntaxBox()		{ return this->syntaxBox_; }
	MoeTreeWnd&				treeCtrl()		{ return this->treeWnd_;   }
	mol::StatusBar&			statusBar()		{ return this->statusBar_; }

private:

    // children sanctuary
	virtual void OnReleaseChild(HWND hwnd);

	// toolbar init and persist support

	void initToolbars(BorderLayout* layout);
	void loadToolBarState( MoeToolBar& bar, int cmd, int pos, LPSTREAM pStm );
	void saveToolBarState( MoeToolBar& bar, int index, LPSTREAM pStm);
	void loadReBarState( int cmd, int pos, LPSTREAM pStm );
	void saveReBarState( int index, LPSTREAM pStm);

	//user interface, toolbars etc

	mol::StatusBar    				statusBar_;
	mol::ReBar						reBar_;
	MoeToolBar						toolBars_[6];
	BYTE							toolBarFrozen_;
	MoeComboBox						syntaxBox_;
	MoeTabControl					tabCtrl_;
	MoeTreeWnd						treeWnd_;
	mol::SearchDlg					searchDlg_;
	UrlDlg							urlDlg_;
	mol::Icon						icon_;
	BOOL							bDirty_;

	MoeWnd*							moeWnd_;

	static int						form_cnt_;
};

#endif