package mol.mshtml  ;

import com4j.*;

public enum _htmlZOrder implements ComEnum {
    htmlZOrderFront(0),
    htmlZOrderBack(1),
    htmlZOrder_Max(2147483647),
    ;

    private final int value;
    _htmlZOrder(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
