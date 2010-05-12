package mol.mshtml  ;

import com4j.*;

public enum _DISPLAY_BREAK implements ComEnum {
    DISPLAY_BREAK_None(0),
    DISPLAY_BREAK_Block(1),
    DISPLAY_BREAK_Break(2),
    DISPLAY_BREAK_Max(2147483647),
    ;

    private final int value;
    _DISPLAY_BREAK(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
