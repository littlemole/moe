package mol.word  ;

import com4j.*;

public enum WdMailerPriority implements ComEnum {
    wdPriorityNormal(1),
    wdPriorityLow(2),
    wdPriorityHigh(3),
    ;

    private final int value;
    WdMailerPriority(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
