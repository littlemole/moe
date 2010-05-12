package mol.word  ;

import com4j.*;

public enum WdCharacterCase implements ComEnum {
    wdNextCase(-1),
    wdLowerCase(0),
    wdUpperCase(1),
    wdTitleWord(2),
    wdTitleSentence(4),
    wdToggleCase(5),
    wdHalfWidth(6),
    wdFullWidth(7),
    wdKatakana(8),
    wdHiragana(9),
    ;

    private final int value;
    WdCharacterCase(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
