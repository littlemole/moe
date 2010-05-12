package mol.word  ;

import com4j.*;

public enum WdMailMergeState {
    wdNormalDocument, // 0
    wdMainDocumentOnly, // 1
    wdMainAndDataSource, // 2
    wdMainAndHeader, // 3
    wdMainAndSourceAndHeader, // 4
    wdDataSource, // 5
}
