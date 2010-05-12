package mol.excel  ;

import com4j.*;

public enum XlAutoFilterOperator implements ComEnum {
    xlAnd(1),
    xlBottom10Items(4),
    xlBottom10Percent(6),
    xlOr(2),
    xlTop10Items(3),
    xlTop10Percent(5),
    xlFilterValues(7),
    xlFilterCellColor(8),
    xlFilterFontColor(9),
    xlFilterIcon(10),
    xlFilterDynamic(11),
    xlFilterNoFill(12),
    xlFilterAutomaticFontColor(13),
    xlFilterNoIcon(14),
    ;

    private final int value;
    XlAutoFilterOperator(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
