package mol.mshtml  ;

import com4j.*;

public enum _LINE_DIRECTION implements ComEnum {
    LINE_DIRECTION_RightToLeft(1),
    LINE_DIRECTION_LeftToRight(2),
    LINE_DIRECTION_Max(2147483647),
    ;

    private final int value;
    _LINE_DIRECTION(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
