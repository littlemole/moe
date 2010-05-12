package mol.word  ;

import com4j.*;

public enum WdReferenceKind implements ComEnum {
    wdContentText(-1),
    wdNumberRelativeContext(-2),
    wdNumberNoContext(-3),
    wdNumberFullContext(-4),
    wdEntireCaption(2),
    wdOnlyLabelAndNumber(3),
    wdOnlyCaptionText(4),
    wdFootnoteNumber(5),
    wdEndnoteNumber(6),
    wdPageNumber(7),
    wdPosition(15),
    wdFootnoteNumberFormatted(16),
    wdEndnoteNumberFormatted(17),
    ;

    private final int value;
    WdReferenceKind(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
