package mol.word  ;

import com4j.*;

public enum WdHeaderFooterIndex implements ComEnum {
    wdHeaderFooterPrimary(1),
    wdHeaderFooterFirstPage(2),
    wdHeaderFooterEvenPages(3),
    ;

    private final int value;
    WdHeaderFooterIndex(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
