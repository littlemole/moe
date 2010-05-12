package mol.office  ;

import com4j.*;

@IID("{000C1727-0000-0000-C000-000000000046}")
public interface IMsoChartGroup extends Com4jObject {
    @VTID(7)
    void axisGroup(
        int piGroup);

    @VTID(8)
    int axisGroup();

    @VTID(9)
    void doughnutHoleSize(
        int pDoughnutHoleSize);

    @VTID(10)
    int doughnutHoleSize();

    @VTID(11)
    mol.office.IMsoDownBars downBars();

    @VTID(12)
    mol.office.IMsoDropLines dropLines();

    @VTID(13)
    void firstSliceAngle(
        int pFirstSliceAngle);

    @VTID(14)
    int firstSliceAngle();

    @VTID(15)
    void gapWidth(
        int pGapWidth);

    @VTID(16)
    int gapWidth();

    @VTID(17)
    void hasDropLines(
        boolean pfHasDropLines);

    @VTID(18)
    boolean hasDropLines();

    @VTID(19)
    void hasHiLoLines(
        boolean pfHasHiLoLines);

    @VTID(20)
    boolean hasHiLoLines();

    @VTID(21)
    void hasRadarAxisLabels(
        boolean pfHasRadarAxisLabels);

    @VTID(22)
    boolean hasRadarAxisLabels();

    @VTID(23)
    void hasSeriesLines(
        boolean pfHasSeriesLines);

    @VTID(24)
    boolean hasSeriesLines();

    @VTID(25)
    void hasUpDownBars(
        boolean pfHasUpDownBars);

    @VTID(26)
    boolean hasUpDownBars();

    @VTID(27)
    mol.office.IMsoHiLoLines hiLoLines();

    @VTID(28)
    int index();

    @VTID(29)
    void overlap(
        int pOverlap);

    @VTID(30)
    int overlap();

    @VTID(31)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject radarAxisLabels();

    @VTID(32)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject seriesCollection(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(33)
    mol.office.IMsoSeriesLines seriesLines();

    @VTID(34)
    void subType(
        int pSubType);

    @VTID(35)
    int subType();

    @VTID(36)
    void type(
        int ptype);

    @VTID(37)
    int type();

    @VTID(38)
    mol.office.IMsoUpBars upBars();

    @VTID(39)
    void varyByCategories(
        boolean pfVaryByCategories);

    @VTID(40)
    boolean varyByCategories();

    @VTID(41)
    mol.office.XlSizeRepresents sizeRepresents();

    @VTID(42)
    void sizeRepresents(
        mol.office.XlSizeRepresents pXlSizeRepresents);

    @VTID(43)
    void bubbleScale(
        int pbubblescale);

    @VTID(44)
    int bubbleScale();

    @VTID(45)
    void showNegativeBubbles(
        boolean pfShowNegativeBubbles);

    @VTID(46)
    boolean showNegativeBubbles();

    @VTID(47)
    void splitType(
        mol.office.XlChartSplitType pChartSplitType);

    @VTID(48)
    mol.office.XlChartSplitType splitType();

    @VTID(49)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object splitValue();

    @VTID(50)
    void splitValue(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pSplitValue);

    @VTID(51)
    int secondPlotSize();

    @VTID(52)
    void secondPlotSize(
        int pSecondPlotSize);

    @VTID(53)
    boolean has3DShading();

    @VTID(54)
    void has3DShading(
        boolean rhs);

}
