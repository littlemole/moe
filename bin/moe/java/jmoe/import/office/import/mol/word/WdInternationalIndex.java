package mol.word  ;

import com4j.*;

public enum WdInternationalIndex implements ComEnum {
    wdListSeparator(17),
    wdDecimalSeparator(18),
    wdThousandsSeparator(19),
    wdCurrencyCode(20),
    wd24HourClock(21),
    wdInternationalAM(22),
    wdInternationalPM(23),
    wdTimeSeparator(24),
    wdDateSeparator(25),
    wdProductLanguageID(26),
    ;

    private final int value;
    WdInternationalIndex(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
