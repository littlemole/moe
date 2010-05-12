package mol.mshtml  ;

import com4j.*;

public enum _htmlStart implements ComEnum {
    htmlStartfileopen(0),
    htmlStartmouseover(1),
    htmlStart_Max(2147483647),
    ;

    private final int value;
    _htmlStart(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
