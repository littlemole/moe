package mol.excel  ;

import com4j.*;

public enum XlBackground implements ComEnum {
    xlBackgroundAutomatic(-4105),
    xlBackgroundOpaque(3),
    xlBackgroundTransparent(2),
    ;

    private final int value;
    XlBackground(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
