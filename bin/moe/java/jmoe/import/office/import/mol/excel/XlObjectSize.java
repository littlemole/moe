package mol.excel  ;

import com4j.*;

public enum XlObjectSize implements ComEnum {
    xlFitToPage(2),
    xlFullPage(3),
    xlScreenSize(1),
    ;

    private final int value;
    XlObjectSize(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
