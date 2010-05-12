package mol.office  ;

import com4j.*;

public enum MsoColorType implements ComEnum {
    msoColorTypeMixed(-2),
    msoColorTypeRGB(1),
    msoColorTypeScheme(2),
    msoColorTypeCMYK(3),
    msoColorTypeCMS(4),
    msoColorTypeInk(5),
    ;

    private final int value;
    MsoColorType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
