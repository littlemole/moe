package mol.excel  ;

import com4j.*;

public enum XlSortMethod implements ComEnum {
    xlPinYin(1),
    xlStroke(2),
    ;

    private final int value;
    XlSortMethod(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
