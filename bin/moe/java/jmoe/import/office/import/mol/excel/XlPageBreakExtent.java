package mol.excel  ;

import com4j.*;

public enum XlPageBreakExtent implements ComEnum {
    xlPageBreakFull(1),
    xlPageBreakPartial(2),
    ;

    private final int value;
    XlPageBreakExtent(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
