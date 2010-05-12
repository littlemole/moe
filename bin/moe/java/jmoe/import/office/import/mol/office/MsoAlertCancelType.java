package mol.office  ;

import com4j.*;

public enum MsoAlertCancelType implements ComEnum {
    msoAlertCancelDefault(-1),
    msoAlertCancelFirst(0),
    msoAlertCancelSecond(1),
    msoAlertCancelThird(2),
    msoAlertCancelFourth(3),
    msoAlertCancelFifth(4),
    ;

    private final int value;
    MsoAlertCancelType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
