package mol.office  ;

import com4j.*;

public enum MsoBarProtection implements ComEnum {
    msoBarNoProtection(0),
    msoBarNoCustomize(1),
    msoBarNoResize(2),
    msoBarNoMove(4),
    msoBarNoChangeVisible(8),
    msoBarNoChangeDock(16),
    msoBarNoVerticalDock(32),
    msoBarNoHorizontalDock(64),
    ;

    private final int value;
    MsoBarProtection(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
