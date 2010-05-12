package mol.office  ;

import com4j.*;

public enum MsoScriptLanguage implements ComEnum {
    msoScriptLanguageJava(1),
    msoScriptLanguageVisualBasic(2),
    msoScriptLanguageASP(3),
    msoScriptLanguageOther(4),
    ;

    private final int value;
    MsoScriptLanguage(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
