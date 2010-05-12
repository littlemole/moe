package mol.office  ;

import com4j.*;

public enum MsoLineDashStyle implements ComEnum {
    msoLineDashStyleMixed(-2),
    msoLineSolid(1),
    msoLineSquareDot(2),
    msoLineRoundDot(3),
    msoLineDash(4),
    msoLineDashDot(5),
    msoLineDashDotDot(6),
    msoLineLongDash(7),
    msoLineLongDashDot(8),
    msoLineLongDashDotDot(9),
    msoLineSysDash(10),
    msoLineSysDot(11),
    msoLineSysDashDot(12),
    ;

    private final int value;
    MsoLineDashStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
