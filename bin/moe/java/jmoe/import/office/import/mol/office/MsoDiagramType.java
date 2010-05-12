package mol.office  ;

import com4j.*;

public enum MsoDiagramType implements ComEnum {
    msoDiagramMixed(-2),
    msoDiagramOrgChart(1),
    msoDiagramCycle(2),
    msoDiagramRadial(3),
    msoDiagramPyramid(4),
    msoDiagramVenn(5),
    msoDiagramTarget(6),
    ;

    private final int value;
    MsoDiagramType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
