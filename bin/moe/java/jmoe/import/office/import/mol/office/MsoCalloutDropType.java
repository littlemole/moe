package mol.office  ;

import com4j.*;

public enum MsoCalloutDropType implements ComEnum {
    msoCalloutDropMixed(-2),
    msoCalloutDropCustom(1),
    msoCalloutDropTop(2),
    msoCalloutDropCenter(3),
    msoCalloutDropBottom(4),
    ;

    private final int value;
    MsoCalloutDropType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
