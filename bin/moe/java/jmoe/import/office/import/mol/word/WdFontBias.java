package mol.word  ;

import com4j.*;

public enum WdFontBias implements ComEnum {
    wdFontBiasDontCare(255),
    wdFontBiasDefault(0),
    wdFontBiasFareast(1),
    ;

    private final int value;
    WdFontBias(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
