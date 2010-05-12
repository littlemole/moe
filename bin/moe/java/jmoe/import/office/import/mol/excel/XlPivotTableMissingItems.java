package mol.excel  ;

import com4j.*;

public enum XlPivotTableMissingItems implements ComEnum {
    xlMissingItemsDefault(-1),
    xlMissingItemsNone(0),
    xlMissingItemsMax(32500),
    xlMissingItemsMax2(1048576),
    ;

    private final int value;
    XlPivotTableMissingItems(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
