package mol.mshtml  ;

import com4j.*;

public enum _styleImeMode implements ComEnum {
    styleImeModeAuto(0),
    styleImeModeActive(1),
    styleImeModeInactive(2),
    styleImeModeDisabled(3),
    styleImeModeNotSet(4),
    styleImeMode_Max(2147483647),
    ;

    private final int value;
    _styleImeMode(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
