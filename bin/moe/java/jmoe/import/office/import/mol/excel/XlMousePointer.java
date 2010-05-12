package mol.excel  ;

import com4j.*;

public enum XlMousePointer implements ComEnum {
    xlIBeam(3),
    xlDefault(-4143),
    xlNorthwestArrow(1),
    xlWait(2),
    ;

    private final int value;
    XlMousePointer(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
