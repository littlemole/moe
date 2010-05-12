package mol.word  ;

import com4j.*;

public enum WdPageNumberStyle implements ComEnum {
    wdPageNumberStyleArabic(0),
    wdPageNumberStyleUppercaseRoman(1),
    wdPageNumberStyleLowercaseRoman(2),
    wdPageNumberStyleUppercaseLetter(3),
    wdPageNumberStyleLowercaseLetter(4),
    wdPageNumberStyleArabicFullWidth(14),
    wdPageNumberStyleKanji(10),
    wdPageNumberStyleKanjiDigit(11),
    wdPageNumberStyleKanjiTraditional(16),
    wdPageNumberStyleNumberInCircle(18),
    wdPageNumberStyleHanjaRead(41),
    wdPageNumberStyleHanjaReadDigit(42),
    wdPageNumberStyleTradChinNum1(33),
    wdPageNumberStyleTradChinNum2(34),
    wdPageNumberStyleSimpChinNum1(37),
    wdPageNumberStyleSimpChinNum2(38),
    wdPageNumberStyleHebrewLetter1(45),
    wdPageNumberStyleArabicLetter1(46),
    wdPageNumberStyleHebrewLetter2(47),
    wdPageNumberStyleArabicLetter2(48),
    wdPageNumberStyleHindiLetter1(49),
    wdPageNumberStyleHindiLetter2(50),
    wdPageNumberStyleHindiArabic(51),
    wdPageNumberStyleHindiCardinalText(52),
    wdPageNumberStyleThaiLetter(53),
    wdPageNumberStyleThaiArabic(54),
    wdPageNumberStyleThaiCardinalText(55),
    wdPageNumberStyleVietCardinalText(56),
    wdPageNumberStyleNumberInDash(57),
    ;

    private final int value;
    WdPageNumberStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
