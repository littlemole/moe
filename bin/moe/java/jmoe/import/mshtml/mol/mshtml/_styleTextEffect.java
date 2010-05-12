package mol.mshtml  ;

import com4j.*;

public enum _styleTextEffect implements ComEnum {
    styleTextEffectNone(0),
    styleTextEffectEmboss(1),
    styleTextEffectEngrave(2),
    styleTextEffectOutline(3),
    styleTextEffect_Max(2147483647),
    ;

    private final int value;
    _styleTextEffect(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
