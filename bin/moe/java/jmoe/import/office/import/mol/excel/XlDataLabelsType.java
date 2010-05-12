package mol.excel  ;

import com4j.*;

public enum XlDataLabelsType implements ComEnum {
    xlDataLabelsShowNone(-4142),
    xlDataLabelsShowValue(2),
    xlDataLabelsShowPercent(3),
    xlDataLabelsShowLabel(4),
    xlDataLabelsShowLabelAndPercent(5),
    xlDataLabelsShowBubbleSizes(6),
    ;

    private final int value;
    XlDataLabelsType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
