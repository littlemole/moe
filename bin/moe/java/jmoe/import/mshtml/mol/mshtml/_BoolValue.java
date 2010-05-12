package mol.mshtml  ;

import com4j.*;

public enum _BoolValue implements ComEnum {
    True(1),
    False(0),
    BoolValue_Max(2147483647),
    ;

    private final int value;
    _BoolValue(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
