package mol.mshtml  ;

import com4j.*;

public enum _styleOverflow implements ComEnum {
    styleOverflowNotSet(0),
    styleOverflowAuto(1),
    styleOverflowHidden(2),
    styleOverflowVisible(3),
    styleOverflowScroll(4),
    styleOverflow_Max(2147483647),
    ;

    private final int value;
    _styleOverflow(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
