package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Borders extends Com4jObject,Iterable<Com4jObject> {
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

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(170)
    @PropGet
    mol.excel.Border item(
        mol.excel.XlBordersIndex index);

    @DISPID(119)
    @PropGet
    java.lang.Object lineStyle();

    @DISPID(119)
    @PropPut
    void lineStyle(
        java.lang.Object rhs);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(6)
    @PropGet
    java.lang.Object value();

    @DISPID(6)
    @PropPut
    void value(
        java.lang.Object rhs);

    @DISPID(120)
    @PropGet
    java.lang.Object weight();

    @DISPID(120)
    @PropPut
    void weight(
        java.lang.Object rhs);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.Border _Default(
        mol.excel.XlBordersIndex index);

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
