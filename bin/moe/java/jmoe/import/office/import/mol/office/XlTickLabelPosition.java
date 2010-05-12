package mol.office  ;

import com4j.*;

public enum XlTickLabelPosition implements ComEnum {
    xlTickLabelPositionHigh(-4127),
    xlTickLabelPositionLow(-4134),
    xlTickLabelPositionNextToAxis(4),
    xlTickLabelPositionNone(-4142),
    ;

    private final int value;
    XlTickLabelPosition(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
