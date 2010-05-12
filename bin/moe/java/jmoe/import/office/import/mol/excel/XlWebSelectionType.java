package mol.excel  ;

import com4j.*;

public enum XlWebSelectionType implements ComEnum {
    xlEntirePage(1),
    xlAllTables(2),
    xlSpecifiedTables(3),
    ;

    private final int value;
    XlWebSelectionType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
