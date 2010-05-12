package mol.office  ;

import com4j.*;

public enum MsoSoftEdgeType implements ComEnum {
    msoSoftEdgeTypeMixed(-2),
    msoSoftEdgeTypeNone(0),
    msoSoftEdgeType1(1),
    msoSoftEdgeType2(2),
    msoSoftEdgeType3(3),
    msoSoftEdgeType4(4),
    msoSoftEdgeType5(5),
    msoSoftEdgeType6(6),
    ;

    private final int value;
    MsoSoftEdgeType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
