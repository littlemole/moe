package mol.office  ;

import com4j.*;

public enum MsoTextCharWrap implements ComEnum {
    msoCharWrapMixed(-2),
    msoNoCharWrap(0),
    msoStandardCharWrap(1),
    msoStrictCharWrap(2),
    msoCustomCharWrap(3),
    ;

    private final int value;
    MsoTextCharWrap(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
