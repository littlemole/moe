package mol.office  ;

import com4j.*;

public enum MsoTextDirection implements ComEnum {
    msoTextDirectionMixed(-2),
    msoTextDirectionLeftToRight(1),
    msoTextDirectionRightToLeft(2),
    ;

    private final int value;
    MsoTextDirection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
