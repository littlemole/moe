package mol.office  ;

import com4j.*;

public enum MsoIconType implements ComEnum {
    msoIconNone(0),
    msoIconAlert(2),
    msoIconTip(3),
    msoIconAlertInfo(4),
    msoIconAlertWarning(5),
    msoIconAlertQuery(6),
    msoIconAlertCritical(7),
    ;

    private final int value;
    MsoIconType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
