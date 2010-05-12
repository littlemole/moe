package mol.mshtml  ;

import com4j.*;

public enum _PARSE_FLAGS implements ComEnum {
    PARSE_ABSOLUTIFYIE40URLS(1),
    PARSE_FLAGS_Max(2147483647),
    ;

    private final int value;
    _PARSE_FLAGS(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
