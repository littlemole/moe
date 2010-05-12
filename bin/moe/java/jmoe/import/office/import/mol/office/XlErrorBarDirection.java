package mol.office  ;

import com4j.*;

public enum XlErrorBarDirection implements ComEnum {
    xlChartX(-4168),
    xlChartY(1),
    ;

    private final int value;
    XlErrorBarDirection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
