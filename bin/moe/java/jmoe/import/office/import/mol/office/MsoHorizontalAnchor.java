package mol.office  ;

import com4j.*;

public enum MsoHorizontalAnchor implements ComEnum {
    msoHorizontalAnchorMixed(-2),
    msoAnchorNone(1),
    msoAnchorCenter(2),
    ;

    private final int value;
    MsoHorizontalAnchor(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
