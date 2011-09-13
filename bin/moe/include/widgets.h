#ifndef MOE_DIALOGS_DEF_GUARD_
#define MOE_DIALOGS_DEF_GUARD_

#include "shared.h"

extern mol::TCHAR  InFilesFilter[];

/////////////////////////////////////////////////////////////////////////////////////////////
// widgets for moe
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeWnd;

mol::string findFile(const mol::string& f);
mol::string engineFromPath(const std::string& path);
std::string resolvePath(const std::string& p);

int msgbox( const mol::string& txt, const mol::string& title, const mol::string& detail );

void unlockInternetExplorer();

/////////////////////////////////////////////////////////////////////////////////////////////
// Status Bar
/////////////////////////////////////////////////////////////////////////////////////////////


class MoeStatusBar : public mol::StatusBarEx 
{
public:

	void status(int i);
	void status( const mol::string& txt );
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
	HRESULT addPropertyToList(HWND tree, TV_INSERTSTRUCTW *insertStruct, IDebugProperty *debugProperty, int level = 0);

	mol::stack_obj<ExpCallback> expCallback;
	mol::punk<IDebugExpression> exp_;
};

/////////////////////////////////////////////////////////////////////////////////////////////
// Simple Script Host (not the debug version, see ThreadScript.h for the full blown one)
/////////////////////////////////////////////////////////////////////////////////////////////


class Script : public mol::com_obj<mol::ScriptHost>
{
public:

	Script();
	~Script();

	void eval ( const mol::string& engine, const mol::string& script, IScintillAx* sci );
	void debug( const mol::string& engine, const mol::string& script, IScintillAx* sci );
	void call ( const mol::string& engine, const mol::string& func, const mol::string& script );

	void formscript( const mol::string& engine, const mol::string& script, IDispatch* form );
	void formdebug( const mol::string& engine, const mol::string& script, IDispatch* form );
	void formcontrols( IUnknown* form );

    virtual HRESULT  __stdcall OnScriptError( IActiveScriptError *pscripterror);
	virtual HRESULT  __stdcall GetWindow(HWND *phwnd );

private:
	 IScintillAx* sci_;
};

/////////////////////////////////////////////////////////////////////

typedef mol::punk<Script>		ScriptingHost;

/////////////////////////////////////////////////////////////////////

class FormScriptEventHandler : public IDispatch
{
public:
	~FormScriptEventHandler();

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
// Property Sheet
/////////////////////////////////////////////////////////////////////

class TabPage  : public mol::win::PropPage
{
public:
	TabPage();

	virtual void init();
	virtual int apply();
};

/////////////////////////////////////////////////////////////////////

class ExportPage  : public mol::win::PropPage
{
public:

	virtual void command(int c);
};

/////////////////////////////////////////////////////////////////////

class PrefPage  : public mol::ole::OlePropPage
{
public:

	PrefPage()
	{
		hbrushBackground_ = (HBRUSH)::GetStockObject(WHITE_BRUSH);
	}
	virtual void setObjects();
};

/////////////////////////////////////////////////////////////////////


class PasteAs
{
public:
	PasteAs();
	~PasteAs();

	std::wstring get();

private:

	mol::win::ClipBoard clipboard_;
};

#endif