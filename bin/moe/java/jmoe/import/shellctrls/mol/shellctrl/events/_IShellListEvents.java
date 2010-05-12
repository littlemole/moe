package mol.shellctrl.events;

import com4j.*;

/**
 * ShellList Event Source Interface
 */
@IID("{24165625-BBB8-404A-B2BC-62B9F40FE7DD}")
public abstract class _IShellListEvents {
    /**
     * List Selection changed
     */
    @DISPID(1)
    public void onListSelection(
        java.lang.String fname) {
            throw new UnsupportedOperationException();
    }

    /**
     * List Item DblClick
     */
    @DISPID(2)
    public void onListDblClick(
        java.lang.String fname) {
            throw new UnsupportedOperationException();
    }

    /**
     * List Item Open
     */
    @DISPID(3)
    public void onListOpen(
        java.lang.String fname) {
            throw new UnsupportedOperationException();
    }

    /**
     * Active Directory changed
     */
    @DISPID(4)
    public void onDirChanged(
        java.lang.String dir) {
            throw new UnsupportedOperationException();
    }

}
