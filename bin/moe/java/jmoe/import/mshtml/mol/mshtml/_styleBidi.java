package mol.mshtml  ;

import com4j.*;

public enum _styleBidi implements ComEnum {
    styleBidiNotSet(0),
    styleBidiNormal(1),
    styleBidiEmbed(2),
    styleBidiOverride(3),
    styleBidiInherit(4),
    styleBidi_Max(2147483647),
    ;

    private final int value;
    _styleBidi(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
