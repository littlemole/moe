package mol.mshtml  ;

import com4j.*;

public enum _htmlReadyState implements ComEnum {
    htmlReadyStateuninitialized(0),
    htmlReadyStateloading(1),
    htmlReadyStateloaded(2),
    htmlReadyStateinteractive(3),
    htmlReadyStatecomplete(4),
    htmlReadyState_Max(2147483647),
    ;

    private final int value;
    _htmlReadyState(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
