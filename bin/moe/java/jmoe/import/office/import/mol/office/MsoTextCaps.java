package mol.office  ;

import com4j.*;

public enum MsoTextCaps implements ComEnum {
    msoCapsMixed(-2),
    msoNoCaps(0),
    msoSmallCaps(1),
    msoAllCaps(2),
    ;

    private final int value;
    MsoTextCaps(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
