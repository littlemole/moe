package mol.excel  ;

import com4j.*;

public enum XlTextParsingType implements ComEnum {
    xlDelimited(1),
    xlFixedWidth(2),
    ;

    private final int value;
    XlTextParsingType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
