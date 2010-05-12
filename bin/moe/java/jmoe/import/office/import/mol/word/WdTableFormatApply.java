package mol.word  ;

import com4j.*;

public enum WdTableFormatApply implements ComEnum {
    wdTableFormatApplyBorders(1),
    wdTableFormatApplyShading(2),
    wdTableFormatApplyFont(4),
    wdTableFormatApplyColor(8),
    wdTableFormatApplyAutoFit(16),
    wdTableFormatApplyHeadingRows(32),
    wdTableFormatApplyLastRow(64),
    wdTableFormatApplyFirstColumn(128),
    wdTableFormatApplyLastColumn(256),
    ;

    private final int value;
    WdTableFormatApply(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
