package mol.office  ;

import com4j.*;

public enum XlTrendlineType implements ComEnum {
    xlExponential(5),
    xlLinear(-4132),
    xlLogarithmic(-4133),
    xlMovingAvg(6),
    xlPolynomial(3),
    xlPower(4),
    ;

    private final int value;
    XlTrendlineType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
