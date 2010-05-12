package mol.office  ;

import com4j.*;

@IID("{000C1531-0000-0000-C000-000000000046}")
public interface ODSOColumn extends mol.office._IMsoDispObj {
    @VTID(9)
    int index();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(12)
    java.lang.String value();

}
