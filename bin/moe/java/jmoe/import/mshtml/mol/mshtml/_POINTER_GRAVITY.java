package mol.mshtml  ;

import com4j.*;

public enum _POINTER_GRAVITY implements ComEnum {
    POINTER_GRAVITY_Left(0),
    POINTER_GRAVITY_Right(1),
    POINTER_GRAVITY_Max(2147483647),
    ;

    private final int value;
    _POINTER_GRAVITY(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
