package mol.word  ;

import com4j.*;

public enum WdOLEVerb implements ComEnum {
    wdOLEVerbPrimary(0),
    wdOLEVerbShow(-1),
    wdOLEVerbOpen(-2),
    wdOLEVerbHide(-3),
    wdOLEVerbUIActivate(-4),
    wdOLEVerbInPlaceActivate(-5),
    wdOLEVerbDiscardUndoState(-6),
    ;

    private final int value;
    WdOLEVerb(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
