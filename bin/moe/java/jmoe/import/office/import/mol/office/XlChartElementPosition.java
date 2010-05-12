package mol.office  ;

import com4j.*;

public enum XlChartElementPosition implements ComEnum {
    xlChartElementPositionAutomatic(-4105),
    xlChartElementPositionCustom(-4114),
    ;

    private final int value;
    XlChartElementPosition(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
