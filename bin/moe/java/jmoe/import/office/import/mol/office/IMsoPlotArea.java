package mol.office  ;

import com4j.*;

@IID("{000C1724-0000-0000-C000-000000000046}")
public interface IMsoPlotArea extends Com4jObject {
    @VTID(7)
    java.lang.String name();

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.IMsoBorder border();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(12)
    double height();

    @VTID(13)
    void height(
        double pd);

    @VTID(14)
    mol.office.IMsoInterior interior();

    @VTID(15)
    mol.office.ChartFillFormat fill();

    @VTID(16)
    double left();

    @VTID(17)
    void left(
        double pd);

    @VTID(18)
    double top();

    @VTID(19)
    void top(
        double pd);

    @VTID(20)
    double width();

    @VTID(21)
    void width(
        double pd);

    @VTID(22)
    double insideLeft();

    @VTID(23)
    void insideLeft(
        double pd);

    @VTID(24)
    double insideTop();

    @VTID(25)
    void insideTop(
        double pd);

    @VTID(26)
    double insideWidth();

    @VTID(27)
    void insideWidth(
        double pd);

    @VTID(28)
    double insideHeight();

    @VTID(29)
    void insideHeight(
        double pd);

    @VTID(30)
    mol.office.XlChartElementPosition position();

    @VTID(31)
    void position(
        mol.office.XlChartElementPosition pval);

    @VTID(32)
    mol.office.IMsoChartFormat format();

}
