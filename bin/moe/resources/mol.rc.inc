#include "../ribbonres.rc"
#include "dlgs.h"
/////////////////////////////////////////////////////////////////////////////
//
// Dialog
//

IDD_ABOUTBOX DIALOGEX 22, 17, 230, 75
STYLE DS_SETFONT | DS_MODALFRAME | WS_CAPTION | WS_SYSMENU
CAPTION "This is not a MFC App"
FONT 8, "Courier", 400, 0, 0x0
BEGIN
    LTEXT           "mole's own editor V 00.1\r\nbuild on scintilla",IDC_STATIC,35,9,136,21,SS_NOPREFIX
    DEFPUSHBUTTON   "OK",IDOK,186,7,37,21,WS_GROUP
    LTEXT           "- dedicated to gerd -\r\n\r\nhe didn't knew which win32 editor to choose",IDC_STATIC,6,38,217,24
    ICON            IDI_MOE,IDC_STATIC,7,9,16,20
END


IDD_DIALOG_TAB DIALOGEX 0, 0, 234, 120
STYLE DS_SETFONT | DS_FIXEDSYS | WS_POPUP | WS_SYSMENU
FONT 8, "MS Shell Dlg", 400, 0, 0x1
BEGIN
    LTEXT           "Tabulator Width",IDC_STATIC,125,18,64,15
    EDITTEXT        IDC_EDIT_TABWIDTH,179,16,27,14,ES_AUTOHSCROLL | ES_NUMBER
    CONTROL         "Use Tabs",IDC_CHECK_USETABS,"Button",BS_AUTOCHECKBOX | WS_TABSTOP,16,18,44,10
    CONTROL         "Tab Indents",IDC_CHECK_TABINDENTS,"Button",BS_AUTOCHECKBOX | WS_TABSTOP,16,51,56,10
    CONTROL         "Backspace Unindents",IDC_CHECK_BACKSPACEUNINDENTS,
                    "Button",BS_AUTOCHECKBOX | WS_TABSTOP,124,51,81,10
    CONTROL         "Show Linenumbers",IDC_CHECK_SHOWLINENUM,"Button",BS_AUTOCHECKBOX | WS_TABSTOP,16,85,70,10
END

IDD_DIALOG_EXPORT DIALOGEX 0, 0, 234, 120
STYLE DS_SETFONT | DS_FIXEDSYS | WS_POPUP | WS_SYSMENU
FONT 8, "MS Shell Dlg", 400, 0, 0x1
BEGIN
    PUSHBUTTON      "Export",IDC_BUTTON_EXPORT,109,43,71,17
    LTEXT           "Export Settings",IDC_STATIC,41,47,52,12
    PUSHBUTTON      "Import",IDC_BUTTON_IMPORT,109,73,71,17
    LTEXT           "Import Settings",IDC_STATIC,42,78,52,12
    LTEXT           "File Extensions",IDC_STATIC,42,17,52,12
    PUSHBUTTON      "Edit Extensions",IDC_BUTTON_EXTENSIONS,109,14,71,17
END

IDD_DIALOG_SETWRAPPER DIALOGEX 0, 0, 234, 120
STYLE DS_SETFONT | DS_FIXEDSYS | WS_POPUP | WS_SYSMENU
FONT 8, "MS Shell Dlg", 400, 0, 0x1
BEGIN

END

/*
IDD_DIALOG_OFN DIALOGEX 0, 0, 316, 153
STYLE DS_SETFONT | DS_FIXEDSYS | WS_CHILD |WS_CLIPSIBLINGS
FONT 8, "MS Shell Dlg", 400, 0, 0x1
BEGIN
    LTEXT           "Static",stc32,28,19,256,82
    COMBOBOX        IDC_COMBO_ENC,59,121,233,21,CBS_DROPDOWN | WS_VSCROLL | WS_TABSTOP
    LTEXT           "Encoding",IDC_STATIC,17,122,32,16
END
*/

IDD_DIALOG_OFN DIALOGEX 0, 0, 365, 28
STYLE DS_SETFONT | DS_FIXEDSYS | WS_CHILD
FONT 8, "MS Shell Dlg", 400, 0, 0x1
BEGIN
    COMBOBOX        IDC_COMBO_ENC,128,8,203,21,CBS_DROPDOWN | WS_VSCROLL | WS_TABSTOP
    LTEXT           "Encoding",IDC_STATIC,69,9,32,16
END


IDD_DIALOG_URL DIALOGEX 0, 0, 231, 44
STYLE DS_SETFONT | DS_MODALFRAME | DS_FIXEDSYS | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "Enter URL"
FONT 8, "MS Shell Dlg", 400, 0, 0x1
BEGIN
    DEFPUSHBUTTON   "GO",IDOK,203,19,14,13,BS_BITMAP
    GROUPBOX        "Enter URL (http://) or file location",IDC_STATIC,7,7,217,31
    COMBOBOX        IDC_EDIT_URL,29,19,169,184,CBS_DROPDOWN | CBS_AUTOHSCROLL | WS_VSCROLL | WS_TABSTOP,WS_EX_ACCEPTFILES
    PUSHBUTTON      "BM",IDC_BUTTON_BOOKMARK,12,19,13,12,BS_BITMAP
END

IDD_DIALOG_EVENTS DIALOGEX 0, 0, 273, 186
STYLE DS_SETFONT | DS_MODALFRAME | DS_FIXEDSYS | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "Events"
FONT 8, "MS Shell Dlg", 400, 0, 0x1
BEGIN
    DEFPUSHBUTTON   "Paste",IDOK,197,164,67,14
    PUSHBUTTON      "Close",IDCANCEL,7,165,64,14
    CONTROL         "",IDC_TREE_EVENTS,"SysTreeView32",WS_BORDER | WS_HSCROLL | WS_TABSTOP,7,7,104,150,WS_EX_CLIENTEDGE
    LISTBOX         IDC_LIST_EVENTS,117,7,147,150,LBS_SORT | LBS_NOINTEGRALHEIGHT | WS_VSCROLL | WS_TABSTOP
END




IDD_DIALOG_DEBUG DIALOGEX 0, 0, 316, 183
STYLE DS_SETFONT | DS_MODALFRAME | DS_FIXEDSYS | WS_POPUP | WS_CAPTION | WS_SYSMENU
EXSTYLE WS_EX_TOOLWINDOW
CAPTION "Immediate Window"
FONT 8, "MS Shell Dlg", 400, 0, 0x1
BEGIN
    DEFPUSHBUTTON   "Evaluate",IDOK,248,134,50,14
    PUSHBUTTON      "Close",IDCANCEL,247,151,50,14
    GROUPBOX        "Variables",IDC_STATIC,7,7,302,76
    EDITTEXT        IDC_EDIT_DEBUG_EXP,15,97,213,23,ES_AUTOHSCROLL
    GROUPBOX        "Expression",IDC_STATIC,7,84,227,42
    EDITTEXT        IDC_EDIT_DEBUG_RESULT,16,140,212,26,ES_AUTOHSCROLL
    PUSHBUTTON      "go",IDC_BUTTON_DEBUG_GO,243,94,18,14,BS_BITMAP
    PUSHBUTTON      "go",IDC_BUTTON_DEBUG_PAUSE,262,94,18,14,BS_BITMAP
    PUSHBUTTON      "go",IDC_BUTTON_DEBUG_QUIT,281,94,18,14,BS_BITMAP
    PUSHBUTTON      "go",IDC_BUTTON_DEBUG_STEPIN,243,111,18,14,BS_BITMAP
    PUSHBUTTON      "go",IDC_BUTTON_DEBUG_STEPOVER,262,111,18,14,BS_BITMAP
    PUSHBUTTON      "go",IDC_BUTTON_DEBUG_STEPOUT,281,111,18,14,BS_BITMAP
    GROUPBOX        "Result",IDC_STATIC,7,130,227,42
    CONTROL         "",IDC_DEBUG_VARIABLES,"SysTreeView32",TVS_HASBUTTONS | TVS_HASLINES| TVS_LINESATROOT |TVS_DISABLEDRAGDROP | TVS_NOTOOLTIPS | TVS_SINGLEEXPAND | WS_HSCROLL | WS_TABSTOP,15,18,286,57
END

/////////////////////////////////////////////////////////////////////////////
//
// String Table
//

STRINGTABLE
BEGIN
   IDC_DISPLAYNAME   "moe"
END

/////////////////////////////////////////////////////////////////////////////
//
// Version Info
//

#define VER_FILEVERSION             1,0,0,0
#define VER_FILEVERSION_STR         "1.0.0.0\0"

#define VER_PRODUCTVERSION          1,0,0,0
#define VER_PRODUCTVERSION_STR      "1.0\0"

#ifndef VERSION_MAIN
#define VERSION_MAIN                1
#endif

#ifndef VERSION_MINOR
#define VERSION_MINOR                0
#endif

#ifndef VERSION_PATCH
#define VERSION_PATCH                0
#endif

#ifndef VERSION_BUILD
#define VERSION_BUILD                0
#endif

#define STR(E) #E
#define EXPAND(E)  STR(E)
#define MAKE_VERSION(MAIN,MINOR,PATCH,BUILD) EXPAND(MAIN) "." EXPAND(MINOR) "." EXPAND(PATCH) "." EXPAND(BUILD)


VS_VERSION_INFO VERSIONINFO
FILEVERSION    	VERSION_MAIN,VERSION_MINOR,VERSION_PATCH,VERSION_BUILD
PRODUCTVERSION 	VERSION_MAIN,VERSION_MINOR,VERSION_PATCH,VERSION_BUILD
FILEFLAGSMASK  	VS_FFI_FILEFLAGSMASK
FILEFLAGS      	0
FILEOS         	VOS_NT_WINDOWS32
FILETYPE       	VFT_APP
FILESUBTYPE    	VFT2_UNKNOWN
BEGIN
    BLOCK "StringFileInfo"
    BEGIN
        BLOCK "040904b0"
        BEGIN
            VALUE "CompanyName",      "oha7.org"
            VALUE "FileDescription",  "moe's own editor"
            VALUE "FileVersion",      MAKE_VERSION(VERSION_MAIN,VERSION_MINOR,VERSION_PATCH,VERSION_BUILD)
            VALUE "InternalName",     "moe"
            VALUE "LegalCopyright",   "(c) 2001-2013"
            VALUE "OriginalFilename", "moe.exe"
            VALUE "ProductName",      "moe"
			VALUE "OLESelfRegister", "\0"
            VALUE "ProductVersion",   MAKE_VERSION(VERSION_MAIN,VERSION_MINOR,VERSION_PATCH,VERSION_BUILD)
        END
    END

    BLOCK "VarFileInfo"
    BEGIN
        /* The following line should only be modified for localized versions.     */
        /* It consists of any number of WORD,WORD pairs, with each pair           */
        /* describing a language,codepage combination supported by the file.      */
        /*                                                                        */
        /* For example, a file might have values "0x409,1252" indicating that it  */
        /* supports English language (0x409) in the Windows ANSI codepage (1252). */

        VALUE "Translation", 0x409, 1252

    END
END
    