package mol.mshtml  ;

import com4j.*;

public enum _HT_RESULTS implements ComEnum {
    HT_RESULTS_Glyph(1),
    HT_RESULTS_Max(2147483647),
    ;

    private final int value;
    _HT_RESULTS(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
