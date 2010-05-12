package mol.office  ;

import com4j.*;

public enum MsoParagraphAlignment implements ComEnum {
    msoAlignMixed(-2),
    msoAlignLeft(1),
    msoAlignCenter(2),
    msoAlignRight(3),
    msoAlignJustify(4),
    msoAlignDistribute(5),
    msoAlignThaiDistribute(6),
    msoAlignJustifyLow(7),
    ;

    private final int value;
    MsoParagraphAlignment(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
