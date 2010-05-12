package mol.excel  ;

import com4j.*;

public enum XlCubeFieldSubType implements ComEnum {
    xlCubeHierarchy(1),
    xlCubeMeasure(2),
    xlCubeSet(3),
    xlCubeAttribute(4),
    xlCubeCalculatedMeasure(5),
    xlCubeKPIValue(6),
    xlCubeKPIGoal(7),
    xlCubeKPIStatus(8),
    xlCubeKPITrend(9),
    xlCubeKPIWeight(10),
    ;

    private final int value;
    XlCubeFieldSubType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
