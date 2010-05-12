package mol.office  ;

import com4j.*;

@IID("{000C037E-0000-0000-C000-000000000046}")
public interface SharedWorkspaceFolders extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(10)
    @DefaultMethod
    mol.office.SharedWorkspaceFolder item(
        int index);

    @VTID(11)
    int count();

    @VTID(12)
    mol.office.SharedWorkspaceFolder add(
        java.lang.String folderName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object parentFolder);

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(14)
    boolean itemCountExceeded();

}
