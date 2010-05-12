package mol.moe  ;

import com4j.*;

public enum XMOE_FORMFLAG implements ComEnum {
    XMOE_FORMFLAG_NONE(0),
    XMOE_FORMFLAG_TITLE(1),
    XMOE_FORMFLAG_NOSCROLL(2),
    XMOE_FORMFLAG_DIALOG(4),
    XMOE_FORMFLAG_STANDALONE(8),
    ;

    private final int value;
    XMOE_FORMFLAG(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
