package mol.excel  ;

import com4j.*;

public enum XlPageBreak implements ComEnum {
    xlPageBreakAutomatic(-4105),
    xlPageBreakManual(-4135),
    xlPageBreakNone(-4142),
    ;

    private final int value;
    XlPageBreak(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
