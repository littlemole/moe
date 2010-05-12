package mol.mshtml  ;

import com4j.*;

public enum _DISPLAY_MOVEUNIT implements ComEnum {
    DISPLAY_MOVEUNIT_PreviousLine(1),
    DISPLAY_MOVEUNIT_NextLine(2),
    DISPLAY_MOVEUNIT_CurrentLineStart(3),
    DISPLAY_MOVEUNIT_CurrentLineEnd(4),
    DISPLAY_MOVEUNIT_TopOfWindow(5),
    DISPLAY_MOVEUNIT_BottomOfWindow(6),
    DISPLAY_MOVEUNIT_Max(2147483647),
    ;

    private final int value;
    _DISPLAY_MOVEUNIT(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
