package mol.office  ;

import com4j.*;

public enum MsoTextChangeCase implements ComEnum {
    msoCaseSentence(1),
    msoCaseLower(2),
    msoCaseUpper(3),
    msoCaseTitle(4),
    msoCaseToggle(5),
    ;

    private final int value;
    MsoTextChangeCase(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
