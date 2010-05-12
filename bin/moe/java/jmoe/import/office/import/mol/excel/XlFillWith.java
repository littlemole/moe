package mol.excel  ;

import com4j.*;

public enum XlFillWith implements ComEnum {
    xlFillWithAll(-4104),
    xlFillWithContents(2),
    xlFillWithFormats(-4122),
    ;

    private final int value;
    XlFillWith(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
