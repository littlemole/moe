package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Border extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(99)
    @PropGet
    java.lang.Object color();

    @DISPID(99)
    @PropPut
    void color(
        java.lang.Object rhs);

    @DISPID(97)
    @PropGet
    java.lang.Object colorIndex();

    @DISPID(97)
    @PropPut
    void colorIndex(
        java.lang.Object rhs);

    @DISPID(119)
    @PropGet
    java.lang.Object lineStyle();

    @DISPID(119)
    @PropPut
    void lineStyle(
        java.lang.Object rhs);

    @DISPID(120)
    @PropGet
    java.lang.Object weight();

    @DISPID(120)
    @PropPut
    void weight(
        java.lang.Object rhs);

    @DISPID(2365)
    @PropGet
    java.lang.Object themeColor();

    @DISPID(2365)
    @PropPut
    void themeColor(
        java.lang.Object rhs);

    @DISPID(2366)
    @PropGet
    java.lang.Object tintAndShade();

    @DISPID(2366)
    @PropPut
    void tintAndShade(
        java.lang.Object rhs);

}
