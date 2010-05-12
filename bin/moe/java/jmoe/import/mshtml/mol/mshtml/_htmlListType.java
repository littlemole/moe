package mol.mshtml  ;

import com4j.*;

public enum _htmlListType implements ComEnum {
    htmlListTypeNotSet(0),
    htmlListTypeLargeAlpha(1),
    htmlListTypeSmallAlpha(2),
    htmlListTypeLargeRoman(3),
    htmlListTypeSmallRoman(4),
    htmlListTypeNumbers(5),
    htmlListTypeDisc(6),
    htmlListTypeCircle(7),
    htmlListTypeSquare(8),
    htmlListType_Max(2147483647),
    ;

    private final int value;
    _htmlListType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
