package mol.mshtml  ;

import com4j.*;

public enum _styleInterpolation implements ComEnum {
    styleInterpolationNotSet(0),
    styleInterpolationNN(1),
    styleInterpolationBCH(2),
    styleInterpolation_Max(2147483647),
    ;

    private final int value;
    _styleInterpolation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
