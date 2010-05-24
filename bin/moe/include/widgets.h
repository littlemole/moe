#ifndef MOE_DIALOGS_DEF_GUARD_
#define MOE_DIALOGS_DEF_GUARD_

#include "win/res.h"
#include "win/wnd.h"
#include "shared.h"


/////////////////////////////////////////////////////////////////////////////////////////////
// widgets for moe
/////////////////////////////////////////////////////////////////////////////////////////////


class MoeWnd;

mol::string findFile(const mol::string& f);
std::string engineFromPath(const std::string& path);

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
// poorer tab dlg
/////////////////////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////////////////////
// URL Dialog
/////////////////////////////////////////////////////////////////////////////////////////////

class UrlDlg  : public mol::win::Dialog
{
STACKSINGLETON(UrlDlg);
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


class Script : public mol::com_obj<mol::ScriptHost>
{
public:

	void eval ( const mol::string& engine, const mol::string& script );
	void debug( const mol::string& engine, const mol::string& script );
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

/////////////////////////////////////////////////////////////////////
// COM event sinks
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
// compiler event sink
/////////////////////////////////////////////////////////////////////////////////////////////
/*
class CompilerEvents	:	
		public mol::Dispatch< ICompilerDualMsg, &IID_ICompilerDualMsg, &LIBID_JIT,1,0 >,
		public mol::interfaces< CompilerEvents, 
			mol::implements< IDispatch, ICompilerMsg> >
{
public:

    HRESULT Advise(IUnknown* object )
    {
		return mol::advise<ICompilerMsg>(object,this,cookie_);
    }
    HRESULT UnAdvise(IUnknown* object )
    {
        return mol::unadvise<ICompilerMsg>(object,cookie_);
    }

private:
    DWORD           cookie_;
};
*/

// compiler sink

/*
class CompilerSink : public stack_obj<CompilerEvents>
{
STACKSINGLETON(CompilerSink);
public : 
	HRESULT virtual __stdcall ErrorMsg(BSTR error);
	HRESULT virtual __stdcall Success();

private:
	CompilerSink() {};
	~CompilerSink() {};
};
*/


// tree events sink
class TreeWndSink : public mol::stack_obj<ShellTreeEvents>
{
STACKSINGLETON(TreeWndSink);
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
STACKSINGLETON(MoeDrop);
public : 
	HRESULT virtual __stdcall Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect);
	HRESULT virtual __stdcall DragEnter( IDataObject*, DWORD, POINTL, DWORD* );
	HRESULT virtual __stdcall DragOver( DWORD, POINTL, DWORD* );
	HRESULT virtual __stdcall DragLeave();
private:
	MoeDrop() {}
	~MoeDrop() {}
};


#endif