package mol.excel  ;

import com4j.*;

public enum XlTextQualifier implements ComEnum {
    xlTextQualifierDoubleQuote(1),
    xlTextQualifierNone(-4142),
    xlTextQualifierSingleQuote(2),
    ;

    private final int value;
    XlTextQualifier(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
