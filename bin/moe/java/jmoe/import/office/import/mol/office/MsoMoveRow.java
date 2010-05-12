package mol.office  ;

import com4j.*;

public enum MsoMoveRow implements ComEnum {
    msoMoveRowFirst(-4),
    msoMoveRowPrev(-3),
    msoMoveRowNext(-2),
    msoMoveRowNbr(-1),
    ;

    private final int value;
    MsoMoveRow(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
