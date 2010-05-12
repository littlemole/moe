package mol.mshtml  ;

import com4j.*;

public enum _htmlMethod implements ComEnum {
    htmlMethodNotSet(0),
    htmlMethodGet(1),
    htmlMethodPost(2),
    htmlMethod_Max(2147483647),
    ;

    private final int value;
    _htmlMethod(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
