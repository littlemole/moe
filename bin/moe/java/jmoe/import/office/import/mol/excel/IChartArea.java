package mol.excel  ;

import com4j.*;

@IID("{000208CC-0001-0000-C000-000000000046}")
public interface IChartArea extends Com4jObject {
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
    java.lang.Object clear();

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearContents();

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object copy();

    @VTID(16)
    mol.excel.Font font();

    @VTID(17)
    boolean shadow();

    @VTID(18)
    void shadow(
        boolean rhs);

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(20)
    double height();

    @VTID(21)
    void height(
        double rhs);

    @VTID(22)
    mol.excel.Interior interior();

    @VTID(23)
    mol.excel.ChartFillFormat fill();

    @VTID(24)
    double left();

    @VTID(25)
    void left(
        double rhs);

    @VTID(26)
    double top();

    @VTID(27)
    void top(
        double rhs);

    @VTID(28)
    double width();

    @VTID(29)
    void width(
        double rhs);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(31)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(32)
    mol.excel.ChartFormat format();

}
