package mol.office  ;

import com4j.*;

@IID("{000C0379-0000-0000-C000-000000000046}")
public interface SharedWorkspaceTask extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String title();

    @VTID(10)
    @DefaultMethod
    void title(
        java.lang.String title);

    @VTID(11)
    java.lang.String assignedTo();

    @VTID(12)
    void assignedTo(
        java.lang.String assignedTo);

    @VTID(13)
    mol.office.MsoSharedWorkspaceTaskStatus status();

    @VTID(14)
    void status(
        mol.office.MsoSharedWorkspaceTaskStatus status);

    @VTID(15)
    mol.office.MsoSharedWorkspaceTaskPriority priority();

    @VTID(16)
    void priority(
        mol.office.MsoSharedWorkspaceTaskPriority priority);

    @VTID(17)
    java.lang.String description();

    @VTID(18)
    void description(
        java.lang.String description);

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dueDate();

    @VTID(20)
    void dueDate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object dueDate);

    @VTID(21)
    java.lang.String createdBy();

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object createdDate();

    @VTID(23)
    java.lang.String modifiedBy();

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object modifiedDate();

    @VTID(25)
    void save();

    @VTID(26)
    void delete();

    @VTID(27)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
