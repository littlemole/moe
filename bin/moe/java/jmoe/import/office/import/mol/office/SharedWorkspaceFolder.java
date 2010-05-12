package mol.office  ;

import com4j.*;

@IID("{000C037D-0000-0000-C000-000000000046}")
public interface SharedWorkspaceFolder extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String folderName();

    @VTID(10)
    void delete(
        @MarshalAs(NativeType.VARIANT) java.lang.Object deleteEventIfFolderContainsFiles);

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
