package mol.mshtml  ;

import com4j.*;

public enum _HTMLCaptionFlag implements ComEnum {
    HTMLCaptionFlagNo(0),
    HTMLCaptionFlagYes(12582912),
    HTMLCaptionFlag_Max(2147483647),
    ;

    private final int value;
    _HTMLCaptionFlag(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
