package mol.mshtml  ;

import com4j.*;

public enum _ELEMENT_ADJACENCY implements ComEnum {
    ELEM_ADJ_BeforeBegin(0),
    ELEM_ADJ_AfterBegin(1),
    ELEM_ADJ_BeforeEnd(2),
    ELEM_ADJ_AfterEnd(3),
    ELEMENT_ADJACENCY_Max(2147483647),
    ;

    private final int value;
    _ELEMENT_ADJACENCY(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
