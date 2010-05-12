package mol.excel  ;

import com4j.*;

@IID("{00020849-0001-0000-C000-000000000046}")
public interface IChartTitle extends Com4jObject {
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
    boolean includeInLayout();

    @VTID(39)
    void includeInLayout(
        boolean rhs);

    @VTID(40)
    mol.excel.XlChartElementPosition position();

    @VTID(41)
    void position(
        mol.excel.XlChartElementPosition rhs);

    @VTID(42)
    mol.excel.ChartFormat format();

}
