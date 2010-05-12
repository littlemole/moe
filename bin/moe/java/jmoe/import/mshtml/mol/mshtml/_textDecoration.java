package mol.mshtml  ;

import com4j.*;

public enum _textDecoration implements ComEnum {
    textDecorationNone(0),
    textDecorationUnderline(1),
    textDecorationOverline(2),
    textDecorationLineThrough(3),
    textDecorationBlink(4),
    textDecoration_Max(2147483647),
    ;

    private final int value;
    _textDecoration(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
