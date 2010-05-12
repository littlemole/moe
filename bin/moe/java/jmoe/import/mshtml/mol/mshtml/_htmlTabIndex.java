package mol.mshtml  ;

import com4j.*;

public enum _htmlTabIndex implements ComEnum {
    htmlTabIndexNotSet(-32768),
    htmlTabIndex_Max(2147483647),
    ;

    private final int value;
    _htmlTabIndex(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
