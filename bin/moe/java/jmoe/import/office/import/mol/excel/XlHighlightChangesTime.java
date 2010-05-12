package mol.excel  ;

import com4j.*;

public enum XlHighlightChangesTime implements ComEnum {
    xlSinceMyLastSave(1),
    xlAllChanges(2),
    xlNotYetReviewed(3),
    ;

    private final int value;
    XlHighlightChangesTime(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
