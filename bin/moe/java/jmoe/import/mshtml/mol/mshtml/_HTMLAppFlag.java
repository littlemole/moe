package mol.mshtml  ;

import com4j.*;

public enum _HTMLAppFlag implements ComEnum {
    HTMLAppFlagNo(0),
    HTMLAppFlagOff(0),
    HTMLAppFlag0(0),
    HTMLAppFlagYes(1),
    HTMLAppFlagOn(1),
    HTMLAppFlag1(1),
    HTMLAppFlag_Max(2147483647),
    ;

    private final int value;
    _HTMLAppFlag(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
