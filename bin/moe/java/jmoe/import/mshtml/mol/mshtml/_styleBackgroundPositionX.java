package mol.mshtml  ;

import com4j.*;

public enum _styleBackgroundPositionX implements ComEnum {
    styleBackgroundPositionXNotSet(0),
    styleBackgroundPositionXLeft(1),
    styleBackgroundPositionXCenter(2),
    styleBackgroundPositionXRight(3),
    styleBackgroundPositionX_Max(2147483647),
    ;

    private final int value;
    _styleBackgroundPositionX(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
