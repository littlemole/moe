package mol.office  ;

import com4j.*;

public enum MsoFillType implements ComEnum {
    msoFillMixed(-2),
    msoFillSolid(1),
    msoFillPatterned(2),
    msoFillGradient(3),
    msoFillTextured(4),
    msoFillBackground(5),
    msoFillPicture(6),
    ;

    private final int value;
    MsoFillType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
