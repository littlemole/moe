package mol.excel  ;

import com4j.*;

public enum XlEnableSelection implements ComEnum {
    xlNoRestrictions(0),
    xlUnlockedCells(1),
    xlNoSelection(-4142),
    ;

    private final int value;
    XlEnableSelection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
