package mol.mshtml  ;

import com4j.*;

public enum _styleBackgroundRepeat implements ComEnum {
    styleBackgroundRepeatRepeat(0),
    styleBackgroundRepeatRepeatX(1),
    styleBackgroundRepeatRepeatY(2),
    styleBackgroundRepeatNoRepeat(3),
    styleBackgroundRepeatNotSet(4),
    styleBackgroundRepeat_Max(2147483647),
    ;

    private final int value;
    _styleBackgroundRepeat(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
