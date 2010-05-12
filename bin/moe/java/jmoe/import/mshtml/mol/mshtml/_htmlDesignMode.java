package mol.mshtml  ;

import com4j.*;

public enum _htmlDesignMode implements ComEnum {
    htmlDesignModeInherit(-2),
    htmlDesignModeOn(-1),
    htmlDesignModeOff(0),
    htmlDesignMode_Max(2147483647),
    ;

    private final int value;
    _htmlDesignMode(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
