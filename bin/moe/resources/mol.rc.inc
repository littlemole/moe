#include "../ribbonres.rc"

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

IDD_DIALOG_TAB DIALOGEX 0, 0, 172, 65
STYLE DS_SETFONT | DS_MODALFRAME | DS_FIXEDSYS | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "Prefs for new Documents"
FONT 8, "MS Shell Dlg", 400, 0, 0x1
BEGIN
    DEFPUSHBUTTON   "OK",IDOK,115,44,50,14
    PUSHBUTTON      "Cancel",IDCANCEL,7,44,50,14
    LTEXT           "Tabulator Width",IDC_STATIC,84,9,64,15
    EDITTEXT        IDC_EDIT_TABWIDTH,138,7,27,14,ES_AUTOHSCROLL | ES_NUMBER
    CONTROL         "Use Tabs",IDC_CHECK_USETABS,"Button",BS_AUTOCHECKBOX | WS_TABSTOP,7,9,44,10
    CONTROL         "Tab Indents",IDC_CHECK_TABINDENTS,"Button",BS_AUTOCHECKBOX | WS_TABSTOP,7,28,56,10
    CONTROL         "Backspace Unindents",IDC_CHECK_BACKSPACEUNINDENTS,
                    "Button",BS_AUTOCHECKBOX | WS_TABSTOP,84,28,81,10
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

/////////////////////////////////////////////////////////////////////////////
//
// String Table
//

STRINGTABLE
BEGIN
   IDC_DISPLAYNAME   "moe"
END

