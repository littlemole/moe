package mol.excel  ;

import com4j.*;

public enum XlCopyPictureFormat implements ComEnum {
    xlBitmap(2),
    xlPicture(-4147),
    ;

    private final int value;
    XlCopyPictureFormat(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
