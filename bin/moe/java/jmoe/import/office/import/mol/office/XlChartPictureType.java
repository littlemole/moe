package mol.office  ;

import com4j.*;

public enum XlChartPictureType implements ComEnum {
    xlStackScale(3),
    xlStack(2),
    xlStretch(1),
    ;

    private final int value;
    XlChartPictureType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
