package mol.mshtml  ;

import com4j.*;

public enum _htmlUnit implements ComEnum {
    htmlUnitCharacter(1),
    htmlUnitWord(2),
    htmlUnitSentence(3),
    htmlUnitTextEdit(6),
    htmlUnit_Max(2147483647),
    ;

    private final int value;
    _htmlUnit(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
