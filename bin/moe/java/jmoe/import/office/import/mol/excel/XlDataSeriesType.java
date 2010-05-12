package mol.excel  ;

import com4j.*;

public enum XlDataSeriesType implements ComEnum {
    xlAutoFill(4),
    xlChronological(3),
    xlGrowth(2),
    xlDataSeriesLinear(-4132),
    ;

    private final int value;
    XlDataSeriesType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
