package mol.excel  ;

import com4j.*;

public enum XlSearchOrder implements ComEnum {
    xlByColumns(2),
    xlByRows(1),
    ;

    private final int value;
    XlSearchOrder(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
