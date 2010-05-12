package mol.excel  ;

import com4j.*;

@IID("{000208BA-0001-0000-C000-000000000046}")
public interface ILegendEntry extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(11)
    mol.excel.Font font();

    @VTID(12)
    int index();

    @VTID(13)
    mol.excel.LegendKey legendKey();

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(16)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(17)
    double left();

    @VTID(18)
    double top();

    @VTID(19)
    double width();

    @VTID(20)
    double height();

    @VTID(21)
    mol.excel.ChartFormat format();

}
