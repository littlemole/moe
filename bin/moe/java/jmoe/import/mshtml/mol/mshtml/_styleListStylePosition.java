package mol.mshtml  ;

import com4j.*;

public enum _styleListStylePosition implements ComEnum {
    styleListStylePositionNotSet(0),
    styleListStylePositionInside(1),
    styleListStylePositionOutSide(2),
    styleListStylePosition_Max(2147483647),
    ;

    private final int value;
    _styleListStylePosition(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
