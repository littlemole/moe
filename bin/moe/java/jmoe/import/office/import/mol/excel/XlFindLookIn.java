package mol.excel  ;

import com4j.*;

public enum XlFindLookIn implements ComEnum {
    xlFormulas(-4123),
    xlComments(-4144),
    xlValues(-4163),
    ;

    private final int value;
    XlFindLookIn(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
