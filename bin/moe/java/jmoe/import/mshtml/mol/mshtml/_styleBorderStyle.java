package mol.mshtml  ;

import com4j.*;

public enum _styleBorderStyle implements ComEnum {
    styleBorderStyleNotSet(0),
    styleBorderStyleDotted(1),
    styleBorderStyleDashed(2),
    styleBorderStyleSolid(3),
    styleBorderStyleDouble(4),
    styleBorderStyleGroove(5),
    styleBorderStyleRidge(6),
    styleBorderStyleInset(7),
    styleBorderStyleOutset(8),
    styleBorderStyleWindowInset(9),
    styleBorderStyleNone(10),
    styleBorderStyle_Max(2147483647),
    ;

    private final int value;
    _styleBorderStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
