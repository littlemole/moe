package mol.office  ;

import com4j.*;

public enum MsoOrientation implements ComEnum {
    msoOrientationMixed(-2),
    msoOrientationHorizontal(1),
    msoOrientationVertical(2),
    ;

    private final int value;
    MsoOrientation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
