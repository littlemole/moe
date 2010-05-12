package mol.office  ;

import com4j.*;

public enum MsoPathFormat implements ComEnum {
    msoPathTypeMixed(-2),
    msoPathTypeNone(0),
    msoPathType1(1),
    msoPathType2(2),
    msoPathType3(3),
    msoPathType4(4),
    ;

    private final int value;
    MsoPathFormat(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
