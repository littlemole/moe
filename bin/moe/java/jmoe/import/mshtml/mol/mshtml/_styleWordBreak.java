package mol.mshtml  ;

import com4j.*;

public enum _styleWordBreak implements ComEnum {
    styleWordBreakNotSet(0),
    styleWordBreakNormal(1),
    styleWordBreakBreakAll(2),
    styleWordBreakKeepAll(3),
    styleWordBreak_Max(2147483647),
    ;

    private final int value;
    _styleWordBreak(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
