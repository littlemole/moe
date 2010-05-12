package mol.excel  ;

import com4j.*;

public enum XlArrowHeadWidth implements ComEnum {
    xlArrowHeadWidthMedium(-4138),
    xlArrowHeadWidthNarrow(1),
    xlArrowHeadWidthWide(3),
    ;

    private final int value;
    XlArrowHeadWidth(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
