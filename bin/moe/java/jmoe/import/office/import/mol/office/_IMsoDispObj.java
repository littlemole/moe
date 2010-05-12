package mol.office  ;

import com4j.*;

@IID("{000C0300-0000-0000-C000-000000000046}")
public interface _IMsoDispObj extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject application();

    @VTID(8)
    int creator();

}
