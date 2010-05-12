package mol.office  ;

import com4j.*;

public enum MsoButtonState implements ComEnum {
    msoButtonUp(0),
    msoButtonDown(-1),
    msoButtonMixed(2),
    ;

    private final int value;
    MsoButtonState(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
