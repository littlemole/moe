package mol.mshtml  ;

import com4j.*;

public enum _styleDisplay implements ComEnum {
    styleDisplayNotSet(0),
    styleDisplayBlock(1),
    styleDisplayInline(2),
    styleDisplayListItem(3),
    styleDisplayNone(4),
    styleDisplayTableHeaderGroup(5),
    styleDisplayTableFooterGroup(6),
    styleDisplayInlineBlock(7),
    styleDisplay_Max(2147483647),
    ;

    private final int value;
    _styleDisplay(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
