package mol.word  ;

import com4j.*;

public enum WdSelectionFlags implements ComEnum {
    wdSelStartActive(1),
    wdSelAtEOL(2),
    wdSelOvertype(4),
    wdSelActive(8),
    wdSelReplace(16),
    ;

    private final int value;
    WdSelectionFlags(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
