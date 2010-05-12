package mol.excel  ;

import com4j.*;

public enum XlBordersIndex implements ComEnum {
    xlInsideHorizontal(12),
    xlInsideVertical(11),
    xlDiagonalDown(5),
    xlDiagonalUp(6),
    xlEdgeBottom(9),
    xlEdgeLeft(7),
    xlEdgeRight(10),
    xlEdgeTop(8),
    ;

    private final int value;
    XlBordersIndex(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
