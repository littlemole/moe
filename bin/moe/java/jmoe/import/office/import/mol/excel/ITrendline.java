package mol.excel  ;

import com4j.*;

@IID("{000208BE-0001-0000-C000-000000000046}")
public interface ITrendline extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int backward();

    @VTID(11)
    void backward(
        int rhs);

    @VTID(12)
    mol.excel.Border border();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(14)
    mol.excel.DataLabel dataLabel();

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(16)
    boolean displayEquation();

    @VTID(17)
    void displayEquation(
        boolean rhs);

    @VTID(18)
    boolean displayRSquared();

    @VTID(19)
    void displayRSquared(
        boolean rhs);

    @VTID(20)
    int forward();

    @VTID(21)
    void forward(
        int rhs);

    @VTID(22)
    int index();

    @VTID(23)
    double intercept();

    @VTID(24)
    void intercept(
        double rhs);

    @VTID(25)
    boolean interceptIsAuto();

    @VTID(26)
    void interceptIsAuto(
        boolean rhs);

    @VTID(27)
    java.lang.String name();

    @VTID(28)
    void name(
        java.lang.String rhs);

    @VTID(29)
    boolean nameIsAuto();

    @VTID(30)
    void nameIsAuto(
        boolean rhs);

    @VTID(31)
    int order();

    @VTID(32)
    void order(
        int rhs);

    @VTID(33)
    int period();

    @VTID(34)
    void period(
        int rhs);

    @VTID(35)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(36)
    mol.excel.XlTrendlineType type();

    @VTID(37)
    void type(
        mol.excel.XlTrendlineType rhs);

    @VTID(38)
    double backward2();

    @VTID(39)
    void backward2(
        double rhs);

    @VTID(40)
    double forward2();

    @VTID(41)
    void forward2(
        double rhs);

    @VTID(42)
    mol.excel.ChartFormat format();

}
