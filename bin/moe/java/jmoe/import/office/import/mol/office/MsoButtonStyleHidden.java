package mol.office  ;

import com4j.*;

public enum MsoButtonStyleHidden implements ComEnum {
    msoButtonWrapText(4),
    msoButtonTextBelow(8),
    ;

    private final int value;
    MsoButtonStyleHidden(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
