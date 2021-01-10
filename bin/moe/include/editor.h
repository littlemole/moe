#ifndef _MOE_DEF_EDITOR_DEFINE_
#define _MOE_DEF_EDITOR_DEFINE_

#include "mdichild.h"
#include "resource.h"
#include "MoeBar.h"
#include "ThreadScript.h"
#include "win/io.h"

//////////////////////////////////////////////////////////////////////////////////
// Editor Wnd
//////////////////////////////////////////////////////////////////////////////////

class TaskbarWnd;
class MoeCLIBar;
class CLIControl;

class Editor 
	: public MoeAxChild<
				Editor,
				MOE_DOCTYPE_DOC,
				&CLSID_ScintillAx,
				IDM_MOE
			>
{
friend class EditorMenu;
friend class EditorScript;
public:

	mol::punk<IScintillAx> sci;

	Editor();
	virtual ~Editor();

	static Instance* CreateInstance(const std::wstring& p, long enc = CP_UTF8, bool readOnly = false);

	// std windows msgs

	void OnMDIActivate(WPARAM unused,HWND activated);
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
	void OnDebugScriptEval();

	void OnCut();
	void OnCopy();
	void OnPaste();
	void OnPasteAs();

	void OnCliReturn();

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

	void OnScriptThread( int line, std::wstring error);
	void OnScriptThreadDone();

   virtual HRESULT __stdcall get_FilePath( BSTR *fname);

   virtual HRESULT __stdcall SaveAsDialog();

protected:

	bool initialize(const std::wstring& p, long enc, bool readOnly);
	void updateUI();		
	void prepareInterfaces();
	void scrollDown();

	virtual void checkModifiedOnDisk();
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
		virtual HRESULT __stdcall OnTabUsage(VARIANT_BOOL vb);
		virtual HRESULT __stdcall OnTabIndents(VARIANT_BOOL vb);
		virtual HRESULT __stdcall OnBackspaceUnindents(VARIANT_BOOL vb);
		virtual HRESULT __stdcall OnShowLineNumbers(VARIANT_BOOL vb);
		virtual HRESULT __stdcall OnWriteBOM(VARIANT_BOOL vb);
		virtual HRESULT __stdcall OnTabWidth(long w);

	} events;

	std::map<int,ISetting*>		shortCutMap;
	std::map<int,ISetting*>		scriptMap;
	std::map<int,ISetting*>		batchMap;
	std::map<int,ISetting*>		formMap;

	mol::Timer timer_;

	ScriptDebugger::Instance* debugger_;
	std::wstring	lasterror_;
	FILETIME lastWriteTime_;


	mol::punk<IScintillAxProperties> props_;
	mol::punk<IScintillAxPosition> position_;
	mol::punk<IScintillAxSelection> selection_;
	mol::punk<IScintillAxLine> line_;
	mol::punk<IScintillAxAnnotation> annotation_;
	mol::punk<IScintillAxMarkers> markers_;
	mol::punk<IScintillAxText> text_;

	bool saving_;
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




