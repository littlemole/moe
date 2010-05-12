package mol.word  ;

import com4j.*;

public enum WdCaptionNumberStyle implements ComEnum {
    wdCaptionNumberStyleArabic(0),
    wdCaptionNumberStyleUppercaseRoman(1),
    wdCaptionNumberStyleLowercaseRoman(2),
    wdCaptionNumberStyleUppercaseLetter(3),
    wdCaptionNumberStyleLowercaseLetter(4),
    wdCaptionNumberStyleArabicFullWidth(14),
    wdCaptionNumberStyleKanji(10),
    wdCaptionNumberStyleKanjiDigit(11),
    wdCaptionNumberStyleKanjiTraditional(16),
    wdCaptionNumberStyleNumberInCircle(18),
    wdCaptionNumberStyleGanada(24),
    wdCaptionNumberStyleChosung(25),
    wdCaptionNumberStyleZodiac1(30),
    wdCaptionNumberStyleZodiac2(31),
    wdCaptionNumberStyleHanjaRead(41),
    wdCaptionNumberStyleHanjaReadDigit(42),
    wdCaptionNumberStyleTradChinNum2(34),
    wdCaptionNumberStyleTradChinNum3(35),
    wdCaptionNumberStyleSimpChinNum2(38),
    wdCaptionNumberStyleSimpChinNum3(39),
    wdCaptionNumberStyleHebrewLetter1(45),
    wdCaptionNumberStyleArabicLetter1(46),
    wdCaptionNumberStyleHebrewLetter2(47),
    wdCaptionNumberStyleArabicLetter2(48),
    wdCaptionNumberStyleHindiLetter1(49),
    wdCaptionNumberStyleHindiLetter2(50),
    wdCaptionNumberStyleHindiArabic(51),
    wdCaptionNumberStyleHindiCardinalText(52),
    wdCaptionNumberStyleThaiLetter(53),
    wdCaptionNumberStyleThaiArabic(54),
    wdCaptionNumberStyleThaiCardinalText(55),
    wdCaptionNumberStyleVietCardinalText(56),
    ;

    private final int value;
    WdCaptionNumberStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
