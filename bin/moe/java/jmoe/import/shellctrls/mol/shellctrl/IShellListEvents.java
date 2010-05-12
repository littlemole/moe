package mol.shellctrl  ;

import com4j.*;

/**
 * dual events for ShellList
 */
@IID("{2ED442CD-E289-46C3-AB7B-8DE1CEF89DB4}")
public interface IShellListEvents extends Com4jObject {
    /**
     * List Selection changed
     */
    @VTID(7)
    void onListSelection(
        java.lang.String fname);

    /**
     * List Item DblClick
     */
    @VTID(8)
    void onListDblClick(
        java.lang.String fname);

    /**
     * List Item Open
     */
    @VTID(9)
    void onListOpen(
        java.lang.String fname);

    /**
     * Active Directory changed
     */
    @VTID(10)
    void onDirChanged(
        java.lang.String dir);

}
