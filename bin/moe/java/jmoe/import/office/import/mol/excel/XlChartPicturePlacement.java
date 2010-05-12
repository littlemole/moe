package mol.excel  ;

import com4j.*;

public enum XlChartPicturePlacement implements ComEnum {
    xlSides(1),
    xlEnd(2),
    xlEndSides(3),
    xlFront(4),
    xlFrontSides(5),
    xlFrontEnd(6),
    xlAllFaces(7),
    ;

    private final int value;
    XlChartPicturePlacement(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
