package mol.mshtml  ;

import com4j.*;

public enum _styleTextDecoration implements ComEnum {
    styleTextDecorationNone(0),
    styleTextDecorationUnderline(1),
    styleTextDecorationOverline(2),
    styleTextDecorationLineThrough(3),
    styleTextDecorationBlink(4),
    styleTextDecoration_Max(2147483647),
    ;

    private final int value;
    _styleTextDecoration(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
