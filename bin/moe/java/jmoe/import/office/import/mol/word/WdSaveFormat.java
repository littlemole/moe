package mol.word  ;

import com4j.*;

public enum WdSaveFormat implements ComEnum {
    wdFormatDocument(0),
    wdFormatDocument97(0),
    wdFormatTemplate(1),
    wdFormatTemplate97(1),
    wdFormatText(2),
    wdFormatTextLineBreaks(3),
    wdFormatDOSText(4),
    wdFormatDOSTextLineBreaks(5),
    wdFormatRTF(6),
    wdFormatUnicodeText(7),
    wdFormatEncodedText(7),
    wdFormatHTML(8),
    wdFormatWebArchive(9),
    wdFormatFilteredHTML(10),
    wdFormatXML(11),
    wdFormatXMLDocument(12),
    wdFormatXMLDocumentMacroEnabled(13),
    wdFormatXMLTemplate(14),
    wdFormatXMLTemplateMacroEnabled(15),
    wdFormatDocumentDefault(16),
    wdFormatPDF(17),
    wdFormatXPS(18),
    wdFormatFlatXML(19),
    wdFormatFlatXMLMacroEnabled(20),
    wdFormatFlatXMLTemplate(21),
    wdFormatFlatXMLTemplateMacroEnabled(22),
    ;

    private final int value;
    WdSaveFormat(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
