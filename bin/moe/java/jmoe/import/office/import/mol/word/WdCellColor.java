package mol.word  ;

import com4j.*;

public enum WdCellColor implements ComEnum {
    wdCellColorByAuthor(-1),
    wdCellColorNoHighlight(0),
    wdCellColorPink(1),
    wdCellColorLightBlue(2),
    wdCellColorLightYellow(3),
    wdCellColorLightPurple(4),
    wdCellColorLightOrange(5),
    wdCellColorLightGreen(6),
    wdCellColorLightGray(7),
    ;

    private final int value;
    WdCellColor(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
