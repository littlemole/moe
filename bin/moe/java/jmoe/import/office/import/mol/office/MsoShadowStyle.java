package mol.office  ;

import com4j.*;

public enum MsoShadowStyle implements ComEnum {
    msoShadowStyleMixed(-2),
    msoShadowStyleInnerShadow(1),
    msoShadowStyleOuterShadow(2),
    ;

    private final int value;
    MsoShadowStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
