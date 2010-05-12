package mol.mshtml  ;

import com4j.*;

public enum _styleRubyAlign implements ComEnum {
    styleRubyAlignNotSet(0),
    styleRubyAlignAuto(1),
    styleRubyAlignLeft(2),
    styleRubyAlignCenter(3),
    styleRubyAlignRight(4),
    styleRubyAlignDistributeLetter(5),
    styleRubyAlignDistributeSpace(6),
    styleRubyAlignLineEdge(7),
    styleRubyAlign_Max(2147483647),
    ;

    private final int value;
    _styleRubyAlign(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
