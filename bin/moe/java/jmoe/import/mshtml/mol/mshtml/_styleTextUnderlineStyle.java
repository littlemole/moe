package mol.mshtml  ;

import com4j.*;

public enum _styleTextUnderlineStyle implements ComEnum {
    styleTextUnderlineStyleUndefined(0),
    styleTextUnderlineStyleSingle(1),
    styleTextUnderlineStyleDouble(2),
    styleTextUnderlineStyleWords(3),
    styleTextUnderlineStyleDotted(4),
    styleTextUnderlineStyleThick(5),
    styleTextUnderlineStyleDash(6),
    styleTextUnderlineStyleDotDash(7),
    styleTextUnderlineStyleDotDotDash(8),
    styleTextUnderlineStyleWave(9),
    styleTextUnderlineStyleSingleAccounting(10),
    styleTextUnderlineStyleDoubleAccounting(11),
    styleTextUnderlineStyleThickDash(12),
    styleTextUnderlineStyle_Max(2147483647),
    ;

    private final int value;
    _styleTextUnderlineStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
