package mol.office  ;

import com4j.*;

@IID("{000C0387-0000-0000-C000-000000000046}")
public interface DocumentLibraryVersion extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object modified();

    @VTID(10)
    int index();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(12)
    java.lang.String modifiedBy();

    @VTID(13)
    java.lang.String comments();

    @VTID(14)
    void delete();

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject open();

    @VTID(16)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject restore();

}
