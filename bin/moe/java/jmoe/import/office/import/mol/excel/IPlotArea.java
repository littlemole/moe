package mol.excel  ;

import com4j.*;

@IID("{000208CB-0001-0000-C000-000000000046}")
public interface IPlotArea extends Com4jObject {
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
    java.lang.Object clearFormats();

    @VTID(14)
    double height();

    @VTID(15)
    void height(
        double rhs);

    @VTID(16)
    mol.excel.Interior interior();

    @VTID(17)
    mol.excel.ChartFillFormat fill();

    @VTID(18)
    double left();

    @VTID(19)
    void left(
        double rhs);

    @VTID(20)
    double top();

    @VTID(21)
    void top(
        double rhs);

    @VTID(22)
    double width();

    @VTID(23)
    void width(
        double rhs);

    @VTID(24)
    double _InsideLeft();

    @VTID(25)
    double _InsideTop();

    @VTID(26)
    double _InsideWidth();

    @VTID(27)
    double _InsideHeight();

    @VTID(28)
    double insideLeft();

    @VTID(29)
    void insideLeft(
        double rhs);

    @VTID(30)
    double insideTop();

    @VTID(31)
    void insideTop(
        double rhs);

    @VTID(32)
    double insideWidth();

    @VTID(33)
    void insideWidth(
        double rhs);

    @VTID(34)
    double insideHeight();

    @VTID(35)
    void insideHeight(
        double rhs);

    @VTID(36)
    mol.excel.XlChartElementPosition position();

    @VTID(37)
    void position(
        mol.excel.XlChartElementPosition rhs);

    @VTID(38)
    mol.excel.ChartFormat format();

}
