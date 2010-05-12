package mol.moe  ;

import com4j.*;

/**
 * XMoe Event Interface
 */
@IID("{00020400-0000-0000-C000-000000000046}")
public interface _IXmoeEvents extends Com4jObject {
    /**
     * FileName changed
     */
    @DISPID(1)
    void onFileNameChanged(
        java.lang.String fname);

    /**
     * Show Menue, return bool value to indicate wether to show default menu
     */
    @DISPID(2)
    void onShowMenu();

    /**
     * Caret Position in editor changed
     */
    @DISPID(3)
    void onPosChange(
        int posLine);

    /**
     * Char was entered in editor
     */
    @DISPID(4)
    void onChar(
        java.lang.String ch);

}
