package mol.excel  ;

import com4j.*;

public enum XlYesNoGuess implements ComEnum {
    xlGuess(0),
    xlNo(2),
    xlYes(1),
    ;

    private final int value;
    XlYesNoGuess(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
