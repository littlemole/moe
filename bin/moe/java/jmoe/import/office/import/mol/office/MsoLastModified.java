package mol.office  ;

import com4j.*;

public enum MsoLastModified implements ComEnum {
    msoLastModifiedYesterday(1),
    msoLastModifiedToday(2),
    msoLastModifiedLastWeek(3),
    msoLastModifiedThisWeek(4),
    msoLastModifiedLastMonth(5),
    msoLastModifiedThisMonth(6),
    msoLastModifiedAnyTime(7),
    ;

    private final int value;
    MsoLastModified(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
