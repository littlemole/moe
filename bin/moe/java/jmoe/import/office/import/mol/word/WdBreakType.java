package mol.word  ;

import com4j.*;

public enum WdBreakType implements ComEnum {
    wdSectionBreakNextPage(2),
    wdSectionBreakContinuous(3),
    wdSectionBreakEvenPage(4),
    wdSectionBreakOddPage(5),
    wdLineBreak(6),
    wdPageBreak(7),
    wdColumnBreak(8),
    wdLineBreakClearLeft(9),
    wdLineBreakClearRight(10),
    wdTextWrappingBreak(11),
    ;

    private final int value;
    WdBreakType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
