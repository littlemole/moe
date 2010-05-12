package mol.mshtml  ;

import com4j.*;

public enum _COORD_SYSTEM implements ComEnum {
    COORD_SYSTEM_GLOBAL(0),
    COORD_SYSTEM_PARENT(1),
    COORD_SYSTEM_CONTAINER(2),
    COORD_SYSTEM_CONTENT(3),
    COORD_SYSTEM_FRAME(4),
    COORD_SYSTEM_Max(2147483647),
    ;

    private final int value;
    _COORD_SYSTEM(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
