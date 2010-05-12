package mol.mshtml  ;

import com4j.*;

public enum _htmlDir implements ComEnum {
    htmlDirNotSet(0),
    htmlDirLeftToRight(1),
    htmlDirRightToLeft(2),
    htmlDir_Max(2147483647),
    ;

    private final int value;
    _htmlDir(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
