package mol.excel  ;

import com4j.*;

public enum XlTickLabelOrientation implements ComEnum {
    xlTickLabelOrientationAutomatic(-4105),
    xlTickLabelOrientationDownward(-4170),
    xlTickLabelOrientationHorizontal(-4128),
    xlTickLabelOrientationUpward(-4171),
    xlTickLabelOrientationVertical(-4166),
    ;

    private final int value;
    XlTickLabelOrientation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
