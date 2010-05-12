package mol.shellctrl.events;

import com4j.*;

/**
 * HexCtrl Event Source Interface
 */
@IID("{AAB8E8A1-A963-4345-ACA6-38DC7CF01A78}")
public abstract class _IHexCtrlEvents {
    /**
     * HexWnd filename changed
     */
    @DISPID(1)
    public void onNewFile(
        java.lang.String fname,
        boolean vbReadOnly) {
            throw new UnsupportedOperationException();
    }

    /**
     * Offset changed
     */
    @DISPID(2)
    public void onNewOffset(
        java.lang.String address,
        java.lang.String value) {
            throw new UnsupportedOperationException();
    }

    /**
     * Value changed
     */
    @DISPID(3)
    public void onNewValue(
        java.lang.String address,
        java.lang.String value) {
            throw new UnsupportedOperationException();
    }

}
