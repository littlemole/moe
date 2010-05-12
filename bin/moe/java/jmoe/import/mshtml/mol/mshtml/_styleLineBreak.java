package mol.mshtml  ;

import com4j.*;

public enum _styleLineBreak implements ComEnum {
    styleLineBreakNotSet(0),
    styleLineBreakNormal(1),
    styleLineBreakStrict(2),
    styleLineBreak_Max(2147483647),
    ;

    private final int value;
    _styleLineBreak(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
