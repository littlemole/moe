package mol.excel  ;

import com4j.*;

public enum XlLookAt implements ComEnum {
    xlPart(2),
    xlWhole(1),
    ;

    private final int value;
    XlLookAt(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
