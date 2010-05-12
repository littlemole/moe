package mol.office  ;

import com4j.*;

public enum MsoSharedWorkspaceTaskStatus implements ComEnum {
    msoSharedWorkspaceTaskStatusNotStarted(1),
    msoSharedWorkspaceTaskStatusInProgress(2),
    msoSharedWorkspaceTaskStatusCompleted(3),
    msoSharedWorkspaceTaskStatusDeferred(4),
    msoSharedWorkspaceTaskStatusWaiting(5),
    ;

    private final int value;
    MsoSharedWorkspaceTaskStatus(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
