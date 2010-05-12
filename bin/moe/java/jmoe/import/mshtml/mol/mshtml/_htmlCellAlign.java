package mol.mshtml  ;

import com4j.*;

public enum _htmlCellAlign implements ComEnum {
    htmlCellAlignNotSet(0),
    htmlCellAlignLeft(1),
    htmlCellAlignCenter(2),
    htmlCellAlignRight(3),
    htmlCellAlignMiddle(2),
    htmlCellAlign_Max(2147483647),
    ;

    private final int value;
    _htmlCellAlign(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
