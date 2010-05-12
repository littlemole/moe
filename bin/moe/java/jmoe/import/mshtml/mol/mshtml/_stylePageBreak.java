package mol.mshtml  ;

import com4j.*;

public enum _stylePageBreak implements ComEnum {
    stylePageBreakNotSet(0),
    stylePageBreakAuto(1),
    stylePageBreakAlways(2),
    stylePageBreakLeft(3),
    stylePageBreakRight(4),
    stylePageBreak_Max(2147483647),
    ;

    private final int value;
    _stylePageBreak(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
