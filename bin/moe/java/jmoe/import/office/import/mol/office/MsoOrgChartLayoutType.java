package mol.office  ;

import com4j.*;

public enum MsoOrgChartLayoutType implements ComEnum {
    msoOrgChartLayoutMixed(-2),
    msoOrgChartLayoutStandard(1),
    msoOrgChartLayoutBothHanging(2),
    msoOrgChartLayoutLeftHanging(3),
    msoOrgChartLayoutRightHanging(4),
    ;

    private final int value;
    MsoOrgChartLayoutType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
