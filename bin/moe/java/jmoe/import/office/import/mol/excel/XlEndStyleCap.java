package mol.excel  ;

import com4j.*;

public enum XlEndStyleCap implements ComEnum {
    xlCap(1),
    xlNoCap(2),
    ;

    private final int value;
    XlEndStyleCap(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
