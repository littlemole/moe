package mol.wsh  ;

import com4j.*;

/**
 * Shell Object Interface
 */
@IID("{24BE5A30-EDFE-11D2-B933-00104B365C9F}")
public interface IWshShell2 extends mol.wsh.IWshShell {
    @VTID(16)
    boolean logEvent(
        java.lang.Object type,
        java.lang.String message,
        java.lang.String target);

    @VTID(17)
    boolean appActivate(
        java.lang.Object app,
        java.lang.Object wait);

    @VTID(18)
    void sendKeys(
        java.lang.String keys,
        java.lang.Object wait);

}
