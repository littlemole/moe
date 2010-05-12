package mol.scintilla.events;

import com4j.*;

/**
 * ScintillAX Event Source Interface
 */
@IID("{2D33B016-176A-40FE-B665-B114A6511AC8}")
public abstract class _IScintillAxEvents {
    /**
     * Name changed
     */
    @DISPID(1)
    public void onFileNameChanged(
        java.lang.String fname,
        java.lang.String fPath) {
            throw new UnsupportedOperationException();
    }

    /**
     * Show Menue
     */
    @DISPID(2)
    public void onShowMenu() {
            throw new UnsupportedOperationException();
    }

    /**
     * Pos change
     */
    @DISPID(3)
    public void onPosChange(
        int iLine) {
            throw new UnsupportedOperationException();
    }

    /**
     * Char entered
     */
    @DISPID(4)
    public void onChar(
        java.lang.String ch) {
            throw new UnsupportedOperationException();
    }

}
