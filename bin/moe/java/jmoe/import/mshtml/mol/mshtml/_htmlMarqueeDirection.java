package mol.mshtml  ;

import com4j.*;

public enum _htmlMarqueeDirection implements ComEnum {
    htmlMarqueeDirectionleft(1),
    htmlMarqueeDirectionright(3),
    htmlMarqueeDirectionup(5),
    htmlMarqueeDirectiondown(7),
    htmlMarqueeDirection_Max(2147483647),
    ;

    private final int value;
    _htmlMarqueeDirection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
