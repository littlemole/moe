package mol.word  ;

import com4j.*;

public enum WdPasteDataType implements ComEnum {
    wdPasteOLEObject(0),
    wdPasteRTF(1),
    wdPasteText(2),
    wdPasteMetafilePicture(3),
    wdPasteBitmap(4),
    wdPasteDeviceIndependentBitmap(5),
    wdPasteHyperlink(7),
    wdPasteShape(8),
    wdPasteEnhancedMetafile(9),
    wdPasteHTML(10),
    ;

    private final int value;
    WdPasteDataType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
