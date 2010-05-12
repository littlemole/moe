package mol.office  ;

import com4j.*;

public enum MsoPresetLightingSoftness implements ComEnum {
    msoPresetLightingSoftnessMixed(-2),
    msoLightingDim(1),
    msoLightingNormal(2),
    msoLightingBright(3),
    ;

    private final int value;
    MsoPresetLightingSoftness(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
