package mol.mshtml  ;

import com4j.*;

public enum _styleDir implements ComEnum {
    styleDirNotSet(0),
    styleDirLeftToRight(1),
    styleDirRightToLeft(2),
    styleDirInherit(3),
    styleDir_Max(2147483647),
    ;

    private final int value;
    _styleDir(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
