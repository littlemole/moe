package mol.office  ;

import com4j.*;

public enum MsoButtonStyle implements ComEnum {
    msoButtonAutomatic(0),
    msoButtonIcon(1),
    msoButtonCaption(2),
    msoButtonIconAndCaption(3),
    msoButtonIconAndWrapCaption(7),
    msoButtonIconAndCaptionBelow(11),
    msoButtonWrapCaption(14),
    msoButtonIconAndWrapCaptionBelow(15),
    ;

    private final int value;
    MsoButtonStyle(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
