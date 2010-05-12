package mol.mshtml  ;

import com4j.*;

public enum _htmlWrap implements ComEnum {
    htmlWrapOff(1),
    htmlWrapSoft(2),
    htmlWrapHard(3),
    htmlWrap_Max(2147483647),
    ;

    private final int value;
    _htmlWrap(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
