package mol.mshtml  ;

import com4j.*;

public enum _BEHAVIOR_LAYOUT_INFO implements ComEnum {
    BEHAVIORLAYOUTINFO_FULLDELEGATION(1),
    BEHAVIORLAYOUTINFO_MODIFYNATURAL(2),
    BEHAVIORLAYOUTINFO_MAPSIZE(4),
    BEHAVIOR_LAYOUT_INFO_Max(2147483647),
    ;

    private final int value;
    _BEHAVIOR_LAYOUT_INFO(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
