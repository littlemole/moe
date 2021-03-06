// Microsoft Visual C++ generated resource script.
//
#include "resource.h"
#include "windows.h"


/////////////////////////////////////////////////////////////////////////////
//
// Dialog
//

IDD_DIALOG_PROP DIALOGEX 0, 0, 224, 110
STYLE DS_SETFONT | DS_FIXEDSYS | WS_CHILD
FONT 8, "MS Shell Dlg", 400, 0, 0x1
BEGIN
    GROUPBOX        "EOL",IDC_STATIC,7,7,50,46
    GROUPBOX        "Tab",IDC_STATIC,7,53,210,49
    CONTROL         "UNIX",IDC_RADIO_UNIX,"Button",BS_AUTORADIOBUTTON,15,18,30,13
    CONTROL         "Win32",IDC_RADIO_WIN32,"Button",BS_AUTORADIOBUTTON,15,33,36,13
    GROUPBOX        "Encoding",IDC_STATIC,61,7,90,46
    COMBOBOX        IDC_COMBO_ENCODING,80,25,61,66,CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP
    EDITTEXT        IDC_EDIT_TABWIDTH,118,64,32,13,ES_AUTOHSCROLL
    LTEXT           "TabWidth",IDC_STATIC,73,66,30,13
    CONTROL         "Use Tabs",IDC_CHECK_USETABS,"Button",BS_AUTOCHECKBOX | WS_TABSTOP,15,65,48,11
    CONTROL         "Backspace Unindents",IDC_CHECK_BACKSPACEUNINDENTS,
                    "Button",BS_AUTOCHECKBOX | WS_TABSTOP,73,77,85,18
    CONTROL         "Tab Indents",IDC_CHECK_TABINDENTS,"Button",BS_AUTOCHECKBOX | WS_TABSTOP,15,80,51,12
    PUSHBUTTON      "ConvertTabs",IDC_CONVERT_BUTTON,157,63,53,30
    GROUPBOX        "BOM",IDC_STATIC,155,7,62,46
    CONTROL         "Write BOM",IDC_CHECK_WRITEBOM,"Button",BS_AUTOCHECKBOX | WS_TABSTOP,162,27,46,9
END


