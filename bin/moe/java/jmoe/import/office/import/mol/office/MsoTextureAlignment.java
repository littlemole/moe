package mol.office  ;

import com4j.*;

public enum MsoTextureAlignment implements ComEnum {
    msoTextureAlignmentMixed(-2),
    msoTextureTopLeft(0),
    msoTextureTop(1),
    msoTextureTopRight(2),
    msoTextureLeft(3),
    msoTextureCenter(4),
    msoTextureRight(5),
    msoTextureBottomLeft(6),
    msoTextureBottom(7),
    msoTextureBottomRight(8),
    ;

    private final int value;
    MsoTextureAlignment(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
