package mol.mshtml  ;

import com4j.*;

public enum _styleTextOverflow implements ComEnum {
    styleTextOverflowClip(0),
    styleTextOverflowEllipsis(1),
    styleTextOverflowNotSet(2),
    styleTextOverflow_Max(2147483647),
    ;

    private final int value;
    _styleTextOverflow(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
