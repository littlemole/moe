package mol.mshtml  ;

import com4j.*;

public enum _styleTextAlignLast implements ComEnum {
    styleTextAlignLastNotSet(0),
    styleTextAlignLastLeft(1),
    styleTextAlignLastCenter(2),
    styleTextAlignLastRight(3),
    styleTextAlignLastJustify(4),
    styleTextAlignLastAuto(5),
    styleTextAlignLast_Max(2147483647),
    ;

    private final int value;
    _styleTextAlignLast(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
