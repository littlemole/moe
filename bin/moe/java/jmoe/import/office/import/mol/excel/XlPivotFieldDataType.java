package mol.excel  ;

import com4j.*;

public enum XlPivotFieldDataType implements ComEnum {
    xlDate(2),
    xlNumber(-4145),
    xlText(-4158),
    ;

    private final int value;
    XlPivotFieldDataType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
