package mol.mshtml  ;

import com4j.*;

public enum _stylePosition implements ComEnum {
    stylePositionNotSet(0),
    stylePositionstatic(1),
    stylePositionrelative(2),
    stylePositionabsolute(3),
    stylePositionfixed(4),
    stylePosition_Max(2147483647),
    ;

    private final int value;
    _stylePosition(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
