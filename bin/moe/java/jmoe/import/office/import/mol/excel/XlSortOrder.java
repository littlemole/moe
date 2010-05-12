package mol.excel  ;

import com4j.*;

public enum XlSortOrder implements ComEnum {
    xlAscending(1),
    xlDescending(2),
    ;

    private final int value;
    XlSortOrder(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
