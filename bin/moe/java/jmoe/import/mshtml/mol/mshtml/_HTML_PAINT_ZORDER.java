package mol.mshtml  ;

import com4j.*;

public enum _HTML_PAINT_ZORDER implements ComEnum {
    HTMLPAINT_ZORDER_NONE(0),
    HTMLPAINT_ZORDER_REPLACE_ALL(1),
    HTMLPAINT_ZORDER_REPLACE_CONTENT(2),
    HTMLPAINT_ZORDER_REPLACE_BACKGROUND(3),
    HTMLPAINT_ZORDER_BELOW_CONTENT(4),
    HTMLPAINT_ZORDER_BELOW_FLOW(5),
    HTMLPAINT_ZORDER_ABOVE_FLOW(6),
    HTMLPAINT_ZORDER_ABOVE_CONTENT(7),
    HTMLPAINT_ZORDER_WINDOW_TOP(8),
    HTML_PAINT_ZORDER_Max(2147483647),
    ;

    private final int value;
    _HTML_PAINT_ZORDER(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
