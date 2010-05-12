package mol.excel  ;

import com4j.*;

public enum XlSummaryColumn implements ComEnum {
    xlSummaryOnLeft(-4131),
    xlSummaryOnRight(-4152),
    ;

    private final int value;
    XlSummaryColumn(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
