package mol.excel  ;

import com4j.*;

public enum XlOrder implements ComEnum {
    xlDownThenOver(1),
    xlOverThenDown(2),
    ;

    private final int value;
    XlOrder(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
