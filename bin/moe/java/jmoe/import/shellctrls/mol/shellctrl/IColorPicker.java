package mol.shellctrl  ;

import com4j.*;

/**
 * ColorPicker Dialog
 */
@IID("{60B3F5EC-7FC7-417A-9D90-F21C78B3FC05}")
public interface IColorPicker extends Com4jObject {
    /**
     * get/set current Color as OLE_COLOR
     */
    @VTID(7)
    void color(
        int cl);

    /**
     * get/set current Color as OLE_COLOR
     */
    @VTID(8)
    int color();

    /**
     * get/set Color as HexValue (HTML-Format)
     */
    @VTID(9)
    void hexColor(
        java.lang.String cl);

    /**
     * get/set Color as HexValue (HTML-Format)
     */
    @VTID(10)
    java.lang.String hexColor();

    /**
     * show the ColorPicker dialog
     */
    @VTID(11)
    boolean show();

}
