package mol.mshtml  ;

import com4j.*;

public enum _styleLayoutGridType implements ComEnum {
    styleLayoutGridTypeNotSet(0),
    styleLayoutGridTypeLoose(1),
    styleLayoutGridTypeStrict(2),
    styleLayoutGridTypeFixed(3),
    styleLayoutGridType_Max(2147483647),
    ;

    private final int value;
    _styleLayoutGridType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
