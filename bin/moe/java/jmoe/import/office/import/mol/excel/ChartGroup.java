package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ChartGroup extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(47)
    @PropGet
    mol.excel.XlAxisGroup axisGroup();

    @DISPID(47)
    @PropPut
    void axisGroup(
        mol.excel.XlAxisGroup rhs);

    @DISPID(1126)
    @PropGet
    int doughnutHoleSize();

    @DISPID(1126)
    @PropPut
    void doughnutHoleSize(
        int rhs);

    @DISPID(141)
    @PropGet
    mol.excel.DownBars downBars();

    @DISPID(142)
    @PropGet
    mol.excel.DropLines dropLines();

    @DISPID(63)
    @PropGet
    int firstSliceAngle();

    @DISPID(63)
    @PropPut
    void firstSliceAngle(
        int rhs);

    @DISPID(51)
    @PropGet
    int gapWidth();

    @DISPID(51)
    @PropPut
    void gapWidth(
        int rhs);

    @DISPID(61)
    @PropGet
    boolean hasDropLines();

    @DISPID(61)
    @PropPut
    void hasDropLines(
        boolean rhs);

    @DISPID(62)
    @PropGet
    boolean hasHiLoLines();

    @DISPID(62)
    @PropPut
    void hasHiLoLines(
        boolean rhs);

    @DISPID(64)
    @PropGet
    boolean hasRadarAxisLabels();

    @DISPID(64)
    @PropPut
    void hasRadarAxisLabels(
        boolean rhs);

    @DISPID(65)
    @PropGet
    boolean hasSeriesLines();

    @DISPID(65)
    @PropPut
    void hasSeriesLines(
        boolean rhs);

    @DISPID(66)
    @PropGet
    boolean hasUpDownBars();

    @DISPID(66)
    @PropPut
    void hasUpDownBars(
        boolean rhs);

    @DISPID(143)
    @PropGet
    mol.excel.HiLoLines hiLoLines();

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(56)
    @PropGet
    int overlap();

    @DISPID(56)
    @PropPut
    void overlap(
        int rhs);

    @DISPID(144)
    @PropGet
    mol.excel.TickLabels radarAxisLabels();

    @DISPID(68)
    com4j.Com4jObject seriesCollection(
        java.lang.Object index);

    @DISPID(145)
    @PropGet
    mol.excel.SeriesLines seriesLines();

    @DISPID(109)
    @PropGet
    int subType();

    @DISPID(109)
    @PropPut
    void subType(
        int rhs);

    @DISPID(108)
    @PropGet
    int type();

    @DISPID(108)
    @PropPut
    void type(
        int rhs);

    @DISPID(140)
    @PropGet
    mol.excel.UpBars upBars();

    @DISPID(60)
    @PropGet
    boolean varyByCategories();

    @DISPID(60)
    @PropPut
    void varyByCategories(
        boolean rhs);

    @DISPID(1652)
    @PropGet
    mol.excel.XlSizeRepresents sizeRepresents();

    @DISPID(1652)
    @PropPut
    void sizeRepresents(
        mol.excel.XlSizeRepresents rhs);

    @DISPID(1653)
    @PropGet
    int bubbleScale();

    @DISPID(1653)
    @PropPut
    void bubbleScale(
        int rhs);

    @DISPID(1654)
    @PropGet
    boolean showNegativeBubbles();

    @DISPID(1654)
    @PropPut
    void showNegativeBubbles(
        boolean rhs);

    @DISPID(1655)
    @PropGet
    mol.excel.XlChartSplitType splitType();

    @DISPID(1655)
    @PropPut
    void splitType(
        mol.excel.XlChartSplitType rhs);

    @DISPID(1656)
    @PropGet
    java.lang.Object splitValue();

    @DISPID(1656)
    @PropPut
    void splitValue(
        java.lang.Object rhs);

    @DISPID(1657)
    @PropGet
    int secondPlotSize();

    @DISPID(1657)
    @PropPut
    void secondPlotSize(
        int rhs);

    @DISPID(1658)
    @PropGet
    boolean has3DShading();

    @DISPID(1658)
    @PropPut
    void has3DShading(
        boolean rhs);

}
