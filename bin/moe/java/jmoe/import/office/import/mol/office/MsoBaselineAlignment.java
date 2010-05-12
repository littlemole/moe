package mol.office  ;

import com4j.*;

public enum MsoBaselineAlignment implements ComEnum {
    msoBaselineAlignMixed(-2),
    msoBaselineAlignBaseline(1),
    msoBaselineAlignTop(2),
    msoBaselineAlignCenter(3),
    msoBaselineAlignFarEast50(4),
    msoBaselineAlignAuto(5),
    ;

    private final int value;
    MsoBaselineAlignment(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
