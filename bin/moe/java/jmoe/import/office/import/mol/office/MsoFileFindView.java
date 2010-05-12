package mol.office  ;

import com4j.*;

public enum MsoFileFindView implements ComEnum {
    msoViewFileInfo(1),
    msoViewPreview(2),
    msoViewSummaryInfo(3),
    ;

    private final int value;
    MsoFileFindView(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
