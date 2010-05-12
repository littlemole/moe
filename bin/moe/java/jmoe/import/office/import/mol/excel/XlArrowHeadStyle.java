package mol.excel  ;

import com4j.*;

public enum XlArrowHeadStyle implements ComEnum {
    xlArrowHeadStyleClosed(3),
    xlArrowHeadStyleDoubleClosed(5),
    xlArrowHeadStyleDoubleOpen(4),
    xlArrowHeadStyleNone(-4142),
    xlArrowHeadStyleOpen(2),
    ;

    private final int value;
    XlArrowHeadStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
