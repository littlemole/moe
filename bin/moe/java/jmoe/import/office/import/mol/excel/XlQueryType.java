package mol.excel  ;

import com4j.*;

public enum XlQueryType implements ComEnum {
    xlODBCQuery(1),
    xlDAORecordset(2),
    xlWebQuery(4),
    xlOLEDBQuery(5),
    xlTextImport(6),
    xlADORecordset(7),
    ;

    private final int value;
    XlQueryType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
