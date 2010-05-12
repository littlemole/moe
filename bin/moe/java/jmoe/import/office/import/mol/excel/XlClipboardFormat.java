package mol.excel  ;

import com4j.*;

public enum XlClipboardFormat implements ComEnum {
    xlClipboardFormatBIFF12(63),
    xlClipboardFormatBIFF(8),
    xlClipboardFormatBIFF2(18),
    xlClipboardFormatBIFF3(20),
    xlClipboardFormatBIFF4(30),
    xlClipboardFormatBinary(15),
    xlClipboardFormatBitmap(9),
    xlClipboardFormatCGM(13),
    xlClipboardFormatCSV(5),
    xlClipboardFormatDIF(4),
    xlClipboardFormatDspText(12),
    xlClipboardFormatEmbeddedObject(21),
    xlClipboardFormatEmbedSource(22),
    xlClipboardFormatLink(11),
    xlClipboardFormatLinkSource(23),
    xlClipboardFormatLinkSourceDesc(32),
    xlClipboardFormatMovie(24),
    xlClipboardFormatNative(14),
    xlClipboardFormatObjectDesc(31),
    xlClipboardFormatObjectLink(19),
    xlClipboardFormatOwnerLink(17),
    xlClipboardFormatPICT(2),
    xlClipboardFormatPrintPICT(3),
    xlClipboardFormatRTF(7),
    xlClipboardFormatScreenPICT(29),
    xlClipboardFormatStandardFont(28),
    xlClipboardFormatStandardScale(27),
    xlClipboardFormatSYLK(6),
    xlClipboardFormatTable(16),
    xlClipboardFormatText(0),
    xlClipboardFormatToolFace(25),
    xlClipboardFormatToolFacePICT(26),
    xlClipboardFormatVALU(1),
    xlClipboardFormatWK1(10),
    ;

    private final int value;
    XlClipboardFormat(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
