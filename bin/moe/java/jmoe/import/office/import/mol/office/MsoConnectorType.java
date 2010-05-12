package mol.office  ;

import com4j.*;

public enum MsoConnectorType implements ComEnum {
    msoConnectorTypeMixed(-2),
    msoConnectorStraight(1),
    msoConnectorElbow(2),
    msoConnectorCurve(3),
    ;

    private final int value;
    MsoConnectorType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
