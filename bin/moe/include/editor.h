#ifndef _MOE_DEF_EDITOR_DEFINE_
#define _MOE_DEF_EDITOR_DEFINE_

#include "shared.h"
#include "resource.h"


//////////////////////////////////////////////////////////////////////////////////
// Editor Wnd
//////////////////////////////////////////////////////////////////////////////////

class TaskbarWnd;
class ThreadScript;

class Editor 
	: 
	public mol::MdiChildFrame<Editor,mol::AxWnd<Editor,mol::MdiChild,&CLSID_ScintillAx>>,
	public DispatchMdiWindow<Editor,IMoeDocument,MOE_DOCTYPE_DOC>,
	public mol::ProvideClassInfo<Editor>,
	public mol::interfaces< Editor, mol::implements< IDispatch, IMoeDocument, IProvideClassInfo> >
{
public:

	mol::punk<IScintillAx> sci;

	Editor();
	virtual ~Editor();

	static Instance* CreateInstance(const mol::string& p, bool utf8, bool readOnly);


	// std windows msgs

	LRESULT OnMDIActivate(WPARAM unused,HWND activated);
	void OnMenu( HMENU menu, LPARAM unused );
	void OnDestroy();
	void OnNcDestroy();
	LRESULT OnClose();

	// menu

	void OnSearch( FINDREPLACE* find );
	void OnBeautify ();
	void OnSaveAs();
	void OnSave();
	void OnUnix();
	void OnWin32();
    void OnSettings();
    void OnReload();
	void OnSelectAll();
	void OnConvertTabs();
	void OnInsertColorDialog();

    void OnEncoding();
	void OnLanguage();
	void OnTabUsage();
	void OnTabWidth();
	void OnTabIndents();
	void OnBackspaceUnindents();
	void OnWriteBOM();
	void OnShowLineNumbers();

	void OnExecScript();
	void OnExecForm(  );

	void OnDebugScriptGo();
	void OnDebugScriptStepIn();
	void OnDebugScriptStepOver();
	void OnDebugScriptStepOut();
	void OnDebugScriptStop();
	void OnDebugScriptQuit();

	void OnCut();
	void OnCopy();
	void OnPaste();


	// syntax highlite switches
	void OnLexer(int code, int id, HWND ctrl);

	// user defined commands
    void OnUserCommand(int code, int id, HWND ctrl);

	// user defined batch
	void OnUserBatch( int code, int id, HWND ctrl);

	// user defined forms
	 void OnUserForm(int code, int id, HWND ctrl);

	// user defined scripts
	 void OnUserScript(int code, int id, HWND ctrl);

	LRESULT OnToolbarDropDown(NMTOOLBAR* toolbar );

	void OnScriptThread( int line, IRemoteDebugApplicationThread* remote,IActiveScriptError* pError);
	void OnScriptThreadDone();

   virtual HRESULT __stdcall get_FilePath( BSTR *fname);

protected:

	bool initialize(const mol::string& p, bool utf8, bool readOnly);
	void updateUI();		
	void createMenuFromConf(HMENU m,HMENU popup);
	void walkConf(HMENU parent, ISetting* set, std::map<int,ISetting*>& confMap, int& id);
	void updateModeMenu( mol::Menu& mode );
	void updateToolMenu( HMENU tools );
	void updateDebugMenu( HMENU debug );
	void populateMenuFromConf( HMENU submenu, ISetting* set, std::map<int,ISetting*>& confMap, int& id);



protected:

	// scintilla events sink
    class Sintilla_Events : 
		public mol::stack_obj<ScintillAxEvents>
    {
        public : outer_this(Editor,events); 

		virtual HRESULT __stdcall OnFileNameChanged( BSTR filename, BSTR path);
		virtual HRESULT __stdcall OnShowMenu( VARIANT_BOOL* showMenue);
		virtual HRESULT __stdcall OnPosChange( long line );
		virtual HRESULT __stdcall OnChar( BSTR ch );
		virtual HRESULT __stdcall OnSyntax( long s);
		virtual HRESULT __stdcall OnSystem( long s);
		virtual HRESULT __stdcall OnEncoding( long e);
		virtual HRESULT __stdcall OnMarker( long line);
    } events;

	std::map<int,ISetting*>		shortCutMap;
	std::map<int,ISetting*>		scriptMap;
	std::map<int,ISetting*>		batchMap;
	std::map<int,ISetting*>		formMap;

	//mol::string filename_;

	mol::punk<IRemoteDebugApplicationThread> remote_;
	ThreadScript* ts_;
	mol::string	lasterror_;
};

//////////////////////////////////////////////////////////////////////////////////

class PrettyNode
{
public:
	PrettyNode ( mol::Element* n );

	void toString( std::ostringstream& str, std::string indent);

protected:
    std::string nl2indent( const std::string& input, const std::string& indention );
	mol::Element*	node_;

};

#endif




