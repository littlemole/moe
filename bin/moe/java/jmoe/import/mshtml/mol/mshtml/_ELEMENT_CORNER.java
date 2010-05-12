package mol.mshtml  ;

import com4j.*;

public enum _ELEMENT_CORNER implements ComEnum {
    ELEMENT_CORNER_NONE(0),
    ELEMENT_CORNER_TOP(1),
    ELEMENT_CORNER_LEFT(2),
    ELEMENT_CORNER_BOTTOM(3),
    ELEMENT_CORNER_RIGHT(4),
    ELEMENT_CORNER_TOPLEFT(5),
    ELEMENT_CORNER_TOPRIGHT(6),
    ELEMENT_CORNER_BOTTOMLEFT(7),
    ELEMENT_CORNER_BOTTOMRIGHT(8),
    ELEMENT_CORNER_Max(2147483647),
    ;

    private final int value;
    _ELEMENT_CORNER(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
