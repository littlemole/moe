package mol.excel  ;

import com4j.*;

@IID("{000208B2-0001-0000-C000-000000000046}")
public interface IDataLabel extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(12)
    mol.excel.Border border();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(14)
    mol.excel.Interior interior();

    @VTID(15)
    mol.excel.ChartFillFormat fill();

    @VTID(16)
    java.lang.String caption();

    @VTID(17)
    void caption(
        java.lang.String rhs);

    @VTID(18)
    mol.excel.Characters characters(
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object length);

    @VTID(19)
    mol.excel.Font font();

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object horizontalAlignment();

    @VTID(21)
    void horizontalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(22)
    double left();

    @VTID(23)
    void left(
        double rhs);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object orientation();

    @VTID(25)
    void orientation(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(26)
    boolean shadow();

    @VTID(27)
    void shadow(
        boolean rhs);

    @VTID(28)
    java.lang.String text();

    @VTID(29)
    void text(
        java.lang.String rhs);

    @VTID(30)
    double top();

    @VTID(31)
    void top(
        double rhs);

    @VTID(32)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object verticalAlignment();

    @VTID(33)
    void verticalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(34)
    int readingOrder();

    @VTID(35)
    void readingOrder(
        int rhs);

    @VTID(36)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(37)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(38)
    boolean autoText();

    @VTID(39)
    void autoText(
        boolean rhs);

    @VTID(40)
    java.lang.String numberFormat();

    @VTID(41)
    void numberFormat(
        java.lang.String rhs);

    @VTID(42)
    boolean numberFormatLinked();

    @VTID(43)
    void numberFormatLinked(
        boolean rhs);

    @VTID(44)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object numberFormatLocal();

    @VTID(45)
    void numberFormatLocal(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(46)
    boolean showLegendKey();

    @VTID(47)
    void showLegendKey(
        boolean rhs);

    @VTID(48)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object type();

    @VTID(49)
    void type(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(50)
    mol.excel.XlDataLabelPosition position();

    @VTID(51)
    void position(
        mol.excel.XlDataLabelPosition rhs);

    @VTID(52)
    boolean showSeriesName();

    @VTID(53)
    void showSeriesName(
        boolean rhs);

    @VTID(54)
    boolean showCategoryName();

    @VTID(55)
    void showCategoryName(
        boolean rhs);

    @VTID(56)
    boolean showValue();

    @VTID(57)
    void showValue(
        boolean rhs);

    @VTID(58)
    boolean showPercentage();

    @VTID(59)
    void showPercentage(
        boolean rhs);

    @VTID(60)
    boolean showBubbleSize();

    @VTID(61)
    void showBubbleSize(
        boolean rhs);

    @VTID(62)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object separator();

    @VTID(63)
    void separator(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(64)
    mol.excel.ChartFormat format();

}
