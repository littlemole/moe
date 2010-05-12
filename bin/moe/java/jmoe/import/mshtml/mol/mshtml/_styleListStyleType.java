package mol.mshtml  ;

import com4j.*;

public enum _styleListStyleType implements ComEnum {
    styleListStyleTypeNotSet(0),
    styleListStyleTypeDisc(1),
    styleListStyleTypeCircle(2),
    styleListStyleTypeSquare(3),
    styleListStyleTypeDecimal(4),
    styleListStyleTypeLowerRoman(5),
    styleListStyleTypeUpperRoman(6),
    styleListStyleTypeLowerAlpha(7),
    styleListStyleTypeUpperAlpha(8),
    styleListStyleTypeNone(9),
    styleListStyleType_Max(2147483647),
    ;

    private final int value;
    _styleListStyleType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
