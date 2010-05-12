package mol.office  ;

import com4j.*;

public enum MsoConnector implements ComEnum {
    msoConnectorAnd(1),
    msoConnectorOr(2),
    ;

    private final int value;
    MsoConnector(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
