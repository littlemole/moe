package mol.mshtml  ;

import com4j.*;

public enum _styleDataRepeat implements ComEnum {
    styleDataRepeatNone(0),
    styleDataRepeatInner(1),
    styleDataRepeat_Max(2147483647),
    ;

    private final int value;
    _styleDataRepeat(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
