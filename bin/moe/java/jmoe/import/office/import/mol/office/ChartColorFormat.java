package mol.office  ;

import com4j.*;

@IID("{000C171D-0000-0000-C000-000000000046}")
public interface ChartColorFormat extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    int schemeColor();

    @VTID(9)
    void schemeColor(
        int rhs);

    @VTID(10)
    int rgb();

    @VTID(11)
    void rgb(
        int rhs);

    @VTID(12)
    @DefaultMethod
    int _Default();

    @VTID(13)
    int type();

}
