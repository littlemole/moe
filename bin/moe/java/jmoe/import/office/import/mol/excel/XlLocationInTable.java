package mol.excel  ;

import com4j.*;

public enum XlLocationInTable implements ComEnum {
    xlColumnHeader(-4110),
    xlColumnItem(5),
    xlDataHeader(3),
    xlDataItem(7),
    xlPageHeader(2),
    xlPageItem(6),
    xlRowHeader(-4153),
    xlRowItem(4),
    xlTableBody(8),
    ;

    private final int value;
    XlLocationInTable(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
