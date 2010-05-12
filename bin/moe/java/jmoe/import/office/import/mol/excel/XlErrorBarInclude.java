package mol.excel  ;

import com4j.*;

public enum XlErrorBarInclude implements ComEnum {
    xlErrorBarIncludeBoth(1),
    xlErrorBarIncludeMinusValues(3),
    xlErrorBarIncludeNone(-4142),
    xlErrorBarIncludePlusValues(2),
    ;

    private final int value;
    XlErrorBarInclude(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
