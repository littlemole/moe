package mol.word  ;

import com4j.*;

public enum WdMailMergeDefaultRecord implements ComEnum {
    wdDefaultFirstRecord(1),
    wdDefaultLastRecord(-16),
    ;

    private final int value;
    WdMailMergeDefaultRecord(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
