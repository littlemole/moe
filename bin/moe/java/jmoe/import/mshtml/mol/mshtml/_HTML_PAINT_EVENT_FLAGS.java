package mol.mshtml  ;

import com4j.*;

public enum _HTML_PAINT_EVENT_FLAGS implements ComEnum {
    HTMLPAINT_EVENT_TARGET(1),
    HTMLPAINT_EVENT_SETCURSOR(2),
    HTML_PAINT_EVENT_FLAGS_Max(2147483647),
    ;

    private final int value;
    _HTML_PAINT_EVENT_FLAGS(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
