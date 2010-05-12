package mol.mshtml  ;

import com4j.*;

public enum _htmlEndPoints implements ComEnum {
    htmlEndPointsStartToStart(1),
    htmlEndPointsStartToEnd(2),
    htmlEndPointsEndToStart(3),
    htmlEndPointsEndToEnd(4),
    htmlEndPoints_Max(2147483647),
    ;

    private final int value;
    _htmlEndPoints(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
