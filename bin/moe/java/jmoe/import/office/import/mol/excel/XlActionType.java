package mol.excel  ;

import com4j.*;

public enum XlActionType implements ComEnum {
    xlActionTypeUrl(1),
    xlActionTypeRowset(16),
    xlActionTypeReport(128),
    xlActionTypeDrillthrough(256),
    ;

    private final int value;
    XlActionType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
