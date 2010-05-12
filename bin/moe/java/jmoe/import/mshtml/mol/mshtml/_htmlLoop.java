package mol.mshtml  ;

import com4j.*;

public enum _htmlLoop implements ComEnum {
    htmlLoopLoopInfinite(-1),
    htmlLoop_Max(2147483647),
    ;

    private final int value;
    _htmlLoop(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
