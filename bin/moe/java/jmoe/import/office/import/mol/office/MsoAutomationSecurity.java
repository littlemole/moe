package mol.office  ;

import com4j.*;

public enum MsoAutomationSecurity implements ComEnum {
    msoAutomationSecurityLow(1),
    msoAutomationSecurityByUI(2),
    msoAutomationSecurityForceDisable(3),
    ;

    private final int value;
    MsoAutomationSecurity(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
