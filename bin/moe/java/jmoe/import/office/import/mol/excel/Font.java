package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Font extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(180)
    @PropGet
    java.lang.Object background();

    @DISPID(180)
    @PropPut
    void background(
        java.lang.Object rhs);

    @DISPID(96)
    @PropGet
    java.lang.Object bold();

    @DISPID(96)
    @PropPut
    void bold(
        java.lang.Object rhs);

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

    @DISPID(177)
    @PropGet
    java.lang.Object fontStyle();

    @DISPID(177)
    @PropPut
    void fontStyle(
        java.lang.Object rhs);

    @DISPID(101)
    @PropGet
    java.lang.Object italic();

    @DISPID(101)
    @PropPut
    void italic(
        java.lang.Object rhs);

    @DISPID(110)
    @PropGet
    java.lang.Object name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.Object rhs);

    @DISPID(221)
    @PropGet
    java.lang.Object outlineFont();

    @DISPID(221)
    @PropPut
    void outlineFont(
        java.lang.Object rhs);

    @DISPID(103)
    @PropGet
    java.lang.Object shadow();

    @DISPID(103)
    @PropPut
    void shadow(
        java.lang.Object rhs);

    @DISPID(104)
    @PropGet
    java.lang.Object size();

    @DISPID(104)
    @PropPut
    void size(
        java.lang.Object rhs);

    @DISPID(105)
    @PropGet
    java.lang.Object strikethrough();

    @DISPID(105)
    @PropPut
    void strikethrough(
        java.lang.Object rhs);

    @DISPID(179)
    @PropGet
    java.lang.Object subscript();

    @DISPID(179)
    @PropPut
    void subscript(
        java.lang.Object rhs);

    @DISPID(178)
    @PropGet
    java.lang.Object superscript();

    @DISPID(178)
    @PropPut
    void superscript(
        java.lang.Object rhs);

    @DISPID(106)
    @PropGet
    java.lang.Object underline();

    @DISPID(106)
    @PropPut
    void underline(
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

    @DISPID(2367)
    @PropGet
    mol.excel.XlThemeFont themeFont();

    @DISPID(2367)
    @PropPut
    void themeFont(
        mol.excel.XlThemeFont rhs);

}
