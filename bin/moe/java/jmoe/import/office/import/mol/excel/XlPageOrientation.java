package mol.excel  ;

import com4j.*;

public enum XlPageOrientation implements ComEnum {
    xlLandscape(2),
    xlPortrait(1),
    ;

    private final int value;
    XlPageOrientation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
