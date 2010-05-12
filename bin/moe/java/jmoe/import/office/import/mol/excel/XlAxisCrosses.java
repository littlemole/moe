package mol.excel  ;

import com4j.*;

public enum XlAxisCrosses implements ComEnum {
    xlAxisCrossesAutomatic(-4105),
    xlAxisCrossesCustom(-4114),
    xlAxisCrossesMaximum(2),
    xlAxisCrossesMinimum(4),
    ;

    private final int value;
    XlAxisCrosses(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
