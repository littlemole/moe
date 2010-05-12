package mol.excel  ;

import com4j.*;

public enum XlFormatConditionType implements ComEnum {
    xlCellValue(1),
    xlExpression(2),
    xlColorScale(3),
    xlDatabar(4),
    xlTop10(5),
    xlIconSets(6),
    xlUniqueValues(8),
    xlTextString(9),
    xlBlanksCondition(10),
    xlTimePeriod(11),
    xlAboveAverageCondition(12),
    xlNoBlanksCondition(13),
    xlErrorsCondition(16),
    xlNoErrorsCondition(17),
    ;

    private final int value;
    XlFormatConditionType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
