package mol.excel  ;

import com4j.*;

public enum XlTopBottom implements ComEnum {
    xlTop10Top(1),
    xlTop10Bottom(0),
    ;

    private final int value;
    XlTopBottom(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
