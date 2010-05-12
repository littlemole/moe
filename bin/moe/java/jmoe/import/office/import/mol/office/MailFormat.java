package mol.office  ;

import com4j.*;

public enum MailFormat implements ComEnum {
    mfPlainText(1),
    mfHTML(2),
    mfRTF(3),
    ;

    private final int value;
    MailFormat(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
