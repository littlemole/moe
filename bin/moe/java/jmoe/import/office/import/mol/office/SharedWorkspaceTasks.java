package mol.office  ;

import com4j.*;

@IID("{000C037A-0000-0000-C000-000000000046}")
public interface SharedWorkspaceTasks extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    mol.office.SharedWorkspaceTask item(
        int index);

    @VTID(10)
    int count();

    @VTID(11)
    mol.office.SharedWorkspaceTask add(
        java.lang.String title,
        @MarshalAs(NativeType.VARIANT) java.lang.Object status,
        @MarshalAs(NativeType.VARIANT) java.lang.Object priority,
        @MarshalAs(NativeType.VARIANT) java.lang.Object assignee,
        @MarshalAs(NativeType.VARIANT) java.lang.Object description,
        @MarshalAs(NativeType.VARIANT) java.lang.Object dueDate);

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(13)
    boolean itemCountExceeded();

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

}
