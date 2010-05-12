package mol.mshtml  ;

import com4j.*;

public enum _styleDefaultTextSelection implements ComEnum {
    styleDefaultTextSelectionFalse(0),
    styleDefaultTextSelectionTrue(1),
    styleDefaultTextSelection_Max(2147483647),
    ;

    private final int value;
    _styleDefaultTextSelection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
