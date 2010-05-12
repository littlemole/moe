package mol.word  ;

import com4j.*;

public enum WdLanguageID2000 implements ComEnum {
    wdChineseHongKong(3076),
    wdChineseMacao(5124),
    wdEnglishTrinidad(11273),
    ;

    private final int value;
    WdLanguageID2000(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
