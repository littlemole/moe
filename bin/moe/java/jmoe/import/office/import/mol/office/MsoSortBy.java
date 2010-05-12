package mol.office  ;

import com4j.*;

public enum MsoSortBy implements ComEnum {
    msoSortByFileName(1),
    msoSortBySize(2),
    msoSortByFileType(3),
    msoSortByLastModified(4),
    msoSortByNone(5),
    ;

    private final int value;
    MsoSortBy(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
