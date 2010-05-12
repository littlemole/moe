package mol.office  ;

import com4j.*;

public enum MsoThemeColorSchemeIndex implements ComEnum {
    msoThemeDark1(1),
    msoThemeLight1(2),
    msoThemeDark2(3),
    msoThemeLight2(4),
    msoThemeAccent1(5),
    msoThemeAccent2(6),
    msoThemeAccent3(7),
    msoThemeAccent4(8),
    msoThemeAccent5(9),
    msoThemeAccent6(10),
    msoThemeHyperlink(11),
    msoThemeFollowedHyperlink(12),
    ;

    private final int value;
    MsoThemeColorSchemeIndex(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
