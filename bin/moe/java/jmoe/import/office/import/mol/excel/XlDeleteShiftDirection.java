package mol.excel  ;

import com4j.*;

public enum XlDeleteShiftDirection implements ComEnum {
    xlShiftToLeft(-4159),
    xlShiftUp(-4162),
    ;

    private final int value;
    XlDeleteShiftDirection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
