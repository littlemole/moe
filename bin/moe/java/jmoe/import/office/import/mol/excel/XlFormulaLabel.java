package mol.excel  ;

import com4j.*;

public enum XlFormulaLabel implements ComEnum {
    xlNoLabels(-4142),
    xlRowLabels(1),
    xlColumnLabels(2),
    xlMixedLabels(3),
    ;

    private final int value;
    XlFormulaLabel(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
