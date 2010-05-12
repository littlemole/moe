package mol.office  ;

import com4j.*;

@IID("{000C0386-0000-0000-C000-000000000046}")
public interface Sync extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    mol.office.MsoSyncStatusType status();

    @VTID(10)
    java.lang.String workspaceLastChangedBy();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object lastSyncTime();

    @VTID(12)
    mol.office.MsoSyncErrorType errorType();

    @VTID(13)
    void getUpdate();

    @VTID(14)
    void putUpdate();

    @VTID(15)
    void openVersion(
        mol.office.MsoSyncVersionType syncVersionType);

    @VTID(16)
    void resolveConflict(
        mol.office.MsoSyncConflictResolutionType syncConflictResolution);

    @VTID(17)
    void unsuspend();

    @VTID(18)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
