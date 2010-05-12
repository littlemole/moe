package mol.office  ;

import com4j.*;

public enum MsoThemeColorIndex implements ComEnum {
    msoThemeColorMixed(-2),
    msoNotThemeColor(0),
    msoThemeColorDark1(1),
    msoThemeColorLight1(2),
    msoThemeColorDark2(3),
    msoThemeColorLight2(4),
    msoThemeColorAccent1(5),
    msoThemeColorAccent2(6),
    msoThemeColorAccent3(7),
    msoThemeColorAccent4(8),
    msoThemeColorAccent5(9),
    msoThemeColorAccent6(10),
    msoThemeColorHyperlink(11),
    msoThemeColorFollowedHyperlink(12),
    msoThemeColorText1(13),
    msoThemeColorBackground1(14),
    msoThemeColorText2(15),
    msoThemeColorBackground2(16),
    ;

    private final int value;
    MsoThemeColorIndex(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
