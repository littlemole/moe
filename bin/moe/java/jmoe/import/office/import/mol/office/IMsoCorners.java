package mol.office  ;

import com4j.*;

@IID("{000C1714-0000-0000-C000-000000000046}")
public interface IMsoCorners extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    java.lang.String name();

    @VTID(9)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

}
