package mol.office  ;

import com4j.*;

public enum MsoVerticalAnchor implements ComEnum {
    msoVerticalAnchorMixed(-2),
    msoAnchorTop(1),
    msoAnchorTopBaseline(2),
    msoAnchorMiddle(3),
    msoAnchorBottom(4),
    msoAnchorBottomBaseLine(5),
    ;

    private final int value;
    MsoVerticalAnchor(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
