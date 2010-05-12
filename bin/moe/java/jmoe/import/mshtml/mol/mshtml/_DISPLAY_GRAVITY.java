package mol.mshtml  ;

import com4j.*;

public enum _DISPLAY_GRAVITY implements ComEnum {
    DISPLAY_GRAVITY_PreviousLine(1),
    DISPLAY_GRAVITY_NextLine(2),
    DISPLAY_GRAVITY_Max(2147483647),
    ;

    private final int value;
    _DISPLAY_GRAVITY(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
