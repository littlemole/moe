package mol.office  ;

import com4j.*;

@IID("{000C1720-0000-0000-C000-000000000046}")
public interface IMsoDataLabel extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    java.lang.String name();

    @VTID(9)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(10)
    mol.office.IMsoBorder border();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(12)
    mol.office.IMsoInterior interior();

    @VTID(13)
    mol.office.ChartFillFormat fill();

    @VTID(14)
    java.lang.String caption();

    @VTID(15)
    void caption(
        java.lang.String rhs);

    @VTID(16)
    mol.office.IMsoCharacters characters(
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object length);

    @VTID(17)
    mol.office.ChartFont font();

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object horizontalAlignment();

    @VTID(19)
    void horizontalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(20)
    double left();

    @VTID(21)
    void left(
        double rhs);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object orientation();

    @VTID(23)
    void orientation(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(24)
    boolean shadow();

    @VTID(25)
    void shadow(
        boolean rhs);

    @VTID(26)
    java.lang.String text();

    @VTID(27)
    void text(
        java.lang.String rhs);

    @VTID(28)
    double top();

    @VTID(29)
    void top(
        double rhs);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object verticalAlignment();

    @VTID(31)
    void verticalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(32)
    int readingOrder();

    @VTID(33)
    void readingOrder(
        int rhs);

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(35)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(36)
    boolean autoText();

    @VTID(37)
    void autoText(
        boolean rhs);

    @VTID(38)
    java.lang.String numberFormat();

    @VTID(39)
    void numberFormat(
        java.lang.String rhs);

    @VTID(40)
    boolean numberFormatLinked();

    @VTID(41)
    void numberFormatLinked(
        boolean rhs);

    @VTID(42)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object numberFormatLocal();

    @VTID(43)
    void numberFormatLocal(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(44)
    boolean showLegendKey();

    @VTID(45)
    void showLegendKey(
        boolean rhs);

    @VTID(46)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object type();

    @VTID(47)
    void type(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(48)
    mol.office.XlDataLabelPosition position();

    @VTID(49)
    void position(
        mol.office.XlDataLabelPosition rhs);

    @VTID(50)
    boolean showSeriesName();

    @VTID(51)
    void showSeriesName(
        boolean rhs);

    @VTID(52)
    boolean showCategoryName();

    @VTID(53)
    void showCategoryName(
        boolean rhs);

    @VTID(54)
    boolean showValue();

    @VTID(55)
    void showValue(
        boolean rhs);

    @VTID(56)
    boolean showPercentage();

    @VTID(57)
    void showPercentage(
        boolean rhs);

    @VTID(58)
    boolean showBubbleSize();

    @VTID(59)
    void showBubbleSize(
        boolean rhs);

    @VTID(60)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object separator();

    @VTID(61)
    void separator(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(62)
    mol.office.IMsoChartFormat format();

    @VTID(63)
    double height();

}
