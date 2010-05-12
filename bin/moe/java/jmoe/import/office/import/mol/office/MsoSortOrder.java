package mol.office  ;

import com4j.*;

public enum MsoSortOrder implements ComEnum {
    msoSortOrderAscending(1),
    msoSortOrderDescending(2),
    ;

    private final int value;
    MsoSortOrder(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
