package mol.office  ;

import com4j.*;

@IID("{000C1728-0000-0000-C000-000000000046}")
public interface IMsoChartArea extends Com4jObject {
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
    java.lang.Object clear();

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearContents();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object copy();

    @VTID(14)
    mol.office.ChartFont font();

    @VTID(15)
    boolean shadow();

    @VTID(16)
    void shadow(
        boolean pf);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(18)
    double height();

    @VTID(19)
    void height(
        double pd);

    @VTID(20)
    mol.office.IMsoInterior interior();

    @VTID(21)
    mol.office.ChartFillFormat fill();

    @VTID(22)
    double left();

    @VTID(23)
    void left(
        double pd);

    @VTID(24)
    double top();

    @VTID(25)
    void top(
        double pd);

    @VTID(26)
    double width();

    @VTID(27)
    void width(
        double pd);

    @VTID(28)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(29)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pvar);

    @VTID(30)
    mol.office.IMsoChartFormat format();

}
