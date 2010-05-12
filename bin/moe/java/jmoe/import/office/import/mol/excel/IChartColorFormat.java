package mol.excel  ;

import com4j.*;

@IID("{00024436-0001-0000-C000-000000000046}")
public interface IChartColorFormat extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int schemeColor();

    @VTID(11)
    void schemeColor(
        int rhs);

    @VTID(12)
    int rgb();

    @VTID(13)
    @DefaultMethod
    int _Default();

    @VTID(14)
    int type();

}
