package mol.word  ;

import com4j.*;

public enum WdNumberStyleWordBasicBiDi implements ComEnum {
    wdListNumberStyleBidi1(49),
    wdListNumberStyleBidi2(50),
    wdCaptionNumberStyleBidiLetter1(49),
    wdCaptionNumberStyleBidiLetter2(50),
    wdNoteNumberStyleBidiLetter1(49),
    wdNoteNumberStyleBidiLetter2(50),
    wdPageNumberStyleBidiLetter1(49),
    wdPageNumberStyleBidiLetter2(50),
    ;

    private final int value;
    WdNumberStyleWordBasicBiDi(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
