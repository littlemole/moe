package mol.excel  ;

import com4j.*;

public enum XlDataLabelSeparator implements ComEnum {
    xlDataLabelSeparatorDefault(1),
    ;

    private final int value;
    XlDataLabelSeparator(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
