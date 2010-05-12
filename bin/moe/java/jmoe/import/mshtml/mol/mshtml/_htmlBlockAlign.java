package mol.mshtml  ;

import com4j.*;

public enum _htmlBlockAlign implements ComEnum {
    htmlBlockAlignNotSet(0),
    htmlBlockAlignLeft(1),
    htmlBlockAlignCenter(2),
    htmlBlockAlignRight(3),
    htmlBlockAlignJustify(4),
    htmlBlockAlign_Max(2147483647),
    ;

    private final int value;
    _htmlBlockAlign(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
