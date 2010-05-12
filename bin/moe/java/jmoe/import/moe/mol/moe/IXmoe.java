package mol.moe  ;

import com4j.*;

/**
 * IXmoe AppObj Interface - the moe application scripting object
 */
@IID("{710B3B21-654C-4C07-A062-B7287132F97D}")
public interface IXmoe extends Com4jObject {
    /**
     * Get MDI Child Documents Collection
     */
    @VTID(7)
    mol.moe.IDocs docs();

    @VTID(7)
    @ReturnValue(defaultPropertyThrough={mol.moe.IDocs.class})
    mol.moe.IDoc docs(
        @MarshalAs(NativeType.VARIANT) java.lang.Object i);

    /**
     * Get/Set Top position of main frame window
     */
    @VTID(8)
    void top(
        int t);

    /**
     * Get/Set Top position of main frame window
     */
    @VTID(9)
    int top();

    /**
     * Get/Set Left position of main frame window
     */
    @VTID(10)
    void left(
        int l);

    /**
     * Get/Set Left position of main frame window
     */
    @VTID(11)
    int left();

    /**
     * Get/Set Height of main frame window
     */
    @VTID(12)
    void height(
        int h);

    /**
     * Get/Set Height of main frame window
     */
    @VTID(13)
    int height();

    /**
     * Get/Set Width of main frame window
     */
    @VTID(14)
    void width(
        int w);

    /**
     * Get/Set Width of main frame window
     */
    @VTID(15)
    int width();

    /**
     * Get Active MDI Document Reference
     */
    @VTID(16)
    mol.moe.IDoc activeDoc();

    /**
     * Show/Hide the TreeView (SideBar) Control
     */
    @VTID(17)
    void showTreeView(
        boolean vb);

    /**
     * Show/Hide the TreeView (SideBar) Control
     */
    @VTID(18)
    boolean showTreeView();

    /**
     * get a object reference to the TreeView (SideBar) Control
     */
    @VTID(19)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject treeView();

    /**
     * Get/Set SysType to UNIX/WIN32 (SCINTILLA_SYSTYPE)
     */
    @VTID(20)
    void sysType(
        int typ);

    /**
     * Get/Set SysType to UNIX/WIN32 (SCINTILLA_SYSTYPE)
     */
    @VTID(21)
    int sysType();

    /**
     * Set Encoding ie UTF-8, Ansi, ... (SCINTILLA_ENCODING)
     */
    @VTID(22)
    void encoding(
        int typ);

    /**
     * Set Encoding ie UTF-8, Ansi, ... (SCINTILLA_ENCODING)
     */
    @VTID(23)
    int encoding();

    /**
     * Get/Set Usage of Tab Characters, false converts tabs to spaces
     */
    @VTID(24)
    void tabUsage(
        boolean vbTabUsage);

    /**
     * Get/Set Usage of Tab Characters, false converts tabs to spaces
     */
    @VTID(25)
    boolean tabUsage();

    /**
     * Get/Set whether Tabulator keystrokes do code-indent
     */
    @VTID(26)
    void tabIndents(
        boolean vbTabIndents);

    /**
     * Get/Set whether Tabulator keystrokes do code-indent
     */
    @VTID(27)
    boolean tabIndents();

    /**
     * Get/Set wether BackSpace keystrokes unindent (code-indention)
     */
    @VTID(28)
    void backSpaceUnindents(
        boolean vbBackSpaceIndents);

    /**
     * Get/Set wether BackSpace keystrokes unindent (code-indention)
     */
    @VTID(29)
    boolean backSpaceUnindents();

    /**
     * Get/Set width of Tabulator in spaces
     */
    @VTID(30)
    void tabWidth(
        int w);

    /**
     * Get/Set width of Tabulator in spaces
     */
    @VTID(31)
    int tabWidth();

    /**
     * Get/Set Syntax index for highlighting (SCINTILLA_SYNTAX)
     */
    @VTID(32)
    void syntax(
        int typ);

    /**
     * Get/Set Syntax index for highlighting (SCINTILLA_SYNTAX)
     */
    @VTID(33)
    int syntax();

    /**
     * Get Configuration Files Path on local system
     */
    @VTID(34)
    java.lang.String configPath();

    /**
     * Get Path to moe executable on local system
     */
    @VTID(35)
    java.lang.String modulePath();

    /**
     * Get a reference to the embedded .NET compiler
     */
    @VTID(36)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject compiler();

    /**
     * Create new, empty (Text-Editor) MDI Child Document
     */
    @VTID(37)
    mol.moe.IDoc _new();

    /**
     * Open existing Document in Text-Editor
     */
    @VTID(38)
    mol.moe.IDoc open(
        java.lang.String fPath);

    /**
     * Open Document in Text-Editor, forcing UTF-8 mode
     */
    @VTID(39)
    mol.moe.IDoc openUTF8(
        java.lang.String fPath);

    /**
     * Open Directory View as MDI child
     */
    @VTID(40)
    mol.moe.IDoc openDir(
        java.lang.String dir);

    /**
     * Open document file in Hex Viewer
     */
    @VTID(41)
    mol.moe.IDoc openHexEditor(
        java.lang.String f,
        boolean vbReadOnly);

    /**
     * Open HTML Document as MDI Child (embedded IE)
     */
    @VTID(42)
    mol.moe.IDoc openHtmlFrame(
        java.lang.String f);

    /**
     * Open Directory Browser and return directory name
     */
    @VTID(43)
    java.lang.String chooseDir();

    /**
     * Save All open MDI documents
     */
    @VTID(44)
    void saveAll();

    /**
     * Close All open MDI documents
     */
    @VTID(45)
    void closeAll();

    /**
     * Show application main window
     */
    @VTID(46)
    void show();

    /**
     * Hide application main window
     */
    @VTID(47)
    void hide();

    /**
     * Activate MDI document with index by number or full-path
     */
    @VTID(48)
    void activate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object i);

    /**
     * Exit moe. Shuts down the application, closing all windows.
     */
    @VTID(49)
    void exit();

    /**
     * Minimize application main window
     */
    @VTID(50)
    void minimize();

    /**
     * Maximize application main window
     */
    @VTID(51)
    void maximize();

    /**
     * Restore application main window
     */
    @VTID(52)
    void restore();

    /**
     * Tile application MDI child windows
     */
    @VTID(53)
    void tile();

    /**
     * Cascade application MDI child windows
     */
    @VTID(54)
    void cascade();

    /**
     * Set the Status Bar text
     */
    @VTID(55)
    void setStatus(
        java.lang.String statusText);

    /**
     * Show the embedded moe HTML Help
     */
    @VTID(56)
    void help();

    /**
     * Run a Script from disk inside moe context
     */
    @VTID(57)
    void run(
        java.lang.String f,
        java.lang.String engine);

    /**
     * Evaluate a Script given as text inside moe context
     */
    @VTID(58)
    void eval(
        java.lang.String scrpt,
        java.lang.String scrptLanguage);

    /**
     * Execute a Shell command
     */
    @VTID(59)
    void system(
        java.lang.String f);

    /**
     * Show a user-defined HTML Form
     */
    @VTID(60)
    void showForm(
        java.lang.String src,
        int l,
        int t,
        int w,
        int h,
        int formStyle);

    /**
     * Show User Preferences for new opened documents dialog
     */
    @VTID(61)
    void preferences();

    /**
     * Show User Custom Settings dialog
     */
    @VTID(62)
    void settings();

    /**
     * Export User Settings to file
     */
    @VTID(63)
    void exportSettings(
        java.lang.String f);

    /**
     * Import User Settings from file
     */
    @VTID(64)
    void importSettings(
        java.lang.String f);

    /**
     * MsgBox
     */
    @VTID(65)
    int msgBox(
        java.lang.String text,
        java.lang.String title,
        int flags);

    /**
     * Debug a Script given as text inside moe context
     */
    @VTID(66)
    void debug(
        java.lang.String scrpt,
        java.lang.String scrptLanguage);

}
