package mol.mshtml  ;

import com4j.*;

public enum _styleBool implements ComEnum {
    styleBoolFalse(0),
    styleBoolTrue(1),
    styleBool_Max(2147483647),
    ;

    private final int value;
    _styleBool(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}