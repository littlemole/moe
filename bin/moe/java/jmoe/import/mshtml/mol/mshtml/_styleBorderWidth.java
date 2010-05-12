package mol.mshtml  ;

import com4j.*;

public enum _styleBorderWidth implements ComEnum {
    styleBorderWidthThin(0),
    styleBorderWidthMedium(1),
    styleBorderWidthThick(2),
    styleBorderWidth_Max(2147483647),
    ;

    private final int value;
    _styleBorderWidth(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
