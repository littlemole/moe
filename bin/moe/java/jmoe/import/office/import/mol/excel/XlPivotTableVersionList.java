package mol.excel  ;

import com4j.*;

public enum XlPivotTableVersionList implements ComEnum {
    xlPivotTableVersion2000(0),
    xlPivotTableVersion10(1),
    xlPivotTableVersion11(2),
    xlPivotTableVersion12(3),
    xlPivotTableVersionCurrent(-1),
    ;

    private final int value;
    XlPivotTableVersionList(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
