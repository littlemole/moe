package mol.office  ;

import com4j.*;

@IID("{000C03A3-0000-0000-C000-000000000046}")
public interface ThemeFont extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String name();

    @VTID(10)
    @DefaultMethod
    void name(
        java.lang.String val);

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
