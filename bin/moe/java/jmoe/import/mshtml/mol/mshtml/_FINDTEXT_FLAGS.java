package mol.mshtml  ;

import com4j.*;

public enum _FINDTEXT_FLAGS implements ComEnum {
    FINDTEXT_BACKWARDS(1),
    FINDTEXT_WHOLEWORD(2),
    FINDTEXT_MATCHCASE(4),
    FINDTEXT_RAW(131072),
    FINDTEXT_MATCHDIAC(536870912),
    FINDTEXT_MATCHKASHIDA(1073741824),
    FINDTEXT_MATCHALEFHAMZA(-2147483648),
    FINDTEXT_FLAGS_Max(2147483647),
    ;

    private final int value;
    _FINDTEXT_FLAGS(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
