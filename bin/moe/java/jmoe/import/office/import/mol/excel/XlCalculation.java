package mol.excel  ;

import com4j.*;

public enum XlCalculation implements ComEnum {
    xlCalculationAutomatic(-4105),
    xlCalculationManual(-4135),
    xlCalculationSemiautomatic(2),
    ;

    private final int value;
    XlCalculation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
