package mol.mshtml  ;

import com4j.*;

public enum _SECUREURLHOSTVALIDATE_FLAGS implements ComEnum {
    SUHV_PROMPTBEFORENO(1),
    SUHV_SILENTYES(2),
    SUHV_UNSECURESOURCE(4),
    SECUREURLHOSTVALIDATE_FLAGS_Max(2147483647),
    ;

    private final int value;
    _SECUREURLHOSTVALIDATE_FLAGS(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
