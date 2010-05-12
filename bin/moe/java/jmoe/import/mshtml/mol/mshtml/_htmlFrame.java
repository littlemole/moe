package mol.mshtml  ;

import com4j.*;

public enum _htmlFrame implements ComEnum {
    htmlFrameNotSet(0),
    htmlFramevoid(1),
    htmlFrameabove(2),
    htmlFramebelow(3),
    htmlFramehsides(4),
    htmlFramelhs(5),
    htmlFramerhs(6),
    htmlFramevsides(7),
    htmlFramebox(8),
    htmlFrameborder(9),
    htmlFrame_Max(2147483647),
    ;

    private final int value;
    _htmlFrame(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
