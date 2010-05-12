package mol.office  ;

import com4j.*;

public enum MsoHTMLProjectState implements ComEnum {
    msoHTMLProjectStateDocumentLocked(1),
    msoHTMLProjectStateProjectLocked(2),
    msoHTMLProjectStateDocumentProjectUnlocked(3),
    ;

    private final int value;
    MsoHTMLProjectState(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
