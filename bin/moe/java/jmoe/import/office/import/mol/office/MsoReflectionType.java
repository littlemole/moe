package mol.office  ;

import com4j.*;

public enum MsoReflectionType implements ComEnum {
    msoReflectionTypeMixed(-2),
    msoReflectionTypeNone(0),
    msoReflectionType1(1),
    msoReflectionType2(2),
    msoReflectionType3(3),
    msoReflectionType4(4),
    msoReflectionType5(5),
    msoReflectionType6(6),
    msoReflectionType7(7),
    msoReflectionType8(8),
    msoReflectionType9(9),
    ;

    private final int value;
    MsoReflectionType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
