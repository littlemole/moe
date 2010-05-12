package mol.word  ;

import com4j.*;

public enum WdBorderType implements ComEnum {
    wdBorderTop(-1),
    wdBorderLeft(-2),
    wdBorderBottom(-3),
    wdBorderRight(-4),
    wdBorderHorizontal(-5),
    wdBorderVertical(-6),
    wdBorderDiagonalDown(-7),
    wdBorderDiagonalUp(-8),
    ;

    private final int value;
    WdBorderType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
