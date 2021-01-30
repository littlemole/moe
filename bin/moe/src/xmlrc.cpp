

#include "stdafx.h"
#include "win/res.h"
#include "xmlui.h"

#include "app.h"

#include "dir3.h"

#include "scpdir.h"

#include "editor.h"

#include "taileditor.h"

#include "hex.h"

#include "html2.h"

#include "img.h"

#include "ole.h"

#include "form2.h"

#include "rtf.h"

#include "Docs.h"

#include "MoeBar.h"

#include "mtree.h"

#include "win/msghandler.h"


using namespace mol;




extern "C" void load_codegen_metadata()
{
  ODBGS("load_codegen_metadata()");
  // prepare commands - associates a title string for each command identifier
    UI().addCmd(IDM_FILE,_T("File"));  
  UI().addCmd(IDM_FILE_NEW,_T("New File"));  
  UI().addCmd(IDM_FILE_NEW_RTF,_T("New RTF Document"));  
  UI().addCmd(IDM_FILE_OPEN,_T("File Open"));  
  UI().addCmd(IDM_FILE_OPEN_HEX,_T("Open Hex"));  
  UI().addCmd(IDM_FILE_OPEN_HTML,_T("Open Url"));  
  UI().addCmd(IDM_FILE_OPEN_FOLDER,_T("Open Folder"));  
  UI().addCmd(IDM_FILE_SAVE,_T("Save"));  
  UI().addCmd(IDM_FILE_SAVE_AS,_T("Save As"));  
  UI().addCmd(IDM_FILE_EXIT,_T("Exit"));  
  UI().addCmd(IDM_FILE_PRINT,_T("Print"));  
  UI().addCmd(IDM_FILE_NEWDIR,_T("New Dir"));  
  UI().addCmd(IDM_FILE_RENAME,_T("Rename"));  
  UI().addCmd(IDM_FILE_UPDIR,_T("Up Dir"));  
  UI().addCmd(IDM_FILE_DIREXEC,_T("Up Dir"));  
  UI().addCmd(IDM_FILE_DIRPROP,_T("Up Dir"));  
  UI().addCmd(IDM_RIBBON_RECENTITEMS,_T("Recent Items"));  
  UI().addCmd(IDM_RIBBON_LANGUAGE,_T("Syntax"));  
  UI().addCmd(IDM_RIBBON_ENCODING,_T("Encoding"));  
  UI().addCmd(IDM_RIBBON_TABUSAGE,_T("Tab Usage"));  
  UI().addCmd(IDM_RIBBON_TABWIDTH,_T("Tab Width"));  
  UI().addCmd(IDM_RIBBON_TABCONVERT,_T("Tab Convert"));  
  UI().addCmd(IDM_RIBBON_TABINDENTS,_T("Tab Indents"));  
  UI().addCmd(IDM_RIBBON_BACKSPACE_UNIDENTS,_T("Backspace Unindents"));  
  UI().addCmd(IDM_RIBBON_WRITE_BOM,_T("Write BOM"));  
  UI().addCmd(IDM_RIBBON_BYTES_SHOWN,_T("Show #Bytes"));  
  UI().addCmd(IDM_RIBBON_FONT_CTRL,_T("Font"));  
  UI().addCmd(IDM_EDIT,_T("Edit"));  
  UI().addCmd(IDM_EDIT_SELECT,_T("Select All"));  
  UI().addCmd(IDM_EDIT_FIND,_T("Find"));  
  UI().addCmd(IDM_EDIT_REPLACE,_T("Replace"));  
  UI().addCmd(IDM_EDIT_UNDO,_T("Undo"));  
  UI().addCmd(IDM_EDIT_REDO,_T("Redo"));  
  UI().addCmd(IDM_EDIT_CUT,_T("Cut"));  
  UI().addCmd(IDM_EDIT_COPY,_T("Copy"));  
  UI().addCmd(IDM_EDIT_PASTE,_T("Paste"));  
  UI().addCmd(IDM_EDIT_PASTEAS,_T("Paste As ..."));  
  UI().addCmd(IDM_EDIT_COLOR,_T("Insert Color"));  
  UI().addCmd(IDM_EDIT_UPDATE,_T("Update"));  
  UI().addCmd(IDM_EDIT_STOP,_T("Stop"));  
  UI().addCmd(IDM_EDIT_EXECUTESCRIPT,_T("Exec Script"));  
  UI().addCmd(IDM_EDIT_DEBUG,_T("Debug"));  
  UI().addCmd(IDM_EDIT_DEBUG_GO,_T("Go"));  
  UI().addCmd(IDM_EDIT_DEBUG_STEPIN,_T("Step in"));  
  UI().addCmd(IDM_EDIT_DEBUG_STEPOVER,_T("Step over"));  
  UI().addCmd(IDM_EDIT_DEBUG_STEPOUT,_T("Step out"));  
  UI().addCmd(IDM_EDIT_DEBUG_STOP,_T("Stop"));  
  UI().addCmd(IDM_EDIT_DEBUG_QUIT,_T("Quit"));  
  UI().addCmd(IDM_EDIT_DEBUG_EVAL_EXPR,_T("Eval Expr"));  
  UI().addCmd(IDM_EDIT_INDENTION,_T("Indention"));  
  UI().addCmd(IDM_EDIT_16BYTES,_T("16 Bytes"));  
  UI().addCmd(IDM_EDIT_20BYTES,_T("20 Bytes"));  
  UI().addCmd(IDM_EDIT_24BYTES,_T("24 Bytes"));  
  UI().addCmd(IDM_EDIT_28BYTES,_T("28 Bytes"));  
  UI().addCmd(IDM_EDIT_32BYTES,_T("32 Bytes"));  
  UI().addCmd(IDM_NAVIGATE,_T("Navigate"));  
  UI().addCmd(IDM_NAVIGATE_NEXT,_T("Next"));  
  UI().addCmd(IDM_NAVIGATE_BACK,_T("Back"));  
  UI().addCmd(IDM_TOOLS,_T("Tools"));  
  UI().addCmd(IDM_MODE,_T("Settings"));  
  UI().addCmd(IDM_MODE_EOL,_T("Mode"));  
  UI().addCmd(IDM_MODE_SETTINGS,_T("Settings"));  
  UI().addCmd(IDM_MODE_LANGUAGE,_T("Language"));  
  UI().addCmd(IDM_MODE_UNIX,_T("UNIX"));  
  UI().addCmd(IDM_MODE_WIN32,_T("WIN32"));  
  UI().addCmd(IDM_MODE_PREFERENCES,_T("Preferences"));  
  UI().addCmd(IDM_MODE_USERSTYLES,_T("Scintilla Styles"));  
  UI().addCmd(IDM_MODE_USETABS,_T("Use Tabs"));  
  UI().addCmd(IDM_MODE_DONT_USE_TABS,_T("Don't use Tabs"));  
  UI().addCmd(IDM_MODE_TABWIDTH,_T("tabwidth"));  
  UI().addCmd(IDM_MODE_EDITSETTINGS,_T("Settings"));  
  UI().addCmd(IDM_MODE_SHOW_LINE_NUMBERS,_T("Show Line Numbers"));  
  UI().addCmd(IDM_TOOLS_EXECUTE_NET,_T("Exec .NET"));  
  UI().addCmd(IDM_MODE_EXECUTEFORM,_T("Exec Form"));  
  UI().addCmd(IDM_SETTINGS_LANG,_T("Language Settings"));  
  UI().addCmd(IDM_SETTINGS_MODE,_T("Mode Settings"));  
  UI().addCmd(IDM_USER_FORM,_T("UserForm"));  
  UI().addCmd(IDM_USER_SHORTCUT,_T("Shortcut"));  
  UI().addCmd(IDM_USER_SCRIPT,_T("UserScript"));  
  UI().addCmd(IDM_USER_BATCH,_T("UserBatch"));  
  UI().addCmd(IDM_LEXER_PLAIN,_T("Text"));  
  UI().addCmd(IDM_LEXER_HTML,_T("Html"));  
  UI().addCmd(IDM_LEXER_CSS,_T("CSS"));  
  UI().addCmd(IDM_LEXER_VB,_T("VBS"));  
  UI().addCmd(IDM_LEXER_JAVASCRIPT,_T("JS"));  
  UI().addCmd(IDM_LEXER_SQL,_T("SQL"));  
  UI().addCmd(IDM_LEXER_SHELL,_T("Shell"));  
  UI().addCmd(IDM_LEXER_PERL,_T("Perl"));  
  UI().addCmd(IDM_LEXER_CPP,_T("C/C++"));  
  UI().addCmd(IDM_LEXER_JAVA,_T("Java"));  
  UI().addCmd(IDM_LEXER_CSHARP,_T("C#"));  
  UI().addCmd(IDM_LEXER_D,_T("D"));  
  UI().addCmd(IDM_LEXER_PYTHON,_T("Python"));  
  UI().addCmd(IDM_VIEW,_T("View"));  
  UI().addCmd(IDM_VIEW_DIRVIEW,_T("View Dirview"));  
  UI().addCmd(IDM_VIEW_MAXIMIZE,_T("Maximize"));  
  UI().addCmd(IDM_VIEW_MINIMIZE,_T("Minimize"));  
  UI().addCmd(IDM_VIEW_TILE,_T("Tile"));  
  UI().addCmd(IDM_VIEW_CASCADE,_T("Cascade"));  
  UI().addCmd(IDM_VIEW_NEXT,_T("Next"));  
  UI().addCmd(IDM_VIEW_CLOSE,_T("Close"));  
  UI().addCmd(IDM_VIEW_CLOSEALL,_T("Close All"));  
  UI().addCmd(IDM_VIEW_TOOLBARS,_T("Toolbars"));  
  UI().addCmd(IDM_TOOLBARS_FILEBAR,_T("Filebar"));  
  UI().addCmd(IDM_TOOLBARS_EDITBAR,_T("Editbar"));  
  UI().addCmd(IDM_TOOLBARS_TOOLBAR,_T("Toolbar"));  
  UI().addCmd(IDM_TOOLBARS_SETTINGBAR,_T("Settingbar"));  
  UI().addCmd(IDM_TOOLBARS_VIEWBAR,_T("Viewbar"));  
  UI().addCmd(IDM_TOOLBARS_USERBAR,_T("Userbar"));  
  UI().addCmd(IDM_TOOLBARS_DIRVIEW,_T("Dirbar"));  
  UI().addCmd(IDM_TOOLBARS_FREEZE,_T("Freeze"));  
  UI().addCmd(IDM_VIEW_WINDOWS,_T("Windows"));  
  UI().addCmd(IDM_VIEW_WINDOWS_TEXT,_T("Select Child"));  
  UI().addCmd(IDM_HELP,_T("?"));  
  UI().addCmd(IDM_HELP_ABOUT,_T("About"));  
  UI().addCmd(IDM_ESCAPE,_T("Escape"));  
  UI().addCmd(IDM_F1,_T(""));  
  UI().addCmd(IDM_F2,_T(""));  
  UI().addCmd(IDM_F3,_T(""));  
  UI().addCmd(IDM_F4,_T(""));  
  UI().addCmd(IDM_F5,_T(""));  
  UI().addCmd(IDM_F6,_T(""));  
  UI().addCmd(IDM_F7,_T(""));  
  UI().addCmd(IDM_F8,_T(""));  
  UI().addCmd(IDM_F9,_T(""));  
  UI().addCmd(IDM_F10,_T(""));  
  UI().addCmd(IDM_F11,_T(""));  
  UI().addCmd(IDM_F12,_T(""));  
  UI().addCmd(IDM_TAB,_T("TAB"));  
  UI().addCmd(IDM_TAB_CLOSETAB,_T("Close"));  
  UI().addCmd(IDM_TAB_CLOSEALLBUTTHIS,_T("Close Others"));  
  UI().addCmd(IDM_TAB_RELOADTAB,_T("Reload"));  
  UI().addCmd(IDM_TAB_SAVETAB,_T("Save"));  
  UI().addCmd(IDM_TAB_DIRTAB,_T("Directory"));  
  UI().addCmd(IDM_WIZARD,_T("Wizard"));  
  UI().addCmd(IDM_FILE_MEMBERS,_T("Members"));  
  UI().addCmd(IDM_FILE_EVENTS,_T("Events"));  
  UI().addCmd(IDM_FORMLANG,_T("Language"));  
  UI().addCmd(IDM_FORMLANG_JAVASCRIPT,_T("Javascript"));  
  UI().addCmd(IDM_FORMLANG_VBSCRIPT,_T("VBScript"));  
  UI().addCmd(IDM_FORMLANG_PERLSCRIPT,_T("PerlScript"));  
  UI().addCmd(IDM_TREE,_T("Tree Window Context Menu"));  
  UI().addCmd(IDM_TREE_OPEN,_T("Open in moe"));  
  UI().addCmd(IDM_TREE_UPDATE,_T("Update"));  
  UI().addCmd(IDM_TREE_RENAME,_T("Rename"));  
  UI().addCmd(IDM_TREE_DELETE,_T("Delete"));  
  UI().addCmd(IDM_TREE_CUT,_T("Delete"));  
  UI().addCmd(IDM_TREE_COPY,_T("Delete"));  
  UI().addCmd(IDM_TREE_PASTE,_T("Execute"));  
  UI().addCmd(IDM_TREE_PROPERTIES,_T("Properties"));  
  UI().addCmd(IDM_TREE_EXECUTE,_T("Execute"));  
  UI().addCmd(IDM_TREE_NEWDIR,_T("New Directory"));  
  UI().addCmd(IDM_CLI_RETURN,_T(""));  
  UI().addCmd(IDM_HTML_FORM_HIDE,_T(""));  

  
  //foreach bitmap - loads and registers bitmap
  // optionally associate cmds to toolbar icons on bitmap
    
  UI().addBmp(IDB_MOE_FAV);
  
  UI().addBmp(IDB_MOE_GO);
  
  UI().addBmp(IDB_DEBUG_GO);
  
  UI().addBmp(IDB_DEBUG_PAUSE);
  
  UI().addBmp(IDB_DEBUG_QUIT);
  
  UI().addBmp(IDB_DEBUG_STEPIN);
  
  UI().addBmp(IDB_DEBUG_STEPOVER);
  
  UI().addBmp(IDB_DEBUG_STEPOUT);
  
  UI().addBmp(IDB_TOOLBAR);
  UI().addBmpCmd( IDB_TOOLBAR, IDM_FILE_NEW );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_FILE_OPEN );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_FILE_OPEN_FOLDER );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_FILE_SAVE );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_FILE_SAVE_AS );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_FILE_PRINT );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_FILE_EXIT );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_UNDO );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_REDO );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_CUT );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_COPY );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_PASTE );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_FIND );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_REPLACE );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_EXECUTESCRIPT );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_MODE_EXECUTEFORM );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_USER_SCRIPT );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_USER_BATCH );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_USER_FORM );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_USER_SHORTCUT );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_COLOR );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_MODE_EOL );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_MODE_LANGUAGE );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_MODE_SETTINGS );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_MODE_PREFERENCES );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_MODE_EDITSETTINGS );
  UI().addBmpCmd( IDB_TOOLBAR, -1 );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_TAB_CLOSEALLBUTTHIS );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_VIEW_MAXIMIZE );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_VIEW_MINIMIZE );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_VIEW_CASCADE );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_VIEW_TILE );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_VIEW_NEXT );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_TAB_RELOADTAB );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_TAB_DIRTAB );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_VIEW_WINDOWS );
  UI().addBmpCmd( IDB_TOOLBAR, -1 );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_HELP_ABOUT );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_VIEW_CLOSE );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_VIEW_CLOSEALL );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_FILE_OPEN_HTML );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_VIEW_TOOLBARS );
  UI().addBmpCmd( IDB_TOOLBAR, -1 );
  UI().addBmpCmd( IDB_TOOLBAR, -1 );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_DEBUG );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_DEBUG_QUIT );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_DEBUG_STEPIN );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_DEBUG_STEPOUT );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_DEBUG_STEPOVER );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_DEBUG_STOP );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_DEBUG_GO );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_FILE_NEW_RTF );
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_PASTEAS );


  // menus
  
  // a main menu
  UI().addMenu(IDM_MOE);    

    UI().addSubMenu(  IDM_MOE,  IDM_MOE,  IDM_FILE );
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_NEW, IDB_TOOLBAR, IDM_FILE_NEW, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_FILE);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_OPEN, IDB_TOOLBAR, IDM_FILE_OPEN, false, true);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_OPEN_HTML, IDB_TOOLBAR, IDM_FILE_OPEN_HTML, false, true);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_OPEN_FOLDER, IDB_TOOLBAR, IDM_FILE_OPEN_FOLDER, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_FILE);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_SAVE, IDB_TOOLBAR, IDM_FILE_SAVE, false, true);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_SAVE_AS, IDB_TOOLBAR, IDM_FILE_SAVE_AS, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_FILE);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_PRINT, IDB_TOOLBAR, IDM_FILE_PRINT, false, true);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_MODE_PREFERENCES, IDB_TOOLBAR, IDM_MODE_PREFERENCES, false, true);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_MODE_USERSTYLES, IDB_TOOLBAR, IDM_MODE_USERSTYLES, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_FILE);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_NEW_RTF, IDB_TOOLBAR, IDM_FILE_NEW_RTF, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_FILE);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_EXIT, IDB_TOOLBAR, IDM_FILE_EXIT, false, true);

    UI().addSubMenu(  IDM_MOE,  IDM_MOE,  IDM_EDIT );
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_FIND, IDB_TOOLBAR, IDM_EDIT_FIND, false, true);
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_REPLACE, IDB_TOOLBAR, IDM_EDIT_REPLACE, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_EDIT);
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_UNDO, IDB_TOOLBAR, IDM_EDIT_UNDO, false, true);
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_REDO, IDB_TOOLBAR, IDM_EDIT_REDO, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_EDIT);
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_CUT, IDB_TOOLBAR, IDM_EDIT_CUT, false, true);
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_COPY, IDB_TOOLBAR, IDM_EDIT_COPY, false, true);
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_PASTE, IDB_TOOLBAR, IDM_EDIT_PASTE, false, true);
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_PASTEAS, IDB_TOOLBAR, IDM_EDIT_PASTEAS, false, true);

    UI().addSubMenu(  IDM_MOE,  IDM_MOE,  IDM_TOOLS );
        UI().addMenuItem(IDM_MOE, IDM_TOOLS, IDM_EDIT_COLOR, IDB_TOOLBAR, IDM_EDIT_COLOR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_TOOLS);
        UI().addMenuItem(IDM_MOE, IDM_TOOLS, IDM_EDIT_EXECUTESCRIPT, IDB_TOOLBAR, IDM_EDIT_EXECUTESCRIPT, false, true);
    UI().addSubMenu(  IDM_MOE, IDM_TOOLS, IDM_EDIT_DEBUG, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE, IDM_EDIT_DEBUG, IDM_EDIT_DEBUG_GO, IDB_TOOLBAR, IDM_EDIT_DEBUG_GO, false, true);
        UI().addMenuItem(IDM_MOE, IDM_EDIT_DEBUG, IDM_EDIT_DEBUG_STEPIN, IDB_TOOLBAR, IDM_EDIT_DEBUG_STEPIN, false, true);
        UI().addMenuItem(IDM_MOE, IDM_EDIT_DEBUG, IDM_EDIT_DEBUG_STEPOVER, IDB_TOOLBAR, IDM_EDIT_DEBUG_STEPOVER, false, true);
        UI().addMenuItem(IDM_MOE, IDM_EDIT_DEBUG, IDM_EDIT_DEBUG_STEPOUT, IDB_TOOLBAR, IDM_EDIT_DEBUG_STEPOUT, false, true);
        UI().addMenuItem(IDM_MOE, IDM_EDIT_DEBUG, IDM_EDIT_DEBUG_STOP, IDB_TOOLBAR, IDM_EDIT_DEBUG_STOP, false, true);
        UI().addMenuItem(IDM_MOE, IDM_EDIT_DEBUG, IDM_EDIT_DEBUG_QUIT, IDB_TOOLBAR, IDM_EDIT_DEBUG_QUIT, false, true);
        UI().addMenuItem(IDM_MOE, IDM_TOOLS, IDM_MODE_EXECUTEFORM, IDB_TOOLBAR, IDM_MODE_EXECUTEFORM, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_TOOLS);
    UI().addSubMenu(  IDM_MOE, IDM_TOOLS, IDM_USER_SCRIPT, IDB_TOOLBAR);
    UI().addSubMenu(  IDM_MOE, IDM_TOOLS, IDM_USER_BATCH, IDB_TOOLBAR);
    UI().addSubMenu(  IDM_MOE, IDM_TOOLS, IDM_USER_FORM, IDB_TOOLBAR);
    UI().addSubMenu(  IDM_MOE, IDM_TOOLS, IDM_USER_SHORTCUT, IDB_TOOLBAR);

    UI().addSubMenu(  IDM_MOE,  IDM_MOE,  IDM_MODE );
    UI().addSubMenu(  IDM_MOE, IDM_MODE, IDM_MODE_EOL, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE, IDM_MODE_EOL, IDM_MODE_UNIX, IDB_TOOLBAR, IDM_MODE_UNIX, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE_EOL, IDM_MODE_WIN32, IDB_TOOLBAR, IDM_MODE_WIN32, true, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE, IDM_MODE_SHOW_LINE_NUMBERS, IDB_TOOLBAR, IDM_MODE_SHOW_LINE_NUMBERS, false, true);
    UI().addSubMenu(  IDM_MOE, IDM_MODE, IDM_MODE_LANGUAGE, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_PLAIN, IDB_TOOLBAR, IDM_LEXER_PLAIN, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_MODE_LANGUAGE);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_HTML, IDB_TOOLBAR, IDM_LEXER_HTML, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_CSS, IDB_TOOLBAR, IDM_LEXER_CSS, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_MODE_LANGUAGE);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_VB, IDB_TOOLBAR, IDM_LEXER_VB, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_JAVASCRIPT, IDB_TOOLBAR, IDM_LEXER_JAVASCRIPT, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_MODE_LANGUAGE);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_SQL, IDB_TOOLBAR, IDM_LEXER_SQL, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_MODE_LANGUAGE);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_SHELL, IDB_TOOLBAR, IDM_LEXER_SHELL, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_PERL, IDB_TOOLBAR, IDM_LEXER_PERL, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_MODE_LANGUAGE);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_CPP, IDB_TOOLBAR, IDM_LEXER_CPP, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_JAVA, IDB_TOOLBAR, IDM_LEXER_JAVA, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_CSHARP, IDB_TOOLBAR, IDM_LEXER_CSHARP, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_D, IDB_TOOLBAR, IDM_LEXER_D, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_PYTHON, IDB_TOOLBAR, IDM_LEXER_PYTHON, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE, IDM_MODE_SETTINGS, IDB_TOOLBAR, IDM_MODE_SETTINGS, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_MODE);
        UI().addMenuItem(IDM_MOE, IDM_MODE, IDM_MODE_USERSTYLES, IDB_TOOLBAR, IDM_MODE_USERSTYLES, false, true);

    UI().addSubMenu(  IDM_MOE,  IDM_MOE,  IDM_VIEW );
        UI().addMenuItem(IDM_MOE, IDM_VIEW, IDM_VIEW_MAXIMIZE, IDB_TOOLBAR, IDM_VIEW_MAXIMIZE, false, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW, IDM_VIEW_MINIMIZE, IDB_TOOLBAR, IDM_VIEW_MINIMIZE, false, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW, IDM_VIEW_TILE, IDB_TOOLBAR, IDM_VIEW_TILE, false, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW, IDM_VIEW_CASCADE, IDB_TOOLBAR, IDM_VIEW_CASCADE, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_VIEW);
        UI().addMenuItem(IDM_MOE, IDM_VIEW, IDM_VIEW_CLOSE, IDB_TOOLBAR, IDM_VIEW_CLOSE, false, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW, IDM_VIEW_CLOSEALL, IDB_TOOLBAR, IDM_VIEW_CLOSEALL, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_VIEW);
    UI().addSubMenu(  IDM_MOE, IDM_VIEW, IDM_VIEW_TOOLBARS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_VIEW_DIRVIEW, IDB_TOOLBAR, IDM_VIEW_DIRVIEW, true, true);
    UI().addMenuSeparator(IDM_MOE,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FILEBAR, IDB_TOOLBAR, IDM_TOOLBARS_FILEBAR, true, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_EDITBAR, IDB_TOOLBAR, IDM_TOOLBARS_EDITBAR, true, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_TOOLBAR, IDB_TOOLBAR, IDM_TOOLBARS_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_SETTINGBAR, IDB_TOOLBAR, IDM_TOOLBARS_SETTINGBAR, true, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_VIEWBAR, IDB_TOOLBAR, IDM_TOOLBARS_VIEWBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_USERBAR, IDB_TOOLBAR, IDM_TOOLBARS_USERBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FREEZE, IDB_TOOLBAR, IDM_TOOLBARS_FREEZE, false, true);
    UI().addSubMenu(  IDM_MOE, IDM_VIEW, IDM_VIEW_WINDOWS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_WINDOWS, IDM_VIEW_WINDOWS_TEXT, IDB_TOOLBAR, IDM_VIEW_WINDOWS_TEXT, false, false);

    UI().addSubMenu(  IDM_MOE,  IDM_MOE,  IDM_HELP );
        UI().addMenuItem(IDM_MOE, IDM_HELP, IDM_HELP_ABOUT, IDB_TOOLBAR, IDM_HELP_ABOUT, false, true);
  
  // a main menu
  UI().addMenu(IDM_MOE_DIR);    

    UI().addSubMenu(  IDM_MOE_DIR,  IDM_MOE_DIR,  IDM_FILE );
        UI().addMenuItem(IDM_MOE_DIR, IDM_FILE, IDM_FILE_NEW, IDB_TOOLBAR, IDM_FILE_NEW, false, true);
    UI().addMenuSeparator(IDM_MOE_DIR,IDM_FILE);
        UI().addMenuItem(IDM_MOE_DIR, IDM_FILE, IDM_FILE_OPEN, IDB_TOOLBAR, IDM_FILE_OPEN, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_FILE, IDM_FILE_OPEN_HTML, IDB_TOOLBAR, IDM_FILE_OPEN_HTML, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_FILE, IDM_FILE_OPEN_FOLDER, IDB_TOOLBAR, IDM_FILE_OPEN_FOLDER, false, true);
    UI().addMenuSeparator(IDM_MOE_DIR,IDM_FILE);
        UI().addMenuItem(IDM_MOE_DIR, IDM_FILE, IDM_MODE_PREFERENCES, IDB_TOOLBAR, IDM_MODE_PREFERENCES, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_FILE, IDM_MODE_USERSTYLES, IDB_TOOLBAR, IDM_MODE_USERSTYLES, false, true);
    UI().addMenuSeparator(IDM_MOE_DIR,IDM_FILE);
        UI().addMenuItem(IDM_MOE_DIR, IDM_FILE, IDM_FILE_EXIT, IDB_TOOLBAR, IDM_FILE_EXIT, false, true);

    UI().addSubMenu(  IDM_MOE_DIR,  IDM_MOE_DIR,  IDM_EDIT );
        UI().addMenuItem(IDM_MOE_DIR, IDM_EDIT, IDM_EDIT_CUT, IDB_TOOLBAR, IDM_EDIT_CUT, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_EDIT, IDM_EDIT_COPY, IDB_TOOLBAR, IDM_EDIT_COPY, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_EDIT, IDM_EDIT_PASTE, IDB_TOOLBAR, IDM_EDIT_PASTE, false, true);

    UI().addSubMenu(  IDM_MOE_DIR,  IDM_MOE_DIR,  IDM_VIEW );
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_MAXIMIZE, IDB_TOOLBAR, IDM_VIEW_MAXIMIZE, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_MINIMIZE, IDB_TOOLBAR, IDM_VIEW_MINIMIZE, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_TILE, IDB_TOOLBAR, IDM_VIEW_TILE, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_CASCADE, IDB_TOOLBAR, IDM_VIEW_CASCADE, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_CLOSE, IDB_TOOLBAR, IDM_VIEW_CLOSE, false, true);
    UI().addMenuSeparator(IDM_MOE_DIR,IDM_VIEW);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_CLOSEALL, IDB_TOOLBAR, IDM_VIEW_CLOSEALL, false, true);
    UI().addMenuSeparator(IDM_MOE_DIR,IDM_VIEW);
    UI().addSubMenu(  IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_TOOLBARS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_VIEW_DIRVIEW, IDB_TOOLBAR, IDM_VIEW_DIRVIEW, true, true);
    UI().addMenuSeparator(IDM_MOE_DIR,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FILEBAR, IDB_TOOLBAR, IDM_TOOLBARS_FILEBAR, true, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_EDITBAR, IDB_TOOLBAR, IDM_TOOLBARS_EDITBAR, true, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_TOOLBAR, IDB_TOOLBAR, IDM_TOOLBARS_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_SETTINGBAR, IDB_TOOLBAR, IDM_TOOLBARS_SETTINGBAR, true, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_VIEWBAR, IDB_TOOLBAR, IDM_TOOLBARS_VIEWBAR, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_USERBAR, IDB_TOOLBAR, IDM_TOOLBARS_USERBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_DIR,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FREEZE, IDB_TOOLBAR, IDM_TOOLBARS_FREEZE, false, true);
    UI().addSubMenu(  IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_WINDOWS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_WINDOWS, IDM_VIEW_WINDOWS_TEXT, IDB_TOOLBAR, IDM_VIEW_WINDOWS_TEXT, false, false);

    UI().addSubMenu(  IDM_MOE_DIR,  IDM_MOE_DIR,  IDM_HELP );
        UI().addMenuItem(IDM_MOE_DIR, IDM_HELP, IDM_HELP_ABOUT, IDB_TOOLBAR, IDM_HELP_ABOUT, false, true);
  
  // a main menu
  UI().addMenu(IDM_MOE_IMG);    

    UI().addSubMenu(  IDM_MOE_IMG,  IDM_MOE_IMG,  IDM_FILE );
        UI().addMenuItem(IDM_MOE_IMG, IDM_FILE, IDM_FILE_NEW, IDB_TOOLBAR, IDM_FILE_NEW, false, true);
    UI().addMenuSeparator(IDM_MOE_IMG,IDM_FILE);
        UI().addMenuItem(IDM_MOE_IMG, IDM_FILE, IDM_FILE_OPEN, IDB_TOOLBAR, IDM_FILE_OPEN, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_FILE, IDM_FILE_OPEN_HTML, IDB_TOOLBAR, IDM_FILE_OPEN_HTML, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_FILE, IDM_FILE_OPEN_FOLDER, IDB_TOOLBAR, IDM_FILE_OPEN_FOLDER, false, true);
    UI().addMenuSeparator(IDM_MOE_IMG,IDM_FILE);
        UI().addMenuItem(IDM_MOE_IMG, IDM_FILE, IDM_MODE_PREFERENCES, IDB_TOOLBAR, IDM_MODE_PREFERENCES, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_FILE, IDM_MODE_USERSTYLES, IDB_TOOLBAR, IDM_MODE_USERSTYLES, false, true);
    UI().addMenuSeparator(IDM_MOE_IMG,IDM_FILE);
        UI().addMenuItem(IDM_MOE_IMG, IDM_FILE, IDM_FILE_EXIT, IDB_TOOLBAR, IDM_FILE_EXIT, false, true);

    UI().addSubMenu(  IDM_MOE_IMG,  IDM_MOE_IMG,  IDM_EDIT );
        UI().addMenuItem(IDM_MOE_IMG, IDM_EDIT, IDM_EDIT_CUT, IDB_TOOLBAR, IDM_EDIT_CUT, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_EDIT, IDM_EDIT_COPY, IDB_TOOLBAR, IDM_EDIT_COPY, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_EDIT, IDM_EDIT_PASTE, IDB_TOOLBAR, IDM_EDIT_PASTE, false, true);

    UI().addSubMenu(  IDM_MOE_IMG,  IDM_MOE_IMG,  IDM_VIEW );
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_MAXIMIZE, IDB_TOOLBAR, IDM_VIEW_MAXIMIZE, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_MINIMIZE, IDB_TOOLBAR, IDM_VIEW_MINIMIZE, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_TILE, IDB_TOOLBAR, IDM_VIEW_TILE, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_CASCADE, IDB_TOOLBAR, IDM_VIEW_CASCADE, false, true);
    UI().addMenuSeparator(IDM_MOE_IMG,IDM_VIEW);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_CLOSE, IDB_TOOLBAR, IDM_VIEW_CLOSE, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_CLOSEALL, IDB_TOOLBAR, IDM_VIEW_CLOSEALL, false, true);
    UI().addMenuSeparator(IDM_MOE_IMG,IDM_VIEW);
    UI().addSubMenu(  IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_TOOLBARS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_VIEW_DIRVIEW, IDB_TOOLBAR, IDM_VIEW_DIRVIEW, true, true);
    UI().addMenuSeparator(IDM_MOE_IMG,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FILEBAR, IDB_TOOLBAR, IDM_TOOLBARS_FILEBAR, true, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_EDITBAR, IDB_TOOLBAR, IDM_TOOLBARS_EDITBAR, true, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_TOOLBAR, IDB_TOOLBAR, IDM_TOOLBARS_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_SETTINGBAR, IDB_TOOLBAR, IDM_TOOLBARS_SETTINGBAR, true, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_VIEWBAR, IDB_TOOLBAR, IDM_TOOLBARS_VIEWBAR, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_USERBAR, IDB_TOOLBAR, IDM_TOOLBARS_USERBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_IMG,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FREEZE, IDB_TOOLBAR, IDM_TOOLBARS_FREEZE, false, true);
    UI().addSubMenu(  IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_WINDOWS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_WINDOWS, IDM_VIEW_WINDOWS_TEXT, IDB_TOOLBAR, IDM_VIEW_WINDOWS_TEXT, false, false);

    UI().addSubMenu(  IDM_MOE_IMG,  IDM_MOE_IMG,  IDM_HELP );
        UI().addMenuItem(IDM_MOE_IMG, IDM_HELP, IDM_HELP_ABOUT, IDB_TOOLBAR, IDM_HELP_ABOUT, false, true);
  
  // a main menu
  UI().addMenu(IDM_SMALL_MENU);    

    UI().addSubMenu(  IDM_SMALL_MENU,  IDM_SMALL_MENU,  IDM_FILE );
        UI().addMenuItem(IDM_SMALL_MENU, IDM_FILE, IDM_FILE_NEW, IDB_TOOLBAR, IDM_FILE_NEW, false, true);
    UI().addMenuSeparator(IDM_SMALL_MENU,IDM_FILE);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_FILE, IDM_FILE_OPEN, IDB_TOOLBAR, IDM_FILE_OPEN, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_FILE, IDM_FILE_OPEN_HTML, IDB_TOOLBAR, IDM_FILE_OPEN_HTML, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_FILE, IDM_FILE_OPEN_FOLDER, IDB_TOOLBAR, IDM_FILE_OPEN_FOLDER, false, true);
    UI().addMenuSeparator(IDM_SMALL_MENU,IDM_FILE);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_FILE, IDM_MODE_PREFERENCES, IDB_TOOLBAR, IDM_MODE_PREFERENCES, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_FILE, IDM_MODE_USERSTYLES, IDB_TOOLBAR, IDM_MODE_USERSTYLES, false, true);
    UI().addMenuSeparator(IDM_SMALL_MENU,IDM_FILE);
    UI().addMenuSeparator(IDM_SMALL_MENU,IDM_FILE);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_FILE, IDM_FILE_EXIT, IDB_TOOLBAR, IDM_FILE_EXIT, false, true);

    UI().addSubMenu(  IDM_SMALL_MENU,  IDM_SMALL_MENU,  IDM_EDIT );
        UI().addMenuItem(IDM_SMALL_MENU, IDM_EDIT, IDM_EDIT_CUT, IDB_TOOLBAR, IDM_EDIT_CUT, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_EDIT, IDM_EDIT_COPY, IDB_TOOLBAR, IDM_EDIT_COPY, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_EDIT, IDM_EDIT_PASTE, IDB_TOOLBAR, IDM_EDIT_PASTE, false, true);

    UI().addSubMenu(  IDM_SMALL_MENU,  IDM_SMALL_MENU,  IDM_VIEW );
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_MAXIMIZE, IDB_TOOLBAR, IDM_VIEW_MAXIMIZE, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_MINIMIZE, IDB_TOOLBAR, IDM_VIEW_MINIMIZE, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_TILE, IDB_TOOLBAR, IDM_VIEW_TILE, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_CASCADE, IDB_TOOLBAR, IDM_VIEW_CASCADE, false, true);
    UI().addMenuSeparator(IDM_SMALL_MENU,IDM_VIEW);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_CLOSE, IDB_TOOLBAR, IDM_VIEW_CLOSE, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_CLOSEALL, IDB_TOOLBAR, IDM_VIEW_CLOSEALL, false, true);
    UI().addMenuSeparator(IDM_SMALL_MENU,IDM_VIEW);
    UI().addSubMenu(  IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_TOOLBARS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_VIEW_DIRVIEW, IDB_TOOLBAR, IDM_VIEW_DIRVIEW, true, true);
    UI().addMenuSeparator(IDM_SMALL_MENU,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FILEBAR, IDB_TOOLBAR, IDM_TOOLBARS_FILEBAR, true, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_EDITBAR, IDB_TOOLBAR, IDM_TOOLBARS_EDITBAR, true, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_TOOLBAR, IDB_TOOLBAR, IDM_TOOLBARS_TOOLBAR, true, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_SETTINGBAR, IDB_TOOLBAR, IDM_TOOLBARS_SETTINGBAR, true, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_VIEWBAR, IDB_TOOLBAR, IDM_TOOLBARS_VIEWBAR, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_USERBAR, IDB_TOOLBAR, IDM_TOOLBARS_USERBAR, false, true);
    UI().addMenuSeparator(IDM_SMALL_MENU,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FREEZE, IDB_TOOLBAR, IDM_TOOLBARS_FREEZE, false, true);
    UI().addSubMenu(  IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_WINDOWS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_WINDOWS, IDM_VIEW_WINDOWS_TEXT, IDB_TOOLBAR, IDM_VIEW_WINDOWS_TEXT, false, false);

    UI().addSubMenu(  IDM_SMALL_MENU,  IDM_SMALL_MENU,  IDM_HELP );
        UI().addMenuItem(IDM_SMALL_MENU, IDM_HELP, IDM_HELP_ABOUT, IDB_TOOLBAR, IDM_HELP_ABOUT, false, true);
  
  // a main menu
  UI().addMenu(IDM_MOE_HEX);    

    UI().addSubMenu(  IDM_MOE_HEX,  IDM_MOE_HEX,  IDM_FILE );
        UI().addMenuItem(IDM_MOE_HEX, IDM_FILE, IDM_FILE_NEW, IDB_TOOLBAR, IDM_FILE_NEW, false, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_FILE);
        UI().addMenuItem(IDM_MOE_HEX, IDM_FILE, IDM_FILE_OPEN, IDB_TOOLBAR, IDM_FILE_OPEN, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_FILE, IDM_FILE_OPEN_HTML, IDB_TOOLBAR, IDM_FILE_OPEN_HTML, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_FILE, IDM_FILE_OPEN_FOLDER, IDB_TOOLBAR, IDM_FILE_OPEN_FOLDER, false, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_FILE);
        UI().addMenuItem(IDM_MOE_HEX, IDM_FILE, IDM_MODE_PREFERENCES, IDB_TOOLBAR, IDM_MODE_PREFERENCES, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_FILE, IDM_MODE_USERSTYLES, IDB_TOOLBAR, IDM_MODE_USERSTYLES, false, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_FILE);
        UI().addMenuItem(IDM_MOE_HEX, IDM_FILE, IDM_FILE_EXIT, IDB_TOOLBAR, IDM_FILE_EXIT, false, true);

    UI().addSubMenu(  IDM_MOE_HEX,  IDM_MOE_HEX,  IDM_EDIT );
        UI().addMenuItem(IDM_MOE_HEX, IDM_EDIT, IDM_EDIT_FIND, IDB_TOOLBAR, IDM_EDIT_FIND, false, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_EDIT);
        UI().addMenuItem(IDM_MOE_HEX, IDM_EDIT, IDM_EDIT_16BYTES, IDB_TOOLBAR, IDM_EDIT_16BYTES, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_EDIT, IDM_EDIT_20BYTES, IDB_TOOLBAR, IDM_EDIT_20BYTES, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_EDIT, IDM_EDIT_24BYTES, IDB_TOOLBAR, IDM_EDIT_24BYTES, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_EDIT, IDM_EDIT_28BYTES, IDB_TOOLBAR, IDM_EDIT_28BYTES, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_EDIT, IDM_EDIT_32BYTES, IDB_TOOLBAR, IDM_EDIT_32BYTES, false, true);

    UI().addSubMenu(  IDM_MOE_HEX,  IDM_MOE_HEX,  IDM_VIEW );
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_MAXIMIZE, IDB_TOOLBAR, IDM_VIEW_MAXIMIZE, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_MINIMIZE, IDB_TOOLBAR, IDM_VIEW_MINIMIZE, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_TILE, IDB_TOOLBAR, IDM_VIEW_TILE, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_CASCADE, IDB_TOOLBAR, IDM_VIEW_CASCADE, false, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_VIEW);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_CLOSE, IDB_TOOLBAR, IDM_VIEW_CLOSE, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_CLOSEALL, IDB_TOOLBAR, IDM_VIEW_CLOSEALL, false, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_VIEW);
    UI().addSubMenu(  IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_TOOLBARS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_VIEW_DIRVIEW, IDB_TOOLBAR, IDM_VIEW_DIRVIEW, true, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FILEBAR, IDB_TOOLBAR, IDM_TOOLBARS_FILEBAR, true, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_EDITBAR, IDB_TOOLBAR, IDM_TOOLBARS_EDITBAR, true, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_TOOLBAR, IDB_TOOLBAR, IDM_TOOLBARS_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_SETTINGBAR, IDB_TOOLBAR, IDM_TOOLBARS_SETTINGBAR, true, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_VIEWBAR, IDB_TOOLBAR, IDM_TOOLBARS_VIEWBAR, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_USERBAR, IDB_TOOLBAR, IDM_TOOLBARS_USERBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FREEZE, IDB_TOOLBAR, IDM_TOOLBARS_FREEZE, false, true);
    UI().addSubMenu(  IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_WINDOWS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_WINDOWS, IDM_VIEW_WINDOWS_TEXT, IDB_TOOLBAR, IDM_VIEW_WINDOWS_TEXT, false, false);

    UI().addSubMenu(  IDM_MOE_HEX,  IDM_MOE_HEX,  IDM_HELP );
        UI().addMenuItem(IDM_MOE_HEX, IDM_HELP, IDM_HELP_ABOUT, IDB_TOOLBAR, IDM_HELP_ABOUT, false, true);
  
  // a main menu
  UI().addMenu(IDM_MOE_HTML);    

    UI().addSubMenu(  IDM_MOE_HTML,  IDM_MOE_HTML,  IDM_FILE );
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_FILE_NEW, IDB_TOOLBAR, IDM_FILE_NEW, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_FILE);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_FILE_OPEN, IDB_TOOLBAR, IDM_FILE_OPEN, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_FILE_OPEN_HTML, IDB_TOOLBAR, IDM_FILE_OPEN_HTML, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_FILE_OPEN_FOLDER, IDB_TOOLBAR, IDM_FILE_OPEN_FOLDER, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_FILE);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_FILE_SAVE_AS, IDB_TOOLBAR, IDM_FILE_SAVE_AS, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_FILE);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_FILE_PRINT, IDB_TOOLBAR, IDM_FILE_PRINT, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_MODE_PREFERENCES, IDB_TOOLBAR, IDM_MODE_PREFERENCES, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_MODE_USERSTYLES, IDB_TOOLBAR, IDM_MODE_USERSTYLES, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_FILE);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_FILE_EXIT, IDB_TOOLBAR, IDM_FILE_EXIT, false, true);

    UI().addSubMenu(  IDM_MOE_HTML,  IDM_MOE_HTML,  IDM_EDIT );
        UI().addMenuItem(IDM_MOE_HTML, IDM_EDIT, IDM_EDIT_FIND, IDB_TOOLBAR, IDM_EDIT_FIND, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_EDIT);
        UI().addMenuItem(IDM_MOE_HTML, IDM_EDIT, IDM_EDIT_UNDO, IDB_TOOLBAR, IDM_EDIT_UNDO, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_EDIT, IDM_EDIT_REDO, IDB_TOOLBAR, IDM_EDIT_REDO, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_EDIT);
        UI().addMenuItem(IDM_MOE_HTML, IDM_EDIT, IDM_EDIT_COPY, IDB_TOOLBAR, IDM_EDIT_COPY, false, true);

    UI().addSubMenu(  IDM_MOE_HTML,  IDM_MOE_HTML,  IDM_NAVIGATE );
        UI().addMenuItem(IDM_MOE_HTML, IDM_NAVIGATE, IDM_NAVIGATE_BACK, IDB_TOOLBAR, IDM_NAVIGATE_BACK, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_NAVIGATE, IDM_NAVIGATE_NEXT, IDB_TOOLBAR, IDM_NAVIGATE_NEXT, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_NAVIGATE);
        UI().addMenuItem(IDM_MOE_HTML, IDM_NAVIGATE, IDM_EDIT_UPDATE, IDB_TOOLBAR, IDM_EDIT_UPDATE, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_NAVIGATE, IDM_EDIT_STOP, IDB_TOOLBAR, IDM_EDIT_STOP, false, true);

    UI().addSubMenu(  IDM_MOE_HTML,  IDM_MOE_HTML,  IDM_VIEW );
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_MAXIMIZE, IDB_TOOLBAR, IDM_VIEW_MAXIMIZE, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_MINIMIZE, IDB_TOOLBAR, IDM_VIEW_MINIMIZE, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_TILE, IDB_TOOLBAR, IDM_VIEW_TILE, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_CASCADE, IDB_TOOLBAR, IDM_VIEW_CASCADE, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_VIEW);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_CLOSE, IDB_TOOLBAR, IDM_VIEW_CLOSE, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_CLOSEALL, IDB_TOOLBAR, IDM_VIEW_CLOSEALL, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_VIEW);
    UI().addSubMenu(  IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_TOOLBARS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_VIEW_DIRVIEW, IDB_TOOLBAR, IDM_VIEW_DIRVIEW, true, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FILEBAR, IDB_TOOLBAR, IDM_TOOLBARS_FILEBAR, true, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_EDITBAR, IDB_TOOLBAR, IDM_TOOLBARS_EDITBAR, true, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_TOOLBAR, IDB_TOOLBAR, IDM_TOOLBARS_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_SETTINGBAR, IDB_TOOLBAR, IDM_TOOLBARS_SETTINGBAR, true, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_VIEWBAR, IDB_TOOLBAR, IDM_TOOLBARS_VIEWBAR, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_USERBAR, IDB_TOOLBAR, IDM_TOOLBARS_USERBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FREEZE, IDB_TOOLBAR, IDM_TOOLBARS_FREEZE, false, true);
    UI().addSubMenu(  IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_WINDOWS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_WINDOWS, IDM_VIEW_WINDOWS_TEXT, IDB_TOOLBAR, IDM_VIEW_WINDOWS_TEXT, false, false);

    UI().addSubMenu(  IDM_MOE_HTML,  IDM_MOE_HTML,  IDM_HELP );
        UI().addMenuItem(IDM_MOE_HTML, IDM_HELP, IDM_HELP_ABOUT, IDB_TOOLBAR, IDM_HELP_ABOUT, false, true);
  
  // a main menu
  UI().addMenu(IDM_MENU_TAB);    

    UI().addSubMenu(  IDM_MENU_TAB,  IDM_MENU_TAB,  IDM_TAB );
        UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_VIEW_CLOSE, IDB_TOOLBAR, IDM_VIEW_CLOSE, false, true);
        UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_TAB_CLOSEALLBUTTHIS, IDB_TOOLBAR, IDM_TAB_CLOSEALLBUTTHIS, false, true);
    UI().addMenuSeparator(IDM_MENU_TAB,IDM_TAB);
        UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_TAB_RELOADTAB, IDB_TOOLBAR, IDM_TAB_RELOADTAB, false, true);
        UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_FILE_SAVE, IDB_TOOLBAR, IDM_FILE_SAVE, false, true);
    UI().addMenuSeparator(IDM_MENU_TAB,IDM_TAB);
        UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_TAB_DIRTAB, IDB_TOOLBAR, IDM_TAB_DIRTAB, false, true);
  
  // a main menu
  UI().addMenu(IDM_MENU_DESIGNFORM);    

    UI().addSubMenu(  IDM_MENU_DESIGNFORM,  IDM_MENU_DESIGNFORM,  IDM_WIZARD );
        UI().addMenuItem(IDM_MENU_DESIGNFORM, IDM_WIZARD, IDM_FILE_MEMBERS, IDB_TOOLBAR, IDM_FILE_MEMBERS, false, true);
        UI().addMenuItem(IDM_MENU_DESIGNFORM, IDM_WIZARD, IDM_FILE_EVENTS, IDB_TOOLBAR, IDM_FILE_EVENTS, false, true);

    UI().addSubMenu(  IDM_MENU_DESIGNFORM,  IDM_MENU_DESIGNFORM,  IDM_FORMLANG );
        UI().addMenuItem(IDM_MENU_DESIGNFORM, IDM_FORMLANG, IDM_FORMLANG_JAVASCRIPT, IDB_TOOLBAR, IDM_FORMLANG_JAVASCRIPT, false, true);
        UI().addMenuItem(IDM_MENU_DESIGNFORM, IDM_FORMLANG, IDM_FORMLANG_VBSCRIPT, IDB_TOOLBAR, IDM_FORMLANG_VBSCRIPT, false, true);
        UI().addMenuItem(IDM_MENU_DESIGNFORM, IDM_FORMLANG, IDM_FORMLANG_PERLSCRIPT, IDB_TOOLBAR, IDM_FORMLANG_PERLSCRIPT, false, true);
  
  // a main menu
  UI().addMenu(IDM_CONTEXT_TREE);    

    UI().addSubMenu(  IDM_CONTEXT_TREE,  IDM_CONTEXT_TREE,  IDM_TREE );
        UI().addMenuItem(IDM_CONTEXT_TREE, IDM_TREE, IDM_TREE_OPEN, IDB_TOOLBAR, IDM_FILE_OPEN, false, true);
        UI().addMenuItem(IDM_CONTEXT_TREE, IDM_TREE, IDM_TREE_UPDATE, IDB_TOOLBAR, IDM_TAB_RELOADTAB, false, true);
    UI().addMenuSeparator(IDM_CONTEXT_TREE,IDM_TREE);
        UI().addMenuItem(IDM_CONTEXT_TREE, IDM_TREE, IDM_TREE_RENAME, IDB_TOOLBAR, IDM_EDIT_PASTE, false, true);
        UI().addMenuItem(IDM_CONTEXT_TREE, IDM_TREE, IDM_TREE_DELETE, IDB_TOOLBAR, IDM_VIEW_CLOSE, false, true);
    UI().addMenuSeparator(IDM_CONTEXT_TREE,IDM_TREE);
        UI().addMenuItem(IDM_CONTEXT_TREE, IDM_TREE, IDM_EDIT_CUT, IDB_TOOLBAR, IDM_EDIT_CUT, false, true);
        UI().addMenuItem(IDM_CONTEXT_TREE, IDM_TREE, IDM_EDIT_COPY, IDB_TOOLBAR, IDM_EDIT_COPY, false, true);
        UI().addMenuItem(IDM_CONTEXT_TREE, IDM_TREE, IDM_EDIT_PASTE, IDB_TOOLBAR, IDM_EDIT_PASTE, false, true);
    UI().addMenuSeparator(IDM_CONTEXT_TREE,IDM_TREE);
        UI().addMenuItem(IDM_CONTEXT_TREE, IDM_TREE, IDM_TREE_PROPERTIES, IDB_TOOLBAR, IDM_MODE_PREFERENCES, false, true);
        UI().addMenuItem(IDM_CONTEXT_TREE, IDM_TREE, IDM_TREE_EXECUTE, IDB_TOOLBAR, IDM_EDIT_EXECUTESCRIPT, false, true);
        UI().addMenuItem(IDM_CONTEXT_TREE, IDM_TREE, IDM_TREE_NEWDIR, IDB_TOOLBAR, IDM_FILE_OPEN_FOLDER, false, true);
  
  // a main menu
  UI().addMenu(IDM_MOE_RTF);    

    UI().addSubMenu(  IDM_MOE_RTF,  IDM_MOE_RTF,  IDM_FILE );
        UI().addMenuItem(IDM_MOE_RTF, IDM_FILE, IDM_FILE_NEW, IDB_TOOLBAR, IDM_FILE_NEW, false, true);
    UI().addMenuSeparator(IDM_MOE_RTF,IDM_FILE);
        UI().addMenuItem(IDM_MOE_RTF, IDM_FILE, IDM_FILE_OPEN, IDB_TOOLBAR, IDM_FILE_OPEN, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_FILE, IDM_FILE_OPEN_HTML, IDB_TOOLBAR, IDM_FILE_OPEN_HTML, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_FILE, IDM_FILE_OPEN_FOLDER, IDB_TOOLBAR, IDM_FILE_OPEN_FOLDER, false, true);
    UI().addMenuSeparator(IDM_MOE_RTF,IDM_FILE);
        UI().addMenuItem(IDM_MOE_RTF, IDM_FILE, IDM_FILE_SAVE, IDB_TOOLBAR, IDM_FILE_SAVE, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_FILE, IDM_FILE_SAVE_AS, IDB_TOOLBAR, IDM_FILE_SAVE_AS, false, true);
    UI().addMenuSeparator(IDM_MOE_RTF,IDM_FILE);
        UI().addMenuItem(IDM_MOE_RTF, IDM_FILE, IDM_FILE_PRINT, IDB_TOOLBAR, IDM_FILE_PRINT, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_FILE, IDM_MODE_PREFERENCES, IDB_TOOLBAR, IDM_MODE_PREFERENCES, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_FILE, IDM_MODE_USERSTYLES, IDB_TOOLBAR, IDM_MODE_USERSTYLES, false, true);
    UI().addMenuSeparator(IDM_MOE_RTF,IDM_FILE);
        UI().addMenuItem(IDM_MOE_RTF, IDM_FILE, IDM_FILE_NEW_RTF, IDB_TOOLBAR, IDM_FILE_NEW_RTF, false, true);
    UI().addMenuSeparator(IDM_MOE_RTF,IDM_FILE);
        UI().addMenuItem(IDM_MOE_RTF, IDM_FILE, IDM_FILE_EXIT, IDB_TOOLBAR, IDM_FILE_EXIT, false, true);

    UI().addSubMenu(  IDM_MOE_RTF,  IDM_MOE_RTF,  IDM_EDIT );
        UI().addMenuItem(IDM_MOE_RTF, IDM_EDIT, IDM_EDIT_FIND, IDB_TOOLBAR, IDM_EDIT_FIND, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_EDIT, IDM_EDIT_REPLACE, IDB_TOOLBAR, IDM_EDIT_REPLACE, false, true);
    UI().addMenuSeparator(IDM_MOE_RTF,IDM_EDIT);
        UI().addMenuItem(IDM_MOE_RTF, IDM_EDIT, IDM_EDIT_UNDO, IDB_TOOLBAR, IDM_EDIT_UNDO, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_EDIT, IDM_EDIT_REDO, IDB_TOOLBAR, IDM_EDIT_REDO, false, true);
    UI().addMenuSeparator(IDM_MOE_RTF,IDM_EDIT);
        UI().addMenuItem(IDM_MOE_RTF, IDM_EDIT, IDM_EDIT_CUT, IDB_TOOLBAR, IDM_EDIT_CUT, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_EDIT, IDM_EDIT_COPY, IDB_TOOLBAR, IDM_EDIT_COPY, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_EDIT, IDM_EDIT_PASTE, IDB_TOOLBAR, IDM_EDIT_PASTE, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_EDIT, IDM_EDIT_PASTEAS, IDB_TOOLBAR, IDM_EDIT_PASTEAS, false, true);

    UI().addSubMenu(  IDM_MOE_RTF,  IDM_MOE_RTF,  IDM_TOOLS );
    UI().addSubMenu(  IDM_MOE_RTF, IDM_TOOLS, IDM_USER_SCRIPT, IDB_TOOLBAR);
    UI().addSubMenu(  IDM_MOE_RTF, IDM_TOOLS, IDM_USER_BATCH, IDB_TOOLBAR);
    UI().addSubMenu(  IDM_MOE_RTF, IDM_TOOLS, IDM_USER_FORM, IDB_TOOLBAR);
    UI().addSubMenu(  IDM_MOE_RTF, IDM_TOOLS, IDM_USER_SHORTCUT, IDB_TOOLBAR);

    UI().addSubMenu(  IDM_MOE_RTF,  IDM_MOE_RTF,  IDM_VIEW );
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW, IDM_VIEW_MAXIMIZE, IDB_TOOLBAR, IDM_VIEW_MAXIMIZE, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW, IDM_VIEW_MINIMIZE, IDB_TOOLBAR, IDM_VIEW_MINIMIZE, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW, IDM_VIEW_TILE, IDB_TOOLBAR, IDM_VIEW_TILE, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW, IDM_VIEW_CASCADE, IDB_TOOLBAR, IDM_VIEW_CASCADE, false, true);
    UI().addMenuSeparator(IDM_MOE_RTF,IDM_VIEW);
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW, IDM_VIEW_CLOSE, IDB_TOOLBAR, IDM_VIEW_CLOSE, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW, IDM_VIEW_CLOSEALL, IDB_TOOLBAR, IDM_VIEW_CLOSEALL, false, true);
    UI().addMenuSeparator(IDM_MOE_RTF,IDM_VIEW);
    UI().addSubMenu(  IDM_MOE_RTF, IDM_VIEW, IDM_VIEW_TOOLBARS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW_TOOLBARS, IDM_VIEW_DIRVIEW, IDB_TOOLBAR, IDM_VIEW_DIRVIEW, true, true);
    UI().addMenuSeparator(IDM_MOE_RTF,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FILEBAR, IDB_TOOLBAR, IDM_TOOLBARS_FILEBAR, true, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_EDITBAR, IDB_TOOLBAR, IDM_TOOLBARS_EDITBAR, true, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_TOOLBAR, IDB_TOOLBAR, IDM_TOOLBARS_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_SETTINGBAR, IDB_TOOLBAR, IDM_TOOLBARS_SETTINGBAR, true, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_VIEWBAR, IDB_TOOLBAR, IDM_TOOLBARS_VIEWBAR, false, true);
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_USERBAR, IDB_TOOLBAR, IDM_TOOLBARS_USERBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_RTF,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FREEZE, IDB_TOOLBAR, IDM_TOOLBARS_FREEZE, false, true);
    UI().addSubMenu(  IDM_MOE_RTF, IDM_VIEW, IDM_VIEW_WINDOWS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_RTF, IDM_VIEW_WINDOWS, IDM_VIEW_WINDOWS_TEXT, IDB_TOOLBAR, IDM_VIEW_WINDOWS_TEXT, false, false);

    UI().addSubMenu(  IDM_MOE_RTF,  IDM_MOE_RTF,  IDM_HELP );
        UI().addMenuItem(IDM_MOE_RTF, IDM_HELP, IDM_HELP_ABOUT, IDB_TOOLBAR, IDM_HELP_ABOUT, false, true);

mol::msgMap<Editor>().addCmdHandler( IDM_VIEW_CLOSEALL, make_handler(&Editor::OnCloseAll) );


}

