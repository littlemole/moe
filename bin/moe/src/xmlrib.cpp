
#include "stdafx.h"
#include "win/res.h"
#include "win/wnd.h"
#include "ole/rib.h"
#include "ribbonres.h"



void init_ribbon_ui(  mol::win::WndProc* wnd )
{


    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonFileNew, IDM_FILE_NEW );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonFileOpen, IDM_FILE_OPEN );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonFileOpenUrl, IDM_FILE_OPEN_HTML );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonFileOpenDirectory, IDM_FILE_OPEN_FOLDER );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonFileSave, IDM_FILE_SAVE );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonFileSaveAs, IDM_FILE_SAVE_AS );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonFileExit, IDM_FILE_EXIT );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonFilePrint, IDM_FILE_PRINT );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonNewDirList, IDM_FILE_NEWDIR );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonRenameList, IDM_FILE_RENAME );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonUpDir, IDM_FILE_UPDIR );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonExecuteList, IDM_FILE_DIREXEC );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonPropertiesList, IDM_FILE_DIRPROP );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonMRUItems, IDM_RIBBON_RECENTITEMS );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonSelectLanguage, IDM_RIBBON_LANGUAGE );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonEncoding, IDM_RIBBON_ENCODING );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonTabUseTabs, IDM_RIBBON_TABUSAGE );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonTabSize, IDM_RIBBON_TABWIDTH );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonTabConvert, IDM_RIBBON_TABCONVERT );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonTabIndents, IDM_RIBBON_TABINDENTS );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonTabBackSpaceUnIndents, IDM_RIBBON_BACKSPACE_UNIDENTS );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonWriteBOM, IDM_RIBBON_WRITE_BOM );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonBytesShown, IDM_RIBBON_BYTES_SHOWN );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonEditSelectAll, IDM_EDIT_SELECT );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonEditFind, IDM_EDIT_FIND );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonEditReplace, IDM_EDIT_REPLACE );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonEditUndo, IDM_EDIT_UNDO );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonEditRedo, IDM_EDIT_REDO );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonEditCut, IDM_EDIT_CUT );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonEditCopy, IDM_EDIT_COPY );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonEditPaste, IDM_EDIT_PASTE );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonToolColor, IDM_EDIT_COLOR );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonEditReload, IDM_EDIT_UPDATE );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonToolExecScript, IDM_EDIT_EXECUTESCRIPT );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonToolDebug, IDM_EDIT_DEBUGSCRIPT );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonModeGroup, IDM_MODE_EOL );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonSettings, IDM_MODE_SETTINGS );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonSelectModeUnix, IDM_MODE_UNIX );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonSelectModeWin32, IDM_MODE_WIN32 );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonFilePreferences, IDM_MODE_PREFERENCES );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonToolExecForm, IDM_MODE_EXECUTEFORM );
  
    mol::Ribbon::ribbon()->registerNotification(*wnd,RibbonToolUserForm, IDM_USER_FORM, TBN_DROPDOWN );
  
    mol::Ribbon::ribbon()->registerNotification(*wnd,RibbonToolUserTemplate, IDM_USER_SHORTCUT, TBN_DROPDOWN );
  
    mol::Ribbon::ribbon()->registerNotification(*wnd,RibbonToolUserScript, IDM_USER_SCRIPT, TBN_DROPDOWN );
  
    mol::Ribbon::ribbon()->registerNotification(*wnd,RibbonToolUserBatch, IDM_USER_BATCH, TBN_DROPDOWN );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonShowDirView, IDM_VIEW_DIRVIEW );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonViewMaximize, IDM_VIEW_MAXIMIZE );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonViewMinimize, IDM_VIEW_MINIMIZE );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonViewTile, IDM_VIEW_TILE );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonViewCascade, IDM_VIEW_CASCADE );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonViewClose, IDM_VIEW_CLOSE );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonViewCloseAll, IDM_VIEW_CLOSEALL );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonHelp, IDM_HELP_ABOUT );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonViewCloseOthers, IDM_TAB_CLOSEALLBUTTHIS );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonParentDirectory, IDM_TAB_DIRTAB );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonJumpDirectory, IDM_TAB_JUMPTAB );
  
    mol::Ribbon::ribbon()->registerCommand(*wnd,RibbonFileNewUFS, IDM_FILE_NEW_UFS );
  

}
