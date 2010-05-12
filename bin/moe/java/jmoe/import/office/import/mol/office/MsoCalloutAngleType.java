package mol.office  ;

import com4j.*;

public enum MsoCalloutAngleType implements ComEnum {
    msoCalloutAngleMixed(-2),
    msoCalloutAngleAutomatic(1),
    msoCalloutAngle30(2),
    msoCalloutAngle45(3),
    msoCalloutAngle60(4),
    msoCalloutAngle90(5),
    ;

    private final int value;
    MsoCalloutAngleType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
