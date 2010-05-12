package mol.office  ;

import com4j.*;

public enum MsoLanguageIDHidden implements ComEnum {
    msoLanguageIDChineseHongKong(3076),
    msoLanguageIDChineseMacao(5124),
    msoLanguageIDEnglishTrinidad(11273),
    ;

    private final int value;
    MsoLanguageIDHidden(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
