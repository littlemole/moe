package mol.excel  ;

import com4j.*;

public enum XlPropertyDisplayedIn implements ComEnum {
    xlDisplayPropertyInPivotTable(1),
    xlDisplayPropertyInTooltip(2),
    xlDisplayPropertyInPivotTableAndTooltip(3),
    ;

    private final int value;
    XlPropertyDisplayedIn(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
