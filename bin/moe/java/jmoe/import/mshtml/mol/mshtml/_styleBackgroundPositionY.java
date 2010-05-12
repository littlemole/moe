package mol.mshtml  ;

import com4j.*;

public enum _styleBackgroundPositionY implements ComEnum {
    styleBackgroundPositionYNotSet(0),
    styleBackgroundPositionYTop(1),
    styleBackgroundPositionYCenter(2),
    styleBackgroundPositionYBottom(3),
    styleBackgroundPositionY_Max(2147483647),
    ;

    private final int value;
    _styleBackgroundPositionY(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
