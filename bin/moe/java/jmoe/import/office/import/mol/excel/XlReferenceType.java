package mol.excel  ;

import com4j.*;

public enum XlReferenceType implements ComEnum {
    xlAbsolute(1),
    xlAbsRowRelColumn(2),
    xlRelative(4),
    xlRelRowAbsColumn(3),
    ;

    private final int value;
    XlReferenceType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
