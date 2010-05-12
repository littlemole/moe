package mol.word  ;

import com4j.*;

public enum WdAlertLevel implements ComEnum {
    wdAlertsNone(0),
    wdAlertsMessageBox(-2),
    wdAlertsAll(-1),
    ;

    private final int value;
    WdAlertLevel(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
