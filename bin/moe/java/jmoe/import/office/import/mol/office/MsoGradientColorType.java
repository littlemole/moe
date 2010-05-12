package mol.office  ;

import com4j.*;

public enum MsoGradientColorType implements ComEnum {
    msoGradientColorMixed(-2),
    msoGradientOneColor(1),
    msoGradientTwoColors(2),
    msoGradientPresetColors(3),
    msoGradientMultiColor(4),
    ;

    private final int value;
    MsoGradientColorType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
