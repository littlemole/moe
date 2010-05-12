package mol.word  ;

import com4j.*;

public enum WdFarEastLineBreakLanguageID implements ComEnum {
    wdLineBreakJapanese(1041),
    wdLineBreakKorean(1042),
    wdLineBreakSimplifiedChinese(2052),
    wdLineBreakTraditionalChinese(1028),
    ;

    private final int value;
    WdFarEastLineBreakLanguageID(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
