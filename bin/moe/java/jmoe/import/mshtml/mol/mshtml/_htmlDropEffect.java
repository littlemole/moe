package mol.mshtml  ;

import com4j.*;

public enum _htmlDropEffect implements ComEnum {
    htmlDropEffectCopy(0),
    htmlDropEffectLink(1),
    htmlDropEffectMove(2),
    htmlDropEffectNone(3),
    htmlDropEffect_Max(2147483647),
    ;

    private final int value;
    _htmlDropEffect(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
