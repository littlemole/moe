package mol.word  ;

import com4j.*;

public enum WdCharacterWidth implements ComEnum {
    wdWidthHalfWidth(6),
    wdWidthFullWidth(7),
    ;

    private final int value;
    WdCharacterWidth(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
