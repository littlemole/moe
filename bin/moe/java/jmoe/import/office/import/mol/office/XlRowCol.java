package mol.office  ;

import com4j.*;

public enum XlRowCol implements ComEnum {
    xlColumns(2),
    xlRows(1),
    ;

    private final int value;
    XlRowCol(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
