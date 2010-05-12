package mol.word  ;

import com4j.*;

public enum WdMailMergeMainDocType implements ComEnum {
    wdNotAMergeDocument(-1),
    wdFormLetters(0),
    wdMailingLabels(1),
    wdEnvelopes(2),
    wdCatalog(3),
    wdEMail(4),
    wdFax(5),
    wdDirectory(3),
    ;

    private final int value;
    WdMailMergeMainDocType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
