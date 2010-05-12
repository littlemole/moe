package mol.mshtml  ;

import com4j.*;

public enum _htmlSelectType implements ComEnum {
    htmlSelectTypeSelectOne(1),
    htmlSelectTypeSelectMultiple(2),
    htmlSelectType_Max(2147483647),
    ;

    private final int value;
    _htmlSelectType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
