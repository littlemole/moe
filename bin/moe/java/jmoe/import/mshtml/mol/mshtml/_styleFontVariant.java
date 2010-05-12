package mol.mshtml  ;

import com4j.*;

public enum _styleFontVariant implements ComEnum {
    styleFontVariantNotSet(0),
    styleFontVariantSmallCaps(1),
    styleFontVariantNormal(2),
    styleFontVariant_Max(2147483647),
    ;

    private final int value;
    _styleFontVariant(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
