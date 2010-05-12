package mol.excel  ;

import com4j.*;

public enum XlLinkType implements ComEnum {
    xlLinkTypeExcelLinks(1),
    xlLinkTypeOLELinks(2),
    ;

    private final int value;
    XlLinkType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
