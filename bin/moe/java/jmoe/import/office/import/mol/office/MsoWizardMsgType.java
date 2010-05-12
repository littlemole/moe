package mol.office  ;

import com4j.*;

public enum MsoWizardMsgType implements ComEnum {
    msoWizardMsgLocalStateOn(1),
    msoWizardMsgLocalStateOff(2),
    msoWizardMsgShowHelp(3),
    msoWizardMsgSuspending(4),
    msoWizardMsgResuming(5),
    ;

    private final int value;
    MsoWizardMsgType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
