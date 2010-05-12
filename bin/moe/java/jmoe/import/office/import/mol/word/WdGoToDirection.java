package mol.word  ;

import com4j.*;

public enum WdGoToDirection implements ComEnum {
    wdGoToFirst(1),
    wdGoToLast(-1),
    wdGoToNext(2),
    wdGoToRelative(2),
    wdGoToPrevious(3),
    wdGoToAbsolute(1),
    ;

    private final int value;
    WdGoToDirection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
