package mol.word  ;

import com4j.*;

public enum WdNumberType implements ComEnum {
    wdNumberParagraph(1),
    wdNumberListNum(2),
    wdNumberAllNumbers(3),
    ;

    private final int value;
    WdNumberType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
