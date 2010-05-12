package mol.excel  ;

import com4j.*;

public enum XlLegendPosition implements ComEnum {
    xlLegendPositionBottom(-4107),
    xlLegendPositionCorner(2),
    xlLegendPositionLeft(-4131),
    xlLegendPositionRight(-4152),
    xlLegendPositionTop(-4160),
    xlLegendPositionCustom(-4161),
    ;

    private final int value;
    XlLegendPosition(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
