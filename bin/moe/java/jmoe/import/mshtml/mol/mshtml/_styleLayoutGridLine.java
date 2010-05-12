package mol.mshtml  ;

import com4j.*;

public enum _styleLayoutGridLine implements ComEnum {
    styleLayoutGridLineNotSet(0),
    styleLayoutGridLineAuto(1),
    styleLayoutGridLineNone(2),
    styleLayoutGridLine_Max(2147483647),
    ;

    private final int value;
    _styleLayoutGridLine(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
