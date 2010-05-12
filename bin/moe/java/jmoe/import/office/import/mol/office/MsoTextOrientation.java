package mol.office  ;

import com4j.*;

public enum MsoTextOrientation implements ComEnum {
    msoTextOrientationMixed(-2),
    msoTextOrientationHorizontal(1),
    msoTextOrientationUpward(2),
    msoTextOrientationDownward(3),
    msoTextOrientationVerticalFarEast(4),
    msoTextOrientationVertical(5),
    msoTextOrientationHorizontalRotatedFarEast(6),
    ;

    private final int value;
    MsoTextOrientation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
