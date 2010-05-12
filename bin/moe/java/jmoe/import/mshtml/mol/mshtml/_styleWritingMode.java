package mol.mshtml  ;

import com4j.*;

public enum _styleWritingMode implements ComEnum {
    styleWritingModeLrtb(0),
    styleWritingModeTbrl(1),
    styleWritingModeRltb(2),
    styleWritingModeBtrl(3),
    styleWritingModeNotSet(4),
    styleWritingMode_Max(2147483647),
    ;

    private final int value;
    _styleWritingMode(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
