package mol.mshtml  ;

import com4j.*;

public enum _styleRubyOverhang implements ComEnum {
    styleRubyOverhangNotSet(0),
    styleRubyOverhangAuto(1),
    styleRubyOverhangWhitespace(2),
    styleRubyOverhangNone(3),
    styleRubyOverhang_Max(2147483647),
    ;

    private final int value;
    _styleRubyOverhang(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
