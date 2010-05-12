package mol.excel  ;

import com4j.*;

public enum XlSizeRepresents implements ComEnum {
    xlSizeIsWidth(2),
    xlSizeIsArea(1),
    ;

    private final int value;
    XlSizeRepresents(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
