package mol.excel  ;

import com4j.*;

public enum XlPlacement implements ComEnum {
    xlFreeFloating(3),
    xlMove(2),
    xlMoveAndSize(1),
    ;

    private final int value;
    XlPlacement(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
