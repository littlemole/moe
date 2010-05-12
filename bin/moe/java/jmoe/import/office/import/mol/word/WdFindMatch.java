package mol.word  ;

import com4j.*;

public enum WdFindMatch implements ComEnum {
    wdMatchParagraphMark(65551),
    wdMatchTabCharacter(9),
    wdMatchCommentMark(5),
    wdMatchAnyCharacter(65599),
    wdMatchAnyDigit(65567),
    wdMatchAnyLetter(65583),
    wdMatchCaretCharacter(11),
    wdMatchColumnBreak(14),
    wdMatchEmDash(8212),
    wdMatchEnDash(8211),
    wdMatchEndnoteMark(65555),
    wdMatchField(19),
    wdMatchFootnoteMark(65554),
    wdMatchGraphic(1),
    wdMatchManualLineBreak(65551),
    wdMatchManualPageBreak(65564),
    wdMatchNonbreakingHyphen(30),
    wdMatchNonbreakingSpace(160),
    wdMatchOptionalHyphen(31),
    wdMatchSectionBreak(65580),
    wdMatchWhiteSpace(65655),
    ;

    private final int value;
    WdFindMatch(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
