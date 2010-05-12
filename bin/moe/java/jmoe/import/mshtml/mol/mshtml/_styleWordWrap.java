package mol.mshtml  ;

import com4j.*;

public enum _styleWordWrap implements ComEnum {
    styleWordWrapNotSet(0),
    styleWordWrapOff(1),
    styleWordWrapOn(2),
    styleWordWrap_Max(2147483647),
    ;

    private final int value;
    _styleWordWrap(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
