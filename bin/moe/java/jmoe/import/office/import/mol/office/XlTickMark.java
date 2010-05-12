package mol.office  ;

import com4j.*;

public enum XlTickMark implements ComEnum {
    xlTickMarkCross(4),
    xlTickMarkInside(2),
    xlTickMarkNone(-4142),
    xlTickMarkOutside(3),
    ;

    private final int value;
    XlTickMark(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
