package mol.excel  ;

import com4j.*;

public enum XlAxisGroup implements ComEnum {
    xlPrimary(1),
    xlSecondary(2),
    ;

    private final int value;
    XlAxisGroup(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
