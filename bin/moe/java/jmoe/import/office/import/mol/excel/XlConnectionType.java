package mol.excel  ;

import com4j.*;

public enum XlConnectionType implements ComEnum {
    xlConnectionTypeOLEDB(1),
    xlConnectionTypeODBC(2),
    xlConnectionTypeXMLMAP(3),
    xlConnectionTypeTEXT(4),
    xlConnectionTypeWEB(5),
    ;

    private final int value;
    XlConnectionType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
