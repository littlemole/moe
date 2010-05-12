package mol.office  ;

import com4j.*;

@IID("{000C037B-0000-0000-C000-000000000046}")
public interface SharedWorkspaceFile extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String url();

    @VTID(10)
    java.lang.String createdBy();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object createdDate();

    @VTID(12)
    java.lang.String modifiedBy();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object modifiedDate();

    @VTID(14)
    void delete();

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
