package mol.word  ;

import com4j.*;

public enum WdViewType implements ComEnum {
    wdNormalView(1),
    wdOutlineView(2),
    wdPrintView(3),
    wdPrintPreview(4),
    wdMasterView(5),
    wdWebView(6),
    wdReadingView(7),
    ;

    private final int value;
    WdViewType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
