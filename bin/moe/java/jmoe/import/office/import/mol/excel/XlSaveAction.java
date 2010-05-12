package mol.excel  ;

import com4j.*;

public enum XlSaveAction implements ComEnum {
    xlDoNotSaveChanges(2),
    xlSaveChanges(1),
    ;

    private final int value;
    XlSaveAction(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
