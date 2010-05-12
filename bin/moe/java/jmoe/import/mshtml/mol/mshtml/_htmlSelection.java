package mol.mshtml  ;

import com4j.*;

public enum _htmlSelection implements ComEnum {
    htmlSelectionNone(0),
    htmlSelectionText(1),
    htmlSelectionControl(2),
    htmlSelectionTable(3),
    htmlSelection_Max(2147483647),
    ;

    private final int value;
    _htmlSelection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
