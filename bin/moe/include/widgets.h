#ifndef MOE_DIALOGS_DEF_GUARD_
#define MOE_DIALOGS_DEF_GUARD_

#include "win/res.h"
#include "win/wnd.h"
#include "win/msgloop.h"
#include "shared.h"
#include <activdbg.h>
#include <Prsht.h>

/////////////////////////////////////////////////////////////////////////////////////////////
// widgets for moe
/////////////////////////////////////////////////////////////////////////////////////////////


class MoeWnd;

mol::string findFile(const mol::string& f);
mol::string engineFromPath(const std::string& path);

class MoeStatusBar : public mol::StatusBarEx 
{
public:

	void status(int i);
	void status( const mol::string& txt );
};

/////////////////////////////////////////////////////////////////////////////////////////////
// the resizable directory tree widget
/////////////////////////////////////////////////////////////////////////////////////////////

typedef mol::CtrlResizer< 
						mol::Window , 
                        100,0,
						mol::win::CtrlResizerImpl::RIGHT> 
RTree;

class MoeTreeWnd : 
	public mol::Frame< 
					MoeTreeWnd,
						mol::AxWnd<
								MoeTreeWnd,
								RTree,
								&CLSID_ShellTree> , 
					    WS_CHILD|WS_VISIBLE|WS_CLIPSIBLINGS|
					    WS_CLIPCHILDREN|WS_THICKFRAME,
					    WS_EX_STATICEDGE >
{
public:
	~MoeTreeWnd() 
	{
		ODBGS("~MoeTreeWnd");
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////
// the url box
/////////////////////////////////////////////////////////////////////////////////////////////


class UrlBox : public mol::Control< mol::RcomboBox,
                      WS_CHILD|WS_VISIBLE|CBS_DROPDOWN|
					  CBS_AUTOHSCROLL,
					  WS_EX_ACCEPTFILES|
					  CBS_DISABLENOSCROLL>
{
public:

	UrlBox();
	~UrlBox();

    void go( const std::string location );
	void updateGUI();

    virtual HRESULT __stdcall Load( LPSTREAM pStm) ;
    virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);
    virtual HRESULT __stdcall GetSizeMax( ULARGE_INTEGER *pCbSize);
   
private:
	
				
	std::list<std::string>  history_;

 };

/////////////////////////////////////////////////////////////////////////////////////////////
// URL Dialog
/////////////////////////////////////////////////////////////////////////////////////////////

class UrlDlg  : public mol::win::Dialog
{
friend mol::Singleton<UrlDlg>; 
friend mol::stack_obj<UrlDlg>;
public:
	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	mol::string url;

    virtual HRESULT __stdcall Load( LPSTREAM pStm);
    virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);
	virtual HRESULT __stdcall GetSizeMax( ULARGE_INTEGER *pCbSize);

private:
	UrlBox urlBox_;

	UrlDlg();
	~UrlDlg() {};
};


/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
// poor info dlg
/////////////////////////////////////////////////////////////////////////////////////////////

class InfoDlg  : public mol::win::Dialog
{
public:
	InfoDlg();
	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
private:
	mol::Icon icon_;
};

/////////////////////////////////////////////////////////////////////////////////////////////
// poor debugger dlg
/////////////////////////////////////////////////////////////////////////////////////////////

class DebugDlg  : public mol::win::Dialog
{
public:
	DebugDlg();
	~DebugDlg();

	mol::punk<IRemoteDebugApplicationThread> remote;

	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	class ExpCallback :
		public IDebugExpressionCallBack,
		public mol::interfaces< ExpCallback, mol::implements<IDebugExpressionCallBack> >
	{
		public: outer_this(DebugDlg,expCallback); 
			
				HRESULT virtual __stdcall onComplete();
	};

	void update_variables(IEnumDebugStackFrames* frames);

private:
	HRESULT addPropertyToList(HWND tree, TV_INSERTSTRUCTW *insertStruct, IDebugProperty *debugProperty);

	mol::stack_obj<ExpCallback> expCallback;
	mol::punk<IDebugExpression> exp_;
};

/////////////////////////////////////////////////////////////////////////////////////////////
// poorer tab dlg
/////////////////////////////////////////////////////////////////////////////////////////////
/*
class TabDlg  : public mol::win::Dialog
{
public:
	TabDlg();
	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    int  width;
	bool usetabs;
	bool tabindents;
	bool backspaceunindents;
};
*/



/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


class Script : public mol::com_obj<mol::ScriptHost>
{
public:

	void eval ( const mol::string& engine, const mol::string& script, IScintillAx* sci );
	void debug( const mol::string& engine, const mol::string& script, IScintillAx* sci );
	void call ( const mol::string& engine, const mol::string& func, const mol::string& script );

	void formscript( const mol::string& engine, const mol::string& script, IDispatch* form );
	void formdebug( const mol::string& engine, const mol::string& script, IDispatch* form );
	void formcontrols( IUnknown* form );

	Script()
	{
		ODBGS("Script start");
	}

	~Script()
	{
		close();
		ODBGS("Script death");
	}

	 virtual HRESULT  __stdcall OnScriptError( IActiveScriptError *pscripterror);
	 virtual HRESULT  __stdcall GetWindow(HWND *phwnd );

private:
	 IScintillAx* sci_;
};

typedef mol::punk<Script>		ScriptingHost;

class ScriptEventHandler : public IDispatch
{
public:
	~ScriptEventHandler();

	void init(Script* s, REFIID iid, const mol::string& on);
	virtual void dispose() {}

	HRESULT virtual __stdcall QueryInterfaceImpl(REFIID iid , LPVOID* ppv) ;              
    HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo );
    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo );
    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId );
    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i);

private:
	IID riid;
	Script* script;
	mol::punk< ITypeInfo> info;
	mol::string objname;
};


// tree events sink
class TreeWndSink : public mol::stack_obj<ShellTreeEvents>
{
friend mol::Singleton<TreeWndSink>; 
friend mol::stack_obj<TreeWndSink>;
public :
	HRESULT virtual __stdcall OnTreeSelection(BSTR filename);
	HRESULT virtual __stdcall OnTreeDblClick(BSTR filename);
	HRESULT virtual __stdcall OnTreeOpen(BSTR filename); 
private:
	TreeWndSink() {}
	~TreeWndSink() {}
};



/////////////////////////////////////////////////////////////////////
// Drag&Drop COM Callback
/////////////////////////////////////////////////////////////////////

class MoeDrop : public mol::stack_obj<mol::ole::DropTargetBase>
{
friend mol::Singleton<MoeDrop>; 
friend mol::stack_obj<MoeDrop>;
public : 
	HRESULT virtual __stdcall Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect);
	HRESULT virtual __stdcall DragEnter( IDataObject*, DWORD, POINTL, DWORD* );
	HRESULT virtual __stdcall DragOver( DWORD, POINTL, DWORD* );
	HRESULT virtual __stdcall DragLeave();
private:
	MoeDrop() {}
	~MoeDrop() {}
};

/////////////////////////////////////////////////////////////////////
// Property Sheets
/////////////////////////////////////////////////////////////////////

class PropSheet;

class PropPage : public mol::win::Dialog
{
friend class PropSheet;
public:

	typedef PropPage BaseWindowType;
	~PropPage();

	virtual void init();
	virtual void reset();
	virtual void command(int c);
	virtual int apply();
	virtual int translateAccel( LPMSG msg);

	PropSheet* ps() { return ps_; }

	LRESULT wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
	static BOOL CALLBACK dialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	operator HPROPSHEETPAGE () { return page_; };

protected:

	void create(PropSheet* ps, const mol::string& tab, int id, int flags = PSP_DEFAULT|PSP_USETITLE);
	PropPage();

	mol::string tab_;
	int id_;

	PROPSHEETPAGE psp_;
	HPROPSHEETPAGE page_;

	PropSheet* ps_;

private:
	virtual LRESULT doModal( int lpTemplate, HWND hWndParent ) { return 0; };
    virtual HWND doModeless( int lpTemplate, HWND hWndParent ) { return 0; };
};

class OlePropPage : 
	public PropPage
{
friend class PropSheet;
public:

	OlePropPage();

	virtual void init();
	virtual void reset();
	virtual int apply();
	virtual int translateAccel( LPMSG msg);

private:

	void create(PropSheet* ps, const mol::string& tab, REFCLSID clsid , int id,int flags = PSP_DEFAULT|PSP_USETITLE);

	void create(PropSheet* ps, const mol::string& tab, int id, int flags = PSP_DEFAULT|PSP_USETITLE) {};

	class PropertyPageSite :
		public IPropertyPageSite,
		public mol::interfaces< PropertyPageSite, mol::implements<IPropertyPageSite> >
	{
		public: outer_this(OlePropPage,propertyPageSite_); 

			void dispose() {};
			
			virtual HRESULT STDMETHODCALLTYPE OnStatusChange( DWORD dwFlags);
			virtual HRESULT STDMETHODCALLTYPE GetLocaleID( LCID *pLocaleID);
			virtual HRESULT STDMETHODCALLTYPE GetPageContainer( IUnknown **ppUnk);
			virtual HRESULT STDMETHODCALLTYPE TranslateAccelerator( MSG* pMsg);
	};


	mol::stack_obj<PropertyPageSite> propertyPageSite_;
	
	mol::punk<IPropertyPage> prop_;

};

class PropSheet
{
public:

	typedef PropSheet BaseWindowType;

	PropSheet(HWND owner, const mol::string& title, int flags = PSH_NOCONTEXTHELP|PSH_PROPTITLE|PSH_USEPSTARTPAGE|PSH_NOAPPLYNOW|PSH_USECALLBACK );

	template<class T>
	void addPage(  const mol::string& tab, int id )
	{
		PropPage* page = new T;
		page->create(this,tab,id);
		addPage(page);
	}

	template<class T>
	void addPage(  const mol::string& tab, REFCLSID clsid ,  int id)
	{
		OlePropPage* page = new T;
		page->create(this,tab,clsid,id);
		addPage(page);
	}

	INT_PTR create();

	static int CALLBACK PropSheetProc( HWND hwndDlg, UINT uMsg, LPARAM lParam );

	void center(HWND hwnd);
protected:

	HPROPSHEETPAGE addPage(PropPage* page);

	bool centered_;
	int startPage_;
	int	nPages_;
	std::vector<HPROPSHEETPAGE> pages_;
	PROPSHEETHEADER ph_;
};


class TabPage  : public PropPage
{
public:
	TabPage();

	virtual void init();
	virtual int apply();
};

class ExportPage  : public PropPage
{
public:

	virtual void command(int c);
};

class PrefPage  : public OlePropPage
{
public:
};

#endif