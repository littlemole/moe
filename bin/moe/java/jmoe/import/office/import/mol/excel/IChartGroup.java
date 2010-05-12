package mol.excel  ;

import com4j.*;

@IID("{00020859-0001-0000-C000-000000000046}")
public interface IChartGroup extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.XlAxisGroup axisGroup();

    @VTID(11)
    void axisGroup(
        mol.excel.XlAxisGroup rhs);

    @VTID(12)
    int doughnutHoleSize();

    @VTID(13)
    void doughnutHoleSize(
        int rhs);

    @VTID(14)
    mol.excel.DownBars downBars();

    @VTID(15)
    mol.excel.DropLines dropLines();

    @VTID(16)
    int firstSliceAngle();

    @VTID(17)
    void firstSliceAngle(
        int rhs);

    @VTID(18)
    int gapWidth();

    @VTID(19)
    void gapWidth(
        int rhs);

    @VTID(20)
    boolean hasDropLines();

    @VTID(21)
    void hasDropLines(
        boolean rhs);

    @VTID(22)
    boolean hasHiLoLines();

    @VTID(23)
    void hasHiLoLines(
        boolean rhs);

    @VTID(24)
    boolean hasRadarAxisLabels();

    @VTID(25)
    void hasRadarAxisLabels(
        boolean rhs);

    @VTID(26)
    boolean hasSeriesLines();

    @VTID(27)
    void hasSeriesLines(
        boolean rhs);

    @VTID(28)
    boolean hasUpDownBars();

    @VTID(29)
    void hasUpDownBars(
        boolean rhs);

    @VTID(30)
    mol.excel.HiLoLines hiLoLines();

    @VTID(31)
    int index();

    @VTID(32)
    int overlap();

    @VTID(33)
    void overlap(
        int rhs);

    @VTID(34)
    mol.excel.TickLabels radarAxisLabels();

    @VTID(35)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject seriesCollection(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(36)
    mol.excel.SeriesLines seriesLines();

    @VTID(37)
    int subType();

    @VTID(38)
    void subType(
        int rhs);

    @VTID(39)
    int type();

    @VTID(40)
    void type(
        int rhs);

    @VTID(41)
    mol.excel.UpBars upBars();

    @VTID(42)
    boolean varyByCategories();

    @VTID(43)
    void varyByCategories(
        boolean rhs);

    @VTID(44)
    mol.excel.XlSizeRepresents sizeRepresents();

    @VTID(45)
    void sizeRepresents(
        mol.excel.XlSizeRepresents rhs);

    @VTID(46)
    int bubbleScale();

    @VTID(47)
    void bubbleScale(
        int rhs);

    @VTID(48)
    boolean showNegativeBubbles();

    @VTID(49)
    void showNegativeBubbles(
        boolean rhs);

    @VTID(50)
    mol.excel.XlChartSplitType splitType();

    @VTID(51)
    void splitType(
        mol.excel.XlChartSplitType rhs);

    @VTID(52)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object splitValue();

    @VTID(53)
    void splitValue(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(54)
    int secondPlotSize();

    @VTID(55)
    void secondPlotSize(
        int rhs);

    @VTID(56)
    boolean has3DShading();

    @VTID(57)
    void has3DShading(
        boolean rhs);

}
