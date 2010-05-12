package mol.office  ;

import com4j.*;

public enum MsoCalloutType implements ComEnum {
    msoCalloutMixed(-2),
    msoCalloutOne(1),
    msoCalloutTwo(2),
    msoCalloutThree(3),
    msoCalloutFour(4),
    ;

    private final int value;
    MsoCalloutType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
