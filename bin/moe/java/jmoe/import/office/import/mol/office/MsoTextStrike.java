package mol.office  ;

import com4j.*;

public enum MsoTextStrike implements ComEnum {
    msoStrikeMixed(-2),
    msoNoStrike(0),
    msoSingleStrike(1),
    msoDoubleStrike(2),
    ;

    private final int value;
    MsoTextStrike(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
