package mol.mshtml  ;

import com4j.*;

public enum _htmlEffectAllowed implements ComEnum {
    htmlEffectAllowedCopy(0),
    htmlEffectAllowedLink(1),
    htmlEffectAllowedMove(2),
    htmlEffectAllowedCopyLink(3),
    htmlEffectAllowedCopyMove(4),
    htmlEffectAllowedLinkMove(5),
    htmlEffectAllowedAll(6),
    htmlEffectAllowedNone(7),
    htmlEffectAllowedUninitialized(8),
    htmlEffectAllowed_Max(2147483647),
    ;

    private final int value;
    _htmlEffectAllowed(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
