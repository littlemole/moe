package mol.word  ;

import com4j.*;

public enum WdTextOrientation implements ComEnum {
    wdTextOrientationHorizontal(0),
    wdTextOrientationUpward(2),
    wdTextOrientationDownward(3),
    wdTextOrientationVerticalFarEast(1),
    wdTextOrientationHorizontalRotatedFarEast(4),
    wdTextOrientationVertical(5),
    ;

    private final int value;
    WdTextOrientation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
