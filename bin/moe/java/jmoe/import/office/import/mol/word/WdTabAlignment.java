package mol.word  ;

import com4j.*;

public enum WdTabAlignment implements ComEnum {
    wdAlignTabLeft(0),
    wdAlignTabCenter(1),
    wdAlignTabRight(2),
    wdAlignTabDecimal(3),
    wdAlignTabBar(4),
    wdAlignTabList(6),
    ;

    private final int value;
    WdTabAlignment(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
