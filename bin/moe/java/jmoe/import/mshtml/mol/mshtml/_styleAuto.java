package mol.mshtml  ;

import com4j.*;

public enum _styleAuto implements ComEnum {
    styleAutoAuto(0),
    styleAuto_Max(2147483647),
    ;

    private final int value;
    _styleAuto(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
