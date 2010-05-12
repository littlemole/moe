package mol.word  ;

import com4j.*;

public enum WdStyleSheetPrecedence implements ComEnum {
    wdStyleSheetPrecedenceHigher(-1),
    wdStyleSheetPrecedenceLower(-2),
    wdStyleSheetPrecedenceHighest(1),
    wdStyleSheetPrecedenceLowest(0),
    ;

    private final int value;
    WdStyleSheetPrecedence(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
