package mol.office  ;

import com4j.*;

public enum MsoArrowheadLength implements ComEnum {
    msoArrowheadLengthMixed(-2),
    msoArrowheadShort(1),
    msoArrowheadLengthMedium(2),
    msoArrowheadLong(3),
    ;

    private final int value;
    MsoArrowheadLength(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
