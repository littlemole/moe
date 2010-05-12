package mol.excel  ;

import com4j.*;

public enum XlWindowView implements ComEnum {
    xlNormalView(1),
    xlPageBreakPreview(2),
    xlPageLayoutView(3),
    ;

    private final int value;
    XlWindowView(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
