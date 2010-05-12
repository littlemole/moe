package mol.word  ;

import com4j.*;

public enum WdMailMergeActiveRecord implements ComEnum {
    wdNoActiveRecord(-1),
    wdNextRecord(-2),
    wdPreviousRecord(-3),
    wdFirstRecord(-4),
    wdLastRecord(-5),
    wdFirstDataSourceRecord(-6),
    wdLastDataSourceRecord(-7),
    wdNextDataSourceRecord(-8),
    wdPreviousDataSourceRecord(-9),
    ;

    private final int value;
    WdMailMergeActiveRecord(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
