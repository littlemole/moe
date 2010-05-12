package mol.excel  ;

import com4j.*;

public enum XlXLMMacroType implements ComEnum {
    xlCommand(2),
    xlFunction(1),
    xlNotXLM(3),
    ;

    private final int value;
    XlXLMMacroType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
