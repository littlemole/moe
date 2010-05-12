package mol.office  ;

import com4j.*;

public enum MsoBevelType implements ComEnum {
    msoBevelTypeMixed(-2),
    msoBevelNone(1),
    msoBevelRelaxedInset(2),
    msoBevelCircle(3),
    msoBevelSlope(4),
    msoBevelCross(5),
    msoBevelAngle(6),
    msoBevelSoftRound(7),
    msoBevelConvex(8),
    msoBevelCoolSlant(9),
    msoBevelDivot(10),
    msoBevelRiblet(11),
    msoBevelHardEdge(12),
    msoBevelArtDeco(13),
    ;

    private final int value;
    MsoBevelType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
