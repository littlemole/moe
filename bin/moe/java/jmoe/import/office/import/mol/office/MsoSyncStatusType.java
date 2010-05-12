package mol.office  ;

import com4j.*;

public enum MsoSyncStatusType implements ComEnum {
    msoSyncStatusNoSharedWorkspace(0),
    msoSyncStatusNotRoaming(0),
    msoSyncStatusLatest(1),
    msoSyncStatusNewerAvailable(2),
    msoSyncStatusLocalChanges(3),
    msoSyncStatusConflict(4),
    msoSyncStatusSuspended(5),
    msoSyncStatusError(6),
    ;

    private final int value;
    MsoSyncStatusType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
