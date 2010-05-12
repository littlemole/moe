package mol.excel  ;

import com4j.*;

public enum XlDVAlertStyle implements ComEnum {
    xlValidAlertStop(1),
    xlValidAlertWarning(2),
    xlValidAlertInformation(3),
    ;

    private final int value;
    XlDVAlertStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
