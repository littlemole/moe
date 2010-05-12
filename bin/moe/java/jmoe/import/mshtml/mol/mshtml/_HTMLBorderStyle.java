package mol.mshtml  ;

import com4j.*;

public enum _HTMLBorderStyle implements ComEnum {
    HTMLBorderStyleNormal(0),
    HTMLBorderStyleRaised(256),
    HTMLBorderStyleSunken(512),
    HTMLBorderStylecombined(768),
    HTMLBorderStyleStatic(131072),
    HTMLBorderStyle_Max(2147483647),
    ;

    private final int value;
    _HTMLBorderStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
