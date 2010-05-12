package mol.word  ;

import com4j.*;

public enum WdSaveOptions implements ComEnum {
    wdDoNotSaveChanges(0),
    wdSaveChanges(-1),
    wdPromptToSaveChanges(-2),
    ;

    private final int value;
    WdSaveOptions(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
