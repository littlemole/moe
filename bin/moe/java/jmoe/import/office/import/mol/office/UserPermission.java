package mol.office  ;

import com4j.*;

@IID("{000C0375-0000-0000-C000-000000000046}")
public interface UserPermission extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String userId();

    @VTID(10)
    int permission();

    @VTID(11)
    void permission(
        int permission);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object expirationDate();

    @VTID(13)
    void expirationDate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object expirationDate);

    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(15)
    void remove();

}
