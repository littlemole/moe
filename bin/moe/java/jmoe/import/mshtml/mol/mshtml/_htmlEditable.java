package mol.mshtml  ;

import com4j.*;

public enum _htmlEditable implements ComEnum {
    htmlEditableInherit(0),
    htmlEditableTrue(1),
    htmlEditableFalse(2),
    htmlEditable_Max(2147483647),
    ;

    private final int value;
    _htmlEditable(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
