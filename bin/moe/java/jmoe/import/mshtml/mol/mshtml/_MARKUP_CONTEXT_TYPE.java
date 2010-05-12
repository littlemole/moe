package mol.mshtml  ;

import com4j.*;

public enum _MARKUP_CONTEXT_TYPE implements ComEnum {
    CONTEXT_TYPE_None(0),
    CONTEXT_TYPE_Text(1),
    CONTEXT_TYPE_EnterScope(2),
    CONTEXT_TYPE_ExitScope(3),
    CONTEXT_TYPE_NoScope(4),
    MARKUP_CONTEXT_TYPE_Max(2147483647),
    ;

    private final int value;
    _MARKUP_CONTEXT_TYPE(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
