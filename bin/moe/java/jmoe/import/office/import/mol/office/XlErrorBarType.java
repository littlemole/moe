package mol.office  ;

import com4j.*;

public enum XlErrorBarType implements ComEnum {
    xlErrorBarTypeCustom(-4114),
    xlErrorBarTypeFixedValue(1),
    xlErrorBarTypePercent(2),
    xlErrorBarTypeStDev(-4155),
    xlErrorBarTypeStError(4),
    ;

    private final int value;
    XlErrorBarType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
