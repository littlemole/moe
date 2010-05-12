package mol.mshtml  ;

import com4j.*;

public enum _htmlCaptionAlign implements ComEnum {
    htmlCaptionAlignNotSet(0),
    htmlCaptionAlignLeft(1),
    htmlCaptionAlignCenter(2),
    htmlCaptionAlignRight(3),
    htmlCaptionAlignJustify(4),
    htmlCaptionAlignTop(5),
    htmlCaptionAlignBottom(6),
    htmlCaptionAlign_Max(2147483647),
    ;

    private final int value;
    _htmlCaptionAlign(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
