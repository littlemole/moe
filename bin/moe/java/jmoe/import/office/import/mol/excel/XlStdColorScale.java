package mol.excel  ;

import com4j.*;

public enum XlStdColorScale implements ComEnum {
    xlColorScaleRYG(1),
    xlColorScaleGYR(2),
    xlColorScaleBlackWhite(3),
    xlColorScaleWhiteBlack(4),
    ;

    private final int value;
    XlStdColorScale(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
