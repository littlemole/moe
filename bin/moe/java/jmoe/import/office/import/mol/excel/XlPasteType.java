package mol.excel  ;

import com4j.*;

public enum XlPasteType implements ComEnum {
    xlPasteAll(-4104),
    xlPasteAllUsingSourceTheme(13),
    xlPasteAllExceptBorders(7),
    xlPasteFormats(-4122),
    xlPasteFormulas(-4123),
    xlPasteComments(-4144),
    xlPasteValues(-4163),
    xlPasteColumnWidths(8),
    xlPasteValidation(6),
    xlPasteFormulasAndNumberFormats(11),
    xlPasteValuesAndNumberFormats(12),
    ;

    private final int value;
    XlPasteType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
