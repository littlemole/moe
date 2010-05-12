package mol.excel  ;

import com4j.*;

public enum XlOrientation implements ComEnum {
    xlDownward(-4170),
    xlHorizontal(-4128),
    xlUpward(-4171),
    xlVertical(-4166),
    ;

    private final int value;
    XlOrientation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
