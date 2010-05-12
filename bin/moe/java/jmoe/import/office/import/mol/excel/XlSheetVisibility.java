package mol.excel  ;

import com4j.*;

public enum XlSheetVisibility implements ComEnum {
    xlSheetVisible(-1),
    xlSheetHidden(0),
    xlSheetVeryHidden(2),
    ;

    private final int value;
    XlSheetVisibility(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
