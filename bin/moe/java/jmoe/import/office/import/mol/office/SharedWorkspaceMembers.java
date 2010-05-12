package mol.office  ;

import com4j.*;

@IID("{000C0382-0000-0000-C000-000000000046}")
public interface SharedWorkspaceMembers extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(10)
    @DefaultMethod
    mol.office.SharedWorkspaceMember item(
        int index);

    @VTID(11)
    int count();

    @VTID(12)
    mol.office.SharedWorkspaceMember add(
        java.lang.String email,
        java.lang.String domainName,
        java.lang.String displayName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object role);

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(14)
    boolean itemCountExceeded();

}
