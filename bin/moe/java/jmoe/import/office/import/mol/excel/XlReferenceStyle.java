package mol.excel  ;

import com4j.*;

public enum XlReferenceStyle implements ComEnum {
    xlA1(1),
    xlR1C1(-4150),
    ;

    private final int value;
    XlReferenceStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
