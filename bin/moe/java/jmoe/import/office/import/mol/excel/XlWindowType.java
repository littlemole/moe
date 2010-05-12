package mol.excel  ;

import com4j.*;

public enum XlWindowType implements ComEnum {
    xlChartAsWindow(5),
    xlChartInPlace(4),
    xlClipboard(3),
    xlInfo(-4129),
    xlWorkbook(1),
    ;

    private final int value;
    XlWindowType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
