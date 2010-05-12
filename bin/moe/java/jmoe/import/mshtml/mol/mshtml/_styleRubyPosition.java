package mol.mshtml  ;

import com4j.*;

public enum _styleRubyPosition implements ComEnum {
    styleRubyPositionNotSet(0),
    styleRubyPositionAbove(1),
    styleRubyPositionInline(2),
    styleRubyPosition_Max(2147483647),
    ;

    private final int value;
    _styleRubyPosition(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
