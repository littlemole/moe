package mol.scintilla  ;

import com4j.*;

/**
 * dual events for ScintillAX
 */
@IID("{E3766918-A0A4-48B7-942A-BA4B4D524CD0}")
public interface IScintillAxEvents extends Com4jObject {
    /**
     * Name changed
     */
    @VTID(7)
    void onFileNameChanged(
        java.lang.String fname,
        java.lang.String fPath);

    /**
     * Show Menue
     */
    @VTID(8)
    boolean onShowMenu();

    /**
     * Pos change
     */
    @VTID(9)
    void onPosChange(
        int iLine);

    /**
     * Char entered
     */
    @VTID(10)
    void onChar(
        java.lang.String ch);

    /**
     * Syntax changed
     */
    @VTID(11)
    void onSyntax(
        int s);

    /**
     * System change
     */
    @VTID(12)
    void onSystem(
        int s);

    /**
     * Encoding changed
     */
    @VTID(13)
    void onEncoding(
        int e);

}
