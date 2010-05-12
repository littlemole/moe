package mol.excel  ;

import com4j.*;

@IID("{000244AF-0001-0000-C000-000000000046}")
public interface ILinearGradient extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.ColorStops colorStops();

    @VTID(11)
    double degree();

    @VTID(12)
    void degree(
        double rhs);

}
