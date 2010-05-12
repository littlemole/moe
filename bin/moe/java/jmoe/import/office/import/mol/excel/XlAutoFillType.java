package mol.excel  ;

import com4j.*;

public enum XlAutoFillType implements ComEnum {
    xlFillCopy(1),
    xlFillDays(5),
    xlFillDefault(0),
    xlFillFormats(3),
    xlFillMonths(7),
    xlFillSeries(2),
    xlFillValues(4),
    xlFillWeekdays(6),
    xlFillYears(8),
    xlGrowthTrend(10),
    xlLinearTrend(9),
    ;

    private final int value;
    XlAutoFillType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
