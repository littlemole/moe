package mol.excel  ;

import com4j.*;

public enum XlDirection implements ComEnum {
    xlDown(-4121),
    xlToLeft(-4159),
    xlToRight(-4161),
    xlUp(-4162),
    ;

    private final int value;
    XlDirection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
