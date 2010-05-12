package mol.office  ;

import com4j.*;

public enum MsoArrowheadWidth implements ComEnum {
    msoArrowheadWidthMixed(-2),
    msoArrowheadNarrow(1),
    msoArrowheadWidthMedium(2),
    msoArrowheadWide(3),
    ;

    private final int value;
    MsoArrowheadWidth(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
