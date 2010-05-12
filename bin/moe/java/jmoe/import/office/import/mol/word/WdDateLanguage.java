package mol.word  ;

import com4j.*;

public enum WdDateLanguage implements ComEnum {
    wdDateLanguageBidi(10),
    wdDateLanguageLatin(1033),
    ;

    private final int value;
    WdDateLanguage(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
