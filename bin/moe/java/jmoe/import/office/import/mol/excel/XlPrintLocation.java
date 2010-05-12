package mol.excel  ;

import com4j.*;

public enum XlPrintLocation implements ComEnum {
    xlPrintSheetEnd(1),
    xlPrintInPlace(16),
    xlPrintNoComments(-4142),
    ;

    private final int value;
    XlPrintLocation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
