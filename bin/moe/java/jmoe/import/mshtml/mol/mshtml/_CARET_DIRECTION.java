package mol.mshtml  ;

import com4j.*;

public enum _CARET_DIRECTION implements ComEnum {
    CARET_DIRECTION_INDETERMINATE(0),
    CARET_DIRECTION_SAME(1),
    CARET_DIRECTION_BACKWARD(2),
    CARET_DIRECTION_FORWARD(3),
    CARET_DIRECTION_Max(2147483647),
    ;

    private final int value;
    _CARET_DIRECTION(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
