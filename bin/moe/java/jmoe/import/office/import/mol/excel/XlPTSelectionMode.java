package mol.excel  ;

import com4j.*;

public enum XlPTSelectionMode implements ComEnum {
    xlLabelOnly(1),
    xlDataAndLabel(0),
    xlDataOnly(2),
    xlOrigin(3),
    xlButton(15),
    xlBlanks(4),
    xlFirstRow(256),
    ;

    private final int value;
    XlPTSelectionMode(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
