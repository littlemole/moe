package mol.excel  ;

import com4j.*;

public enum XlArrowHeadLength implements ComEnum {
    xlArrowHeadLengthLong(3),
    xlArrowHeadLengthMedium(-4138),
    xlArrowHeadLengthShort(1),
    ;

    private final int value;
    XlArrowHeadLength(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
