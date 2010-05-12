package mol.office  ;

import com4j.*;

@IID("{000C0390-0000-0000-C000-000000000046}")
public interface ServerPolicy extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    mol.office.PolicyItem item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(10)
    java.lang.String id();

    @VTID(11)
    java.lang.String name();

    @VTID(12)
    java.lang.String description();

    @VTID(13)
    java.lang.String statement();

    @VTID(14)
    int count();

    @VTID(15)
    boolean blockPreview();

    @VTID(16)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
