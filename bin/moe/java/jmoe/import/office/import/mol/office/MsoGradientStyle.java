package mol.office  ;

import com4j.*;

public enum MsoGradientStyle implements ComEnum {
    msoGradientMixed(-2),
    msoGradientHorizontal(1),
    msoGradientVertical(2),
    msoGradientDiagonalUp(3),
    msoGradientDiagonalDown(4),
    msoGradientFromCorner(5),
    msoGradientFromTitle(6),
    msoGradientFromCenter(7),
    ;

    private final int value;
    MsoGradientStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
