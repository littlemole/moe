package mol.office  ;

import com4j.*;

public enum MsoExtrusionColorType implements ComEnum {
    msoExtrusionColorTypeMixed(-2),
    msoExtrusionColorAutomatic(1),
    msoExtrusionColorCustom(2),
    ;

    private final int value;
    MsoExtrusionColorType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
