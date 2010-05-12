package mol.mshtml  ;

import com4j.*;

public enum _htmlCellVAlign implements ComEnum {
    htmlCellVAlignNotSet(0),
    htmlCellVAlignTop(1),
    htmlCellVAlignMiddle(2),
    htmlCellVAlignBottom(3),
    htmlCellVAlignBaseline(4),
    htmlCellVAlignCenter(2),
    htmlCellVAlign_Max(2147483647),
    ;

    private final int value;
    _htmlCellVAlign(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
