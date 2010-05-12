package mol.word  ;

import com4j.*;

public enum WdUnderline implements ComEnum {
    wdUnderlineNone(0),
    wdUnderlineSingle(1),
    wdUnderlineWords(2),
    wdUnderlineDouble(3),
    wdUnderlineDotted(4),
    wdUnderlineThick(6),
    wdUnderlineDash(7),
    wdUnderlineDotDash(9),
    wdUnderlineDotDotDash(10),
    wdUnderlineWavy(11),
    wdUnderlineWavyHeavy(27),
    wdUnderlineDottedHeavy(20),
    wdUnderlineDashHeavy(23),
    wdUnderlineDotDashHeavy(25),
    wdUnderlineDotDotDashHeavy(26),
    wdUnderlineDashLong(39),
    wdUnderlineDashLongHeavy(55),
    wdUnderlineWavyDouble(43),
    ;

    private final int value;
    WdUnderline(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
