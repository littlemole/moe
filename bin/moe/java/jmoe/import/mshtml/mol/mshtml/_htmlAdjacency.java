package mol.mshtml  ;

import com4j.*;

public enum _htmlAdjacency implements ComEnum {
    htmlAdjacencyBeforeBegin(1),
    htmlAdjacencyAfterBegin(2),
    htmlAdjacencyBeforeEnd(3),
    htmlAdjacencyAfterEnd(4),
    htmlAdjacency_Max(2147483647),
    ;

    private final int value;
    _htmlAdjacency(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
