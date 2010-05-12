package mol.mshtml  ;

import com4j.*;

public enum _HTMLWindowState implements ComEnum {
    HTMLWindowStateNormal(1),
    HTMLWindowStateMaximize(3),
    HTMLWindowStateMinimize(6),
    HTMLWindowState_Max(2147483647),
    ;

    private final int value;
    _HTMLWindowState(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
