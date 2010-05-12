package mol.excel  ;

import com4j.*;

public enum XlEditionFormat implements ComEnum {
    xlBIFF(2),
    xlPICT(1),
    xlRTF(4),
    xlVALU(8),
    ;

    private final int value;
    XlEditionFormat(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
