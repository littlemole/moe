package mol.shellctrl.events;

import com4j.*;

/**
 * ShellTree Event Source Interface
 */
@IID("{642D2ED7-975F-4699-B7C9-D95AAB97F826}")
public abstract class _IShellTreeEvents {
    /**
     * Tree Selection changed
     */
    @DISPID(1)
    public void onTreeSelection(
        java.lang.String fname) {
            throw new UnsupportedOperationException();
    }

    /**
     * Tree Item DblClick
     */
    @DISPID(2)
    public void onTreeDblClick(
        java.lang.String fname) {
            throw new UnsupportedOperationException();
    }

    /**
     * Tree Item Open
     */
    @DISPID(3)
    public void onTreeOpen(
        java.lang.String fname) {
            throw new UnsupportedOperationException();
    }

}
