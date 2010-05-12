package mol.excel  ;

import com4j.*;

@IID("{0002086B-0001-0000-C000-000000000046}")
public interface ISeries extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _ApplyDataLabels(
        mol.excel.XlDataLabelsType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object legendKey,
        @MarshalAs(NativeType.VARIANT) java.lang.Object autoText,
        @MarshalAs(NativeType.VARIANT) java.lang.Object hasLeaderLines);

    @VTID(11)
    mol.excel.XlAxisGroup axisGroup();

    @VTID(12)
    void axisGroup(
        mol.excel.XlAxisGroup rhs);

    @VTID(13)
    mol.excel.Border border();

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object copy();

    @VTID(16)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject dataLabels(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object errorBar(
        mol.excel.XlErrorBarDirection direction,
        mol.excel.XlErrorBarInclude include,
        mol.excel.XlErrorBarType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object amount,
        @MarshalAs(NativeType.VARIANT) java.lang.Object minusValues);

    @VTID(19)
    mol.excel.ErrorBars errorBars();

    @VTID(20)
    int explosion();

    @VTID(21)
    void explosion(
        int rhs);

    @VTID(22)
    java.lang.String formula();

    @VTID(23)
    void formula(
        java.lang.String rhs);

    @VTID(24)
    java.lang.String formulaLocal();

    @VTID(25)
    void formulaLocal(
        java.lang.String rhs);

    @VTID(26)
    java.lang.String formulaR1C1();

    @VTID(27)
    void formulaR1C1(
        java.lang.String rhs);

    @VTID(28)
    java.lang.String formulaR1C1Local();

    @VTID(29)
    void formulaR1C1Local(
        java.lang.String rhs);

    @VTID(30)
    boolean hasDataLabels();

    @VTID(31)
    void hasDataLabels(
        boolean rhs);

    @VTID(32)
    boolean hasErrorBars();

    @VTID(33)
    void hasErrorBars(
        boolean rhs);

    @VTID(34)
    mol.excel.Interior interior();

    @VTID(35)
    mol.excel.ChartFillFormat fill();

    @VTID(36)
    boolean invertIfNegative();

    @VTID(37)
    void invertIfNegative(
        boolean rhs);

    @VTID(38)
    int markerBackgroundColor();

    @VTID(39)
    void markerBackgroundColor(
        int rhs);

    @VTID(40)
    mol.excel.XlColorIndex markerBackgroundColorIndex();

    @VTID(41)
    void markerBackgroundColorIndex(
        mol.excel.XlColorIndex rhs);

    @VTID(42)
    int markerForegroundColor();

    @VTID(43)
    void markerForegroundColor(
        int rhs);

    @VTID(44)
    mol.excel.XlColorIndex markerForegroundColorIndex();

    @VTID(45)
    void markerForegroundColorIndex(
        mol.excel.XlColorIndex rhs);

    @VTID(46)
    int markerSize();

    @VTID(47)
    void markerSize(
        int rhs);

    @VTID(48)
    mol.excel.XlMarkerStyle markerStyle();

    @VTID(49)
    void markerStyle(
        mol.excel.XlMarkerStyle rhs);

    @VTID(50)
    java.lang.String name();

    @VTID(51)
    void name(
        java.lang.String rhs);

    @VTID(52)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object paste();

    @VTID(53)
    mol.excel.XlChartPictureType pictureType();

    @VTID(54)
    void pictureType(
        mol.excel.XlChartPictureType rhs);

    @VTID(55)
    int pictureUnit();

    @VTID(56)
    void pictureUnit(
        int rhs);

    @VTID(57)
    int plotOrder();

    @VTID(58)
    void plotOrder(
        int rhs);

    @VTID(59)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject points(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(60)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(61)
    boolean smooth();

    @VTID(62)
    void smooth(
        boolean rhs);

    @VTID(63)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject trendlines(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(64)
    int type();

    @VTID(65)
    void type(
        int rhs);

    @VTID(66)
    mol.excel.XlChartType chartType();

    @VTID(67)
    void chartType(
        mol.excel.XlChartType rhs);

    @VTID(68)
    void applyCustomType(
        mol.excel.XlChartType chartType);

    @VTID(69)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object values();

    @VTID(70)
    void values(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(71)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object xValues();

    @VTID(72)
    void xValues(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(73)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object bubbleSizes();

    @VTID(74)
    void bubbleSizes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(75)
    mol.excel.XlBarShape barShape();

    @VTID(76)
    void barShape(
        mol.excel.XlBarShape rhs);

    @VTID(77)
    boolean applyPictToSides();

    @VTID(78)
    void applyPictToSides(
        boolean rhs);

    @VTID(79)
    boolean applyPictToFront();

    @VTID(80)
    void applyPictToFront(
        boolean rhs);

    @VTID(81)
    boolean applyPictToEnd();

    @VTID(82)
    void applyPictToEnd(
        boolean rhs);

    @VTID(83)
    boolean has3DEffect();

    @VTID(84)
    void has3DEffect(
        boolean rhs);

    @VTID(85)
    boolean shadow();

    @VTID(86)
    void shadow(
        boolean rhs);

    @VTID(87)
    boolean hasLeaderLines();

    @VTID(88)
    void hasLeaderLines(
        boolean rhs);

    @VTID(89)
    mol.excel.LeaderLines leaderLines();

    @VTID(90)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object applyDataLabels(
        mol.excel.XlDataLabelsType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object legendKey,
        @MarshalAs(NativeType.VARIANT) java.lang.Object autoText,
        @MarshalAs(NativeType.VARIANT) java.lang.Object hasLeaderLines,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showSeriesName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showCategoryName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showValue,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showPercentage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showBubbleSize,
        @MarshalAs(NativeType.VARIANT) java.lang.Object separator);

    @VTID(91)
    double pictureUnit2();

    @VTID(92)
    void pictureUnit2(
        double rhs);

    @VTID(93)
    mol.excel.ChartFormat format();

}
