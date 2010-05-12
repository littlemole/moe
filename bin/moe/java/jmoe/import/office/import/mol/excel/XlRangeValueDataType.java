package mol.excel  ;

import com4j.*;

public enum XlRangeValueDataType implements ComEnum {
    xlRangeValueDefault(10),
    xlRangeValueXMLSpreadsheet(11),
    xlRangeValueMSPersistXML(12),
    ;

    private final int value;
    XlRangeValueDataType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
