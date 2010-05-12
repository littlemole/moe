package mol.mshtml  ;

import com4j.*;

public enum _styleWhiteSpace implements ComEnum {
    styleWhiteSpaceNotSet(0),
    styleWhiteSpaceNormal(1),
    styleWhiteSpacePre(2),
    styleWhiteSpaceNowrap(3),
    styleWhiteSpace_Max(2147483647),
    ;

    private final int value;
    _styleWhiteSpace(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
