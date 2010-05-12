package mol.mshtml  ;

import com4j.*;

public enum _styleTableLayout implements ComEnum {
    styleTableLayoutNotSet(0),
    styleTableLayoutAuto(1),
    styleTableLayoutFixed(2),
    styleTableLayout_Max(2147483647),
    ;

    private final int value;
    _styleTableLayout(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
