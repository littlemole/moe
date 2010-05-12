package mol.excel  ;

import com4j.*;

public enum XlPivotFieldCalculation implements ComEnum {
    xlDifferenceFrom(2),
    xlIndex(9),
    xlNoAdditionalCalculation(-4143),
    xlPercentDifferenceFrom(4),
    xlPercentOf(3),
    xlPercentOfColumn(7),
    xlPercentOfRow(6),
    xlPercentOfTotal(8),
    xlRunningTotal(5),
    ;

    private final int value;
    XlPivotFieldCalculation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
