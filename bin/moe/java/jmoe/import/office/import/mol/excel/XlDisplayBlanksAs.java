package mol.excel  ;

import com4j.*;

public enum XlDisplayBlanksAs implements ComEnum {
    xlInterpolated(3),
    xlNotPlotted(1),
    xlZero(2),
    ;

    private final int value;
    XlDisplayBlanksAs(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
