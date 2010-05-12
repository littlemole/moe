package mol.excel  ;

import com4j.*;

public enum XlEnableCancelKey implements ComEnum {
    xlDisabled(0),
    xlErrorHandler(2),
    xlInterrupt(1),
    ;

    private final int value;
    XlEnableCancelKey(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
