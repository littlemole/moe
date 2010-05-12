package mol.word  ;

import com4j.*;

public enum WdParagraphAlignment implements ComEnum {
    wdAlignParagraphLeft(0),
    wdAlignParagraphCenter(1),
    wdAlignParagraphRight(2),
    wdAlignParagraphJustify(3),
    wdAlignParagraphDistribute(4),
    wdAlignParagraphJustifyMed(5),
    wdAlignParagraphJustifyHi(7),
    wdAlignParagraphJustifyLow(8),
    wdAlignParagraphThaiJustify(9),
    ;

    private final int value;
    WdParagraphAlignment(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
