package mol.office  ;

import com4j.*;

public enum MsoTabStopType implements ComEnum {
    msoTabStopMixed(-2),
    msoTabStopLeft(1),
    msoTabStopCenter(2),
    msoTabStopRight(3),
    msoTabStopDecimal(4),
    ;

    private final int value;
    MsoTabStopType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
