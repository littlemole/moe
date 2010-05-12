package mol.excel  ;

import com4j.*;

public enum XlChartSplitType implements ComEnum {
    xlSplitByPosition(1),
    xlSplitByPercentValue(3),
    xlSplitByCustomSplit(4),
    xlSplitByValue(2),
    ;

    private final int value;
    XlChartSplitType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
