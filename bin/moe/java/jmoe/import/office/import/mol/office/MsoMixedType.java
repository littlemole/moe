package mol.office  ;

import com4j.*;

public enum MsoMixedType implements ComEnum {
    msoIntegerMixed(32768),
    msoSingleMixed(-2147483648),
    ;

    private final int value;
    MsoMixedType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
