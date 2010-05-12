package mol.word  ;

import com4j.*;

public enum WdCalendarTypeBi implements ComEnum {
    wdCalendarTypeBidi(99),
    wdCalendarTypeGregorian(100),
    ;

    private final int value;
    WdCalendarTypeBi(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
