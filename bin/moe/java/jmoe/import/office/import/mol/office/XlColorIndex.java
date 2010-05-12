package mol.office  ;

import com4j.*;

public enum XlColorIndex implements ComEnum {
    xlColorIndexAutomatic(-4105),
    xlColorIndexNone(-4142),
    ;

    private final int value;
    XlColorIndex(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
