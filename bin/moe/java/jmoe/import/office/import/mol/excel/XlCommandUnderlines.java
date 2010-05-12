package mol.excel  ;

import com4j.*;

public enum XlCommandUnderlines implements ComEnum {
    xlCommandUnderlinesAutomatic(-4105),
    xlCommandUnderlinesOff(-4146),
    xlCommandUnderlinesOn(1),
    ;

    private final int value;
    XlCommandUnderlines(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
