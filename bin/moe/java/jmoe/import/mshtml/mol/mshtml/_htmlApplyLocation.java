package mol.mshtml  ;

import com4j.*;

public enum _htmlApplyLocation implements ComEnum {
    htmlApplyLocationInside(0),
    htmlApplyLocationOutside(1),
    htmlApplyLocation_Max(2147483647),
    ;

    private final int value;
    _htmlApplyLocation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}