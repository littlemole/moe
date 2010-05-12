package mol.word  ;

import com4j.*;

public enum WdProtectionType implements ComEnum {
    wdNoProtection(-1),
    wdAllowOnlyRevisions(0),
    wdAllowOnlyComments(1),
    wdAllowOnlyFormFields(2),
    wdAllowOnlyReading(3),
    ;

    private final int value;
    WdProtectionType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
