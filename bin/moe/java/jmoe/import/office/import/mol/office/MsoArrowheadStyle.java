package mol.office  ;

import com4j.*;

public enum MsoArrowheadStyle implements ComEnum {
    msoArrowheadStyleMixed(-2),
    msoArrowheadNone(1),
    msoArrowheadTriangle(2),
    msoArrowheadOpen(3),
    msoArrowheadStealth(4),
    msoArrowheadDiamond(5),
    msoArrowheadOval(6),
    ;

    private final int value;
    MsoArrowheadStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
