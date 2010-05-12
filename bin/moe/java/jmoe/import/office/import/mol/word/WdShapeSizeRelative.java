package mol.word  ;

import com4j.*;

public enum WdShapeSizeRelative implements ComEnum {
    wdShapeSizeRelativeNone(-999999),
    ;

    private final int value;
    WdShapeSizeRelative(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
