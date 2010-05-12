package mol.excel  ;

import com4j.*;

public enum XlSaveAsAccessMode implements ComEnum {
    xlExclusive(3),
    xlNoChange(1),
    xlShared(2),
    ;

    private final int value;
    XlSaveAsAccessMode(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
