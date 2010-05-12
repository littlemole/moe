package mol.word  ;

import com4j.*;

public enum WdIMEMode implements ComEnum {
    wdIMEModeNoControl(0),
    wdIMEModeOn(1),
    wdIMEModeOff(2),
    wdIMEModeHiragana(4),
    wdIMEModeKatakana(5),
    wdIMEModeKatakanaHalf(6),
    wdIMEModeAlphaFull(7),
    wdIMEModeAlpha(8),
    wdIMEModeHangulFull(9),
    wdIMEModeHangul(10),
    ;

    private final int value;
    WdIMEMode(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
