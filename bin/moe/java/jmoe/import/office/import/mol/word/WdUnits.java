package mol.word  ;

import com4j.*;

public enum WdUnits implements ComEnum {
    wdCharacter(1),
    wdWord(2),
    wdSentence(3),
    wdParagraph(4),
    wdLine(5),
    wdStory(6),
    wdScreen(7),
    wdSection(8),
    wdColumn(9),
    wdRow(10),
    wdWindow(11),
    wdCell(12),
    wdCharacterFormatting(13),
    wdParagraphFormatting(14),
    wdTable(15),
    wdItem(16),
    ;

    private final int value;
    WdUnits(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
