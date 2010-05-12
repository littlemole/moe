package mol.mshtml  ;

import com4j.*;

public enum _htmlControlAlign implements ComEnum {
    htmlControlAlignNotSet(0),
    htmlControlAlignLeft(1),
    htmlControlAlignCenter(2),
    htmlControlAlignRight(3),
    htmlControlAlignTextTop(4),
    htmlControlAlignAbsMiddle(5),
    htmlControlAlignBaseline(6),
    htmlControlAlignAbsBottom(7),
    htmlControlAlignBottom(8),
    htmlControlAlignMiddle(9),
    htmlControlAlignTop(10),
    htmlControlAlign_Max(2147483647),
    ;

    private final int value;
    _htmlControlAlign(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
