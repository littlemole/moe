package mol.mshtml  ;

import com4j.*;

public enum _htmlClear implements ComEnum {
    htmlClearNotSet(0),
    htmlClearAll(1),
    htmlClearLeft(2),
    htmlClearRight(3),
    htmlClearBoth(4),
    htmlClearNone(5),
    htmlClear_Max(2147483647),
    ;

    private final int value;
    _htmlClear(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
