package mol.mshtml  ;

import com4j.*;

public enum _BEHAVIOR_RELATION implements ComEnum {
    BEHAVIOR_FIRSTRELATION(0),
    BEHAVIOR_SAMEELEMENT(0),
    BEHAVIOR_PARENT(1),
    BEHAVIOR_CHILD(2),
    BEHAVIOR_SIBLING(3),
    BEHAVIOR_LASTRELATION(3),
    BEHAVIOR_RELATION_Max(2147483647),
    ;

    private final int value;
    _BEHAVIOR_RELATION(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
