package mol.office  ;

import com4j.*;

public enum MsoClipboardFormat implements ComEnum {
    msoClipboardFormatMixed(-2),
    msoClipboardFormatNative(1),
    msoClipboardFormatHTML(2),
    msoClipboardFormatRTF(3),
    msoClipboardFormatPlainText(4),
    ;

    private final int value;
    MsoClipboardFormat(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
