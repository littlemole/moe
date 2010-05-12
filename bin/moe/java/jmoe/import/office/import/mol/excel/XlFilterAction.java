package mol.excel  ;

import com4j.*;

public enum XlFilterAction implements ComEnum {
    xlFilterCopy(2),
    xlFilterInPlace(1),
    ;

    private final int value;
    XlFilterAction(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
