package mol.office  ;

import com4j.*;

public enum MsoFarEastLineBreakLanguageID implements ComEnum {
    MsoFarEastLineBreakLanguageJapanese(1041),
    MsoFarEastLineBreakLanguageKorean(1042),
    MsoFarEastLineBreakLanguageSimplifiedChinese(2052),
    MsoFarEastLineBreakLanguageTraditionalChinese(1028),
    ;

    private final int value;
    MsoFarEastLineBreakLanguageID(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
