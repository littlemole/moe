package mol.office  ;

import com4j.*;

public enum MsoSharedWorkspaceTaskPriority implements ComEnum {
    msoSharedWorkspaceTaskPriorityHigh(1),
    msoSharedWorkspaceTaskPriorityNormal(2),
    msoSharedWorkspaceTaskPriorityLow(3),
    ;

    private final int value;
    MsoSharedWorkspaceTaskPriority(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
