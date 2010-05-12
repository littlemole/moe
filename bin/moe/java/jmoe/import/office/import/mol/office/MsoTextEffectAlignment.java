package mol.office  ;

import com4j.*;

public enum MsoTextEffectAlignment implements ComEnum {
    msoTextEffectAlignmentMixed(-2),
    msoTextEffectAlignmentLeft(1),
    msoTextEffectAlignmentCentered(2),
    msoTextEffectAlignmentRight(3),
    msoTextEffectAlignmentLetterJustify(4),
    msoTextEffectAlignmentWordJustify(5),
    msoTextEffectAlignmentStretchJustify(6),
    ;

    private final int value;
    MsoTextEffectAlignment(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
