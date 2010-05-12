package mol.excel  ;

import com4j.*;

public enum XlPictureAppearance implements ComEnum {
    xlPrinter(2),
    xlScreen(1),
    ;

    private final int value;
    XlPictureAppearance(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
