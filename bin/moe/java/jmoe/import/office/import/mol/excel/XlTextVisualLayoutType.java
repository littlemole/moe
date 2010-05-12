package mol.excel  ;

import com4j.*;

public enum XlTextVisualLayoutType implements ComEnum {
    xlTextVisualLTR(1),
    xlTextVisualRTL(2),
    ;

    private final int value;
    XlTextVisualLayoutType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
