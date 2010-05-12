package mol.office  ;

import com4j.*;

public enum MsoCharacterSet implements ComEnum {
    msoCharacterSetArabic(1),
    msoCharacterSetCyrillic(2),
    msoCharacterSetEnglishWesternEuropeanOtherLatinScript(3),
    msoCharacterSetGreek(4),
    msoCharacterSetHebrew(5),
    msoCharacterSetJapanese(6),
    msoCharacterSetKorean(7),
    msoCharacterSetMultilingualUnicode(8),
    msoCharacterSetSimplifiedChinese(9),
    msoCharacterSetThai(10),
    msoCharacterSetTraditionalChinese(11),
    msoCharacterSetVietnamese(12),
    ;

    private final int value;
    MsoCharacterSet(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
