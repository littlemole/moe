package mol.mshtml  ;

import com4j.*;

public enum _styleNormal implements ComEnum {
    styleNormalNormal(0),
    styleNormal_Max(2147483647),
    ;

    private final int value;
    _styleNormal(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
