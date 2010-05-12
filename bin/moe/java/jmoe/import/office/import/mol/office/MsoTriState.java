package mol.office  ;

import com4j.*;

public enum MsoTriState implements ComEnum {
    msoTrue(-1),
    msoFalse(0),
    msoCTrue(1),
    msoTriStateToggle(-3),
    msoTriStateMixed(-2),
    ;

    private final int value;
    MsoTriState(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
