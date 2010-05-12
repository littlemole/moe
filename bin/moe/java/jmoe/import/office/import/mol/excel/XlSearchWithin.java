package mol.excel  ;

import com4j.*;

public enum XlSearchWithin implements ComEnum {
    xlWithinSheet(1),
    xlWithinWorkbook(2),
    ;

    private final int value;
    XlSearchWithin(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
