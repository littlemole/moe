package mol.shellctrl  ;

import com4j.*;

/**
 * dual events for ShellTree
 */
@IID("{D975C13F-537C-4065-A27A-D25A271A7A6E}")
public interface IShellTreeEvents extends Com4jObject {
    /**
     * Tree Selection changed
     */
    @VTID(7)
    void onTreeSelection(
        java.lang.String fname);

    /**
     * Tree Item DblClick
     */
    @VTID(8)
    void onTreeDblClick(
        java.lang.String fname);

    /**
     * Tree Item Open
     */
    @VTID(9)
    void onTreeOpen(
        java.lang.String fname);

}
