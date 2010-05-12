package mol.office  ;

import com4j.*;

public enum MsoPresetLightingDirection implements ComEnum {
    msoPresetLightingDirectionMixed(-2),
    msoLightingTopLeft(1),
    msoLightingTop(2),
    msoLightingTopRight(3),
    msoLightingLeft(4),
    msoLightingNone(5),
    msoLightingRight(6),
    msoLightingBottomLeft(7),
    msoLightingBottom(8),
    msoLightingBottomRight(9),
    ;

    private final int value;
    MsoPresetLightingDirection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
