package mol.excel  ;

import com4j.*;

public enum XlPivotFilterType implements ComEnum {
    xlTopCount(1),
    xlBottomCount(2),
    xlTopPercent(3),
    xlBottomPercent(4),
    xlTopSum(5),
    xlBottomSum(6),
    xlValueEquals(7),
    xlValueDoesNotEqual(8),
    xlValueIsGreaterThan(9),
    xlValueIsGreaterThanOrEqualTo(10),
    xlValueIsLessThan(11),
    xlValueIsLessThanOrEqualTo(12),
    xlValueIsBetween(13),
    xlValueIsNotBetween(14),
    xlCaptionEquals(15),
    xlCaptionDoesNotEqual(16),
    xlCaptionBeginsWith(17),
    xlCaptionDoesNotBeginWith(18),
    xlCaptionEndsWith(19),
    xlCaptionDoesNotEndWith(20),
    xlCaptionContains(21),
    xlCaptionDoesNotContain(22),
    xlCaptionIsGreaterThan(23),
    xlCaptionIsGreaterThanOrEqualTo(24),
    xlCaptionIsLessThan(25),
    xlCaptionIsLessThanOrEqualTo(26),
    xlCaptionIsBetween(27),
    xlCaptionIsNotBetween(28),
    xlSpecificDate(29),
    xlNotSpecificDate(30),
    xlBefore(31),
    xlBeforeOrEqualTo(32),
    xlAfter(33),
    xlAfterOrEqualTo(34),
    xlDateBetween(35),
    xlDateNotBetween(36),
    xlDateTomorrow(37),
    xlDateToday(38),
    xlDateYesterday(39),
    xlDateNextWeek(40),
    xlDateThisWeek(41),
    xlDateLastWeek(42),
    xlDateNextMonth(43),
    xlDateThisMonth(44),
    xlDateLastMonth(45),
    xlDateNextQuarter(46),
    xlDateThisQuarter(47),
    xlDateLastQuarter(48),
    xlDateNextYear(49),
    xlDateThisYear(50),
    xlDateLastYear(51),
    xlYearToDate(52),
    xlAllDatesInPeriodQuarter1(53),
    xlAllDatesInPeriodQuarter2(54),
    xlAllDatesInPeriodQuarter3(55),
    xlAllDatesInPeriodQuarter4(56),
    xlAllDatesInPeriodJanuary(57),
    xlAllDatesInPeriodFebruary(58),
    xlAllDatesInPeriodMarch(59),
    xlAllDatesInPeriodApril(60),
    xlAllDatesInPeriodMay(61),
    xlAllDatesInPeriodJune(62),
    xlAllDatesInPeriodJuly(63),
    xlAllDatesInPeriodAugust(64),
    xlAllDatesInPeriodSeptember(65),
    xlAllDatesInPeriodOctober(66),
    xlAllDatesInPeriodNovember(67),
    xlAllDatesInPeriodDecember(68),
    ;

    private final int value;
    XlPivotFilterType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
