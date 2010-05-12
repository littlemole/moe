package mol.excel  ;

import com4j.*;

public enum XlPivotFieldOrientation implements ComEnum {
    xlColumnField(2),
    xlDataField(4),
    xlHidden(0),
    xlPageField(3),
    xlRowField(1),
    ;

    private final int value;
    XlPivotFieldOrientation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
