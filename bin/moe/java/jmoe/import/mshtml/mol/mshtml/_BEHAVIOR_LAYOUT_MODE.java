package mol.mshtml  ;

import com4j.*;

public enum _BEHAVIOR_LAYOUT_MODE implements ComEnum {
    BEHAVIORLAYOUTMODE_NATURAL(1),
    BEHAVIORLAYOUTMODE_MINWIDTH(2),
    BEHAVIORLAYOUTMODE_MAXWIDTH(4),
    BEHAVIORLAYOUTMODE_MEDIA_RESOLUTION(16384),
    BEHAVIORLAYOUTMODE_FINAL_PERCENT(32768),
    BEHAVIOR_LAYOUT_MODE_Max(2147483647),
    ;

    private final int value;
    _BEHAVIOR_LAYOUT_MODE(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
