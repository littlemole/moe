package mol.excel  ;

import com4j.*;

@IID("{0002086A-0001-0000-C000-000000000046}")
public interface IPoint extends Com4jObject {
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
    mol.excel.Border border();

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object copy();

    @VTID(14)
    mol.excel.DataLabel dataLabel();

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(16)
    int explosion();

    @VTID(17)
    void explosion(
        int rhs);

    @VTID(18)
    boolean hasDataLabel();

    @VTID(19)
    void hasDataLabel(
        boolean rhs);

    @VTID(20)
    mol.excel.Interior interior();

    @VTID(21)
    boolean invertIfNegative();

    @VTID(22)
    void invertIfNegative(
        boolean rhs);

    @VTID(23)
    int markerBackgroundColor();

    @VTID(24)
    void markerBackgroundColor(
        int rhs);

    @VTID(25)
    mol.excel.XlColorIndex markerBackgroundColorIndex();

    @VTID(26)
    void markerBackgroundColorIndex(
        mol.excel.XlColorIndex rhs);

    @VTID(27)
    int markerForegroundColor();

    @VTID(28)
    void markerForegroundColor(
        int rhs);

    @VTID(29)
    mol.excel.XlColorIndex markerForegroundColorIndex();

    @VTID(30)
    void markerForegroundColorIndex(
        mol.excel.XlColorIndex rhs);

    @VTID(31)
    int markerSize();

    @VTID(32)
    void markerSize(
        int rhs);

    @VTID(33)
    mol.excel.XlMarkerStyle markerStyle();

    @VTID(34)
    void markerStyle(
        mol.excel.XlMarkerStyle rhs);

    @VTID(35)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object paste();

    @VTID(36)
    mol.excel.XlChartPictureType pictureType();

    @VTID(37)
    void pictureType(
        mol.excel.XlChartPictureType rhs);

    @VTID(38)
    int pictureUnit();

    @VTID(39)
    void pictureUnit(
        int rhs);

    @VTID(40)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(41)
    boolean applyPictToSides();

    @VTID(42)
    void applyPictToSides(
        boolean rhs);

    @VTID(43)
    boolean applyPictToFront();

    @VTID(44)
    void applyPictToFront(
        boolean rhs);

    @VTID(45)
    boolean applyPictToEnd();

    @VTID(46)
    void applyPictToEnd(
        boolean rhs);

    @VTID(47)
    boolean shadow();

    @VTID(48)
    void shadow(
        boolean rhs);

    @VTID(49)
    boolean secondaryPlot();

    @VTID(50)
    void secondaryPlot(
        boolean rhs);

    @VTID(51)
    mol.excel.ChartFillFormat fill();

    @VTID(52)
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

    @VTID(53)
    boolean has3DEffect();

    @VTID(54)
    void has3DEffect(
        boolean rhs);

    @VTID(55)
    double pictureUnit2();

    @VTID(56)
    void pictureUnit2(
        double rhs);

    @VTID(57)
    mol.excel.ChartFormat format();

}
