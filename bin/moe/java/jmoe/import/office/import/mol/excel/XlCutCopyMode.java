package mol.excel  ;

import com4j.*;

public enum XlCutCopyMode implements ComEnum {
    xlCopy(1),
    xlCut(2),
    ;

    private final int value;
    XlCutCopyMode(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
