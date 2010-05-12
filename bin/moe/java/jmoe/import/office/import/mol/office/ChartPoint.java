package mol.office  ;

import com4j.*;

@IID("{000C170C-0000-0000-C000-000000000046}")
public interface ChartPoint extends Com4jObject {
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
    mol.office.IMsoBorder border();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object copy();

    @VTID(12)
    mol.office.IMsoDataLabel dataLabel();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(14)
    int explosion();

    @VTID(15)
    void explosion(
        int rhs);

    @VTID(16)
    boolean hasDataLabel();

    @VTID(17)
    void hasDataLabel(
        boolean rhs);

    @VTID(18)
    mol.office.IMsoInterior interior();

    @VTID(19)
    boolean invertIfNegative();

    @VTID(20)
    void invertIfNegative(
        boolean rhs);

    @VTID(21)
    int markerBackgroundColor();

    @VTID(22)
    void markerBackgroundColor(
        int rhs);

    @VTID(23)
    mol.office.XlColorIndex markerBackgroundColorIndex();

    @VTID(24)
    void markerBackgroundColorIndex(
        mol.office.XlColorIndex rhs);

    @VTID(25)
    int markerForegroundColor();

    @VTID(26)
    void markerForegroundColor(
        int rhs);

    @VTID(27)
    mol.office.XlColorIndex markerForegroundColorIndex();

    @VTID(28)
    void markerForegroundColorIndex(
        mol.office.XlColorIndex rhs);

    @VTID(29)
    int markerSize();

    @VTID(30)
    void markerSize(
        int rhs);

    @VTID(31)
    mol.office.XlMarkerStyle markerStyle();

    @VTID(32)
    void markerStyle(
        mol.office.XlMarkerStyle rhs);

    @VTID(33)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object paste();

    @VTID(34)
    mol.office.XlChartPictureType pictureType();

    @VTID(35)
    void pictureType(
        mol.office.XlChartPictureType rhs);

    @VTID(36)
    double pictureUnit();

    @VTID(37)
    void pictureUnit(
        double rhs);

    @VTID(38)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(39)
    boolean applyPictToSides();

    @VTID(40)
    void applyPictToSides(
        boolean rhs);

    @VTID(41)
    boolean applyPictToFront();

    @VTID(42)
    void applyPictToFront(
        boolean rhs);

    @VTID(43)
    boolean applyPictToEnd();

    @VTID(44)
    void applyPictToEnd(
        boolean rhs);

    @VTID(45)
    boolean shadow();

    @VTID(46)
    void shadow(
        boolean rhs);

    @VTID(47)
    boolean secondaryPlot();

    @VTID(48)
    void secondaryPlot(
        boolean rhs);

    @VTID(49)
    mol.office.ChartFillFormat fill();

    @VTID(50)
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

    @VTID(51)
    boolean has3DEffect();

    @VTID(52)
    void has3DEffect(
        boolean rhs);

    @VTID(53)
    mol.office.IMsoChartFormat format();

}
