package mol.mshtml  ;

import com4j.*;

public enum _styleLayoutFlow implements ComEnum {
    styleLayoutFlowHorizontal(0),
    styleLayoutFlowVerticalIdeographic(1),
    styleLayoutFlowNotSet(2),
    styleLayoutFlow_Max(2147483647),
    ;

    private final int value;
    _styleLayoutFlow(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
