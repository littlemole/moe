package mol.word  ;

import com4j.*;

public enum WdThemeColorIndex implements ComEnum {
    wdNotThemeColor(-1),
    wdThemeColorMainDark1(0),
    wdThemeColorMainLight1(1),
    wdThemeColorMainDark2(2),
    wdThemeColorMainLight2(3),
    wdThemeColorAccent1(4),
    wdThemeColorAccent2(5),
    wdThemeColorAccent3(6),
    wdThemeColorAccent4(7),
    wdThemeColorAccent5(8),
    wdThemeColorAccent6(9),
    wdThemeColorHyperlink(10),
    wdThemeColorHyperlinkFollowed(11),
    wdThemeColorBackground1(12),
    wdThemeColorText1(13),
    wdThemeColorBackground2(14),
    wdThemeColorText2(15),
    ;

    private final int value;
    WdThemeColorIndex(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
