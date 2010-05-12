package mol.office  ;

import com4j.*;

@IID("{000C0395-0000-0000-C000-000000000046}")
public interface IRibbonControl extends Com4jObject {
    @VTID(7)
    java.lang.String id();

    @VTID(8)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject context();

    @VTID(9)
    java.lang.String tag();

}
