package mol.mshtml  ;

import com4j.*;

public enum _styleVerticalAlign implements ComEnum {
    styleVerticalAlignAuto(0),
    styleVerticalAlignBaseline(1),
    styleVerticalAlignSub(2),
    styleVerticalAlignSuper(3),
    styleVerticalAlignTop(4),
    styleVerticalAlignTextTop(5),
    styleVerticalAlignMiddle(6),
    styleVerticalAlignBottom(7),
    styleVerticalAlignTextBottom(8),
    styleVerticalAlignInherit(9),
    styleVerticalAlignNotSet(10),
    styleVerticalAlign_Max(2147483647),
    ;

    private final int value;
    _styleVerticalAlign(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
