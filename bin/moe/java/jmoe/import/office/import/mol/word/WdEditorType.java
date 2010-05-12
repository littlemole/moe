package mol.word  ;

import com4j.*;

public enum WdEditorType implements ComEnum {
    wdEditorEveryone(-1),
    wdEditorOwners(-4),
    wdEditorEditors(-5),
    wdEditorCurrent(-6),
    ;

    private final int value;
    WdEditorType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
