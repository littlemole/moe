package mol.excel  ;

import com4j.*;

public enum XlScaleType implements ComEnum {
    xlScaleLinear(-4132),
    xlScaleLogarithmic(-4133),
    ;

    private final int value;
    XlScaleType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
