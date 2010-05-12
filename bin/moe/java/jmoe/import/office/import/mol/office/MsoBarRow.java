package mol.office  ;

import com4j.*;

public enum MsoBarRow implements ComEnum {
    msoBarRowFirst(0),
    msoBarRowLast(-1),
    ;

    private final int value;
    MsoBarRow(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
