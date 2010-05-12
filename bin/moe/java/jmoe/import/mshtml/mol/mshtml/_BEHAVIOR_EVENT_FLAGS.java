package mol.mshtml  ;

import com4j.*;

public enum _BEHAVIOR_EVENT_FLAGS implements ComEnum {
    BEHAVIOREVENTFLAGS_BUBBLE(1),
    BEHAVIOREVENTFLAGS_STANDARDADDITIVE(2),
    BEHAVIOR_EVENT_FLAGS_Max(2147483647),
    ;

    private final int value;
    _BEHAVIOR_EVENT_FLAGS(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
