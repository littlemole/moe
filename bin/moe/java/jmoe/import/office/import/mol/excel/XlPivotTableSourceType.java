package mol.excel  ;

import com4j.*;

public enum XlPivotTableSourceType implements ComEnum {
    xlScenario(4),
    xlConsolidation(3),
    xlDatabase(1),
    xlExternal(2),
    xlPivotTable(-4148),
    ;

    private final int value;
    XlPivotTableSourceType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
