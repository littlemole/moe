package mol.mshtml  ;

import com4j.*;

public enum _htmlSelectExFlag implements ComEnum {
    htmlSelectExFlagNone(0),
    htmlSelectExFlagHideSelectionInDesign(1),
    htmlSelectExFlag_Max(2147483647),
    ;

    private final int value;
    _htmlSelectExFlag(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
