package mol.excel  ;

import com4j.*;

public enum XlDynamicFilterCriteria implements ComEnum {
    xlFilterToday(1),
    xlFilterYesterday(2),
    xlFilterTomorrow(3),
    xlFilterThisWeek(4),
    xlFilterLastWeek(5),
    xlFilterNextWeek(6),
    xlFilterThisMonth(7),
    xlFilterLastMonth(8),
    xlFilterNextMonth(9),
    xlFilterThisQuarter(10),
    xlFilterLastQuarter(11),
    xlFilterNextQuarter(12),
    xlFilterThisYear(13),
    xlFilterLastYear(14),
    xlFilterNextYear(15),
    xlFilterYearToDate(16),
    xlFilterAllDatesInPeriodQuarter1(17),
    xlFilterAllDatesInPeriodQuarter2(18),
    xlFilterAllDatesInPeriodQuarter3(19),
    xlFilterAllDatesInPeriodQuarter4(20),
    xlFilterAllDatesInPeriodJanuary(21),
    xlFilterAllDatesInPeriodFebruray(22),
    xlFilterAllDatesInPeriodMarch(23),
    xlFilterAllDatesInPeriodApril(24),
    xlFilterAllDatesInPeriodMay(25),
    xlFilterAllDatesInPeriodJune(26),
    xlFilterAllDatesInPeriodJuly(27),
    xlFilterAllDatesInPeriodAugust(28),
    xlFilterAllDatesInPeriodSeptember(29),
    xlFilterAllDatesInPeriodOctober(30),
    xlFilterAllDatesInPeriodNovember(31),
    xlFilterAllDatesInPeriodDecember(32),
    xlFilterAboveAverage(33),
    xlFilterBelowAverage(34),
    ;

    private final int value;
    XlDynamicFilterCriteria(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
