package mol.word  ;

import com4j.*;

public enum WdPrintOutItem implements ComEnum {
    wdPrintDocumentContent(0),
    wdPrintProperties(1),
    wdPrintComments(2),
    wdPrintMarkup(2),
    wdPrintStyles(3),
    wdPrintAutoTextEntries(4),
    wdPrintKeyAssignments(5),
    wdPrintEnvelope(6),
    wdPrintDocumentWithMarkup(7),
    ;

    private final int value;
    WdPrintOutItem(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
