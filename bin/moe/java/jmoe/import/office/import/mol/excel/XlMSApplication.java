package mol.excel  ;

import com4j.*;

public enum XlMSApplication implements ComEnum {
    xlMicrosoftAccess(4),
    xlMicrosoftFoxPro(5),
    xlMicrosoftMail(3),
    xlMicrosoftPowerPoint(2),
    xlMicrosoftProject(6),
    xlMicrosoftSchedulePlus(7),
    xlMicrosoftWord(1),
    ;

    private final int value;
    XlMSApplication(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
