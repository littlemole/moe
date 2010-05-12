package mol.excel  ;

import com4j.*;

public enum XlHAlign implements ComEnum {
    xlHAlignCenter(-4108),
    xlHAlignCenterAcrossSelection(7),
    xlHAlignDistributed(-4117),
    xlHAlignFill(5),
    xlHAlignGeneral(1),
    xlHAlignJustify(-4130),
    xlHAlignLeft(-4131),
    xlHAlignRight(-4152),
    ;

    private final int value;
    XlHAlign(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
