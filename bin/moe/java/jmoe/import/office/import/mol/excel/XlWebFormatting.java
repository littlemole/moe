package mol.excel  ;

import com4j.*;

public enum XlWebFormatting implements ComEnum {
    xlWebFormattingAll(1),
    xlWebFormattingRTF(2),
    xlWebFormattingNone(3),
    ;

    private final int value;
    XlWebFormatting(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
