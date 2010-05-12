package mol.excel  ;

import com4j.*;

public enum XlInsertShiftDirection implements ComEnum {
    xlShiftDown(-4121),
    xlShiftToRight(-4161),
    ;

    private final int value;
    XlInsertShiftDirection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
