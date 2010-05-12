package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Point extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(151)
    java.lang.Object _ApplyDataLabels(
        mol.excel.XlDataLabelsType type,
        java.lang.Object legendKey,
        java.lang.Object autoText,
        java.lang.Object hasLeaderLines);

    @DISPID(128)
    @PropGet
    mol.excel.Border border();

    @DISPID(112)
    java.lang.Object clearFormats();

    @DISPID(551)
    java.lang.Object copy();

    @DISPID(158)
    @PropGet
    mol.excel.DataLabel dataLabel();

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(182)
    @PropGet
    int explosion();

    @DISPID(182)
    @PropPut
    void explosion(
        int rhs);

    @DISPID(77)
    @PropGet
    boolean hasDataLabel();

    @DISPID(77)
    @PropPut
    void hasDataLabel(
        boolean rhs);

    @DISPID(129)
    @PropGet
    mol.excel.Interior interior();

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

    @DISPID(211)
    java.lang.Object paste();

    @DISPID(161)
    @PropGet
    mol.excel.XlChartPictureType pictureType();

    @DISPID(161)
    @PropPut
    void pictureType(
        mol.excel.XlChartPictureType rhs);

    @DISPID(162)
    @PropGet
    int pictureUnit();

    @DISPID(162)
    @PropPut
    void pictureUnit(
        int rhs);

    @DISPID(235)
    java.lang.Object select();

    @DISPID(1659)
    @PropGet
    boolean applyPictToSides();

    @DISPID(1659)
    @PropPut
    void applyPictToSides(
        boolean rhs);

    @DISPID(1660)
    @PropGet
    boolean applyPictToFront();

    @DISPID(1660)
    @PropPut
    void applyPictToFront(
        boolean rhs);

    @DISPID(1661)
    @PropGet
    boolean applyPictToEnd();

    @DISPID(1661)
    @PropPut
    void applyPictToEnd(
        boolean rhs);

    @DISPID(103)
    @PropGet
    boolean shadow();

    @DISPID(103)
    @PropPut
    void shadow(
        boolean rhs);

    @DISPID(1662)
    @PropGet
    boolean secondaryPlot();

    @DISPID(1662)
    @PropPut
    void secondaryPlot(
        boolean rhs);

    @DISPID(1663)
    @PropGet
    mol.excel.ChartFillFormat fill();

    @DISPID(1922)
    java.lang.Object applyDataLabels(
        mol.excel.XlDataLabelsType type,
        java.lang.Object legendKey,
        java.lang.Object autoText,
        java.lang.Object hasLeaderLines,
        java.lang.Object showSeriesName,
        java.lang.Object showCategoryName,
        java.lang.Object showValue,
        java.lang.Object showPercentage,
        java.lang.Object showBubbleSize,
        java.lang.Object separator);

    @DISPID(1665)
    @PropGet
    boolean has3DEffect();

    @DISPID(1665)
    @PropPut
    void has3DEffect(
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
