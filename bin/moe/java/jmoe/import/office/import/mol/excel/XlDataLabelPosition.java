package mol.excel  ;

import com4j.*;

public enum XlDataLabelPosition implements ComEnum {
    xlLabelPositionCenter(-4108),
    xlLabelPositionAbove(0),
    xlLabelPositionBelow(1),
    xlLabelPositionLeft(-4131),
    xlLabelPositionRight(-4152),
    xlLabelPositionOutsideEnd(2),
    xlLabelPositionInsideEnd(3),
    xlLabelPositionInsideBase(4),
    xlLabelPositionBestFit(5),
    xlLabelPositionMixed(6),
    xlLabelPositionCustom(7),
    ;

    private final int value;
    XlDataLabelPosition(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
