package mol.excel  ;

import com4j.*;

public enum XlConditionValueTypes implements ComEnum {
    xlConditionValueNone(-1),
    xlConditionValueNumber(0),
    xlConditionValueLowestValue(1),
    xlConditionValueHighestValue(2),
    xlConditionValuePercent(3),
    xlConditionValueFormula(4),
    xlConditionValuePercentile(5),
    ;

    private final int value;
    XlConditionValueTypes(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
