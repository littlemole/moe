package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Interior extends Com4jObject {
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

    @DISPID(132)
    @PropGet
    java.lang.Object invertIfNegative();

    @DISPID(132)
    @PropPut
    void invertIfNegative(
        java.lang.Object rhs);

    @DISPID(95)
    @PropGet
    java.lang.Object pattern();

    @DISPID(95)
    @PropPut
    void pattern(
        java.lang.Object rhs);

    @DISPID(100)
    @PropGet
    java.lang.Object patternColor();

    @DISPID(100)
    @PropPut
    void patternColor(
        java.lang.Object rhs);

    @DISPID(98)
    @PropGet
    java.lang.Object patternColorIndex();

    @DISPID(98)
    @PropPut
    void patternColorIndex(
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

    @DISPID(2643)
    @PropGet
    java.lang.Object patternThemeColor();

    @DISPID(2643)
    @PropPut
    void patternThemeColor(
        java.lang.Object rhs);

    @DISPID(2644)
    @PropGet
    java.lang.Object patternTintAndShade();

    @DISPID(2644)
    @PropPut
    void patternTintAndShade(
        java.lang.Object rhs);

    @DISPID(2645)
    @PropGet
    com4j.Com4jObject gradient();

}
