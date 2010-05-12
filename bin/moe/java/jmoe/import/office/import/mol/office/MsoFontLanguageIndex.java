package mol.office  ;

import com4j.*;

public enum MsoFontLanguageIndex implements ComEnum {
    msoThemeLatin(1),
    msoThemeComplexScript(2),
    msoThemeEastAsian(3),
    ;

    private final int value;
    MsoFontLanguageIndex(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
