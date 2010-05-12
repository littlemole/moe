package mol.excel  ;

import com4j.*;

@IID("{000208CD-0001-0000-C000-000000000046}")
public interface ILegend extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(12)
    mol.excel.Border border();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(14)
    mol.excel.Font font();

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject legendEntries(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(16)
    mol.excel.XlLegendPosition position();

    @VTID(17)
    void position(
        mol.excel.XlLegendPosition rhs);

    @VTID(18)
    boolean shadow();

    @VTID(19)
    void shadow(
        boolean rhs);

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clear();

    @VTID(21)
    double height();

    @VTID(22)
    void height(
        double rhs);

    @VTID(23)
    mol.excel.Interior interior();

    @VTID(24)
    mol.excel.ChartFillFormat fill();

    @VTID(25)
    double left();

    @VTID(26)
    void left(
        double rhs);

    @VTID(27)
    double top();

    @VTID(28)
    void top(
        double rhs);

    @VTID(29)
    double width();

    @VTID(30)
    void width(
        double rhs);

    @VTID(31)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(32)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(33)
    boolean includeInLayout();

    @VTID(34)
    void includeInLayout(
        boolean rhs);

    @VTID(35)
    mol.excel.ChartFormat format();

}
