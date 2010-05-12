package mol.word  ;

import com4j.*;

public enum WdMailMergeDataSource implements ComEnum {
    wdNoMergeInfo(-1),
    wdMergeInfoFromWord(0),
    wdMergeInfoFromAccessDDE(1),
    wdMergeInfoFromExcelDDE(2),
    wdMergeInfoFromMSQueryDDE(3),
    wdMergeInfoFromODBC(4),
    wdMergeInfoFromODSO(5),
    ;

    private final int value;
    WdMailMergeDataSource(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
