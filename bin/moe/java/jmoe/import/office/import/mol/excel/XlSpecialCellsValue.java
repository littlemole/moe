package mol.excel  ;

import com4j.*;

public enum XlSpecialCellsValue implements ComEnum {
    xlErrors(16),
    xlLogical(4),
    xlNumbers(1),
    xlTextValues(2),
    ;

    private final int value;
    XlSpecialCellsValue(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
