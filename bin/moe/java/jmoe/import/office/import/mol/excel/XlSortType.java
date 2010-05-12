package mol.excel  ;

import com4j.*;

public enum XlSortType implements ComEnum {
    xlSortLabels(2),
    xlSortValues(1),
    ;

    private final int value;
    XlSortType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
