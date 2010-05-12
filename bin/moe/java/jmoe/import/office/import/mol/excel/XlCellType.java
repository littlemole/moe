package mol.excel  ;

import com4j.*;

public enum XlCellType implements ComEnum {
    xlCellTypeBlanks(4),
    xlCellTypeConstants(2),
    xlCellTypeFormulas(-4123),
    xlCellTypeLastCell(11),
    xlCellTypeComments(-4144),
    xlCellTypeVisible(12),
    xlCellTypeAllFormatConditions(-4172),
    xlCellTypeSameFormatConditions(-4173),
    xlCellTypeAllValidation(-4174),
    xlCellTypeSameValidation(-4175),
    ;

    private final int value;
    XlCellType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
