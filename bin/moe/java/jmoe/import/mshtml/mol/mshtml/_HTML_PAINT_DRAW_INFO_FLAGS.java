package mol.mshtml  ;

import com4j.*;

public enum _HTML_PAINT_DRAW_INFO_FLAGS implements ComEnum {
    HTMLPAINT_DRAWINFO_VIEWPORT(1),
    HTMLPAINT_DRAWINFO_UPDATEREGION(2),
    HTMLPAINT_DRAWINFO_XFORM(4),
    HTML_PAINT_DRAW_INFO_FLAGS_Max(2147483647),
    ;

    private final int value;
    _HTML_PAINT_DRAW_INFO_FLAGS(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
