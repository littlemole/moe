package mol.mshtml  ;

import com4j.*;

public enum _styleBackgroundAttachment implements ComEnum {
    styleBackgroundAttachmentFixed(0),
    styleBackgroundAttachmentScroll(1),
    styleBackgroundAttachmentNotSet(2),
    styleBackgroundAttachment_Max(2147483647),
    ;

    private final int value;
    _styleBackgroundAttachment(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
