package mol.office  ;

import com4j.*;

public enum MsoFileFindSortBy implements ComEnum {
    msoFileFindSortbyAuthor(1),
    msoFileFindSortbyDateCreated(2),
    msoFileFindSortbyLastSavedBy(3),
    msoFileFindSortbyDateSaved(4),
    msoFileFindSortbyFileName(5),
    msoFileFindSortbySize(6),
    msoFileFindSortbyTitle(7),
    ;

    private final int value;
    MsoFileFindSortBy(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
