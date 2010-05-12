package mol.office  ;

import com4j.*;

public enum MsoBackgroundStyleIndex implements ComEnum {
    msoBackgroundStyleMixed(-2),
    msoBackgroundStyleNotAPreset(0),
    msoBackgroundStylePreset1(1),
    msoBackgroundStylePreset2(2),
    msoBackgroundStylePreset3(3),
    msoBackgroundStylePreset4(4),
    msoBackgroundStylePreset5(5),
    msoBackgroundStylePreset6(6),
    msoBackgroundStylePreset7(7),
    msoBackgroundStylePreset8(8),
    msoBackgroundStylePreset9(9),
    msoBackgroundStylePreset10(10),
    msoBackgroundStylePreset11(11),
    msoBackgroundStylePreset12(12),
    ;

    private final int value;
    MsoBackgroundStyleIndex(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
