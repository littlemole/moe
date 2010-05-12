package mol.office  ;

import com4j.*;

public enum MsoTextUnderlineType implements ComEnum {
    msoUnderlineMixed(-2),
    msoNoUnderline(0),
    msoUnderlineWords(1),
    msoUnderlineSingleLine(2),
    msoUnderlineDoubleLine(3),
    msoUnderlineHeavyLine(4),
    msoUnderlineDottedLine(5),
    msoUnderlineDottedHeavyLine(6),
    msoUnderlineDashLine(7),
    msoUnderlineDashHeavyLine(8),
    msoUnderlineDashLongLine(9),
    msoUnderlineDashLongHeavyLine(10),
    msoUnderlineDotDashLine(11),
    msoUnderlineDotDashHeavyLine(12),
    msoUnderlineDotDotDashLine(13),
    msoUnderlineDotDotDashHeavyLine(14),
    msoUnderlineWavyLine(15),
    msoUnderlineWavyHeavyLine(16),
    msoUnderlineWavyDoubleLine(17),
    ;

    private final int value;
    MsoTextUnderlineType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
