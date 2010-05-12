package mol.word  ;

import com4j.*;

public enum WdShapePositionRelative implements ComEnum {
    wdShapePositionRelativeNone(-999999),
    ;

    private final int value;
    WdShapePositionRelative(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
