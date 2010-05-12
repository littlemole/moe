

#include "stdafx.h"
#include "win/res.h"
#include "xmlui.h"

#include "app.h"

#include "dir3.h"

#include "editor.h"

#include "hex.h"

#include "html.h"

#include "img.h"

#include "ole.h"

#include "form.h"

#include "Docs.h"

#include "MoeBar.h"


using namespace mol;




extern "C" void load_codegen_metadata()
{
  ODBGS("load_codegen_metadata()");
  // prepare commands - associates a title string for each command identifier
    UI().addCmd(IDM_FILE,_T("File"));  
  UI().addCmd(IDM_FILE_NEW,_T("New File"));  
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
  UI().addCmd(IDM_EDIT,_T("Edit"));  
  UI().addCmd(IDM_EDIT_SELECT,_T("Select All"));  
  UI().addCmd(IDM_EDIT_FIND,_T("Find"));  
  UI().addCmd(IDM_EDIT_REPLACE,_T("Replace"));  
  UI().addCmd(IDM_EDIT_UNDO,_T("Undo"));  
  UI().addCmd(IDM_EDIT_REDO,_T("Redo"));  
  UI().addCmd(IDM_EDIT_CUT,_T("Cut"));  
  UI().addCmd(IDM_EDIT_COPY,_T("Copy"));  
  UI().addCmd(IDM_EDIT_PASTE,_T("Paste"));  
  UI().addCmd(IDM_EDIT_COLOR,_T("Insert Color"));  
  UI().addCmd(IDM_EDIT_UPDATE,_T("Update"));  
  UI().addCmd(IDM_EDIT_STOP,_T("Stop"));  
  UI().addCmd(IDM_EDIT_EXECUTESCRIPT,_T("Exec Script"));  
  UI().addCmd(IDM_EDIT_DEBUGSCRIPT,_T("Debug Script"));  
  UI().addCmd(IDM_EDIT_INDENTION,_T("Indention"));  
  UI().addCmd(IDM_EDIT_16BYTES,_T("16 Bytes"));  
  UI().addCmd(IDM_EDIT_20BYTES,_T("20 Bytes"));  
  UI().addCmd(IDM_EDIT_24BYTES,_T("24 Bytes"));  
  UI().addCmd(IDM_EDIT_28BYTES,_T("28 Bytes"));  
  UI().addCmd(IDM_EDIT_32BYTES,_T("32 Bytes"));  
  UI().addCmd(IDM_TOOLS,_T("Tools"));  
  UI().addCmd(IDM_MODE,_T("Settings"));  
  UI().addCmd(IDM_MODE_EOL,_T("Mode"));  
  UI().addCmd(IDM_MODE_SETTINGS,_T("Settings"));  
  UI().addCmd(IDM_MODE_LANGUAGE,_T("Language"));  
  UI().addCmd(IDM_MODE_UNIX,_T("UNIX"));  
  UI().addCmd(IDM_MODE_WIN32,_T("WIN32"));  
  UI().addCmd(IDM_MODE_PREFERENCES,_T("Preferences"));  
  UI().addCmd(IDM_MODE_USETABS,_T("Use Tabs"));  
  UI().addCmd(IDM_MODE_DONT_USE_TABS,_T("Don't use Tabs"));  
  UI().addCmd(IDM_MODE_TABWIDTH,_T("tabwidth"));  
  UI().addCmd(IDM_MODE_EDITSETTINGS,_T("Settings"));  
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
  UI().addCmd(IDM_TAB_JUMPTAB,_T("Jump"));  

  
  //foreach bitmap - loads and registers bitmap
  // optionally associate cmds to toolbar icons on bitmap
    
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
  UI().addBmpCmd( IDB_TOOLBAR, IDM_EDIT_DEBUGSCRIPT );
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
  UI().addBmpCmd( IDB_TOOLBAR, IDM_TAB_JUMPTAB );
  
  UI().addBmp(IDB_MOE_FAV);
  
  UI().addBmp(IDB_MOE_GO);


  // menus
  
  // a main menu
  UI().addMenu(IDM_MOE);    

    UI().addSubMenu(  IDM_MOE,  IDM_MOE,  IDM_FILE );
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_NEW, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_OPEN, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_OPEN_HTML, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_OPEN_FOLDER, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_FILE);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_SAVE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_SAVE_AS, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_FILE);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_PRINT, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_MODE_PREFERENCES, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_FILE);
        UI().addMenuItem(IDM_MOE, IDM_FILE, IDM_FILE_EXIT, IDB_TOOLBAR, false, true);

    UI().addSubMenu(  IDM_MOE,  IDM_MOE,  IDM_EDIT );
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_FIND, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_REPLACE, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_EDIT);
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_UNDO, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_REDO, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_EDIT);
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_CUT, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_COPY, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_EDIT, IDM_EDIT_PASTE, IDB_TOOLBAR, false, true);

    UI().addSubMenu(  IDM_MOE,  IDM_MOE,  IDM_TOOLS );
        UI().addMenuItem(IDM_MOE, IDM_TOOLS, IDM_EDIT_COLOR, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_TOOLS);
        UI().addMenuItem(IDM_MOE, IDM_TOOLS, IDM_EDIT_EXECUTESCRIPT, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_TOOLS, IDM_EDIT_DEBUGSCRIPT, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_TOOLS, IDM_MODE_EXECUTEFORM, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_TOOLS);
    UI().addSubMenu(  IDM_MOE, IDM_TOOLS, IDM_USER_SCRIPT, IDB_TOOLBAR);
    UI().addSubMenu(  IDM_MOE, IDM_TOOLS, IDM_USER_BATCH, IDB_TOOLBAR);
    UI().addSubMenu(  IDM_MOE, IDM_TOOLS, IDM_USER_FORM, IDB_TOOLBAR);
    UI().addSubMenu(  IDM_MOE, IDM_TOOLS, IDM_USER_SHORTCUT, IDB_TOOLBAR);

    UI().addSubMenu(  IDM_MOE,  IDM_MOE,  IDM_MODE );
    UI().addSubMenu(  IDM_MOE, IDM_MODE, IDM_MODE_EOL, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE, IDM_MODE_EOL, IDM_MODE_UNIX, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE_EOL, IDM_MODE_WIN32, IDB_TOOLBAR, true, true);
    UI().addSubMenu(  IDM_MOE, IDM_MODE, IDM_MODE_LANGUAGE, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_PLAIN, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_MODE_LANGUAGE);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_HTML, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_CSS, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_MODE_LANGUAGE);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_VB, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_JAVASCRIPT, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_MODE_LANGUAGE);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_SQL, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_MODE_LANGUAGE);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_SHELL, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_PERL, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_MODE_LANGUAGE);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_CPP, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_JAVA, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE_LANGUAGE, IDM_LEXER_CSHARP, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_MODE, IDM_MODE_SETTINGS, IDB_TOOLBAR, false, true);

    UI().addSubMenu(  IDM_MOE,  IDM_MOE,  IDM_VIEW );
        UI().addMenuItem(IDM_MOE, IDM_VIEW, IDM_VIEW_MAXIMIZE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW, IDM_VIEW_MINIMIZE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW, IDM_VIEW_TILE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW, IDM_VIEW_CASCADE, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_VIEW);
        UI().addMenuItem(IDM_MOE, IDM_VIEW, IDM_VIEW_CLOSE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW, IDM_VIEW_CLOSEALL, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_VIEW);
    UI().addSubMenu(  IDM_MOE, IDM_VIEW, IDM_VIEW_TOOLBARS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_VIEW_DIRVIEW, IDB_TOOLBAR, true, true);
    UI().addMenuSeparator(IDM_MOE,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FILEBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_EDITBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_TOOLBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_SETTINGBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_VIEWBAR, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_USERBAR, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FREEZE, IDB_TOOLBAR, false, true);
    UI().addSubMenu(  IDM_MOE, IDM_VIEW, IDM_VIEW_WINDOWS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE, IDM_VIEW_WINDOWS, IDM_VIEW_WINDOWS_TEXT, IDB_TOOLBAR, false, false);

    UI().addSubMenu(  IDM_MOE,  IDM_MOE,  IDM_HELP );
        UI().addMenuItem(IDM_MOE, IDM_HELP, IDM_HELP_ABOUT, IDB_TOOLBAR, false, true);
  
  // a main menu
  UI().addMenu(IDM_MOE_DIR);    

    UI().addSubMenu(  IDM_MOE_DIR,  IDM_MOE_DIR,  IDM_FILE );
        UI().addMenuItem(IDM_MOE_DIR, IDM_FILE, IDM_FILE_NEW, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_FILE, IDM_FILE_OPEN, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_FILE, IDM_FILE_OPEN_HTML, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_FILE, IDM_FILE_OPEN_FOLDER, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_DIR,IDM_FILE);
        UI().addMenuItem(IDM_MOE_DIR, IDM_FILE, IDM_MODE_PREFERENCES, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_DIR,IDM_FILE);
        UI().addMenuItem(IDM_MOE_DIR, IDM_FILE, IDM_FILE_EXIT, IDB_TOOLBAR, false, true);

    UI().addSubMenu(  IDM_MOE_DIR,  IDM_MOE_DIR,  IDM_EDIT );
        UI().addMenuItem(IDM_MOE_DIR, IDM_EDIT, IDM_EDIT_CUT, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_EDIT, IDM_EDIT_COPY, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_EDIT, IDM_EDIT_PASTE, IDB_TOOLBAR, false, true);

    UI().addSubMenu(  IDM_MOE_DIR,  IDM_MOE_DIR,  IDM_VIEW );
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_MAXIMIZE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_MINIMIZE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_TILE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_CASCADE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_CLOSE, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_DIR,IDM_VIEW);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_CLOSEALL, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_DIR,IDM_VIEW);
    UI().addSubMenu(  IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_TOOLBARS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_VIEW_DIRVIEW, IDB_TOOLBAR, true, true);
    UI().addMenuSeparator(IDM_MOE_DIR,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FILEBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_EDITBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_TOOLBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_SETTINGBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_VIEWBAR, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_USERBAR, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_DIR,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FREEZE, IDB_TOOLBAR, false, true);
    UI().addSubMenu(  IDM_MOE_DIR, IDM_VIEW, IDM_VIEW_WINDOWS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_DIR, IDM_VIEW_WINDOWS, IDM_VIEW_WINDOWS_TEXT, IDB_TOOLBAR, false, false);

    UI().addSubMenu(  IDM_MOE_DIR,  IDM_MOE_DIR,  IDM_HELP );
        UI().addMenuItem(IDM_MOE_DIR, IDM_HELP, IDM_HELP_ABOUT, IDB_TOOLBAR, false, true);
  
  // a main menu
  UI().addMenu(IDM_MOE_IMG);    

    UI().addSubMenu(  IDM_MOE_IMG,  IDM_MOE_IMG,  IDM_FILE );
        UI().addMenuItem(IDM_MOE_IMG, IDM_FILE, IDM_FILE_NEW, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_FILE, IDM_FILE_OPEN, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_FILE, IDM_FILE_OPEN_HTML, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_FILE, IDM_FILE_OPEN_FOLDER, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_IMG,IDM_FILE);
        UI().addMenuItem(IDM_MOE_IMG, IDM_FILE, IDM_MODE_PREFERENCES, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_IMG,IDM_FILE);
        UI().addMenuItem(IDM_MOE_IMG, IDM_FILE, IDM_FILE_EXIT, IDB_TOOLBAR, false, true);

    UI().addSubMenu(  IDM_MOE_IMG,  IDM_MOE_IMG,  IDM_EDIT );
        UI().addMenuItem(IDM_MOE_IMG, IDM_EDIT, IDM_EDIT_CUT, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_EDIT, IDM_EDIT_COPY, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_EDIT, IDM_EDIT_PASTE, IDB_TOOLBAR, false, true);

    UI().addSubMenu(  IDM_MOE_IMG,  IDM_MOE_IMG,  IDM_VIEW );
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_MAXIMIZE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_MINIMIZE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_TILE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_CASCADE, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_IMG,IDM_VIEW);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_CLOSE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_CLOSEALL, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_IMG,IDM_VIEW);
    UI().addSubMenu(  IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_TOOLBARS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_VIEW_DIRVIEW, IDB_TOOLBAR, true, true);
    UI().addMenuSeparator(IDM_MOE_IMG,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FILEBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_EDITBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_TOOLBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_SETTINGBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_VIEWBAR, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_USERBAR, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_IMG,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FREEZE, IDB_TOOLBAR, false, true);
    UI().addSubMenu(  IDM_MOE_IMG, IDM_VIEW, IDM_VIEW_WINDOWS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_IMG, IDM_VIEW_WINDOWS, IDM_VIEW_WINDOWS_TEXT, IDB_TOOLBAR, false, false);

    UI().addSubMenu(  IDM_MOE_IMG,  IDM_MOE_IMG,  IDM_HELP );
        UI().addMenuItem(IDM_MOE_IMG, IDM_HELP, IDM_HELP_ABOUT, IDB_TOOLBAR, false, true);
  
  // a main menu
  UI().addMenu(IDM_SMALL_MENU);    

    UI().addSubMenu(  IDM_SMALL_MENU,  IDM_SMALL_MENU,  IDM_FILE );
        UI().addMenuItem(IDM_SMALL_MENU, IDM_FILE, IDM_FILE_NEW, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_FILE, IDM_FILE_OPEN, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_FILE, IDM_FILE_OPEN_HTML, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_FILE, IDM_FILE_OPEN_FOLDER, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_SMALL_MENU,IDM_FILE);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_FILE, IDM_MODE_PREFERENCES, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_SMALL_MENU,IDM_FILE);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_FILE, IDM_FILE_EXIT, IDB_TOOLBAR, false, true);

    UI().addSubMenu(  IDM_SMALL_MENU,  IDM_SMALL_MENU,  IDM_EDIT );
        UI().addMenuItem(IDM_SMALL_MENU, IDM_EDIT, IDM_EDIT_CUT, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_EDIT, IDM_EDIT_COPY, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_EDIT, IDM_EDIT_PASTE, IDB_TOOLBAR, false, true);

    UI().addSubMenu(  IDM_SMALL_MENU,  IDM_SMALL_MENU,  IDM_VIEW );
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_MAXIMIZE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_MINIMIZE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_TILE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_CASCADE, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_SMALL_MENU,IDM_VIEW);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_CLOSE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_CLOSEALL, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_SMALL_MENU,IDM_VIEW);
    UI().addSubMenu(  IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_TOOLBARS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_VIEW_DIRVIEW, IDB_TOOLBAR, true, true);
    UI().addMenuSeparator(IDM_SMALL_MENU,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FILEBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_EDITBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_TOOLBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_SETTINGBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_VIEWBAR, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_USERBAR, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_SMALL_MENU,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FREEZE, IDB_TOOLBAR, false, true);
    UI().addSubMenu(  IDM_SMALL_MENU, IDM_VIEW, IDM_VIEW_WINDOWS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_SMALL_MENU, IDM_VIEW_WINDOWS, IDM_VIEW_WINDOWS_TEXT, IDB_TOOLBAR, false, false);

    UI().addSubMenu(  IDM_SMALL_MENU,  IDM_SMALL_MENU,  IDM_HELP );
        UI().addMenuItem(IDM_SMALL_MENU, IDM_HELP, IDM_HELP_ABOUT, IDB_TOOLBAR, false, true);
  
  // a main menu
  UI().addMenu(IDM_MOE_HEX);    

    UI().addSubMenu(  IDM_MOE_HEX,  IDM_MOE_HEX,  IDM_FILE );
        UI().addMenuItem(IDM_MOE_HEX, IDM_FILE, IDM_FILE_NEW, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_FILE, IDM_FILE_OPEN, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_FILE, IDM_FILE_OPEN_HTML, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_FILE, IDM_FILE_OPEN_FOLDER, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_FILE);
        UI().addMenuItem(IDM_MOE_HEX, IDM_FILE, IDM_MODE_PREFERENCES, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_FILE);
        UI().addMenuItem(IDM_MOE_HEX, IDM_FILE, IDM_FILE_EXIT, IDB_TOOLBAR, false, true);

    UI().addSubMenu(  IDM_MOE_HEX,  IDM_MOE_HEX,  IDM_EDIT );
        UI().addMenuItem(IDM_MOE_HEX, IDM_EDIT, IDM_EDIT_FIND, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_EDIT);
        UI().addMenuItem(IDM_MOE_HEX, IDM_EDIT, IDM_EDIT_16BYTES, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_EDIT, IDM_EDIT_20BYTES, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_EDIT, IDM_EDIT_24BYTES, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_EDIT, IDM_EDIT_28BYTES, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_EDIT, IDM_EDIT_32BYTES, IDB_TOOLBAR, false, true);

    UI().addSubMenu(  IDM_MOE_HEX,  IDM_MOE_HEX,  IDM_VIEW );
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_MAXIMIZE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_MINIMIZE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_TILE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_CASCADE, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_VIEW);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_CLOSE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_CLOSEALL, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_VIEW);
    UI().addSubMenu(  IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_TOOLBARS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_VIEW_DIRVIEW, IDB_TOOLBAR, true, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FILEBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_EDITBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_TOOLBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_SETTINGBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_VIEWBAR, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_USERBAR, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HEX,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FREEZE, IDB_TOOLBAR, false, true);
    UI().addSubMenu(  IDM_MOE_HEX, IDM_VIEW, IDM_VIEW_WINDOWS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_HEX, IDM_VIEW_WINDOWS, IDM_VIEW_WINDOWS_TEXT, IDB_TOOLBAR, false, false);

    UI().addSubMenu(  IDM_MOE_HEX,  IDM_MOE_HEX,  IDM_HELP );
        UI().addMenuItem(IDM_MOE_HEX, IDM_HELP, IDM_HELP_ABOUT, IDB_TOOLBAR, false, true);
  
  // a main menu
  UI().addMenu(IDM_MOE_HTML);    

    UI().addSubMenu(  IDM_MOE_HTML,  IDM_MOE_HTML,  IDM_FILE );
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_FILE_NEW, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_FILE_OPEN, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_FILE_OPEN_HTML, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_FILE_OPEN_FOLDER, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_FILE);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_FILE_SAVE_AS, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_FILE);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_FILE_PRINT, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_MODE_PREFERENCES, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_FILE);
        UI().addMenuItem(IDM_MOE_HTML, IDM_FILE, IDM_FILE_EXIT, IDB_TOOLBAR, false, true);

    UI().addSubMenu(  IDM_MOE_HTML,  IDM_MOE_HTML,  IDM_EDIT );
        UI().addMenuItem(IDM_MOE_HTML, IDM_EDIT, IDM_EDIT_FIND, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_EDIT);
        UI().addMenuItem(IDM_MOE_HTML, IDM_EDIT, IDM_EDIT_UNDO, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_EDIT, IDM_EDIT_REDO, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_EDIT);
        UI().addMenuItem(IDM_MOE_HTML, IDM_EDIT, IDM_EDIT_UPDATE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_EDIT, IDM_EDIT_STOP, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_EDIT);
        UI().addMenuItem(IDM_MOE_HTML, IDM_EDIT, IDM_EDIT_COPY, IDB_TOOLBAR, false, true);

    UI().addSubMenu(  IDM_MOE_HTML,  IDM_MOE_HTML,  IDM_VIEW );
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_MAXIMIZE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_MINIMIZE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_TILE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_CASCADE, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_VIEW);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_CLOSE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_CLOSEALL, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_VIEW);
    UI().addSubMenu(  IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_TOOLBARS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_VIEW_DIRVIEW, IDB_TOOLBAR, true, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FILEBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_EDITBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_TOOLBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_SETTINGBAR, IDB_TOOLBAR, true, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_VIEWBAR, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_USERBAR, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MOE_HTML,IDM_VIEW_TOOLBARS);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_TOOLBARS, IDM_TOOLBARS_FREEZE, IDB_TOOLBAR, false, true);
    UI().addSubMenu(  IDM_MOE_HTML, IDM_VIEW, IDM_VIEW_WINDOWS, IDB_TOOLBAR);
        UI().addMenuItem(IDM_MOE_HTML, IDM_VIEW_WINDOWS, IDM_VIEW_WINDOWS_TEXT, IDB_TOOLBAR, false, false);

    UI().addSubMenu(  IDM_MOE_HTML,  IDM_MOE_HTML,  IDM_HELP );
        UI().addMenuItem(IDM_MOE_HTML, IDM_HELP, IDM_HELP_ABOUT, IDB_TOOLBAR, false, true);
  
  // a main menu
  UI().addMenu(IDM_MENU_TAB);    

    UI().addSubMenu(  IDM_MENU_TAB,  IDM_MENU_TAB,  IDM_TAB );
        UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_VIEW_CLOSE, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_TAB_CLOSEALLBUTTHIS, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MENU_TAB,IDM_TAB);
        UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_TAB_RELOADTAB, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_FILE_SAVE, IDB_TOOLBAR, false, true);
    UI().addMenuSeparator(IDM_MENU_TAB,IDM_TAB);
        UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_TAB_DIRTAB, IDB_TOOLBAR, false, true);
        UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_TAB_JUMPTAB, IDB_TOOLBAR, false, true);

mol::msgMap<MoeWnd>().addMsgHandler( WM_CREATE, make_handler(&MoeWnd::OnCreate) );

mol::msgMap<MoeWnd>().addMsgHandler( WM_CLOSE, make_handler(&MoeWnd::OnClose) );

mol::msgMap<MoeWnd>().addMsgHandler( WM_DESTROY, make_handler(&MoeWnd::OnDestroy) );

mol::msgMap<MoeWnd>().addMsgHandler( WM_NCDESTROY, make_handler(&MoeWnd::OnNcDestroy) );

mol::msgMap<MoeWnd>().addMsgHandler( WM_MDIACTIVATE, make_handler(&MoeWnd::OnMDIActivate) );

mol::msgMap<MoeWnd>().addMsgHandler( WM_INITMENUPOPUP, make_handler(&MoeWnd::OnMenu) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_FILE_NEW, make_handler(&MoeWnd::OnFileNew) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_FILE_OPEN, make_handler(&MoeWnd::OnFileOpen) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_FILE_OPEN_HTML, make_handler(&MoeWnd::OnFileOpenHtml) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_FILE_OPEN_FOLDER, make_handler(&MoeWnd::OnFileOpenDir) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_FILE_OPEN_HEX, make_handler(&MoeWnd::OnFileOpenHex) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_FILE_EXIT, make_handler(&MoeWnd::OnFileExit) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_EDIT_FIND, make_handler(&MoeWnd::OnFind) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_EDIT_REPLACE, make_handler(&MoeWnd::OnReplace) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_EDIT_EXECUTESCRIPT, make_handler(&MoeWnd::OnExecScript) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_EDIT_DEBUGSCRIPT, make_handler(&MoeWnd::OnDebugScript) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_MODE_EXECUTEFORM, make_handler(&MoeWnd::OnExecForm) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_MODE_EDITSETTINGS, make_handler(&MoeWnd::OnEditSettings) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_MODE_PREFERENCES, make_handler(&MoeWnd::OnEditPrefs) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_HELP_ABOUT, make_handler(&MoeWnd::OnHelpAbout) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_EDIT_CUT, make_handler(&MoeWnd::OnEditCut) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_EDIT_COPY, make_handler(&MoeWnd::OnEditCopy) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_EDIT_PASTE, make_handler(&MoeWnd::OnEditPaste) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_TOOLBARS_FREEZE, make_handler(&MoeWnd::OnFreezeToolBar) );

mol::msgMap<MoeWnd>().addCmdHandler( IDW_SYNTAX_BOX, make_handler(&MoeWnd::OnSyntax) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_RIBBON_RECENTITEMS, make_handler(&MoeWnd::OnRecentItems) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_FILE_PRINT, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addMsgHandler( WM_SEARCH_MSG, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_FILE_SAVE, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_FILE_SAVE_AS, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_MODE_UNIX, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_MODE_WIN32, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_MODE_USETABS, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_MODE_DONT_USE_TABS, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_MODE_SETTINGS, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_PERL, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_CPP, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_CSS, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_JAVA, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_JAVASCRIPT, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_VB, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_SHELL, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_SQL, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_HTML, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_PLAIN, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_CSHARP, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_MODE_EOL, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_EDIT_COLOR, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_EDIT_SELECT, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_EDIT_UNDO, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_EDIT_REDO, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_EDIT_STOP, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_EDIT_UPDATE, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_EDIT_INDENTION, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_JAVASCRIPT, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_JAVASCRIPT, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_JAVASCRIPT, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_JAVASCRIPT, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_JAVASCRIPT, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_LEXER_JAVASCRIPT, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_FILE_NEWDIR, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_FILE_UPDIR, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_FILE_DIREXEC, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_FILE_DIRPROP, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_RIBBON_TABCONVERT, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_RIBBON_ENCODING, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_RIBBON_LANGUAGE, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_RIBBON_TABUSAGE, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_RIBBON_TABWIDTH, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_RIBBON_TABINDENTS, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_RIBBON_BACKSPACE_UNIDENTS, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_RIBBON_WRITE_BOM, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_RIBBON_BYTES_SHOWN, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_VIEW_MAXIMIZE, make_handler(&MoeWnd::OnMaximize) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_VIEW_MINIMIZE, make_handler(&MoeWnd::OnMinimize) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_VIEW_TILE, make_handler(&MoeWnd::OnTileHorizontal) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_VIEW_CASCADE, make_handler(&MoeWnd::OnCascade) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_VIEW_NEXT, make_handler(&MoeWnd::OnNext) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_VIEW_CLOSE, make_handler(&MoeWnd::OnCloseChild) );

mol::msgMap<MoeWnd>().addCmdHandler( IDM_VIEW_CLOSEALL, make_handler(&MoeWnd::OnCloseAll) );

make_command_range_handler( MoeWnd, IDM_F1, IDM_F12, OnFx );

make_command_range_handler( MoeWnd, IDM_TOOLBARS_FILEBAR, IDM_TOOLBARS_DIRVIEW, OnShowToolBar );

make_command_range_handler( MoeWnd, ID_FIRST_USER_CMD, ID_LAST_USER_CMD, OnDispatch );

make_command_range_handler( MoeWnd, ID_FIRST_USER_SCRIPT, ID_LAST_USER_SCRIPT, OnDispatch );

make_command_range_handler( MoeWnd, ID_FIRST_USER_BATCH, ID_LAST_USER_BATCH, OnDispatch );

make_command_range_handler( MoeWnd, ID_FIRST_USER_FORM, ID_LAST_USER_FORM, OnDispatch );

make_command_range_handler( MoeWnd, IDM_EDIT_16BYTES, IDM_EDIT_32BYTES, OnDispatch );

mol::msgMap<MoeWnd>().addNotifyIdHandler( IDW_TAB_CTRL, make_handler(&MoeWnd::OnTabCtrl) );

mol::msgMap<MoeWnd>().addNotifyCodeHandler( TBN_DROPDOWN, make_handler(&MoeWnd::OnDispatch) );

mol::msgMap<MoeWnd>().addNotifyCodeHandler( NM_RCLICK, make_handler(&MoeWnd::OnToolbarRightClick) );

mol::msgMap<DirChild>().addMsgHandler( WM_MDIACTIVATE, make_handler(&DirChild::OnMDIActivate) );

mol::msgMap<DirChild>().addMsgHandler( WM_CLOSE, make_handler(&DirChild::OnClose) );

mol::msgMap<DirChild>().addMsgHandler( WM_NCDESTROY, make_handler(&DirChild::OnNcDestroy) );

mol::msgMap<DirChild>().addMsgHandler( WM_DESTROY, make_handler(&DirChild::OnDestroy) );

mol::msgMap<DirChild>().addCmdHandler( IDM_EDIT_UPDATE, make_ole_handler<DirChild>(&IShellPane::Update) );

mol::msgMap<DirChild>().addCmdHandler( IDM_EDIT_CUT, make_ole_handler<DirChild>(&IShellPane::Cut) );

mol::msgMap<DirChild>().addCmdHandler( IDM_EDIT_COPY, make_ole_handler<DirChild>(&IShellPane::Copy) );

mol::msgMap<DirChild>().addCmdHandler( IDM_EDIT_PASTE, make_ole_handler<DirChild>(&IShellPane::Paste) );

mol::msgMap<DirChild>().addCmdHandler( IDM_FILE_DIREXEC, make_ole_handler<DirChild>(&IShellPane::Execute) );

mol::msgMap<DirChild>().addCmdHandler( IDM_FILE_DIRPROP, make_ole_handler<DirChild>(&IShellPane::Properties) );

mol::msgMap<DirChild>().addCmdHandler( IDM_FILE_NEWDIR, make_ole_handler<DirChild>(&IShellPane::CreateDir) );

mol::msgMap<DirChild>().addCmdHandler( IDM_FILE_UPDIR, make_ole_handler<DirChild>(&IShellPane::UpDir) );

mol::msgMap<Editor>().addMsgHandler( WM_MDIACTIVATE, make_handler(&Editor::OnMDIActivate) );

mol::msgMap<Editor>().addMsgHandler( WM_INITMENUPOPUP, make_handler(&Editor::OnMenu) );

mol::msgMap<Editor>().addMsgHandler( WM_DESTROY, make_handler(&Editor::OnDestroy) );

mol::msgMap<Editor>().addMsgHandler( WM_NCDESTROY, make_handler(&Editor::OnNcDestroy) );

mol::msgMap<Editor>().addMsgHandler( WM_CLOSE, make_handler(&Editor::OnClose) );

mol::msgMap<Editor>().addMsgHandler( WM_SEARCH_MSG, make_handler(&Editor::OnSearch) );

mol::msgMap<Editor>().addCmdHandler( IDM_EDIT_INDENTION, make_handler(&Editor::OnBeautify) );

mol::msgMap<Editor>().addCmdHandler( IDM_FILE_SAVE_AS, make_handler(&Editor::OnSaveAs) );

mol::msgMap<Editor>().addCmdHandler( IDM_FILE_SAVE, make_handler(&Editor::OnSave) );

mol::msgMap<Editor>().addCmdHandler( IDM_MODE_UNIX, make_handler(&Editor::OnUnix) );

mol::msgMap<Editor>().addCmdHandler( IDM_MODE_WIN32, make_handler(&Editor::OnWin32) );

mol::msgMap<Editor>().addCmdHandler( IDM_MODE_SETTINGS, make_handler(&Editor::OnSettings) );

mol::msgMap<Editor>().addCmdHandler( IDM_EDIT_UPDATE, make_handler(&Editor::OnReload) );

mol::msgMap<Editor>().addCmdHandler( IDM_EDIT_SELECT, make_handler(&Editor::OnSelectAll) );

mol::msgMap<Editor>().addCmdHandler( IDM_EDIT_COLOR, make_handler(&Editor::OnInsertColorDialog) );

mol::msgMap<Editor>().addCmdHandler( IDM_RIBBON_TABCONVERT, make_handler(&Editor::OnConvertTabs) );

mol::msgMap<Editor>().addCmdHandler( IDM_RIBBON_ENCODING, make_handler(&Editor::OnEncoding) );

mol::msgMap<Editor>().addCmdHandler( IDM_RIBBON_LANGUAGE, make_handler(&Editor::OnLanguage) );

mol::msgMap<Editor>().addCmdHandler( IDM_RIBBON_TABUSAGE, make_handler(&Editor::OnTabUsage) );

mol::msgMap<Editor>().addCmdHandler( IDM_RIBBON_TABWIDTH, make_handler(&Editor::OnTabWidth) );

mol::msgMap<Editor>().addCmdHandler( IDM_RIBBON_TABINDENTS, make_handler(&Editor::OnTabIndents) );

mol::msgMap<Editor>().addCmdHandler( IDM_RIBBON_BACKSPACE_UNIDENTS, make_handler(&Editor::OnBackspaceUnindents) );

mol::msgMap<Editor>().addCmdHandler( IDM_RIBBON_WRITE_BOM, make_handler(&Editor::OnWriteBOM) );

mol::msgMap<Editor>().addCmdHandler( IDM_EDIT_CUT, make_ole_handler<Editor>(&IScintillAx::Cut) );

mol::msgMap<Editor>().addCmdHandler( IDM_EDIT_COPY, make_ole_handler<Editor>(&IScintillAx::Copy) );

mol::msgMap<Editor>().addCmdHandler( IDM_EDIT_PASTE, make_ole_handler<Editor>(&IScintillAx::Paste) );

mol::msgMap<Editor>().addCmdHandler( IDM_EDIT_UNDO, make_ole_handler<Editor>(&IScintillAx::Undo) );

mol::msgMap<Editor>().addCmdHandler( IDM_EDIT_REDO, make_ole_handler<Editor>(&IScintillAx::Redo) );

mol::msgMap<Editor>().addCmdHandler( IDM_FILE_PRINT, make_ole_handler<Editor>(&IScintillAx::Print) );

make_command_range_handler( Editor, IDM_LEXER_PLAIN, IDM_LEXER_CSHARP, OnLexer );

make_command_range_handler( Editor, ID_FIRST_USER_CMD, ID_LAST_USER_CMD, OnUserCommand );

make_command_range_handler( Editor, ID_FIRST_USER_BATCH, ID_LAST_USER_BATCH, OnUserBatch );

make_command_range_handler( Editor, ID_FIRST_USER_FORM, ID_LAST_USER_FORM, OnUserForm );

make_command_range_handler( Editor, ID_FIRST_USER_SCRIPT, ID_LAST_USER_SCRIPT, OnUserScript );

mol::msgMap<Editor>().addNotifyCodeHandler( TBN_DROPDOWN, make_handler(&Editor::OnToolbarDropDown) );

mol::msgMap<Hex>().addMsgHandler( WM_MDIACTIVATE, make_handler(&Hex::OnMDIActivate) );

mol::msgMap<Hex>().addMsgHandler( WM_INITMENUPOPUP, make_handler(&Hex::OnMenu) );

mol::msgMap<Hex>().addMsgHandler( WM_DESTROY, make_handler(&Hex::OnDestroy) );

mol::msgMap<Hex>().addMsgHandler( WM_NCDESTROY, make_handler(&Hex::OnNcDestroy) );

mol::msgMap<Hex>().addMsgHandler( WM_CLOSE, make_handler(&Hex::OnClose) );

mol::msgMap<Hex>().addCmdHandler( IDM_EDIT_FIND, make_handler(&Hex::OnFind) );

mol::msgMap<Hex>().addMsgHandler( WM_SEARCH_MSG, make_handler(&Hex::OnSearch) );

mol::msgMap<Hex>().addCmdHandler( IDM_RIBBON_BYTES_SHOWN, make_handler(&Hex::OnBytesShown) );

make_command_range_handler( Hex, IDM_EDIT_16BYTES, IDM_EDIT_32BYTES, OnHexRange );

mol::msgMap<MoeHtmlWnd>().addMsgHandler( WM_CLOSE, make_handler(&MoeHtmlWnd::OnClose) );

mol::msgMap<MoeHtmlWnd>().addMsgHandler( WM_DESTROY, make_handler(&MoeHtmlWnd::OnDestroy) );

mol::msgMap<MoeHtmlWnd>().addMsgHandler( WM_NCDESTROY, make_handler(&MoeHtmlWnd::OnNcDestroy) );

mol::msgMap<MoeHtmlWnd>().addMsgHandler( WM_SEARCH_MSG, make_handler(&MoeHtmlWnd::OnSearch) );

mol::msgMap<MoeHtmlWnd>().addMsgHandler( WM_MDIACTIVATE, make_handler(&MoeHtmlWnd::OnMDIActivate) );

mol::msgMap<MoeHtmlWnd>().addCmdHandler( IDM_EDIT_UNDO, make_handler(&MoeHtmlWnd::back) );

mol::msgMap<MoeHtmlWnd>().addCmdHandler( IDM_EDIT_REDO, make_handler(&MoeHtmlWnd::forward) );

mol::msgMap<MoeHtmlWnd>().addCmdHandler( IDM_EDIT_STOP, make_handler(&MoeHtmlWnd::stop) );

mol::msgMap<MoeHtmlWnd>().addCmdHandler( IDM_EDIT_UPDATE, make_handler(&MoeHtmlWnd::reload) );

mol::msgMap<MoeHtmlWnd>().addCmdHandler( IDM_MODE_SETTINGS, make_handler(&MoeHtmlWnd::options) );

mol::msgMap<MoeHtmlWnd>().addCmdHandler( IDM_EDIT_COPY, make_generic_handler(&MoeHtmlWnd::oleStdTargetExec, OLECMDID_COPY ) );

mol::msgMap<MoeHtmlWnd>().addCmdHandler( IDM_EDIT_CUT, make_generic_handler(&MoeHtmlWnd::oleStdTargetExec, OLECMDID_CUT ) );

mol::msgMap<MoeHtmlWnd>().addCmdHandler( IDM_EDIT_PASTE, make_generic_handler(&MoeHtmlWnd::oleStdTargetExec, OLECMDID_PASTE ) );

mol::msgMap<MoeHtmlWnd>().addCmdHandler( IDM_FILE_SAVE_AS, make_generic_handler(&MoeHtmlWnd::oleStdTargetExec, OLECMDID_SAVEAS ) );

mol::msgMap<MoeHtmlWnd>().addCmdHandler( IDM_FILE_PRINT, make_generic_handler(&MoeHtmlWnd::oleStdTargetExec, OLECMDID_PRINT ) );

mol::msgMap<ImgViewer>().addMsgHandler( WM_MDIACTIVATE, make_handler(&ImgViewer::OnMDIActivate) );

mol::msgMap<ImgViewer>().addMsgHandler( WM_CREATE, make_handler(&ImgViewer::OnCreate) );

mol::msgMap<ImgViewer>().addMsgHandler( WM_DESTROY, make_handler(&ImgViewer::OnDestroy) );

mol::msgMap<ImgViewer>().addMsgHandler( WM_NCDESTROY, make_handler(&ImgViewer::OnNcDestroy) );

mol::msgMap<ImgViewer>().addMsgHandler( WM_PAINT, make_handler(&ImgViewer::OnPaint) );

mol::msgMap<OleChild>().addMsgHandler( WM_DESTROY, make_handler(&OleChild::OnDestroy) );

mol::msgMap<OleChild>().addMsgHandler( WM_NCDESTROY, make_handler(&OleChild::OnNcDestroy) );

mol::msgMap<OleChild>().addMsgHandler( WM_MDIACTIVATE, make_handler(&OleChild::OnMDIActivate) );

mol::msgMap<OleChild>().addCmdHandler( IDM_FILE_SAVE, make_handler(&OleChild::IOleClientSite_SaveObject) );

mol::msgMap<OleChild>().addCmdHandler( IDM_FILE_SAVE_AS, make_generic_handler(&OleChild::oleTargetExec, OLECMDID_SAVECOPYAS,OLECMDEXECOPT_PROMPTUSER ) );

mol::msgMap<OleChild>().addCmdHandler( IDM_FILE_PRINT, make_generic_handler(&OleChild::oleTargetExec, OLECMDID_PRINT,OLECMDEXECOPT_PROMPTUSER ) );

mol::msgMap<OleChild>().addCmdHandler( IDM_EDIT_COPY, make_generic_handler(&OleChild::oleTargetExec, OLECMDID_COPY,OLECMDEXECOPT_DODEFAULT ) );

mol::msgMap<OleChild>().addCmdHandler( IDM_EDIT_CUT, make_generic_handler(&OleChild::oleTargetExec, OLECMDID_CUT,OLECMDEXECOPT_DODEFAULT ) );

mol::msgMap<OleChild>().addCmdHandler( IDM_EDIT_PASTE, make_generic_handler(&OleChild::oleTargetExec, OLECMDID_PASTE,OLECMDEXECOPT_DODEFAULT ) );

mol::msgMap<OleChild>().addCmdHandler( IDM_EDIT_UNDO, make_generic_handler(&OleChild::oleTargetExec, OLECMDID_UNDO,OLECMDEXECOPT_DODEFAULT ) );

mol::msgMap<OleChild>().addCmdHandler( IDM_EDIT_REDO, make_generic_handler(&OleChild::oleTargetExec, OLECMDID_REDO,OLECMDEXECOPT_DODEFAULT ) );

mol::msgMap<MoeFormWnd>().addMsgHandler( WM_CLOSE, make_handler(&MoeFormWnd::OnClose) );

mol::msgMap<MoeFormWnd>().addMsgHandler( WM_NCDESTROY, make_handler(&MoeFormWnd::OnNcDestroy) );


}
