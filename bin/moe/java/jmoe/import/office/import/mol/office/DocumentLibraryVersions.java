package mol.office  ;

import com4j.*;

@IID("{000C0388-0000-0000-C000-000000000046}")
public interface DocumentLibraryVersions extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    mol.office.DocumentLibraryVersion item(
        int lIndex);

    @VTID(10)
    int count();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(12)
    boolean isVersioningEnabled();

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

}
