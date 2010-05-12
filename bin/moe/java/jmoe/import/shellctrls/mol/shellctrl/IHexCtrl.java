package mol.shellctrl  ;

import com4j.*;

/**
 * IHexCtrl Interface
 */
@IID("{3F6F041B-6B7A-4465-9542-4652528C3FB7}")
public interface IHexCtrl extends Com4jObject {
    /**
     * Get/Set Readonly mode
     */
    @VTID(7)
    boolean readOnly();

    /**
     * Get/Set Readonly mode
     */
    @VTID(8)
    void readOnly(
        boolean vb);

    /**
     * Get/Set width of columns to display
     */
    @VTID(9)
    int displayColumns();

    /**
     * Get/Set width of columns to display
     */
    @VTID(10)
    void displayColumns(
        int cols);

    /**
     * Get/Set Filename
     */
    @VTID(11)
    java.lang.String filename();

    /**
     * Get/Set Filename
     */
    @VTID(12)
    void filename(
        java.lang.String fname);

    /**
     * returns true when Controls has the focus
     */
    @VTID(13)
    boolean hasFocus();

    /**
     * Get/Set display of Toolbar
     */
    @VTID(14)
    boolean showToolbar();

    /**
     * Get/Set display of Toolbar
     */
    @VTID(15)
    void showToolbar(
        boolean vb);

    /**
     * Get/Set ScrollPos
     */
    @VTID(16)
    int scrollPos();

    /**
     * Get/Set ScrollPos
     */
    @VTID(17)
    void scrollPos(
        int pos);

    /**
     * return the maximum scroll position
     */
    @VTID(18)
    int scrollMax();

    /**
     * Get/Set the current offset into file to display
     */
    @VTID(19)
    int offset();

    /**
     * Get/Set the current offset into file to display
     */
    @VTID(20)
    void offset(
        int off);

    /**
     * Get the File's size
     */
    @VTID(21)
    int fileSize();

    /**
     * Get/Set current Search position
     */
    @VTID(22)
    int searchPos();

    /**
     * Get/Set current Search position
     */
    @VTID(23)
    void searchPos(
        int pos);

    /**
     * Open a File
     */
    @VTID(24)
    boolean open(
        java.lang.String file);

    /**
     * Open a File ReadOnly
     */
    @VTID(25)
    boolean openReadOnly(
        java.lang.String file);

    /**
     * Set DWORD value (in hex chars) at Offset
     */
    @VTID(26)
    void setOffsetDWORD(
        int offset,
        java.lang.String val);

    /**
     * Set BYTE value (in hex chars) at Offset
     */
    @VTID(27)
    void setOffsetByte(
        int offset,
        java.lang.String val);

    /**
     * Set Char value at Offset
     */
    @VTID(28)
    void setOffsetChar(
        int offset,
        int val);

    /**
     * Search in file 
     */
    @VTID(29)
    void search(
        java.lang.String what,
        int flags);

    /**
     * Get Value at specific offset
     */
    @VTID(30)
    java.lang.String value(
        int off);

}
