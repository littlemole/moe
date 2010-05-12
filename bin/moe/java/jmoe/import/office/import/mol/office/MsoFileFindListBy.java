package mol.office  ;

import com4j.*;

public enum MsoFileFindListBy implements ComEnum {
    msoListbyName(1),
    msoListbyTitle(2),
    ;

    private final int value;
    MsoFileFindListBy(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
