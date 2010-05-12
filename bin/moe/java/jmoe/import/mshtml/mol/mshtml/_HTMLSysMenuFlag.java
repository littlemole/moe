package mol.mshtml  ;

import com4j.*;

public enum _HTMLSysMenuFlag implements ComEnum {
    HTMLSysMenuFlagNo(0),
    HTMLSysMenuFlagYes(524288),
    HTMLSysMenuFlag_Max(2147483647),
    ;

    private final int value;
    _HTMLSysMenuFlag(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
