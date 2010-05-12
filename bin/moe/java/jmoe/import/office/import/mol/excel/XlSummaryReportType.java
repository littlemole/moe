package mol.excel  ;

import com4j.*;

public enum XlSummaryReportType implements ComEnum {
    xlSummaryPivotTable(-4148),
    xlStandardSummary(1),
    ;

    private final int value;
    XlSummaryReportType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
