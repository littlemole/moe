package mol.mshtml  ;

import com4j.*;

public enum _styleFontSize implements ComEnum {
    styleFontSizeXXSmall(0),
    styleFontSizeXSmall(1),
    styleFontSizeSmall(2),
    styleFontSizeMedium(3),
    styleFontSizeLarge(4),
    styleFontSizeXLarge(5),
    styleFontSizeXXLarge(6),
    styleFontSizeSmaller(7),
    styleFontSizeLarger(8),
    styleFontSize_Max(2147483647),
    ;

    private final int value;
    _styleFontSize(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
