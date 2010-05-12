package mol.excel  ;

import com4j.*;

public enum XlSearchDirection implements ComEnum {
    xlNext(1),
    xlPrevious(2),
    ;

    private final int value;
    XlSearchDirection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
