package mol.word  ;

import com4j.*;

public enum WdSummaryLength implements ComEnum {
    wd10Sentences(-2),
    wd20Sentences(-3),
    wd100Words(-4),
    wd500Words(-5),
    wd10Percent(-6),
    wd25Percent(-7),
    wd50Percent(-8),
    wd75Percent(-9),
    ;

    private final int value;
    WdSummaryLength(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
