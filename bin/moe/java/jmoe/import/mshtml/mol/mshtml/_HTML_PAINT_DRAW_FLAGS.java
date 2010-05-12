package mol.mshtml  ;

import com4j.*;

public enum _HTML_PAINT_DRAW_FLAGS implements ComEnum {
    HTMLPAINT_DRAW_UPDATEREGION(1),
    HTMLPAINT_DRAW_USE_XFORM(2),
    HTML_PAINT_DRAW_FLAGS_Max(2147483647),
    ;

    private final int value;
    _HTML_PAINT_DRAW_FLAGS(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
