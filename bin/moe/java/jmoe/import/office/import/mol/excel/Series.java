package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Series extends Com4jObject {
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

    @DISPID(47)
    @PropGet
    mol.excel.XlAxisGroup axisGroup();

    @DISPID(47)
    @PropPut
    void axisGroup(
        mol.excel.XlAxisGroup rhs);

    @DISPID(128)
    @PropGet
    mol.excel.Border border();

    @DISPID(112)
    java.lang.Object clearFormats();

    @DISPID(551)
    java.lang.Object copy();

    @DISPID(157)
    com4j.Com4jObject dataLabels(
        java.lang.Object index);

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(152)
    java.lang.Object errorBar(
        mol.excel.XlErrorBarDirection direction,
        mol.excel.XlErrorBarInclude include,
        mol.excel.XlErrorBarType type,
        java.lang.Object amount,
        java.lang.Object minusValues);

    @DISPID(159)
    @PropGet
    mol.excel.ErrorBars errorBars();

    @DISPID(182)
    @PropGet
    int explosion();

    @DISPID(182)
    @PropPut
    void explosion(
        int rhs);

    @DISPID(261)
    @PropGet
    java.lang.String formula();

    @DISPID(261)
    @PropPut
    void formula(
        java.lang.String rhs);

    @DISPID(263)
    @PropGet
    java.lang.String formulaLocal();

    @DISPID(263)
    @PropPut
    void formulaLocal(
        java.lang.String rhs);

    @DISPID(264)
    @PropGet
    java.lang.String formulaR1C1();

    @DISPID(264)
    @PropPut
    void formulaR1C1(
        java.lang.String rhs);

    @DISPID(265)
    @PropGet
    java.lang.String formulaR1C1Local();

    @DISPID(265)
    @PropPut
    void formulaR1C1Local(
        java.lang.String rhs);

    @DISPID(78)
    @PropGet
    boolean hasDataLabels();

    @DISPID(78)
    @PropPut
    void hasDataLabels(
        boolean rhs);

    @DISPID(160)
    @PropGet
    boolean hasErrorBars();

    @DISPID(160)
    @PropPut
    void hasErrorBars(
        boolean rhs);

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

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

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

    @DISPID(228)
    @PropGet
    int plotOrder();

    @DISPID(228)
    @PropPut
    void plotOrder(
        int rhs);

    @DISPID(70)
    com4j.Com4jObject points(
        java.lang.Object index);

    @DISPID(235)
    java.lang.Object select();

    @DISPID(163)
    @PropGet
    boolean smooth();

    @DISPID(163)
    @PropPut
    void smooth(
        boolean rhs);

    @DISPID(154)
    com4j.Com4jObject trendlines(
        java.lang.Object index);

    @DISPID(108)
    @PropGet
    int type();

    @DISPID(108)
    @PropPut
    void type(
        int rhs);

    @DISPID(1400)
    @PropGet
    mol.excel.XlChartType chartType();

    @DISPID(1400)
    @PropPut
    void chartType(
        mol.excel.XlChartType rhs);

    @DISPID(1401)
    void applyCustomType(
        mol.excel.XlChartType chartType);

    @DISPID(164)
    @PropGet
    java.lang.Object values();

    @DISPID(164)
    @PropPut
    void values(
        java.lang.Object rhs);

    @DISPID(1111)
    @PropGet
    java.lang.Object xValues();

    @DISPID(1111)
    @PropPut
    void xValues(
        java.lang.Object rhs);

    @DISPID(1664)
    @PropGet
    java.lang.Object bubbleSizes();

    @DISPID(1664)
    @PropPut
    void bubbleSizes(
        java.lang.Object rhs);

    @DISPID(1403)
    @PropGet
    mol.excel.XlBarShape barShape();

    @DISPID(1403)
    @PropPut
    void barShape(
        mol.excel.XlBarShape rhs);

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

    @DISPID(1665)
    @PropGet
    boolean has3DEffect();

    @DISPID(1665)
    @PropPut
    void has3DEffect(
        boolean rhs);

    @DISPID(103)
    @PropGet
    boolean shadow();

    @DISPID(103)
    @PropPut
    void shadow(
        boolean rhs);

    @DISPID(1394)
    @PropGet
    boolean hasLeaderLines();

    @DISPID(1394)
    @PropPut
    void hasLeaderLines(
        boolean rhs);

    @DISPID(1666)
    @PropGet
    mol.excel.LeaderLines leaderLines();

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
