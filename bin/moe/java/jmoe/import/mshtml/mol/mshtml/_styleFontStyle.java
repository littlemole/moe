package mol.mshtml  ;

import com4j.*;

public enum _styleFontStyle implements ComEnum {
    styleFontStyleNotSet(0),
    styleFontStyleItalic(1),
    styleFontStyleOblique(2),
    styleFontStyleNormal(3),
    styleFontStyle_Max(2147483647),
    ;

    private final int value;
    _styleFontStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
