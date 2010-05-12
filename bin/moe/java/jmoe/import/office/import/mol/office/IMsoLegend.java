package mol.office  ;

import com4j.*;

@IID("{000C1710-0000-0000-C000-000000000046}")
public interface IMsoLegend extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    java.lang.String name();

    @VTID(9)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(10)
    mol.office.IMsoBorder border();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(12)
    mol.office.ChartFont font();

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject legendEntries(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    mol.office.XlLegendPosition position();

    @VTID(15)
    void position(
        mol.office.XlLegendPosition rhs);

    @VTID(16)
    boolean shadow();

    @VTID(17)
    void shadow(
        boolean rhs);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clear();

    @VTID(19)
    double height();

    @VTID(20)
    void height(
        double rhs);

    @VTID(21)
    mol.office.IMsoInterior interior();

    @VTID(22)
    mol.office.ChartFillFormat fill();

    @VTID(23)
    double left();

    @VTID(24)
    void left(
        double rhs);

    @VTID(25)
    double top();

    @VTID(26)
    void top(
        double rhs);

    @VTID(27)
    double width();

    @VTID(28)
    void width(
        double rhs);

    @VTID(29)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(30)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(31)
    boolean includeInLayout();

    @VTID(32)
    void includeInLayout(
        boolean rhs);

    @VTID(33)
    mol.office.IMsoChartFormat format();

}
