package mol.excel  ;

import com4j.*;

public enum XlWBATemplate implements ComEnum {
    xlWBATChart(-4109),
    xlWBATExcel4IntlMacroSheet(4),
    xlWBATExcel4MacroSheet(3),
    xlWBATWorksheet(-4167),
    ;

    private final int value;
    XlWBATemplate(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
