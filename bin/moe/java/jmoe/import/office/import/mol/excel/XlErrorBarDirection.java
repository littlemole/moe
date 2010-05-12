package mol.excel  ;

import com4j.*;

public enum XlErrorBarDirection implements ComEnum {
    xlX(-4168),
    xlY(1),
    ;

    private final int value;
    XlErrorBarDirection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
