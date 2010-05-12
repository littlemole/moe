package mol.office  ;

import com4j.*;

public enum MsoOrgChartOrientation implements ComEnum {
    msoOrgChartOrientationMixed(-2),
    msoOrgChartOrientationVertical(1),
    ;

    private final int value;
    MsoOrgChartOrientation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
