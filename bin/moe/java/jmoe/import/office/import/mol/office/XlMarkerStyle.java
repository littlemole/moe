package mol.office  ;

import com4j.*;

public enum XlMarkerStyle implements ComEnum {
    xlMarkerStyleAutomatic(-4105),
    xlMarkerStyleCircle(8),
    xlMarkerStyleDash(-4115),
    xlMarkerStyleDiamond(2),
    xlMarkerStyleDot(-4118),
    xlMarkerStyleNone(-4142),
    xlMarkerStylePicture(-4147),
    xlMarkerStylePlus(9),
    xlMarkerStyleSquare(1),
    xlMarkerStyleStar(5),
    xlMarkerStyleTriangle(3),
    xlMarkerStyleX(-4168),
    ;

    private final int value;
    XlMarkerStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
