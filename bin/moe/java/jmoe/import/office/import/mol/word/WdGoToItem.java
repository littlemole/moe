package mol.word  ;

import com4j.*;

public enum WdGoToItem implements ComEnum {
    wdGoToBookmark(-1),
    wdGoToSection(0),
    wdGoToPage(1),
    wdGoToTable(2),
    wdGoToLine(3),
    wdGoToFootnote(4),
    wdGoToEndnote(5),
    wdGoToComment(6),
    wdGoToField(7),
    wdGoToGraphic(8),
    wdGoToObject(9),
    wdGoToEquation(10),
    wdGoToHeading(11),
    wdGoToPercent(12),
    wdGoToSpellingError(13),
    wdGoToGrammaticalError(14),
    wdGoToProofreadingError(15),
    ;

    private final int value;
    WdGoToItem(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
