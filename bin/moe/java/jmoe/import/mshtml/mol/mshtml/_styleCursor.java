package mol.mshtml  ;

import com4j.*;

public enum _styleCursor implements ComEnum {
    styleCursorAuto(0),
    styleCursorCrosshair(1),
    styleCursorDefault(2),
    styleCursorHand(3),
    styleCursorMove(4),
    styleCursorE_resize(5),
    styleCursorNe_resize(6),
    styleCursorNw_resize(7),
    styleCursorN_resize(8),
    styleCursorSe_resize(9),
    styleCursorSw_resize(10),
    styleCursorS_resize(11),
    styleCursorW_resize(12),
    styleCursorText(13),
    styleCursorWait(14),
    styleCursorHelp(15),
    styleCursorPointer(16),
    styleCursorProgress(17),
    styleCursorNot_allowed(18),
    styleCursorNo_drop(19),
    styleCursorVertical_text(20),
    styleCursorall_scroll(21),
    styleCursorcol_resize(22),
    styleCursorrow_resize(23),
    styleCursorcustom(24),
    styleCursorNotSet(25),
    styleCursor_Max(2147483647),
    ;

    private final int value;
    _styleCursor(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
