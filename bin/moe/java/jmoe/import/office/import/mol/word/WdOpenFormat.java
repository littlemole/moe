package mol.word  ;

import com4j.*;

public enum WdOpenFormat implements ComEnum {
    wdOpenFormatAuto(0),
    wdOpenFormatDocument(1),
    wdOpenFormatTemplate(2),
    wdOpenFormatRTF(3),
    wdOpenFormatText(4),
    wdOpenFormatUnicodeText(5),
    wdOpenFormatEncodedText(5),
    wdOpenFormatAllWord(6),
    wdOpenFormatWebPages(7),
    wdOpenFormatXML(8),
    wdOpenFormatXMLDocument(9),
    wdOpenFormatXMLDocumentMacroEnabled(10),
    wdOpenFormatXMLTemplate(11),
    wdOpenFormatXMLTemplateMacroEnabled(12),
    wdOpenFormatDocument97(1),
    wdOpenFormatTemplate97(2),
    wdOpenFormatAllWordTemplates(13),
    wdOpenFormatXMLDocumentSerialized(14),
    wdOpenFormatXMLDocumentMacroEnabledSerialized(15),
    wdOpenFormatXMLTemplateSerialized(16),
    wdOpenFormatXMLTemplateMacroEnabledSerialized(17),
    ;

    private final int value;
    WdOpenFormat(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
