package mol.excel  ;

import com4j.*;

public enum XlPlatform implements ComEnum {
    xlMacintosh(1),
    xlMSDOS(3),
    xlWindows(2),
    ;

    private final int value;
    XlPlatform(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
