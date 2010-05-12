package mol.word  ;

import com4j.*;

public enum WdBuildingBlockTypes implements ComEnum {
    wdTypeQuickParts(1),
    wdTypeCoverPage(2),
    wdTypeEquations(3),
    wdTypeFooters(4),
    wdTypeHeaders(5),
    wdTypePageNumber(6),
    wdTypeTables(7),
    wdTypeWatermarks(8),
    wdTypeAutoText(9),
    wdTypeTextBox(10),
    wdTypePageNumberTop(11),
    wdTypePageNumberBottom(12),
    wdTypePageNumberPage(13),
    wdTypeTableOfContents(14),
    wdTypeCustomQuickParts(15),
    wdTypeCustomCoverPage(16),
    wdTypeCustomEquations(17),
    wdTypeCustomFooters(18),
    wdTypeCustomHeaders(19),
    wdTypeCustomPageNumber(20),
    wdTypeCustomTables(21),
    wdTypeCustomWatermarks(22),
    wdTypeCustomAutoText(23),
    wdTypeCustomTextBox(24),
    wdTypeCustomPageNumberTop(25),
    wdTypeCustomPageNumberBottom(26),
    wdTypeCustomPageNumberPage(27),
    wdTypeCustomTableOfContents(28),
    wdTypeCustom1(29),
    wdTypeCustom2(30),
    wdTypeCustom3(31),
    wdTypeCustom4(32),
    wdTypeCustom5(33),
    wdTypeBibliography(34),
    wdTypeCustomBibliography(35),
    ;

    private final int value;
    WdBuildingBlockTypes(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
