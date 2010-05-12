package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Trendline extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(185)
    @PropGet
    int backward();

    @DISPID(185)
    @PropPut
    void backward(
        int rhs);

    @DISPID(128)
    @PropGet
    mol.excel.Border border();

    @DISPID(112)
    java.lang.Object clearFormats();

    @DISPID(158)
    @PropGet
    mol.excel.DataLabel dataLabel();

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(190)
    @PropGet
    boolean displayEquation();

    @DISPID(190)
    @PropPut
    void displayEquation(
        boolean rhs);

    @DISPID(189)
    @PropGet
    boolean displayRSquared();

    @DISPID(189)
    @PropPut
    void displayRSquared(
        boolean rhs);

    @DISPID(191)
    @PropGet
    int forward();

    @DISPID(191)
    @PropPut
    void forward(
        int rhs);

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(186)
    @PropGet
    double intercept();

    @DISPID(186)
    @PropPut
    void intercept(
        double rhs);

    @DISPID(187)
    @PropGet
    boolean interceptIsAuto();

    @DISPID(187)
    @PropPut
    void interceptIsAuto(
        boolean rhs);

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(188)
    @PropGet
    boolean nameIsAuto();

    @DISPID(188)
    @PropPut
    void nameIsAuto(
        boolean rhs);

    @DISPID(192)
    @PropGet
    int order();

    @DISPID(192)
    @PropPut
    void order(
        int rhs);

    @DISPID(184)
    @PropGet
    int period();

    @DISPID(184)
    @PropPut
    void period(
        int rhs);

    @DISPID(235)
    java.lang.Object select();

    @DISPID(108)
    @PropGet
    mol.excel.XlTrendlineType type();

    @DISPID(108)
    @PropPut
    void type(
        mol.excel.XlTrendlineType rhs);

    @DISPID(2650)
    @PropGet
    double backward2();

    @DISPID(2650)
    @PropPut
    void backward2(
        double rhs);

    @DISPID(2651)
    @PropGet
    double forward2();

    @DISPID(2651)
    @PropPut
    void forward2(
        double rhs);

    @DISPID(116)
    @PropGet
    mol.excel.ChartFormat format();

}
