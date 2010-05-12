package mol.excel  ;

import com4j.*;

public enum XlRunAutoMacro implements ComEnum {
    xlAutoActivate(3),
    xlAutoClose(2),
    xlAutoDeactivate(4),
    xlAutoOpen(1),
    ;

    private final int value;
    XlRunAutoMacro(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
