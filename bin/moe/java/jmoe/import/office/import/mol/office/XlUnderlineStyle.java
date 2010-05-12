package mol.office  ;

import com4j.*;

public enum XlUnderlineStyle implements ComEnum {
    xlUnderlineStyleDouble(-4119),
    xlUnderlineStyleDoubleAccounting(5),
    xlUnderlineStyleNone(-4142),
    xlUnderlineStyleSingle(2),
    xlUnderlineStyleSingleAccounting(4),
    ;

    private final int value;
    XlUnderlineStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
