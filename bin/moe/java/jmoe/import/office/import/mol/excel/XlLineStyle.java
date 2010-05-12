package mol.excel  ;

import com4j.*;

public enum XlLineStyle implements ComEnum {
    xlContinuous(1),
    xlDash(-4115),
    xlDashDot(4),
    xlDashDotDot(5),
    xlDot(-4118),
    xlDouble(-4119),
    xlSlantDashDot(13),
    xlLineStyleNone(-4142),
    ;

    private final int value;
    XlLineStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
