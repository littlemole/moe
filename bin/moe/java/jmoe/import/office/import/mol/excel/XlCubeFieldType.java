package mol.excel  ;

import com4j.*;

public enum XlCubeFieldType implements ComEnum {
    xlHierarchy(1),
    xlMeasure(2),
    xlSet(3),
    ;

    private final int value;
    XlCubeFieldType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
