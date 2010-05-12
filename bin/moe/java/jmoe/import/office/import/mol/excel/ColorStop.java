package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ColorStop extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(117)
    void delete();

    @DISPID(99)
    @PropGet
    java.lang.Object color();

    @DISPID(99)
    @PropPut
    void color(
        java.lang.Object rhs);

    @DISPID(2365)
    @PropGet
    int themeColor();

    @DISPID(2365)
    @PropPut
    void themeColor(
        int rhs);

    @DISPID(2366)
    @PropGet
    java.lang.Object tintAndShade();

    @DISPID(2366)
    @PropPut
    void tintAndShade(
        java.lang.Object rhs);

    @DISPID(133)
    @PropGet
    double position();

    @DISPID(133)
    @PropPut
    void position(
        double rhs);

}
