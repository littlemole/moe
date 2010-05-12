package mol.word  ;

import com4j.*;

public enum WdExportItem implements ComEnum {
    wdExportDocumentContent(0),
    wdExportDocumentWithMarkup(7),
    ;

    private final int value;
    WdExportItem(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
