package mol.office  ;

import com4j.*;

@IID("{000C170E-0000-0000-C000-000000000046}")
public interface IMsoTrendline extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    double backward();

    @VTID(9)
    void backward(
        double rhs);

    @VTID(10)
    mol.office.IMsoBorder border();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(12)
    mol.office.IMsoDataLabel dataLabel();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(14)
    boolean displayEquation();

    @VTID(15)
    void displayEquation(
        boolean rhs);

    @VTID(16)
    boolean displayRSquared();

    @VTID(17)
    void displayRSquared(
        boolean rhs);

    @VTID(18)
    double forward();

    @VTID(19)
    void forward(
        double rhs);

    @VTID(20)
    int index();

    @VTID(21)
    double intercept();

    @VTID(22)
    void intercept(
        double rhs);

    @VTID(23)
    boolean interceptIsAuto();

    @VTID(24)
    void interceptIsAuto(
        boolean rhs);

    @VTID(25)
    java.lang.String name();

    @VTID(26)
    void name(
        java.lang.String rhs);

    @VTID(27)
    boolean nameIsAuto();

    @VTID(28)
    void nameIsAuto(
        boolean rhs);

    @VTID(29)
    int order();

    @VTID(30)
    void order(
        int rhs);

    @VTID(31)
    int period();

    @VTID(32)
    void period(
        int rhs);

    @VTID(33)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(34)
    mol.office.XlTrendlineType type();

    @VTID(35)
    void type(
        mol.office.XlTrendlineType rhs);

    @VTID(36)
    mol.office.IMsoChartFormat format();

}
