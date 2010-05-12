package mol.office  ;

import com4j.*;

public enum MsoTextureType implements ComEnum {
    msoTextureTypeMixed(-2),
    msoTexturePreset(1),
    msoTextureUserDefined(2),
    ;

    private final int value;
    MsoTextureType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
