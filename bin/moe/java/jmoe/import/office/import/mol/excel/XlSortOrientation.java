package mol.excel  ;

import com4j.*;

public enum XlSortOrientation implements ComEnum {
    xlSortRows(2),
    xlSortColumns(1),
    ;

    private final int value;
    XlSortOrientation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
