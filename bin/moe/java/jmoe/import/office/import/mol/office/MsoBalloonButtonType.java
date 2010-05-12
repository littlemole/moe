package mol.office  ;

import com4j.*;

public enum MsoBalloonButtonType implements ComEnum {
    msoBalloonButtonYesToAll(-15),
    msoBalloonButtonOptions(-14),
    msoBalloonButtonTips(-13),
    msoBalloonButtonClose(-12),
    msoBalloonButtonSnooze(-11),
    msoBalloonButtonSearch(-10),
    msoBalloonButtonIgnore(-9),
    msoBalloonButtonAbort(-8),
    msoBalloonButtonRetry(-7),
    msoBalloonButtonNext(-6),
    msoBalloonButtonBack(-5),
    msoBalloonButtonNo(-4),
    msoBalloonButtonYes(-3),
    msoBalloonButtonCancel(-2),
    msoBalloonButtonOK(-1),
    msoBalloonButtonNull(0),
    ;

    private final int value;
    MsoBalloonButtonType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
