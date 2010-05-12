package mol.office  ;

import com4j.*;

@IID("{000C170B-0000-0000-C000-000000000046}")
public interface IMsoSeries extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _ApplyDataLabels(
        mol.office.XlDataLabelsType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iMsoLegendKey,
        @MarshalAs(NativeType.VARIANT) java.lang.Object autoText,
        @MarshalAs(NativeType.VARIANT) java.lang.Object hasLeaderLines);

    @VTID(9)
    mol.office.XlAxisGroup axisGroup();

    @VTID(10)
    void axisGroup(
        mol.office.XlAxisGroup rhs);

    @VTID(11)
    mol.office.IMsoBorder border();

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object copy();

    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject dataLabels(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object errorBar(
        mol.office.XlErrorBarDirection direction,
        mol.office.XlErrorBarInclude include,
        mol.office.XlErrorBarType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object amount,
        @MarshalAs(NativeType.VARIANT) java.lang.Object minusValues);

    @VTID(17)
    mol.office.IMsoErrorBars errorBars();

    @VTID(18)
    int explosion();

    @VTID(19)
    void explosion(
        int rhs);

    @VTID(20)
    java.lang.String formula();

    @VTID(21)
    void formula(
        java.lang.String rhs);

    @VTID(22)
    java.lang.String formulaLocal();

    @VTID(23)
    void formulaLocal(
        java.lang.String rhs);

    @VTID(24)
    java.lang.String formulaR1C1();

    @VTID(25)
    void formulaR1C1(
        java.lang.String rhs);

    @VTID(26)
    java.lang.String formulaR1C1Local();

    @VTID(27)
    void formulaR1C1Local(
        java.lang.String rhs);

    @VTID(28)
    boolean hasDataLabels();

    @VTID(29)
    void hasDataLabels(
        boolean rhs);

    @VTID(30)
    boolean hasErrorBars();

    @VTID(31)
    void hasErrorBars(
        boolean rhs);

    @VTID(32)
    mol.office.IMsoInterior interior();

    @VTID(33)
    mol.office.ChartFillFormat fill();

    @VTID(34)
    boolean invertIfNegative();

    @VTID(35)
    void invertIfNegative(
        boolean rhs);

    @VTID(36)
    int markerBackgroundColor();

    @VTID(37)
    void markerBackgroundColor(
        int rhs);

    @VTID(38)
    mol.office.XlColorIndex markerBackgroundColorIndex();

    @VTID(39)
    void markerBackgroundColorIndex(
        mol.office.XlColorIndex rhs);

    @VTID(40)
    int markerForegroundColor();

    @VTID(41)
    void markerForegroundColor(
        int rhs);

    @VTID(42)
    mol.office.XlColorIndex markerForegroundColorIndex();

    @VTID(43)
    void markerForegroundColorIndex(
        mol.office.XlColorIndex rhs);

    @VTID(44)
    int markerSize();

    @VTID(45)
    void markerSize(
        int rhs);

    @VTID(46)
    mol.office.XlMarkerStyle markerStyle();

    @VTID(47)
    void markerStyle(
        mol.office.XlMarkerStyle rhs);

    @VTID(48)
    java.lang.String name();

    @VTID(49)
    void name(
        java.lang.String rhs);

    @VTID(50)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object paste();

    @VTID(51)
    mol.office.XlChartPictureType pictureType();

    @VTID(52)
    void pictureType(
        mol.office.XlChartPictureType rhs);

    @VTID(53)
    double pictureUnit();

    @VTID(54)
    void pictureUnit(
        double rhs);

    @VTID(55)
    int plotOrder();

    @VTID(56)
    void plotOrder(
        int rhs);

    @VTID(57)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject points(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(58)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(59)
    boolean smooth();

    @VTID(60)
    void smooth(
        boolean rhs);

    @VTID(61)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject trendlines(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(62)
    int type();

    @VTID(63)
    void type(
        int rhs);

    @VTID(64)
    mol.office.XlChartType chartType();

    @VTID(65)
    void chartType(
        mol.office.XlChartType rhs);

    @VTID(66)
    void applyCustomType(
        mol.office.XlChartType chartType);

    @VTID(67)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object values();

    @VTID(68)
    void values(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(69)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object xValues();

    @VTID(70)
    void xValues(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(71)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object bubbleSizes();

    @VTID(72)
    void bubbleSizes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(73)
    mol.office.XlBarShape barShape();

    @VTID(74)
    void barShape(
        mol.office.XlBarShape rhs);

    @VTID(75)
    boolean applyPictToSides();

    @VTID(76)
    void applyPictToSides(
        boolean rhs);

    @VTID(77)
    boolean applyPictToFront();

    @VTID(78)
    void applyPictToFront(
        boolean rhs);

    @VTID(79)
    boolean applyPictToEnd();

    @VTID(80)
    void applyPictToEnd(
        boolean rhs);

    @VTID(81)
    boolean has3DEffect();

    @VTID(82)
    void has3DEffect(
        boolean rhs);

    @VTID(83)
    boolean shadow();

    @VTID(84)
    void shadow(
        boolean rhs);

    @VTID(85)
    boolean hasLeaderLines();

    @VTID(86)
    void hasLeaderLines(
        boolean rhs);

    @VTID(87)
    mol.office.IMsoLeaderLines leaderLines();

    @VTID(88)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object applyDataLabels(
        mol.office.XlDataLabelsType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iMsoLegendKey,
        @MarshalAs(NativeType.VARIANT) java.lang.Object autoText,
        @MarshalAs(NativeType.VARIANT) java.lang.Object hasLeaderLines,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showSeriesName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showCategoryName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showValue,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showPercentage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showBubbleSize,
        @MarshalAs(NativeType.VARIANT) java.lang.Object separator);

    @VTID(89)
    mol.office.IMsoChartFormat format();

}
