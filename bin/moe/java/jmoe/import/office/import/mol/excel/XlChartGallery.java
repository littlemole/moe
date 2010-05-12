package mol.excel  ;

import com4j.*;

public enum XlChartGallery implements ComEnum {
    xlBuiltIn(21),
    xlUserDefined(22),
    xlAnyGallery(23),
    ;

    private final int value;
    XlChartGallery(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
