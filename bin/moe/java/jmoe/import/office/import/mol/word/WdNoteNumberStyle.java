package mol.word  ;

import com4j.*;

public enum WdNoteNumberStyle implements ComEnum {
    wdNoteNumberStyleArabic(0),
    wdNoteNumberStyleUppercaseRoman(1),
    wdNoteNumberStyleLowercaseRoman(2),
    wdNoteNumberStyleUppercaseLetter(3),
    wdNoteNumberStyleLowercaseLetter(4),
    wdNoteNumberStyleSymbol(9),
    wdNoteNumberStyleArabicFullWidth(14),
    wdNoteNumberStyleKanji(10),
    wdNoteNumberStyleKanjiDigit(11),
    wdNoteNumberStyleKanjiTraditional(16),
    wdNoteNumberStyleNumberInCircle(18),
    wdNoteNumberStyleHanjaRead(41),
    wdNoteNumberStyleHanjaReadDigit(42),
    wdNoteNumberStyleTradChinNum1(33),
    wdNoteNumberStyleTradChinNum2(34),
    wdNoteNumberStyleSimpChinNum1(37),
    wdNoteNumberStyleSimpChinNum2(38),
    wdNoteNumberStyleHebrewLetter1(45),
    wdNoteNumberStyleArabicLetter1(46),
    wdNoteNumberStyleHebrewLetter2(47),
    wdNoteNumberStyleArabicLetter2(48),
    wdNoteNumberStyleHindiLetter1(49),
    wdNoteNumberStyleHindiLetter2(50),
    wdNoteNumberStyleHindiArabic(51),
    wdNoteNumberStyleHindiCardinalText(52),
    wdNoteNumberStyleThaiLetter(53),
    wdNoteNumberStyleThaiArabic(54),
    wdNoteNumberStyleThaiCardinalText(55),
    wdNoteNumberStyleVietCardinalText(56),
    ;

    private final int value;
    WdNoteNumberStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
