package mol.mshtml  ;

import com4j.*;

public enum _ELEMENTDESCRIPTOR_FLAGS implements ComEnum {
    ELEMENTDESCRIPTORFLAGS_LITERAL(1),
    ELEMENTDESCRIPTORFLAGS_NESTED_LITERAL(2),
    ELEMENTDESCRIPTOR_FLAGS_Max(2147483647),
    ;

    private final int value;
    _ELEMENTDESCRIPTOR_FLAGS(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
