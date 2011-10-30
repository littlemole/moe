#ifndef _MAINFRAME_WND_X_DEF_
#define _MAINFRAME_WND_X_DEF_

#include "Docs.h"
#include "resource.h"

class MoeWnd;

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

	mol::punk<IScpCredentialProvider> credentialProvider;

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

	// dispatch to tree if active, else  to active child
	LRESULT OnEditCut(UINT, WPARAM, LPARAM );
	LRESULT OnEditCopy(UINT, WPARAM, LPARAM  );
	LRESULT OnEditPaste(UINT, WPARAM, LPARAM );


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
     void OnHelpAbout();
	 void OnFileExit ( );

	 // toggle dirview
	 void OnShowDirView();

	 // document chooser tab-ctrl events
	 void OnTabCtrl( NMHDR* notify );

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
    virtual HRESULT __stdcall Exit();


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

	// shared small moe icon
	mol::Icon						icon;

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	 // toolbars (winxp style only)

	 // freeze the toolbars
	 void OnFreezeToolBar();

	 // select syntax dropdown box
	 void OnSyntax(int code, int id, HWND ctrl);

	 // show toolbar switches
	 void OnShowToolBar(int code, int id, HWND ctrl);

	 // toolbar right click event
 	 void OnToolbarRightClick(NMHDR* notify );

	 typedef std::pair<int,std::wstring> CodePage;

	 const std::vector<CodePage>& codePages()
	 {
		 return codePages_;
	 }

	 size_t codePageIndex( int cp )
	 {
		 for ( size_t i = 0; i < codePages_.size(); i++)
		 {
			 if ( codePages_[i].first == cp )
			 {
				 return i;
			 }
		 }
		 return -1;
	 }

	class Credentials : public mol::ssh::CredentialCallback
	{
		public: 
		outer_this(MoeWnd,credentials);

		virtual bool getCredentials(const std::string& host, int port,std::string& user, std::string& pwd);
		virtual bool promptCredentials(const std::string& host, int port,const std::string& prompt, const std::string& desc,std::string& value,bool echo);
		virtual bool acceptHost(const std::string& host, int port, const std::string& hash);
		virtual bool rememberHostCredentials(const std::string& host, int port, const std::string& user, const std::string& pwd);
		virtual bool deleteHostCredentials(const std::string& host, int port);

	} credentials;

private:

	std::vector<CodePage> codePages_;
	
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


