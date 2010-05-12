package mol.excel  ;

import com4j.*;

public enum XlColumnDataType implements ComEnum {
    xlGeneralFormat(1),
    xlTextFormat(2),
    xlMDYFormat(3),
    xlDMYFormat(4),
    xlYMDFormat(5),
    xlMYDFormat(6),
    xlDYMFormat(7),
    xlYDMFormat(8),
    xlSkipColumn(9),
    xlEMDFormat(10),
    ;

    private final int value;
    XlColumnDataType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
