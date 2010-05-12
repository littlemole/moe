package mol.office  ;

import com4j.*;

public enum MsoFileFindOptions implements ComEnum {
    msoOptionsNew(1),
    msoOptionsAdd(2),
    msoOptionsWithin(3),
    ;

    private final int value;
    MsoFileFindOptions(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
