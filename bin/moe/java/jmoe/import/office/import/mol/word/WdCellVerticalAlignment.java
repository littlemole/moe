package mol.word  ;

import com4j.*;

public enum WdCellVerticalAlignment implements ComEnum {
    wdCellAlignVerticalTop(0),
    wdCellAlignVerticalCenter(1),
    wdCellAlignVerticalBottom(3),
    ;

    private final int value;
    WdCellVerticalAlignment(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
