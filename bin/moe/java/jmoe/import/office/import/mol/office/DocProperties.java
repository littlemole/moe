package mol.office  ;

import com4j.*;

public enum DocProperties implements ComEnum {
    offPropertyTypeNumber(1),
    offPropertyTypeBoolean(2),
    offPropertyTypeDate(3),
    offPropertyTypeString(4),
    offPropertyTypeFloat(5),
    ;

    private final int value;
    DocProperties(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
