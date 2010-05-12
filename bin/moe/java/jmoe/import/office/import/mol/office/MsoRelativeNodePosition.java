package mol.office  ;

import com4j.*;

public enum MsoRelativeNodePosition implements ComEnum {
    msoBeforeNode(1),
    msoAfterNode(2),
    msoBeforeFirstSibling(3),
    msoAfterLastSibling(4),
    ;

    private final int value;
    MsoRelativeNodePosition(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
