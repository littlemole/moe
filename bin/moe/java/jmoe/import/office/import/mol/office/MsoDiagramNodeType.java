package mol.office  ;

import com4j.*;

public enum MsoDiagramNodeType implements ComEnum {
    msoDiagramNode(1),
    msoDiagramAssistant(2),
    ;

    private final int value;
    MsoDiagramNodeType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
