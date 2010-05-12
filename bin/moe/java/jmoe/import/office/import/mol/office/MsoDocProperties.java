package mol.office  ;

import com4j.*;

public enum MsoDocProperties implements ComEnum {
    msoPropertyTypeNumber(1),
    msoPropertyTypeBoolean(2),
    msoPropertyTypeDate(3),
    msoPropertyTypeString(4),
    msoPropertyTypeFloat(5),
    ;

    private final int value;
    MsoDocProperties(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
