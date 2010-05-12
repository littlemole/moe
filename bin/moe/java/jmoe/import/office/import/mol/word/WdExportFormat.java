package mol.word  ;

import com4j.*;

public enum WdExportFormat implements ComEnum {
    wdExportFormatPDF(17),
    wdExportFormatXPS(18),
    ;

    private final int value;
    WdExportFormat(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
