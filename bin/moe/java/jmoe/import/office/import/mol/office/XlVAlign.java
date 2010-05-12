package mol.office  ;

import com4j.*;

public enum XlVAlign implements ComEnum {
    xlVAlignBottom(-4107),
    xlVAlignCenter(-4108),
    xlVAlignDistributed(-4117),
    xlVAlignJustify(-4130),
    xlVAlignTop(-4160),
    ;

    private final int value;
    XlVAlign(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
