package mol.office  ;

import com4j.*;

@IID("{000C171A-0000-0000-C000-000000000046}")
public interface LegendEntry extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(9)
    mol.office.ChartFont font();

    @VTID(10)
    int index();

    @VTID(11)
    mol.office.IMsoLegendKey legendKey();

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(14)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(15)
    double left();

    @VTID(16)
    double top();

    @VTID(17)
    double width();

    @VTID(18)
    double height();

    @VTID(19)
    mol.office.IMsoChartFormat format();

}
