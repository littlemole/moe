package mol.mshtml  ;

import com4j.*;

public enum _styleVisibility implements ComEnum {
    styleVisibilityNotSet(0),
    styleVisibilityInherit(1),
    styleVisibilityVisible(2),
    styleVisibilityHidden(3),
    styleVisibility_Max(2147483647),
    ;

    private final int value;
    _styleVisibility(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
