package mol.excel  ;

import com4j.*;

public enum XlFileAccess implements ComEnum {
    xlReadOnly(3),
    xlReadWrite(2),
    ;

    private final int value;
    XlFileAccess(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
