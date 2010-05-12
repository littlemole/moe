package mol.office  ;

import com4j.*;

public enum MsoTextTabAlign implements ComEnum {
    msoTabAlignMixed(-2),
    msoTabAlignLeft(0),
    msoTabAlignCenter(1),
    msoTabAlignRight(2),
    msoTabAlignDecimal(3),
    ;

    private final int value;
    MsoTextTabAlign(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
