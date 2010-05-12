package mol.mshtml  ;

import com4j.*;

public enum _htmlDirection implements ComEnum {
    htmlDirectionForward(99999),
    htmlDirectionBackward(-99999),
    htmlDirection_Max(2147483647),
    ;

    private final int value;
    _htmlDirection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
