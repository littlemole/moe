package mol.word  ;

import com4j.*;

public enum WdRecoveryType implements ComEnum {
    wdPasteDefault(0),
    wdSingleCellText(5),
    wdSingleCellTable(6),
    wdListContinueNumbering(7),
    wdListRestartNumbering(8),
    wdTableInsertAsRows(11),
    wdTableAppendTable(10),
    wdTableOriginalFormatting(12),
    wdChartPicture(13),
    wdChart(14),
    wdChartLinked(15),
    wdFormatOriginalFormatting(16),
    wdFormatSurroundingFormattingWithEmphasis(20),
    wdFormatPlainText(22),
    wdTableOverwriteCells(23),
    wdListCombineWithExistingList(24),
    wdListDontMerge(25),
    wdUseDestinationStylesRecovery(19),
    ;

    private final int value;
    WdRecoveryType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
