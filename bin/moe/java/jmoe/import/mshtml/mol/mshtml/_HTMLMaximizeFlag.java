package mol.mshtml  ;

import com4j.*;

public enum _HTMLMaximizeFlag implements ComEnum {
    HTMLMaximizeFlagNo(0),
    HTMLMaximizeFlagYes(65536),
    HTMLMaximizeFlag_Max(2147483647),
    ;

    private final int value;
    _HTMLMaximizeFlag(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
