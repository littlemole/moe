package mol.excel  ;

import com4j.*;

public enum XlDataSeriesDate implements ComEnum {
    xlDay(1),
    xlMonth(3),
    xlWeekday(2),
    xlYear(4),
    ;

    private final int value;
    XlDataSeriesDate(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
