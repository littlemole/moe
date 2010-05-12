package mol.mshtml  ;

import com4j.*;

public enum _BEHAVIOR_EVENT implements ComEnum {
    BEHAVIOREVENT_FIRST(0),
    BEHAVIOREVENT_CONTENTREADY(0),
    BEHAVIOREVENT_DOCUMENTREADY(1),
    BEHAVIOREVENT_APPLYSTYLE(2),
    BEHAVIOREVENT_DOCUMENTCONTEXTCHANGE(3),
    BEHAVIOREVENT_CONTENTSAVE(4),
    BEHAVIOREVENT_LAST(4),
    BEHAVIOR_EVENT_Max(2147483647),
    ;

    private final int value;
    _BEHAVIOR_EVENT(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
