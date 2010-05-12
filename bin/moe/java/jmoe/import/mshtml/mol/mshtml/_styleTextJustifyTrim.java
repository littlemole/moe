package mol.mshtml  ;

import com4j.*;

public enum _styleTextJustifyTrim implements ComEnum {
    styleTextJustifyTrimNotSet(0),
    styleTextJustifyTrimNone(1),
    styleTextJustifyTrimPunctuation(2),
    styleTextJustifyTrimPunctAndKana(3),
    styleTextJustifyTrim_Max(2147483647),
    ;

    private final int value;
    _styleTextJustifyTrim(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
