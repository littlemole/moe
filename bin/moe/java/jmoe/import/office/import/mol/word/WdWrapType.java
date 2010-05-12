package mol.word  ;

import com4j.*;

public enum WdWrapType implements ComEnum {
    wdWrapSquare(0),
    wdWrapTight(1),
    wdWrapThrough(2),
    wdWrapNone(3),
    wdWrapTopBottom(4),
    wdWrapBehind(5),
    wdWrapFront(3),
    wdWrapInline(7),
    ;

    private final int value;
    WdWrapType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
