package mol.mshtml  ;

import com4j.*;

public enum _ELEMENTNAMESPACE_FLAGS implements ComEnum {
    ELEMENTNAMESPACEFLAGS_ALLOWANYTAG(1),
    ELEMENTNAMESPACEFLAGS_QUERYFORUNKNOWNTAGS(2),
    ELEMENTNAMESPACE_FLAGS_Max(2147483647),
    ;

    private final int value;
    _ELEMENTNAMESPACE_FLAGS(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
