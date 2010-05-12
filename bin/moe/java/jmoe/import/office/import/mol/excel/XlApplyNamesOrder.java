package mol.excel  ;

import com4j.*;

public enum XlApplyNamesOrder implements ComEnum {
    xlColumnThenRow(2),
    xlRowThenColumn(1),
    ;

    private final int value;
    XlApplyNamesOrder(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
