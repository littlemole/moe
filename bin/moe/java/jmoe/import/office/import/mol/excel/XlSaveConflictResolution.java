package mol.excel  ;

import com4j.*;

public enum XlSaveConflictResolution implements ComEnum {
    xlLocalSessionChanges(2),
    xlOtherSessionChanges(3),
    xlUserResolution(1),
    ;

    private final int value;
    XlSaveConflictResolution(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
