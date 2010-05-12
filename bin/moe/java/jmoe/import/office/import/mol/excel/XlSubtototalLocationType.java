package mol.excel  ;

import com4j.*;

public enum XlSubtototalLocationType implements ComEnum {
    xlAtTop(1),
    xlAtBottom(2),
    ;

    private final int value;
    XlSubtototalLocationType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
