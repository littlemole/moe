package mol.mshtml  ;

import com4j.*;

public enum _htmlCaptionVAlign implements ComEnum {
    htmlCaptionVAlignNotSet(0),
    htmlCaptionVAlignTop(1),
    htmlCaptionVAlignBottom(2),
    htmlCaptionVAlign_Max(2147483647),
    ;

    private final int value;
    _htmlCaptionVAlign(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
