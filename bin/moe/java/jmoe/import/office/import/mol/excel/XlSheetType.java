package mol.excel  ;

import com4j.*;

public enum XlSheetType implements ComEnum {
    xlChart(-4109),
    xlDialogSheet(-4116),
    xlExcel4IntlMacroSheet(4),
    xlExcel4MacroSheet(3),
    xlWorksheet(-4167),
    ;

    private final int value;
    XlSheetType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
