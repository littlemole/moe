package mol.office  ;

import com4j.*;

@IID("{000C03A6-0000-0000-C000-000000000046}")
public interface ThemeEffectScheme extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void load(
        java.lang.String fileName);

}
