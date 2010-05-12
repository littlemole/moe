package mol.excel  ;

import com4j.*;

public enum XlAxisType implements ComEnum {
    xlCategory(1),
    xlSeriesAxis(3),
    xlValue(2),
    ;

    private final int value;
    XlAxisType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
