package mol.office  ;

import com4j.*;

@IID("{000C0391-0000-0000-C000-000000000046}")
public interface PolicyItem extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String id();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    java.lang.String description();

    @VTID(12)
    java.lang.String data();

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
