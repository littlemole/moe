package mol.office  ;

import com4j.*;

@IID("{000C171F-0000-0000-C000-000000000046}")
public interface IMsoDataLabels extends Com4jObject,Iterable<Com4jObject> {
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
    mol.office.IMsoCharacters characters(
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object length);

    @VTID(15)
    mol.office.ChartFont font();

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object horizontalAlignment();

    @VTID(17)
    void horizontalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object orientation();

    @VTID(19)
    void orientation(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(20)
    boolean shadow();

    @VTID(21)
    void shadow(
        boolean rhs);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object verticalAlignment();

    @VTID(23)
    void verticalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(24)
    int readingOrder();

    @VTID(25)
    void readingOrder(
        int rhs);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(27)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(28)
    boolean autoText();

    @VTID(29)
    void autoText(
        boolean rhs);

    @VTID(30)
    java.lang.String numberFormat();

    @VTID(31)
    void numberFormat(
        java.lang.String rhs);

    @VTID(32)
    boolean numberFormatLinked();

    @VTID(33)
    void numberFormatLinked(
        boolean rhs);

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object numberFormatLocal();

    @VTID(35)
    void numberFormatLocal(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(36)
    boolean showLegendKey();

    @VTID(37)
    void showLegendKey(
        boolean rhs);

    @VTID(38)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object type();

    @VTID(39)
    void type(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(40)
    mol.office.XlDataLabelPosition position();

    @VTID(41)
    void position(
        mol.office.XlDataLabelPosition rhs);

    @VTID(42)
    boolean showSeriesName();

    @VTID(43)
    void showSeriesName(
        boolean rhs);

    @VTID(44)
    boolean showCategoryName();

    @VTID(45)
    void showCategoryName(
        boolean rhs);

    @VTID(46)
    boolean showValue();

    @VTID(47)
    void showValue(
        boolean rhs);

    @VTID(48)
    boolean showPercentage();

    @VTID(49)
    void showPercentage(
        boolean rhs);

    @VTID(50)
    boolean showBubbleSize();

    @VTID(51)
    void showBubbleSize(
        boolean rhs);

    @VTID(52)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object separator();

    @VTID(53)
    void separator(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(54)
    int count();

    @VTID(55)
    mol.office.IMsoDataLabel item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(56)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(57)
    mol.office.IMsoChartFormat format();

}
