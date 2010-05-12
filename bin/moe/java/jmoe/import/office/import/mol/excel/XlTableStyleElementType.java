package mol.excel  ;

import com4j.*;

public enum XlTableStyleElementType implements ComEnum {
    xlWholeTable(0),
    xlHeaderRow(1),
    xlTotalRow(2),
    xlGrandTotalRow(2),
    xlFirstColumn(3),
    xlLastColumn(4),
    xlGrandTotalColumn(4),
    xlRowStripe1(5),
    xlRowStripe2(6),
    xlColumnStripe1(7),
    xlColumnStripe2(8),
    xlFirstHeaderCell(9),
    xlLastHeaderCell(10),
    xlFirstTotalCell(11),
    xlLastTotalCell(12),
    xlSubtotalColumn1(13),
    xlSubtotalColumn2(14),
    xlSubtotalColumn3(15),
    xlSubtotalRow1(16),
    xlSubtotalRow2(17),
    xlSubtotalRow3(18),
    xlBlankRow(19),
    xlColumnSubheading1(20),
    xlColumnSubheading2(21),
    xlColumnSubheading3(22),
    xlRowSubheading1(23),
    xlRowSubheading2(24),
    xlRowSubheading3(25),
    xlPageFieldLabels(26),
    xlPageFieldValues(27),
    ;

    private final int value;
    XlTableStyleElementType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
