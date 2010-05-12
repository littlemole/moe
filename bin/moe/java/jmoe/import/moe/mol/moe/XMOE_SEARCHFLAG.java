package mol.moe  ;

import com4j.*;

public enum XMOE_SEARCHFLAG implements ComEnum {
    XMOE_SEARCHFLAG_DOWN(1),
    XMOE_SEARCHFLAG_WHOLEWORD(2),
    XMOE_SEARCHFLAG_MATCHCASE(4),
    XMOE_SEARCHFLAG_FINDNEXT(8),
    XMOE_SEARCHFLAG_REPLACE(16),
    XMOE_SEARCHFLAG_REPLACEALL(32),
    XMOE_SEARCHFLAG_DIALOGTERM(64),
    ;

    private final int value;
    XMOE_SEARCHFLAG(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
