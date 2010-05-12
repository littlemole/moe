package mol.office  ;

import com4j.*;

@IID("{000C037C-0000-0000-C000-000000000046}")
public interface SharedWorkspaceFiles extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(10)
    @DefaultMethod
    mol.office.SharedWorkspaceFile item(
        int index);

    @VTID(11)
    int count();

    @VTID(12)
    mol.office.SharedWorkspaceFile add(
        java.lang.String fileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object parentFolder,
        @MarshalAs(NativeType.VARIANT) java.lang.Object overwriteIfFileAlreadyExists,
        @MarshalAs(NativeType.VARIANT) java.lang.Object keepInSync);

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(14)
    boolean itemCountExceeded();

}
