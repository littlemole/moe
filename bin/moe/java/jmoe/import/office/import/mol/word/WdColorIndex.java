package mol.word  ;

import com4j.*;

public enum WdColorIndex implements ComEnum {
    wdAuto(0),
    wdBlack(1),
    wdBlue(2),
    wdTurquoise(3),
    wdBrightGreen(4),
    wdPink(5),
    wdRed(6),
    wdYellow(7),
    wdWhite(8),
    wdDarkBlue(9),
    wdTeal(10),
    wdGreen(11),
    wdViolet(12),
    wdDarkRed(13),
    wdDarkYellow(14),
    wdGray50(15),
    wdGray25(16),
    wdByAuthor(-1),
    wdNoHighlight(0),
    ;

    private final int value;
    WdColorIndex(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
