package mol.office  ;

import com4j.*;

public enum MsoPresetExtrusionDirection implements ComEnum {
    msoPresetExtrusionDirectionMixed(-2),
    msoExtrusionBottomRight(1),
    msoExtrusionBottom(2),
    msoExtrusionBottomLeft(3),
    msoExtrusionRight(4),
    msoExtrusionNone(5),
    msoExtrusionLeft(6),
    msoExtrusionTopRight(7),
    msoExtrusionTop(8),
    msoExtrusionTopLeft(9),
    ;

    private final int value;
    MsoPresetExtrusionDirection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
