package mol.excel  ;

import com4j.*;

public enum XlFormatConditionOperator implements ComEnum {
    xlBetween(1),
    xlNotBetween(2),
    xlEqual(3),
    xlNotEqual(4),
    xlGreater(5),
    xlLess(6),
    xlGreaterEqual(7),
    xlLessEqual(8),
    ;

    private final int value;
    XlFormatConditionOperator(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
