package mol.mshtml  ;

import com4j.*;

public enum _SELECTION_TYPE implements ComEnum {
    SELECTION_TYPE_None(0),
    SELECTION_TYPE_Caret(1),
    SELECTION_TYPE_Text(2),
    SELECTION_TYPE_Control(3),
    SELECTION_TYPE_Max(2147483647),
    ;

    private final int value;
    _SELECTION_TYPE(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
