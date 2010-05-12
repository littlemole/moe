package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface LegendKey extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(128)
    @PropGet
    mol.excel.Border border();

    @DISPID(112)
    java.lang.Object clearFormats();

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(129)
    @PropGet
    mol.excel.Interior interior();

    @DISPID(1663)
    @PropGet
    mol.excel.ChartFillFormat fill();

    @DISPID(132)
    @PropGet
    boolean invertIfNegative();

    @DISPID(132)
    @PropPut
    void invertIfNegative(
        boolean rhs);

    @DISPID(73)
    @PropGet
    int markerBackgroundColor();

    @DISPID(73)
    @PropPut
    void markerBackgroundColor(
        int rhs);

    @DISPID(74)
    @PropGet
    mol.excel.XlColorIndex markerBackgroundColorIndex();

    @DISPID(74)
    @PropPut
    void markerBackgroundColorIndex(
        mol.excel.XlColorIndex rhs);

    @DISPID(75)
    @PropGet
    int markerForegroundColor();

    @DISPID(75)
    @PropPut
    void markerForegroundColor(
        int rhs);

    @DISPID(76)
    @PropGet
    mol.excel.XlColorIndex markerForegroundColorIndex();

    @DISPID(76)
    @PropPut
    void markerForegroundColorIndex(
        mol.excel.XlColorIndex rhs);

    @DISPID(231)
    @PropGet
    int markerSize();

    @DISPID(231)
    @PropPut
    void markerSize(
        int rhs);

    @DISPID(72)
    @PropGet
    mol.excel.XlMarkerStyle markerStyle();

    @DISPID(72)
    @PropPut
    void markerStyle(
        mol.excel.XlMarkerStyle rhs);

    @DISPID(161)
    @PropGet
    int pictureType();

    @DISPID(161)
    @PropPut
    void pictureType(
        int rhs);

    @DISPID(162)
    @PropGet
    int pictureUnit();

    @DISPID(162)
    @PropPut
    void pictureUnit(
        int rhs);

    @DISPID(235)
    java.lang.Object select();

    @DISPID(163)
    @PropGet
    boolean smooth();

    @DISPID(163)
    @PropPut
    void smooth(
        boolean rhs);

    @DISPID(127)
    @PropGet
    double left();

    @DISPID(126)
    @PropGet
    double top();

    @DISPID(122)
    @PropGet
    double width();

    @DISPID(123)
    @PropGet
    double height();

    @DISPID(103)
    @PropGet
    boolean shadow();

    @DISPID(103)
    @PropPut
    void shadow(
        boolean rhs);

    @DISPID(2649)
    @PropGet
    double pictureUnit2();

    @DISPID(2649)
    @PropPut
    void pictureUnit2(
        double rhs);

    @DISPID(116)
    @PropGet
    mol.excel.ChartFormat format();

}
