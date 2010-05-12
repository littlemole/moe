package mol.shellctrl  ;

import com4j.*;

/**
 * dual events for HexCtrl
 */
@IID("{2031340D-A1E9-4FCF-8774-B94A565D6225}")
public interface IHexCtrlEvents extends Com4jObject {
    /**
     * HexWnd filename changed
     */
    @VTID(7)
    void onNewFile(
        java.lang.String fname,
        boolean vbReadOnly);

    /**
     * Offset changed
     */
    @VTID(8)
    void onNewOffset(
        java.lang.String address,
        java.lang.String value);

    /**
     * Value changed
     */
    @VTID(9)
    void onNewValue(
        java.lang.String address,
        java.lang.String value);

}
