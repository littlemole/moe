package mol.excel  ;

import com4j.*;

public enum XlDisplayUnit implements ComEnum {
    xlHundreds(-2),
    xlThousands(-3),
    xlTenThousands(-4),
    xlHundredThousands(-5),
    xlMillions(-6),
    xlTenMillions(-7),
    xlHundredMillions(-8),
    xlThousandMillions(-9),
    xlMillionMillions(-10),
    ;

    private final int value;
    XlDisplayUnit(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
