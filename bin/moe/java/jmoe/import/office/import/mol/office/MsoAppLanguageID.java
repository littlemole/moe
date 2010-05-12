package mol.office  ;

import com4j.*;

public enum MsoAppLanguageID implements ComEnum {
    msoLanguageIDInstall(1),
    msoLanguageIDUI(2),
    msoLanguageIDHelp(3),
    msoLanguageIDExeMode(4),
    msoLanguageIDUIPrevious(5),
    ;

    private final int value;
    MsoAppLanguageID(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
