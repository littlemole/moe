package mol.word  ;

import com4j.*;

public enum WdWordDialogTabHID implements ComEnum {
    wdDialogFilePageSetupTabPaperSize(150001),
    wdDialogFilePageSetupTabPaperSource(150002),
    ;

    private final int value;
    WdWordDialogTabHID(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
