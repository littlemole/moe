package mol.excel  ;

import com4j.*;

public enum XlChartLocation implements ComEnum {
    xlLocationAsNewSheet(1),
    xlLocationAsObject(2),
    xlLocationAutomatic(3),
    ;

    private final int value;
    XlChartLocation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
