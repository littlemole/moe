package mol.mshtml  ;

import com4j.*;

public enum _styleLayoutGridMode implements ComEnum {
    styleLayoutGridModeNotSet(0),
    styleLayoutGridModeChar(1),
    styleLayoutGridModeLine(2),
    styleLayoutGridModeBoth(3),
    styleLayoutGridModeNone(4),
    styleLayoutGridMode_Max(2147483647),
    ;

    private final int value;
    _styleLayoutGridMode(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
