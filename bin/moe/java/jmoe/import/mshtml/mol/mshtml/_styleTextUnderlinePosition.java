package mol.mshtml  ;

import com4j.*;

public enum _styleTextUnderlinePosition implements ComEnum {
    styleTextUnderlinePositionBelow(0),
    styleTextUnderlinePositionAbove(1),
    styleTextUnderlinePositionAuto(2),
    styleTextUnderlinePositionNotSet(3),
    styleTextUnderlinePosition_Max(2147483647),
    ;

    private final int value;
    _styleTextUnderlinePosition(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
