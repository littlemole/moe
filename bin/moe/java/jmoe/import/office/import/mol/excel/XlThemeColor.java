package mol.excel  ;

import com4j.*;

public enum XlThemeColor implements ComEnum {
    xlThemeColorDark1(1),
    xlThemeColorLight1(2),
    xlThemeColorDark2(3),
    xlThemeColorLight2(4),
    xlThemeColorAccent1(5),
    xlThemeColorAccent2(6),
    xlThemeColorAccent3(7),
    xlThemeColorAccent4(8),
    xlThemeColorAccent5(9),
    xlThemeColorAccent6(10),
    xlThemeColorHyperlink(11),
    xlThemeColorFollowedHyperlink(12),
    ;

    private final int value;
    XlThemeColor(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
